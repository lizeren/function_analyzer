#include <iostream>
#include <clang/AST/AST.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendActions.h>
#include <llvm/Support/CommandLine.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/SourceManager.h>

using namespace clang;
using namespace clang::tooling;
using namespace clang::ast_matchers;
static llvm::cl::OptionCategory ToolingSampleCategory("My Tooling Sample Options");

class FunctionAnalyzer : public MatchFinder::MatchCallback {
public:
    void run(const MatchFinder::MatchResult &Result) override {
        if (const FunctionDecl *FD = Result.Nodes.getNodeAs<FunctionDecl>("functionDecl")) {
            // Check if the function declaration is from a user-provided source file
            if (!FD->getLocation().isInvalid() &&
                Result.SourceManager->isInMainFile(FD->getLocation())) {
                std::cout << "Function name: " << FD->getNameAsString() << std::endl;
                std::cout << "Number of parameters: " << FD->getNumParams() << std::endl;
                std::cout << "Parameters: ";
                for (const auto *param : FD->parameters()) {
                    std::string paramType = param->getType().getAsString();
                    std::cout << param->getNameAsString() << " (" << paramType << ") ";
                }
                std::cout << std::endl;
                std::cout << "Number of local variables: " << std::endl;
                // Local variable analysis not implemented yet
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
