#!/bin/bash

# Define the path to the JSON output file
OUTPUT_JSON="../output/src_feature.json"

# Check if the output JSON file exists and delete it
if [ -f "$OUTPUT_JSON" ]; then
    echo "Removing existing JSON file: $OUTPUT_JSON"
    rm -f "$OUTPUT_JSON"
fi

# Define the directory containing the source files

SRC_DIR="../example/src"

# Define the directory containing the header files

HEADER_DIR="../example/include"


# Check if the source directory exists
if [ ! -d "$SRC_DIR" ]; then
    echo "Source directory $SRC_DIR does not exist."
    exit 1
fi

# Check if the header directory exists
if [ ! -d "$HEADER_DIR" ]; then
    echo "Header directory $HEADER_DIR does not exist."
    exit 1
fi

# Check if the static analyzer executable exists
if [ ! -f "./MyStaticAnalyzer" ]; then
    echo "Static analyzer executable not found."
    exit 1
fi

# Loop through all .cpp files in the source directory
for src_file in "$SRC_DIR"/*.cpp; do
    echo "Analyzing file: $src_file"
    ./MyStaticAnalyzer "$src_file" -- -Iinclude -I"$HEADER_DIR" 
    # Include header
    # https://stackoverflow.com/questions/19952307/clang-tool-libtooling-set-header-search-path-to-standard-libs-headers-founda
done

echo "Analysis complete."
