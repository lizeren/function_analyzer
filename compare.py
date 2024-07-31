import json

def load_json(file_path):
    """Load JSON data from a file."""
    with open(file_path, 'r') as file:
        return json.load(file)

def find_matching_functions(file1, file2, vector_file1, vector_file2):
    """Compare two lists of functions and find matches based on the entry point."""
    functions1 = load_json(file1)
    functions2 = load_json(file2)
    vectors1 = load_json(vector_file1)
    vectors2 = load_json(vector_file2)

    # Create dictionaries for quick lookup by entry point and name
    entry_point_map = {func['entry_point']: func['name'] for func in functions2}
    vector_map1 = {vec['function_name']: vec['vector'] for vec in vectors1}
    vector_map2 = {vec['function_name']: vec['vector'] for vec in vectors2}

    # List to hold matches
    matches = []

    # Check each function from file1 against entry points in file2
    for func in functions1:
        if func['entry_point'] in entry_point_map:
            name_file2 = entry_point_map[func['entry_point']]
            match = {
                "entry_point": func['entry_point'],
                "name_file1": func['name'],
                "name_file2": name_file2,
                "vector_file1": vector_map1.get(func['name'], []),
                "vector_file2": vector_map2.get(name_file2, [])
            }
            matches.append(match)

    return matches

def write_matches_to_json(matches, output_file):
    """Write the matched functions with vectors to a JSON file."""
    with open(output_file, 'w') as file:
        json.dump(matches, file, indent=4)

if __name__ == '__main__':
    # File paths
    file1_path = 'output/src_functions_list.json'
    file2_path = 'output/dec_functions_list.json'
    vector_file1_path = 'output/src_feature.json'
    vector_file2_path = 'output/dec_feature.json'
    output_json_path = 'output/matched_functions_with_vectors.json'

    # Process the matching
    matched_functions = find_matching_functions(file1_path, file2_path, vector_file1_path, vector_file2_path)

    # Save the results
    if matched_functions:
        write_matches_to_json(matched_functions, output_json_path)
        print(f"Found and saved {len(matched_functions)} matches with feature vectors to {output_json_path}")
    else:
        print("No matches found.")
