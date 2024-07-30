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


using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
static llvm::cl::OptionCategory ToolingSampleCategory("My Tooling Sample Options");

class LocalVariableCounter : public RecursiveASTVisitor<LocalVariableCounter> {
public:
    std::unordered_map<std::string, int> typeCount;
    unsigned long long stackSize = 0;

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
        }
        return true;
    }
};

class FunctionAnalyzer : public MatchFinder::MatchCallback {
public:
    std::vector<std::string> functionData;  // To store JSON objects as strings

    void run(const MatchFinder::MatchResult &Result) override {
        if (const FunctionDecl *FD = Result.Nodes.getNodeAs<FunctionDecl>("functionDecl")) {
            if (!FD->getLocation().isInvalid() && Result.SourceManager->isInMainFile(FD->getLocation())) {
                std::ostringstream json;
                json << "{\n";
                json << "  \"function_name\": \"" << FD->getNameAsString() << "\",\n";
                json << "  \"number_of_parameters\": " << FD->getNumParams() << ",\n";

                unsigned long long paramStackSize = 0;
                int total_local_variables = 0;
                unsigned long long localVariableStackSize = 0;
                int meaningfulBlocks = 0;

                for (const auto *param : FD->parameters()) {
                    unsigned paramSize = FD->getASTContext().getTypeSize(param->getType()) / 8;
                    paramStackSize += paramSize;
                }
                json << "  \"total_parameter_stack_size_bytes\": " << paramStackSize << ",\n";

                LocalVariableCounter LVC;
                LVC.TraverseDecl(FD);
                localVariableStackSize = LVC.stackSize;
                for (const auto &typePair : LVC.typeCount) {
                    total_local_variables += typePair.second;
                }
                json << "  \"total_local_variable_stack_size_bytes\": " << localVariableStackSize << ",\n";
                json << "  \"total_local_variables\": " << total_local_variables << ",\n";

                std::unique_ptr<CFG> cfg = CFG::buildCFG(FD, FD->getBody(), &FD->getASTContext(), CFG::BuildOptions());
                if (cfg) {
                    for (auto *block : *cfg) {
                        if (!block->empty() && block != &cfg->getEntry() && block != &cfg->getExit()) {
                            meaningfulBlocks++;
                        }
                    }
                }
                json << "  \"number_of_meaningful_basic_blocks\": " << meaningfulBlocks << "\n";
                json << "}\n";

                functionData.push_back(json.str());
            }
        }
    }

~FunctionAnalyzer() {
    std::ifstream existingFile("../output/src_feature.json", std::ios::ate); // Open file to check size
    bool isEmpty = true;
    if (!existingFile.is_open() || existingFile.tellg() == 0) {
        // If the file isn't open or the size is 0, it's considered empty
        isEmpty = true;
    } else {
        isEmpty = false;
    }
    existingFile.close();

    std::ofstream jsonFile;
    if (isEmpty) {
        jsonFile.open("../output/src_feature.json", std::ios::out);
        jsonFile << "[\n"; // Start a new JSON array if the file is empty
        
    } else {
        // If the file is not empty, we prepare it for appending by removing the last "]\n"
        std::fstream modifyFile("../output/src_feature.json", std::ios::in | std::ios::out);
        long pos = modifyFile.tellg();
        modifyFile.seekg(-2, std::ios::end);
        pos = modifyFile.tellg(); // Find the position before the last "]"
        modifyFile.seekp(pos); // Position the file pointer here to overwrite "]" with ","
        modifyFile << "\n,\n"; // Properly format the separation between JSON entries
        modifyFile.close();
        
        jsonFile.open("../output/src_feature.json", std::ios::out | std::ios::app);
    }

    // Append the new JSON objects
    for (size_t i = 0; i < functionData.size(); ++i) {
        jsonFile << functionData[i];
        if (i != functionData.size() - 1) {
            jsonFile << ",\n";
        }
    }

    jsonFile << "]"; // Close the JSON array
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