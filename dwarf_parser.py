import json
from elftools.elf.elffile import ELFFile

def extract_function_addresses(filename, output_file):
    with open(filename, 'rb') as f:
        elffile = ELFFile(f)

        # Prepare to collect function data
        functions_data = []

        # Check if file has DWARF information
        if not elffile.has_dwarf_info():
            functions_data.append({"error": "No DWARF info found in this file."})
        else:
            # Get DWARF info from the file
            dwarf_info = elffile.get_dwarf_info()

            # Iterate over all the Compilation Units (CUs) in the DWARF information
            for CU in dwarf_info.iter_CUs():
                # Each CU contains a tree of DIEs
                for DIE in CU.iter_DIEs():
                    # Check if this DIE represents a subprogram (function)
                    if DIE.tag == 'DW_TAG_subprogram':
                        try:
                            # Retrieve the function name and address range
                            name = DIE.attributes['DW_AT_name'].value.decode('utf-8')
                            low_pc = DIE.attributes['DW_AT_low_pc'].value
                            high_pc = DIE.attributes['DW_AT_high_pc'].value

                            # High PC might be an offset; calculate end address
                            if isinstance(high_pc, int):
                                high_pc = low_pc + high_pc

                            # Append function info to the list
                            functions_data.append({
                                "name": name,
                                "entry_point": hex(low_pc),
                                "end_address": hex(high_pc)
                            })
                        except KeyError:
                            # If any of the expected attributes are missing, skip this entry
                            continue

        # Write the collected data to a JSON file
        with open(output_file, 'w') as out:
            json.dump(functions_data, out, indent=4)

if __name__ == '__main__':
    extract_function_addresses('example', 'output/src_functions_list.json')
