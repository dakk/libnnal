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
include CMakeFiles/../bin/patterntest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/../bin/patterntest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/../bin/patterntest.dir/flags.make

CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o: CMakeFiles/../bin/patterntest.dir/flags.make
CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o: test/patterntest.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/Projects/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o   -c /home/dak/Projects/libnnal/src/test/patterntest.c

CMakeFiles/../bin/patterntest.dir/test/patterntest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/../bin/patterntest.dir/test/patterntest.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/Projects/libnnal/src/test/patterntest.c > CMakeFiles/../bin/patterntest.dir/test/patterntest.c.i

CMakeFiles/../bin/patterntest.dir/test/patterntest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/../bin/patterntest.dir/test/patterntest.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/Projects/libnnal/src/test/patterntest.c -o CMakeFiles/../bin/patterntest.dir/test/patterntest.c.s

CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o.requires:
.PHONY : CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o.requires

CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o.provides: CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o.requires
	$(MAKE) -f CMakeFiles/../bin/patterntest.dir/build.make CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o.provides.build
.PHONY : CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o.provides

CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o.provides.build: CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o

# Object files for target ../bin/patterntest
__/bin/patterntest_OBJECTS = \
"CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o"

# External object files for target ../bin/patterntest
__/bin/patterntest_EXTERNAL_OBJECTS =

../bin/patterntest: CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o
../bin/patterntest: libneuralnetwork.a
../bin/patterntest: CMakeFiles/../bin/patterntest.dir/build.make
../bin/patterntest: CMakeFiles/../bin/patterntest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../bin/patterntest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/../bin/patterntest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/../bin/patterntest.dir/build: ../bin/patterntest
.PHONY : CMakeFiles/../bin/patterntest.dir/build

CMakeFiles/../bin/patterntest.dir/requires: CMakeFiles/../bin/patterntest.dir/test/patterntest.c.o.requires
.PHONY : CMakeFiles/../bin/patterntest.dir/requires

CMakeFiles/../bin/patterntest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/../bin/patterntest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/../bin/patterntest.dir/clean

CMakeFiles/../bin/patterntest.dir/depend:
	cd /home/dak/Projects/libnnal/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src/bin/patterntest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/../bin/patterntest.dir/depend

