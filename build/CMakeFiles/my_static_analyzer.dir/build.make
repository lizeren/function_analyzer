# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lizeren/Desktop/static_analyzer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lizeren/Desktop/static_analyzer/build

# Include any dependencies generated for this target.
include CMakeFiles/my_static_analyzer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_static_analyzer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_static_analyzer.dir/flags.make

CMakeFiles/my_static_analyzer.dir/main.cpp.o: CMakeFiles/my_static_analyzer.dir/flags.make
CMakeFiles/my_static_analyzer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lizeren/Desktop/static_analyzer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_static_analyzer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_static_analyzer.dir/main.cpp.o -c /home/lizeren/Desktop/static_analyzer/main.cpp

CMakeFiles/my_static_analyzer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_static_analyzer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lizeren/Desktop/static_analyzer/main.cpp > CMakeFiles/my_static_analyzer.dir/main.cpp.i

CMakeFiles/my_static_analyzer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_static_analyzer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lizeren/Desktop/static_analyzer/main.cpp -o CMakeFiles/my_static_analyzer.dir/main.cpp.s

# Object files for target my_static_analyzer
my_static_analyzer_OBJECTS = \
"CMakeFiles/my_static_analyzer.dir/main.cpp.o"

# External object files for target my_static_analyzer
my_static_analyzer_EXTERNAL_OBJECTS =

my_static_analyzer: CMakeFiles/my_static_analyzer.dir/main.cpp.o
my_static_analyzer: CMakeFiles/my_static_analyzer.dir/build.make
my_static_analyzer: /usr/lib/llvm-10/lib/libclangTooling.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangBasic.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangASTMatchers.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangFormat.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangToolingInclusions.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangFrontend.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangDriver.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangParse.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangSerialization.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangSema.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangEdit.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangAnalysis.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangASTMatchers.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangToolingCore.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangAST.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangRewrite.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangLex.a
my_static_analyzer: /usr/lib/llvm-10/lib/libclangBasic.a
my_static_analyzer: /usr/lib/llvm-10/lib/libLLVM-10.so.1
my_static_analyzer: CMakeFiles/my_static_analyzer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lizeren/Desktop/static_analyzer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_static_analyzer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_static_analyzer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_static_analyzer.dir/build: my_static_analyzer

.PHONY : CMakeFiles/my_static_analyzer.dir/build

CMakeFiles/my_static_analyzer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_static_analyzer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_static_analyzer.dir/clean

CMakeFiles/my_static_analyzer.dir/depend:
	cd /home/lizeren/Desktop/static_analyzer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lizeren/Desktop/static_analyzer /home/lizeren/Desktop/static_analyzer /home/lizeren/Desktop/static_analyzer/build /home/lizeren/Desktop/static_analyzer/build /home/lizeren/Desktop/static_analyzer/build/CMakeFiles/my_static_analyzer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_static_analyzer.dir/depend

