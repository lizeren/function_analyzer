#!/bin/bash

# Define the path to the JSON output file
OUTPUT_JSON="../output/src_feature.json"

# Check if the output JSON file exists and delete it
if [ -f "$OUTPUT_JSON" ]; then
    echo "Removing existing JSON file: $OUTPUT_JSON"
    rm -f "$OUTPUT_JSON"
fi

# Define the directory containing the source files
# SRC_DIR="/home/lizeren/Downloads/curl-8.9.1/src"
SRC_DIR="/home/lizeren/Downloads/curl-8.9.1/lib"


# Define the directories containing the header files
HEADER_DIRS=("/home/lizeren/Downloads/curl-8.9.1/include" 
            "/home/lizeren/Downloads/curl-8.9.1/src" 
            "/home/lizeren/Downloads/curl-8.9.1/lib")

# Location of the build directory containing compile_commands.json
# To generate compile_commands.json,add set(CMAKE_EXPORT_COMPILE_COMMANDS ON) in src/cmakelists.txt
BUILD_DIR="/home/lizeren/Downloads/curl-8.9.1"

# Ensure build directory is available
if [ ! -d "$BUILD_DIR" ]; then
    echo "Build directory $BUILD_DIR does not exist. Please run CMake first."
    exit 1
fi

# Check if the source directory exists
if [ ! -d "$SRC_DIR" ]; then
    echo "Source directory $SRC_DIR does not exist."
    exit 1
fi

# Check each header directory exists
for dir in "${HEADER_DIRS[@]}"; do
    if [ ! -d "$dir" ]; then
        echo "Header directory $dir does not exist."
        exit 1
    fi
done

# Check if the static analyzer executable exists
if [ ! -f "./MyStaticAnalyzer" ]; then
    echo "Static analyzer executable not found."
    exit 1
fi

# Loop through all .c files in the source directory
for src_file in "$SRC_DIR"/*.c; do
    echo "Analyzing file: $src_file"
    include_args=""
    for dir in "${HEADER_DIRS[@]}"; do
        include_args+=" -I$dir"
    done
    ./MyStaticAnalyzer --extra-arg=-w -p "${BUILD_DIR}" "$src_file"
    # without --extra-arg=-w flags from gcc will give warnings
done

echo "Analysis complete."
