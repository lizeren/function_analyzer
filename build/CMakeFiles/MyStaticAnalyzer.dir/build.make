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
include CMakeFiles/MyStaticAnalyzer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyStaticAnalyzer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyStaticAnalyzer.dir/flags.make

CMakeFiles/MyStaticAnalyzer.dir/main.cpp.o: CMakeFiles/MyStaticAnalyzer.dir/flags.make
CMakeFiles/MyStaticAnalyzer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lizeren/Desktop/static_analyzer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyStaticAnalyzer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyStaticAnalyzer.dir/main.cpp.o -c /home/lizeren/Desktop/static_analyzer/main.cpp

CMakeFiles/MyStaticAnalyzer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyStaticAnalyzer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lizeren/Desktop/static_analyzer/main.cpp > CMakeFiles/MyStaticAnalyzer.dir/main.cpp.i

CMakeFiles/MyStaticAnalyzer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyStaticAnalyzer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lizeren/Desktop/static_analyzer/main.cpp -o CMakeFiles/MyStaticAnalyzer.dir/main.cpp.s

# Object files for target MyStaticAnalyzer
MyStaticAnalyzer_OBJECTS = \
"CMakeFiles/MyStaticAnalyzer.dir/main.cpp.o"

# External object files for target MyStaticAnalyzer
MyStaticAnalyzer_EXTERNAL_OBJECTS =

MyStaticAnalyzer: CMakeFiles/MyStaticAnalyzer.dir/main.cpp.o
MyStaticAnalyzer: CMakeFiles/MyStaticAnalyzer.dir/build.make
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangTooling.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangASTMatchers.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangBasic.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangAST.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangFrontend.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangSerialization.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangParse.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangSema.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangEdit.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangAnalysis.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangASTMatchers.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangDriver.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangFormat.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangToolingInclusions.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangToolingCore.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangAST.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangRewrite.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangLex.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libclangBasic.a
MyStaticAnalyzer: /usr/lib/llvm-10/lib/libLLVM-10.so.1
MyStaticAnalyzer: CMakeFiles/MyStaticAnalyzer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lizeren/Desktop/static_analyzer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyStaticAnalyzer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyStaticAnalyzer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyStaticAnalyzer.dir/build: MyStaticAnalyzer

.PHONY : CMakeFiles/MyStaticAnalyzer.dir/build

CMakeFiles/MyStaticAnalyzer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyStaticAnalyzer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyStaticAnalyzer.dir/clean

CMakeFiles/MyStaticAnalyzer.dir/depend:
	cd /home/lizeren/Desktop/static_analyzer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lizeren/Desktop/static_analyzer /home/lizeren/Desktop/static_analyzer /home/lizeren/Desktop/static_analyzer/build /home/lizeren/Desktop/static_analyzer/build /home/lizeren/Desktop/static_analyzer/build/CMakeFiles/MyStaticAnalyzer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyStaticAnalyzer.dir/depend

