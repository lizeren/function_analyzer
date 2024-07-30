#!/bin/bash

# Define the path to the JSON output file
OUTPUT_JSON="../output/dec_feature.json"

# Check if the output JSON file exists and delete it
if [ -f "$OUTPUT_JSON" ]; then
    echo "Removing existing JSON file: $OUTPUT_JSON"
    rm -f "$OUTPUT_JSON"
fi

# Define the directory containing the source files

SRC_DIR="../output/dec_func"


# Check if the source directory exists
if [ ! -d "$SRC_DIR" ]; then
    echo "Source directory $SRC_DIR does not exist."
    exit 1
fi


# Check if the static analyzer executable exists
if [ ! -f "./MyStaticAnalyzer" ]; then
    echo "Static analyzer executable not found."
    exit 1
fi

# Loop through all .c files in the source directory
for src_file in "$SRC_DIR"/*.c; do
    echo "Analyzing file: $src_file"
    ./MyStaticAnalyzer "$src_file" 
done

echo "Analysis complete."
