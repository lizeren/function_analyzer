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
    void run(const MatchFinder::MatchResult &Result) override {
        if (const FunctionDecl *FD = Result.Nodes.getNodeAs<FunctionDecl>("functionDecl")) {
            if (!FD->getLocation().isInvalid() && Result.SourceManager->isInMainFile(FD->getLocation())) {
                std::cout << std::endl;
                std::cout << "Function name: " << FD->getNameAsString() << std::endl;

                // Parameter analysis

                unsigned long long paramStackSize = 0;


                std::cout << "Number of parameters: " << FD->getNumParams() << std::endl;
                std::cout << "Parameters: ";
                for (const auto *param : FD->parameters()) {
                    std::string paramType = param->getType().getAsString();

                    unsigned paramSize = FD->getASTContext().getTypeSize(param->getType()) / 8; // Convert bit to byte
                    paramStackSize += paramSize;

                    std::cout << param->getNameAsString() << " (" << paramType << ") ";
                }
                std::cout << "\nTotal Parameter Stack Size (bytes): " << paramStackSize << std::endl;
                


                // Local variable analysis
                LocalVariableCounter LVC;

                 LVC.TraverseDecl(FD);
                std::cout << "Total Local Variable Stack Size (bytes): " << LVC.stackSize << std::endl;

                LVC.TraverseDecl(FD);  // Directly pass const Decl*
                int total_local_variables = 0;
                std::cout << "Local variables: " << std::endl;
                for (const auto &typePair : LVC.typeCount) {
                    std::cout << "Type: " << typePair.first << ", Count: " << typePair.second << std::endl;
                    total_local_variables += typePair.second;
                }
                std::cout << "Total Local variables: " << total_local_variables << std::endl;


                // Basic Block counting
                // BuildCFG - Constructs a CFG from an AST.
                std::unique_ptr<CFG> cfg = CFG::buildCFG(FD, FD->getBody(), &FD->getASTContext(), CFG::BuildOptions());
                if (cfg) {
                    int meaningfulBlocks = 0;
                    for (auto *block : *cfg) {
                        if (!block->empty() && block != &cfg->getEntry() && block != &cfg->getExit()) {
                            meaningfulBlocks++;
                        }
                    }
                    std::cout << "Number of meaningful Basic Blocks: " << meaningfulBlocks << std::endl;
                } else {
                    std::cout << "CFG could not be built for this function." << std::endl;
                }
            }
        }
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

