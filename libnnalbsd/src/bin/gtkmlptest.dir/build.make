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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dak/libnnal/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dak/libnnal/src

# Include any dependencies generated for this target.
include CMakeFiles/../bin/gtkmlptest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/../bin/gtkmlptest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/../bin/gtkmlptest.dir/flags.make

CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o: CMakeFiles/../bin/gtkmlptest.dir/flags.make
CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o: test/gtkmlptest.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o   -c /home/dak/libnnal/src/test/gtkmlptest.c

CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/libnnal/src/test/gtkmlptest.c > CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.i

CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/libnnal/src/test/gtkmlptest.c -o CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.s

CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o.requires:
.PHONY : CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o.requires

CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o.provides: CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o.requires
	$(MAKE) -f CMakeFiles/../bin/gtkmlptest.dir/build.make CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o.provides.build
.PHONY : CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o.provides

CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o.provides.build: CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o
.PHONY : CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o.provides.build

# Object files for target ../bin/gtkmlptest
__/bin/gtkmlptest_OBJECTS = \
"CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o"

# External object files for target ../bin/gtkmlptest
__/bin/gtkmlptest_EXTERNAL_OBJECTS =

../bin/gtkmlptest: CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o
../bin/gtkmlptest: libpnglite.a
../bin/gtkmlptest: libgtkmlpwidget.a
../bin/gtkmlptest: /usr/lib/libz.so
../bin/gtkmlptest: /usr/local/lib/libcairo.so
../bin/gtkmlptest: /usr/local/lib/libgtk-x11-2.0.so
../bin/gtkmlptest: libneuralnetwork.a
../bin/gtkmlptest: CMakeFiles/../bin/gtkmlptest.dir/build.make
../bin/gtkmlptest: CMakeFiles/../bin/gtkmlptest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../bin/gtkmlptest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/../bin/gtkmlptest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/../bin/gtkmlptest.dir/build: ../bin/gtkmlptest
.PHONY : CMakeFiles/../bin/gtkmlptest.dir/build

CMakeFiles/../bin/gtkmlptest.dir/requires: CMakeFiles/../bin/gtkmlptest.dir/test/gtkmlptest.c.o.requires
.PHONY : CMakeFiles/../bin/gtkmlptest.dir/requires

CMakeFiles/../bin/gtkmlptest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/../bin/gtkmlptest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/../bin/gtkmlptest.dir/clean

CMakeFiles/../bin/gtkmlptest.dir/depend:
	cd /home/dak/libnnal/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dak/libnnal/src /home/dak/libnnal/src /home/dak/libnnal/src /home/dak/libnnal/src /home/dak/libnnal/src/bin/gtkmlptest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/../bin/gtkmlptest.dir/depend

