# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/seungcoh/.brew/Cellar/cmake/3.20.5/bin/cmake

# The command to remove a file.
RM = /Users/seungcoh/.brew/Cellar/cmake/3.20.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/seungcoh/doing/temp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/seungcoh/doing/temp/build

# Include any dependencies generated for this target.
include CMakeFiles/temp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/temp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/temp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/temp.dir/flags.make

CMakeFiles/temp.dir/check.c.o: CMakeFiles/temp.dir/flags.make
CMakeFiles/temp.dir/check.c.o: ../check.c
CMakeFiles/temp.dir/check.c.o: CMakeFiles/temp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungcoh/doing/temp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/temp.dir/check.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/temp.dir/check.c.o -MF CMakeFiles/temp.dir/check.c.o.d -o CMakeFiles/temp.dir/check.c.o -c /Users/seungcoh/doing/temp/check.c

CMakeFiles/temp.dir/check.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/temp.dir/check.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seungcoh/doing/temp/check.c > CMakeFiles/temp.dir/check.c.i

CMakeFiles/temp.dir/check.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/temp.dir/check.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seungcoh/doing/temp/check.c -o CMakeFiles/temp.dir/check.c.s

CMakeFiles/temp.dir/ft_printf.c.o: CMakeFiles/temp.dir/flags.make
CMakeFiles/temp.dir/ft_printf.c.o: ../ft_printf.c
CMakeFiles/temp.dir/ft_printf.c.o: CMakeFiles/temp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungcoh/doing/temp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/temp.dir/ft_printf.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/temp.dir/ft_printf.c.o -MF CMakeFiles/temp.dir/ft_printf.c.o.d -o CMakeFiles/temp.dir/ft_printf.c.o -c /Users/seungcoh/doing/temp/ft_printf.c

CMakeFiles/temp.dir/ft_printf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/temp.dir/ft_printf.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seungcoh/doing/temp/ft_printf.c > CMakeFiles/temp.dir/ft_printf.c.i

CMakeFiles/temp.dir/ft_printf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/temp.dir/ft_printf.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seungcoh/doing/temp/ft_printf.c -o CMakeFiles/temp.dir/ft_printf.c.s

CMakeFiles/temp.dir/ft_printf_utils.c.o: CMakeFiles/temp.dir/flags.make
CMakeFiles/temp.dir/ft_printf_utils.c.o: ../ft_printf_utils.c
CMakeFiles/temp.dir/ft_printf_utils.c.o: CMakeFiles/temp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungcoh/doing/temp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/temp.dir/ft_printf_utils.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/temp.dir/ft_printf_utils.c.o -MF CMakeFiles/temp.dir/ft_printf_utils.c.o.d -o CMakeFiles/temp.dir/ft_printf_utils.c.o -c /Users/seungcoh/doing/temp/ft_printf_utils.c

CMakeFiles/temp.dir/ft_printf_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/temp.dir/ft_printf_utils.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seungcoh/doing/temp/ft_printf_utils.c > CMakeFiles/temp.dir/ft_printf_utils.c.i

CMakeFiles/temp.dir/ft_printf_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/temp.dir/ft_printf_utils.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seungcoh/doing/temp/ft_printf_utils.c -o CMakeFiles/temp.dir/ft_printf_utils.c.s

CMakeFiles/temp.dir/ft_printf_utils2.c.o: CMakeFiles/temp.dir/flags.make
CMakeFiles/temp.dir/ft_printf_utils2.c.o: ../ft_printf_utils2.c
CMakeFiles/temp.dir/ft_printf_utils2.c.o: CMakeFiles/temp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungcoh/doing/temp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/temp.dir/ft_printf_utils2.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/temp.dir/ft_printf_utils2.c.o -MF CMakeFiles/temp.dir/ft_printf_utils2.c.o.d -o CMakeFiles/temp.dir/ft_printf_utils2.c.o -c /Users/seungcoh/doing/temp/ft_printf_utils2.c

CMakeFiles/temp.dir/ft_printf_utils2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/temp.dir/ft_printf_utils2.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seungcoh/doing/temp/ft_printf_utils2.c > CMakeFiles/temp.dir/ft_printf_utils2.c.i

CMakeFiles/temp.dir/ft_printf_utils2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/temp.dir/ft_printf_utils2.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seungcoh/doing/temp/ft_printf_utils2.c -o CMakeFiles/temp.dir/ft_printf_utils2.c.s

CMakeFiles/temp.dir/main.c.o: CMakeFiles/temp.dir/flags.make
CMakeFiles/temp.dir/main.c.o: ../main.c
CMakeFiles/temp.dir/main.c.o: CMakeFiles/temp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungcoh/doing/temp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/temp.dir/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/temp.dir/main.c.o -MF CMakeFiles/temp.dir/main.c.o.d -o CMakeFiles/temp.dir/main.c.o -c /Users/seungcoh/doing/temp/main.c

CMakeFiles/temp.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/temp.dir/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seungcoh/doing/temp/main.c > CMakeFiles/temp.dir/main.c.i

CMakeFiles/temp.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/temp.dir/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seungcoh/doing/temp/main.c -o CMakeFiles/temp.dir/main.c.s

CMakeFiles/temp.dir/print.c.o: CMakeFiles/temp.dir/flags.make
CMakeFiles/temp.dir/print.c.o: ../print.c
CMakeFiles/temp.dir/print.c.o: CMakeFiles/temp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungcoh/doing/temp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/temp.dir/print.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/temp.dir/print.c.o -MF CMakeFiles/temp.dir/print.c.o.d -o CMakeFiles/temp.dir/print.c.o -c /Users/seungcoh/doing/temp/print.c

CMakeFiles/temp.dir/print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/temp.dir/print.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seungcoh/doing/temp/print.c > CMakeFiles/temp.dir/print.c.i

CMakeFiles/temp.dir/print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/temp.dir/print.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seungcoh/doing/temp/print.c -o CMakeFiles/temp.dir/print.c.s

# Object files for target temp
temp_OBJECTS = \
"CMakeFiles/temp.dir/check.c.o" \
"CMakeFiles/temp.dir/ft_printf.c.o" \
"CMakeFiles/temp.dir/ft_printf_utils.c.o" \
"CMakeFiles/temp.dir/ft_printf_utils2.c.o" \
"CMakeFiles/temp.dir/main.c.o" \
"CMakeFiles/temp.dir/print.c.o"

# External object files for target temp
temp_EXTERNAL_OBJECTS =

temp: CMakeFiles/temp.dir/check.c.o
temp: CMakeFiles/temp.dir/ft_printf.c.o
temp: CMakeFiles/temp.dir/ft_printf_utils.c.o
temp: CMakeFiles/temp.dir/ft_printf_utils2.c.o
temp: CMakeFiles/temp.dir/main.c.o
temp: CMakeFiles/temp.dir/print.c.o
temp: CMakeFiles/temp.dir/build.make
temp: CMakeFiles/temp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/seungcoh/doing/temp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable temp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/temp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/temp.dir/build: temp
.PHONY : CMakeFiles/temp.dir/build

CMakeFiles/temp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/temp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/temp.dir/clean

CMakeFiles/temp.dir/depend:
	cd /Users/seungcoh/doing/temp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/seungcoh/doing/temp /Users/seungcoh/doing/temp /Users/seungcoh/doing/temp/build /Users/seungcoh/doing/temp/build /Users/seungcoh/doing/temp/build/CMakeFiles/temp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/temp.dir/depend

