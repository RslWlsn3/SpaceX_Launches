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
CMAKE_SOURCE_DIR = /mnt/c/Users/connor.mote/dev/spacexlaunches

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/connor.mote/dev/spacexlaunches/build

# Utility rule file for ContinuousSubmit.

# Include the progress variables for this target.
include json/CMakeFiles/ContinuousSubmit.dir/progress.make

json/CMakeFiles/ContinuousSubmit:
	cd /mnt/c/Users/connor.mote/dev/spacexlaunches/build/json && /usr/bin/ctest -D ContinuousSubmit

ContinuousSubmit: json/CMakeFiles/ContinuousSubmit
ContinuousSubmit: json/CMakeFiles/ContinuousSubmit.dir/build.make

.PHONY : ContinuousSubmit

# Rule to build all files generated by this target.
json/CMakeFiles/ContinuousSubmit.dir/build: ContinuousSubmit

.PHONY : json/CMakeFiles/ContinuousSubmit.dir/build

json/CMakeFiles/ContinuousSubmit.dir/clean:
	cd /mnt/c/Users/connor.mote/dev/spacexlaunches/build/json && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousSubmit.dir/cmake_clean.cmake
.PHONY : json/CMakeFiles/ContinuousSubmit.dir/clean

json/CMakeFiles/ContinuousSubmit.dir/depend:
	cd /mnt/c/Users/connor.mote/dev/spacexlaunches/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/connor.mote/dev/spacexlaunches /mnt/c/Users/connor.mote/dev/spacexlaunches/json /mnt/c/Users/connor.mote/dev/spacexlaunches/build /mnt/c/Users/connor.mote/dev/spacexlaunches/build/json /mnt/c/Users/connor.mote/dev/spacexlaunches/build/json/CMakeFiles/ContinuousSubmit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : json/CMakeFiles/ContinuousSubmit.dir/depend

