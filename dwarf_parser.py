from elftools.elf.elffile import ELFFile

def extract_function_addresses(filename):
    with open(filename, 'rb') as f:
        elffile = ELFFile(f)

        # Check if file has DWARF information
        if not elffile.has_dwarf_info():
            print("No DWARF info found in this file.")
            return

        # Get DWARF info from the file
        dwarf_info = elffile.get_dwarf_info()

        # Iterate over all the Compilation Units (CUs) in the DWARF information
        for CU in dwarf_info.iter_CUs():
            # Each CU contains a tree of DIEs
            for DIE in CU.iter_DIEs():
                # Check if this DIE represents a subprogram (function)
                if DIE.tag == 'DW_TAG_subprogram':
                    try:
                        # Retrieve and print the low and high PC values, if available
                        name = DIE.attributes['DW_AT_name'].value.decode('utf-8')
                        low_pc = DIE.attributes['DW_AT_low_pc'].value
                        high_pc = DIE.attributes['DW_AT_high_pc'].value # DW_AT_high_pc is a misleading term. it really means the memory range of a fucntion
                        
                        # High PC might be an offset; calculate end address
                        if isinstance(high_pc, int):
                            high_pc = low_pc + high_pc
                        
                        print(f"Function: {name}")
                        print(f"  Start Address: {hex(low_pc)}")
                        print(f"  End Address: {hex(high_pc)}")
                    except KeyError:
                        # If any of the expected attributes are missing, skip this entry
                        continue

if __name__ == '__main__':
    extract_function_addresses('example')
