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
CMAKE_SOURCE_DIR = /home/seungcoh/바탕화면/temp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seungcoh/바탕화면/temp/build

# Include any dependencies generated for this target.
include CMakeFiles/d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/d.dir/flags.make

CMakeFiles/d.dir/main.cpp.o: CMakeFiles/d.dir/flags.make
CMakeFiles/d.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seungcoh/바탕화면/temp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/d.dir/main.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/d.dir/main.cpp.o -c /home/seungcoh/바탕화면/temp/main.cpp

CMakeFiles/d.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/d.dir/main.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seungcoh/바탕화면/temp/main.cpp > CMakeFiles/d.dir/main.cpp.i

CMakeFiles/d.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/d.dir/main.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seungcoh/바탕화면/temp/main.cpp -o CMakeFiles/d.dir/main.cpp.s

# Object files for target d
d_OBJECTS = \
"CMakeFiles/d.dir/main.cpp.o"

# External object files for target d
d_EXTERNAL_OBJECTS =

d : CMakeFiles/d.dir/main.cpp.o
d : CMakeFiles/d.dir/build.make
d : CMakeFiles/d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seungcoh/바탕화면/temp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/d.dir/build: d

.PHONY : CMakeFiles/d.dir/build

CMakeFiles/d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/d.dir/clean

CMakeFiles/d.dir/depend:
	cd /home/seungcoh/바탕화면/temp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seungcoh/바탕화면/temp /home/seungcoh/바탕화면/temp /home/seungcoh/바탕화면/temp/build /home/seungcoh/바탕화면/temp/build /home/seungcoh/바탕화면/temp/build/CMakeFiles/d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/d.dir/depend

