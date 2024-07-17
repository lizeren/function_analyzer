# Installation Instructions

Follow these instructions to install the necessary tools and compile the project.

## Dependencies

First, install LLVM, libclang, and clang tools using the following commands:

```bash
sudo apt-get install llvm
sudo apt-get install libclang-10-dev
sudo apt-get install clang-tools-10
```
## Building the Project

Create a build directory (if it does not exist) and compile the project:

```bash
mkdir -p build
cd build
cmake ..
make
```

## Running the Analyzer

After building the project, you can run the static analyzer on an example file:
```bash
./MyStaticAnalyzer ../example.cpp
```