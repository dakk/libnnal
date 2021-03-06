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
include CMakeFiles/neuralnetwork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/neuralnetwork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/neuralnetwork.dir/flags.make

CMakeFiles/neuralnetwork.dir/mlp.c.o: CMakeFiles/neuralnetwork.dir/flags.make
CMakeFiles/neuralnetwork.dir/mlp.c.o: mlp.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/Projects/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/neuralnetwork.dir/mlp.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/neuralnetwork.dir/mlp.c.o   -c /home/dak/Projects/libnnal/src/mlp.c

CMakeFiles/neuralnetwork.dir/mlp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/neuralnetwork.dir/mlp.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/Projects/libnnal/src/mlp.c > CMakeFiles/neuralnetwork.dir/mlp.c.i

CMakeFiles/neuralnetwork.dir/mlp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/neuralnetwork.dir/mlp.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/Projects/libnnal/src/mlp.c -o CMakeFiles/neuralnetwork.dir/mlp.c.s

CMakeFiles/neuralnetwork.dir/mlp.c.o.requires:
.PHONY : CMakeFiles/neuralnetwork.dir/mlp.c.o.requires

CMakeFiles/neuralnetwork.dir/mlp.c.o.provides: CMakeFiles/neuralnetwork.dir/mlp.c.o.requires
	$(MAKE) -f CMakeFiles/neuralnetwork.dir/build.make CMakeFiles/neuralnetwork.dir/mlp.c.o.provides.build
.PHONY : CMakeFiles/neuralnetwork.dir/mlp.c.o.provides

CMakeFiles/neuralnetwork.dir/mlp.c.o.provides.build: CMakeFiles/neuralnetwork.dir/mlp.c.o

CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o: CMakeFiles/neuralnetwork.dir/flags.make
CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o: pattern_recognition.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/Projects/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o   -c /home/dak/Projects/libnnal/src/pattern_recognition.c

CMakeFiles/neuralnetwork.dir/pattern_recognition.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/neuralnetwork.dir/pattern_recognition.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/Projects/libnnal/src/pattern_recognition.c > CMakeFiles/neuralnetwork.dir/pattern_recognition.c.i

CMakeFiles/neuralnetwork.dir/pattern_recognition.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/neuralnetwork.dir/pattern_recognition.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/Projects/libnnal/src/pattern_recognition.c -o CMakeFiles/neuralnetwork.dir/pattern_recognition.c.s

CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o.requires:
.PHONY : CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o.requires

CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o.provides: CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o.requires
	$(MAKE) -f CMakeFiles/neuralnetwork.dir/build.make CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o.provides.build
.PHONY : CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o.provides

CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o.provides.build: CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o

CMakeFiles/neuralnetwork.dir/fuzzy.c.o: CMakeFiles/neuralnetwork.dir/flags.make
CMakeFiles/neuralnetwork.dir/fuzzy.c.o: fuzzy.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/Projects/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/neuralnetwork.dir/fuzzy.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/neuralnetwork.dir/fuzzy.c.o   -c /home/dak/Projects/libnnal/src/fuzzy.c

CMakeFiles/neuralnetwork.dir/fuzzy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/neuralnetwork.dir/fuzzy.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/Projects/libnnal/src/fuzzy.c > CMakeFiles/neuralnetwork.dir/fuzzy.c.i

CMakeFiles/neuralnetwork.dir/fuzzy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/neuralnetwork.dir/fuzzy.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/Projects/libnnal/src/fuzzy.c -o CMakeFiles/neuralnetwork.dir/fuzzy.c.s

CMakeFiles/neuralnetwork.dir/fuzzy.c.o.requires:
.PHONY : CMakeFiles/neuralnetwork.dir/fuzzy.c.o.requires

CMakeFiles/neuralnetwork.dir/fuzzy.c.o.provides: CMakeFiles/neuralnetwork.dir/fuzzy.c.o.requires
	$(MAKE) -f CMakeFiles/neuralnetwork.dir/build.make CMakeFiles/neuralnetwork.dir/fuzzy.c.o.provides.build
.PHONY : CMakeFiles/neuralnetwork.dir/fuzzy.c.o.provides

CMakeFiles/neuralnetwork.dir/fuzzy.c.o.provides.build: CMakeFiles/neuralnetwork.dir/fuzzy.c.o

CMakeFiles/neuralnetwork.dir/mathf.c.o: CMakeFiles/neuralnetwork.dir/flags.make
CMakeFiles/neuralnetwork.dir/mathf.c.o: mathf.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/Projects/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/neuralnetwork.dir/mathf.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/neuralnetwork.dir/mathf.c.o   -c /home/dak/Projects/libnnal/src/mathf.c

CMakeFiles/neuralnetwork.dir/mathf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/neuralnetwork.dir/mathf.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/Projects/libnnal/src/mathf.c > CMakeFiles/neuralnetwork.dir/mathf.c.i

CMakeFiles/neuralnetwork.dir/mathf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/neuralnetwork.dir/mathf.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/Projects/libnnal/src/mathf.c -o CMakeFiles/neuralnetwork.dir/mathf.c.s

CMakeFiles/neuralnetwork.dir/mathf.c.o.requires:
.PHONY : CMakeFiles/neuralnetwork.dir/mathf.c.o.requires

CMakeFiles/neuralnetwork.dir/mathf.c.o.provides: CMakeFiles/neuralnetwork.dir/mathf.c.o.requires
	$(MAKE) -f CMakeFiles/neuralnetwork.dir/build.make CMakeFiles/neuralnetwork.dir/mathf.c.o.provides.build
.PHONY : CMakeFiles/neuralnetwork.dir/mathf.c.o.provides

CMakeFiles/neuralnetwork.dir/mathf.c.o.provides.build: CMakeFiles/neuralnetwork.dir/mathf.c.o

CMakeFiles/neuralnetwork.dir/som.c.o: CMakeFiles/neuralnetwork.dir/flags.make
CMakeFiles/neuralnetwork.dir/som.c.o: som.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/Projects/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/neuralnetwork.dir/som.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/neuralnetwork.dir/som.c.o   -c /home/dak/Projects/libnnal/src/som.c

CMakeFiles/neuralnetwork.dir/som.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/neuralnetwork.dir/som.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/Projects/libnnal/src/som.c > CMakeFiles/neuralnetwork.dir/som.c.i

CMakeFiles/neuralnetwork.dir/som.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/neuralnetwork.dir/som.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/Projects/libnnal/src/som.c -o CMakeFiles/neuralnetwork.dir/som.c.s

CMakeFiles/neuralnetwork.dir/som.c.o.requires:
.PHONY : CMakeFiles/neuralnetwork.dir/som.c.o.requires

CMakeFiles/neuralnetwork.dir/som.c.o.provides: CMakeFiles/neuralnetwork.dir/som.c.o.requires
	$(MAKE) -f CMakeFiles/neuralnetwork.dir/build.make CMakeFiles/neuralnetwork.dir/som.c.o.provides.build
.PHONY : CMakeFiles/neuralnetwork.dir/som.c.o.provides

CMakeFiles/neuralnetwork.dir/som.c.o.provides.build: CMakeFiles/neuralnetwork.dir/som.c.o

# Object files for target neuralnetwork
neuralnetwork_OBJECTS = \
"CMakeFiles/neuralnetwork.dir/mlp.c.o" \
"CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o" \
"CMakeFiles/neuralnetwork.dir/fuzzy.c.o" \
"CMakeFiles/neuralnetwork.dir/mathf.c.o" \
"CMakeFiles/neuralnetwork.dir/som.c.o"

# External object files for target neuralnetwork
neuralnetwork_EXTERNAL_OBJECTS =

libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/mlp.c.o
libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o
libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/fuzzy.c.o
libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/mathf.c.o
libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/som.c.o
libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/build.make
libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libneuralnetwork.a"
	$(CMAKE_COMMAND) -P CMakeFiles/neuralnetwork.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/neuralnetwork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/neuralnetwork.dir/build: libneuralnetwork.a
.PHONY : CMakeFiles/neuralnetwork.dir/build

CMakeFiles/neuralnetwork.dir/requires: CMakeFiles/neuralnetwork.dir/mlp.c.o.requires
CMakeFiles/neuralnetwork.dir/requires: CMakeFiles/neuralnetwork.dir/pattern_recognition.c.o.requires
CMakeFiles/neuralnetwork.dir/requires: CMakeFiles/neuralnetwork.dir/fuzzy.c.o.requires
CMakeFiles/neuralnetwork.dir/requires: CMakeFiles/neuralnetwork.dir/mathf.c.o.requires
CMakeFiles/neuralnetwork.dir/requires: CMakeFiles/neuralnetwork.dir/som.c.o.requires
.PHONY : CMakeFiles/neuralnetwork.dir/requires

CMakeFiles/neuralnetwork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/neuralnetwork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/neuralnetwork.dir/clean

CMakeFiles/neuralnetwork.dir/depend:
	cd /home/dak/Projects/libnnal/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src /home/dak/Projects/libnnal/src/CMakeFiles/neuralnetwork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/neuralnetwork.dir/depend

