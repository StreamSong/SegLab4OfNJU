# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/cs144/SegLab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs144/SegLab4/build

# Include any dependencies generated for this target.
include ComplieAndRun/CMakeFiles/RunOneFile.dir/depend.make

# Include the progress variables for this target.
include ComplieAndRun/CMakeFiles/RunOneFile.dir/progress.make

# Include the compile flags for this target's objects.
include ComplieAndRun/CMakeFiles/RunOneFile.dir/flags.make

ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o: ComplieAndRun/CMakeFiles/RunOneFile.dir/flags.make
ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o: ../ComplieAndRun/RunOneFile.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs144/SegLab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o"
	cd /home/cs144/SegLab4/build/ComplieAndRun && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RunOneFile.dir/RunOneFile.cc.o -c /home/cs144/SegLab4/ComplieAndRun/RunOneFile.cc

ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RunOneFile.dir/RunOneFile.cc.i"
	cd /home/cs144/SegLab4/build/ComplieAndRun && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs144/SegLab4/ComplieAndRun/RunOneFile.cc > CMakeFiles/RunOneFile.dir/RunOneFile.cc.i

ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RunOneFile.dir/RunOneFile.cc.s"
	cd /home/cs144/SegLab4/build/ComplieAndRun && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs144/SegLab4/ComplieAndRun/RunOneFile.cc -o CMakeFiles/RunOneFile.dir/RunOneFile.cc.s

ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o.requires:

.PHONY : ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o.requires

ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o.provides: ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o.requires
	$(MAKE) -f ComplieAndRun/CMakeFiles/RunOneFile.dir/build.make ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o.provides.build
.PHONY : ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o.provides

ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o.provides.build: ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o


# Object files for target RunOneFile
RunOneFile_OBJECTS = \
"CMakeFiles/RunOneFile.dir/RunOneFile.cc.o"

# External object files for target RunOneFile
RunOneFile_EXTERNAL_OBJECTS =

ComplieAndRun/RunOneFile: ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o
ComplieAndRun/RunOneFile: ComplieAndRun/CMakeFiles/RunOneFile.dir/build.make
ComplieAndRun/RunOneFile: ComplieAndRun/CMakeFiles/RunOneFile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs144/SegLab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RunOneFile"
	cd /home/cs144/SegLab4/build/ComplieAndRun && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RunOneFile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ComplieAndRun/CMakeFiles/RunOneFile.dir/build: ComplieAndRun/RunOneFile

.PHONY : ComplieAndRun/CMakeFiles/RunOneFile.dir/build

ComplieAndRun/CMakeFiles/RunOneFile.dir/requires: ComplieAndRun/CMakeFiles/RunOneFile.dir/RunOneFile.cc.o.requires

.PHONY : ComplieAndRun/CMakeFiles/RunOneFile.dir/requires

ComplieAndRun/CMakeFiles/RunOneFile.dir/clean:
	cd /home/cs144/SegLab4/build/ComplieAndRun && $(CMAKE_COMMAND) -P CMakeFiles/RunOneFile.dir/cmake_clean.cmake
.PHONY : ComplieAndRun/CMakeFiles/RunOneFile.dir/clean

ComplieAndRun/CMakeFiles/RunOneFile.dir/depend:
	cd /home/cs144/SegLab4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs144/SegLab4 /home/cs144/SegLab4/ComplieAndRun /home/cs144/SegLab4/build /home/cs144/SegLab4/build/ComplieAndRun /home/cs144/SegLab4/build/ComplieAndRun/CMakeFiles/RunOneFile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ComplieAndRun/CMakeFiles/RunOneFile.dir/depend

