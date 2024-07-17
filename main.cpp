#include <iostream>
#include <clang/AST/AST.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendActions.h>
#include <llvm/Support/CommandLine.h>


using namespace clang;
using namespace clang::tooling;
using namespace clang::ast_matchers;
static llvm::cl::OptionCategory ToolingSampleCategory("My Tooling Sample Options");

#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/SourceManager.h>

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
                    std::cout << param->getNameAsString() << " ";
                }
                std::cout << std::endl;
                std::cout << "Number of local variables: " << std::endl;
            }
        }
    }
};


int main(int argc, const char **argv) {
    // Parse command-line arguments using CommonOptionsParser
    CommonOptionsParser OptionsParser(argc, argv, ToolingSampleCategory); // Note: ToolingSampleCategory should be defined or managed accordingly

    // Create a ClangTool to run analysis based on parsed options
    ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());

    // Instantiate the analyzer and the matcher
    FunctionAnalyzer Analyzer;
    MatchFinder Finder;

    // Define the AST matcher rule for function declarations and bind them to the analyzer
    Finder.addMatcher(functionDecl().bind("functionDecl"), &Analyzer);

    // Run the tool with the created frontend action factory and return the result
    return Tool.run(newFrontendActionFactory(&Finder).get());
}
