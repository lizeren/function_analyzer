set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.10)
project(MyStaticAnalyzer)

# Find LLVM and Clang packages
find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

message(STATUS "LLVM version: ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using ClangConfig.cmake in: ${CLANG_DIR}")


# Add definitions and include directories
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})

# This line is necessary to ensure all necessary Clang components are linked
link_directories(${LLVM_LIBRARY_DIRS})

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the executable from the specified source file
add_executable(MyStaticAnalyzer feature_extraction.cpp)

# Link against Clang and LLVM libraries
target_link_libraries(MyStaticAnalyzer
  PRIVATE
  clangTooling
  clangASTMatchers
  clangBasic
  clangAST
  clangFrontend
  clangSerialization
  LLVM
)
