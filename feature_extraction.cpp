#include <iostream>
#include <unordered_map>
#include <string>
#include <clang/AST/AST.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/CommandLine.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Analysis/CFG.h>
#include <clang/Analysis/Analyses/Dominators.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <nlohmann/json.hpp>

// Use the library's namespace for convenience
using json = nlohmann::json;

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
static llvm::cl::OptionCategory ToolingSampleCategory("My Tooling Sample Options");

class LocalVariableCounter : public RecursiveASTVisitor<LocalVariableCounter> {
public:
    std::unordered_map<std::string, int> typeCount;
    unsigned long long stackSize = 0;
    int totalLocalCount = 0;  // Total count of local variables


    // Override to accept const Decl*
    bool TraverseDecl(const Decl *D) {
        if (!D) return true; // Handle null pointers gracefully
        return RecursiveASTVisitor<LocalVariableCounter>::TraverseDecl(const_cast<Decl*>(D));
    }

    bool VisitVarDecl(const VarDecl *v) {
        if (v->isLocalVarDecl() && !v->hasGlobalStorage()) {
            std::string typeName = v->getType().getAsString();
            typeCount[typeName]++;

            // Calculate size of the type in bytes
            unsigned typeSize = v->getASTContext().getTypeSize(v->getType()) / 8; // getTypeSize returns size in bits
            stackSize += typeSize;
            totalLocalCount++;
        }
        return true;
    }
};

class FunctionAnalyzer : public MatchFinder::MatchCallback {
public:
    std::vector<json> functionData;  // To store JSON objects

    void run(const MatchFinder::MatchResult &Result) override {
        if (const FunctionDecl *FD = Result.Nodes.getNodeAs<FunctionDecl>("functionDecl")) {
            if (!FD->getLocation().isInvalid() && Result.SourceManager->isInMainFile(FD->getLocation())) {
                json functionJson;
                functionJson["function_name"] = FD->getNameAsString();
                functionJson["number_of_parameters"] = FD->getNumParams();

                unsigned long long paramStackSize = 0;
                for (const auto *param : FD->parameters()) {
                    unsigned paramSize = FD->getASTContext().getTypeSize(param->getType()) / 8;
                    paramStackSize += paramSize;
                }
                functionJson["total_parameter_stack_size_bytes"] = paramStackSize;

                LocalVariableCounter LVC;
                LVC.TraverseDecl(FD);
                functionJson["total_local_variable_stack_size_bytes"] = LVC.stackSize;
                functionJson["total_local_variables"] = LVC.totalLocalCount;

                // Calculate the number of meaningful basic blocks
                auto cfg = CFG::buildCFG(FD, FD->getBody(), &FD->getASTContext(), CFG::BuildOptions());
                int meaningfulBlocks = 0;
                if (cfg) {
                    for (const auto *block : *cfg) {
                        if (!block->empty() && block != &cfg->getEntry() && block != &cfg->getExit()) {
                            meaningfulBlocks++;
                        }
                    }
                }
                functionJson["number_of_meaningful_basic_blocks"] = meaningfulBlocks;
                // # of parameters, parameter stack size, local variable stack size, # of local variables,# of basic blocks
                functionJson["vector"] = {FD->getNumParams(),paramStackSize,LVC.stackSize,LVC.totalLocalCount,meaningfulBlocks};
                functionData.push_back(functionJson);
            }
        }
    }

    ~FunctionAnalyzer() {
    // Path to the JSON output file
    std::string jsonFilePath = "../output/src_feature.json";
    std::ifstream existingFile(jsonFilePath);
    json outputJson;

    // Check if the file exists and is not empty
    if (existingFile.good()) {
        // Load the existing JSON from the file
        try {
            existingFile >> outputJson;
        } catch (const json::parse_error& e) {
            // Handle possible JSON parsing error
            std::cerr << "JSON parsing error: " << e.what() << '\n';
            // Initialize as an empty array if parsing fails
            outputJson = json::array();
        }
    } else {
        // If the file does not exist or cannot be opened, start with a new array
        outputJson = json::array();
    }
    existingFile.close();

    // Append new function data to the loaded or newly created JSON array
    for (const auto &funcJson : functionData) {
        outputJson.push_back(funcJson);
    }

    // Write the updated JSON array back to the file
    std::ofstream jsonFile(jsonFilePath);
    if (!jsonFile.is_open()) {
        std::cerr << "Failed to open JSON file for writing.\n";
        return;
    }
    jsonFile << outputJson.dump(4);  // Write with an indentation of 4 spaces for readability
    jsonFile.close();
}
};





int main(int argc, const char **argv) {
    CommonOptionsParser OptionsParser(argc, argv, ToolingSampleCategory);
    ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());

    FunctionAnalyzer Analyzer;
    MatchFinder Finder;
    Finder.addMatcher(functionDecl().bind("functionDecl"), &Analyzer);

    return Tool.run(newFrontendActionFactory(&Finder).get());
}