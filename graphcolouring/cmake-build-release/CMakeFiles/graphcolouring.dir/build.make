# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nicolesood/Desktop/graphcolouring

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nicolesood/Desktop/graphcolouring/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/graphcolouring.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graphcolouring.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphcolouring.dir/flags.make

CMakeFiles/graphcolouring.dir/main.cpp.o: CMakeFiles/graphcolouring.dir/flags.make
CMakeFiles/graphcolouring.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolesood/Desktop/graphcolouring/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphcolouring.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphcolouring.dir/main.cpp.o -c /Users/nicolesood/Desktop/graphcolouring/main.cpp

CMakeFiles/graphcolouring.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphcolouring.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolesood/Desktop/graphcolouring/main.cpp > CMakeFiles/graphcolouring.dir/main.cpp.i

CMakeFiles/graphcolouring.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphcolouring.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolesood/Desktop/graphcolouring/main.cpp -o CMakeFiles/graphcolouring.dir/main.cpp.s

CMakeFiles/graphcolouring.dir/Graph.cpp.o: CMakeFiles/graphcolouring.dir/flags.make
CMakeFiles/graphcolouring.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nicolesood/Desktop/graphcolouring/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphcolouring.dir/Graph.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphcolouring.dir/Graph.cpp.o -c /Users/nicolesood/Desktop/graphcolouring/Graph.cpp

CMakeFiles/graphcolouring.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphcolouring.dir/Graph.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nicolesood/Desktop/graphcolouring/Graph.cpp > CMakeFiles/graphcolouring.dir/Graph.cpp.i

CMakeFiles/graphcolouring.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphcolouring.dir/Graph.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nicolesood/Desktop/graphcolouring/Graph.cpp -o CMakeFiles/graphcolouring.dir/Graph.cpp.s

# Object files for target graphcolouring
graphcolouring_OBJECTS = \
"CMakeFiles/graphcolouring.dir/main.cpp.o" \
"CMakeFiles/graphcolouring.dir/Graph.cpp.o"

# External object files for target graphcolouring
graphcolouring_EXTERNAL_OBJECTS =

graphcolouring: CMakeFiles/graphcolouring.dir/main.cpp.o
graphcolouring: CMakeFiles/graphcolouring.dir/Graph.cpp.o
graphcolouring: CMakeFiles/graphcolouring.dir/build.make
graphcolouring: CMakeFiles/graphcolouring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nicolesood/Desktop/graphcolouring/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable graphcolouring"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphcolouring.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphcolouring.dir/build: graphcolouring

.PHONY : CMakeFiles/graphcolouring.dir/build

CMakeFiles/graphcolouring.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphcolouring.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphcolouring.dir/clean

CMakeFiles/graphcolouring.dir/depend:
	cd /Users/nicolesood/Desktop/graphcolouring/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nicolesood/Desktop/graphcolouring /Users/nicolesood/Desktop/graphcolouring /Users/nicolesood/Desktop/graphcolouring/cmake-build-release /Users/nicolesood/Desktop/graphcolouring/cmake-build-release /Users/nicolesood/Desktop/graphcolouring/cmake-build-release/CMakeFiles/graphcolouring.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graphcolouring.dir/depend

