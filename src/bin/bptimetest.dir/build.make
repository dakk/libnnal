# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dak/Projects/libnnal/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dak/Projects/libnnal/src

# Include any dependencies generated for this target.
include CMakeFiles/../bin/bptimetest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/../bin/bptimetest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/../bin/bptimetest.dir/flags.make

CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o: CMakeFiles/../bin/bptimetest.dir/flags.make
CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o: test/bptimetest.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/Projects/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o   -c /home/dak/Projects/libnnal/src/test/bptimetest.c

CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/Projects/libnnal/src/test/bptimetest.c > CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.i

CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/Projects/libnnal/src/test/bptimetest.c -o CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.s

CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o.requires:
.PHONY : CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o.requires

CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o.provides: CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o.requires
	$(MAKE) -f CMakeFiles/../bin/bptimetest.dir/build.make CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o.provides.build
.PHONY : CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o.provides

CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o.provides.build: CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o

# Object files for target ../bin/bptimetest
__/bin/bptimetest_OBJECTS = \
"CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o"

# External object files for target ../bin/bptimetest
__/bin/bptimetest_EXTERNAL_OBJECTS =

../bin/bptimetest: CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o
../bin/bptimetest: libneuralnetwork.a
../bin/bptimetest: CMakeFiles/../bin/bptimetest.dir/build.make
../bin/bptimetest: CMakeFiles/../bin/bptimetest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../bin/bptimetest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/../bin/bptimetest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/../bin/bptimetest.dir/build: ../bin/bptimetest
.PHONY : CMakeFiles/../bin/bptimetest.dir/build

CMakeFiles/../bin/bptimetest.dir/requires: CMakeFiles/../bin/bptimetest.dir/test/bptimetest.c.o.requires
.PHONY : CMakeFiles/../bin/bptimetest.dir/requires

CMakeFiles/../bin/bptimetest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/../bin/bptimetest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/../bin/bptimetest.dir/clean

CMakeFiles/../bin/bptimetest.dir/depend:
	cd /home/dak/Projects/libnnal/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src/bin/bptimetest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/../bin/bptimetest.dir/depend
