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

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
static llvm::cl::OptionCategory ToolingSampleCategory("My Tooling Sample Options");

class LocalVariableCounter : public RecursiveASTVisitor<LocalVariableCounter> {
public:
    std::unordered_map<std::string, int> typeCount;

    bool VisitVarDecl(VarDecl *v) {
        if (v->isLocalVarDecl() && !v->hasGlobalStorage()) {
            std::string typeName = v->getType().getAsString();
            typeCount[typeName]++;
        }
        return true;
    }
};

class FunctionAnalyzer : public MatchFinder::MatchCallback {
public:
    void run(const MatchFinder::MatchResult &Result) override {
        // Inside FunctionAnalyzer::run method
        if (const FunctionDecl *FD = Result.Nodes.getNodeAs<FunctionDecl>("functionDecl")) {
            if (!FD->getLocation().isInvalid() && Result.SourceManager->isInMainFile(FD->getLocation())) {
                std::cout << "Function name: " << FD->getNameAsString() << std::endl;
                std::cout << "Number of parameters: " << FD->getNumParams() << std::endl;
                std::cout << "Parameters: ";
                for (const auto *param : FD->parameters()) {
                    std::string paramType = param->getType().getAsString();
                    std::cout << param->getNameAsString() << " (" << paramType << ") ";
                }
                std::cout << std::endl;

                // Local variable analysis
                LocalVariableCounter LVC;
                LVC.TraverseDecl(const_cast<Decl *>(static_cast<const Decl *>(FD)));  // Remove const-ness
                std::cout << "Local variables: " << std::endl;
                for (const auto &typePair : LVC.typeCount) {
                    std::cout << "Type: " << typePair.first << ", Count: " << typePair.second << std::endl;
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
