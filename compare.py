import json

def load_functions(file_path):
    """ Load functions from a JSON file. """
    with open(file_path, 'r') as file:
        return json.load(file)

def find_matching_functions(file1, file2):
    """ Compare two lists of functions and find matches based on the entry point. """
    functions1 = load_functions(file1)
    functions2 = load_functions(file2)

    # Convert list of dictionaries from file2 into a dictionary for quick lookup
    entry_point_map = {func['entry_point']: func['name'] for func in functions2}

    # List to hold matches
    matches = []

    # Check each function from file1 against entry points in file2
    for func in functions1:
        if func['entry_point'] in entry_point_map:
            matches.append({
                "entry_point": func['entry_point'],
                "name_file1": func['name'],
                "name_file2": entry_point_map[func['entry_point']]
            })

    return matches

if __name__ == '__main__':
    # File paths
    file1_path = 'output/src_functions_list.json'
    file2_path = 'output/dec_functions_list.json'

    # Finding matches
    matched_functions = find_matching_functions(file1_path, file2_path)

    # Output results
    if matched_functions:
        print("Found Matches:")
        for match in matched_functions:
            print(f"Entry Point: {match['entry_point']}")
            print(f" Function in File 1: {match['name_file1']}")
            print(f" Function in File 2: {match['name_file2']}\n")
    else:
        print("No matches found.")
