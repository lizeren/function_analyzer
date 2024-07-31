# Installation Instructions

Follow these instructions to install the necessary tools and compile the project.

## Dependencies

First, install LLVM, libclang, json tools, and clang tools using the following commands:

```bash
sudo apt-get install llvm
sudo apt-get install libclang-10-dev
sudo apt-get install clang-tools-10
sudo apt-get install nlohmann-json3-dev

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


## Dependencies for pyelftools
```bash
pip install pyelftools
```

## Running the dwarf parser

Build the source file in which you are interested to find the starting memory address of each function.
```bash
g++ -O0 -g example.cpp -o example
```
Run the parser
```bash
python3 dwarf_parser.py
```

## Dependencies for pyelftools
compare.py - for finding functions that have the same entry point address
```bash
python3 comapre.py
```