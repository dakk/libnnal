# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

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
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dak/libneuralnetwork/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dak/libneuralnetwork/src

# Include any dependencies generated for this target.
include CMakeFiles/../bin/mlptest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/../bin/mlptest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/../bin/mlptest.dir/flags.make

CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o: CMakeFiles/../bin/mlptest.dir/flags.make
CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o: test/mlptest.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/libneuralnetwork/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o   -c /home/dak/libneuralnetwork/src/test/mlptest.c

CMakeFiles/../bin/mlptest.dir/test/mlptest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/../bin/mlptest.dir/test/mlptest.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/libneuralnetwork/src/test/mlptest.c > CMakeFiles/../bin/mlptest.dir/test/mlptest.c.i

CMakeFiles/../bin/mlptest.dir/test/mlptest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/../bin/mlptest.dir/test/mlptest.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/libneuralnetwork/src/test/mlptest.c -o CMakeFiles/../bin/mlptest.dir/test/mlptest.c.s

CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o.requires:
.PHONY : CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o.requires

CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o.provides: CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o.requires
	$(MAKE) -f CMakeFiles/../bin/mlptest.dir/build.make CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o.provides.build
.PHONY : CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o.provides

CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o.provides.build: CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o
.PHONY : CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o.provides.build

# Object files for target ../bin/mlptest
__/bin/mlptest_OBJECTS = \
"CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o"

# External object files for target ../bin/mlptest
__/bin/mlptest_EXTERNAL_OBJECTS =

../bin/mlptest: CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o
../bin/mlptest: libneuralnetwork.a
../bin/mlptest: CMakeFiles/../bin/mlptest.dir/build.make
../bin/mlptest: CMakeFiles/../bin/mlptest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../bin/mlptest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/../bin/mlptest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/../bin/mlptest.dir/build: ../bin/mlptest
.PHONY : CMakeFiles/../bin/mlptest.dir/build

CMakeFiles/../bin/mlptest.dir/requires: CMakeFiles/../bin/mlptest.dir/test/mlptest.c.o.requires
.PHONY : CMakeFiles/../bin/mlptest.dir/requires

CMakeFiles/../bin/mlptest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/../bin/mlptest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/../bin/mlptest.dir/clean

CMakeFiles/../bin/mlptest.dir/depend:
	cd /home/dak/libneuralnetwork/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dak/libneuralnetwork/src /home/dak/libneuralnetwork/src /home/dak/libneuralnetwork/src /home/dak/libneuralnetwork/src /home/dak/libneuralnetwork/src/bin/mlptest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/../bin/mlptest.dir/depend

