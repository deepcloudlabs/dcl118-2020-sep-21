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
CMAKE_COMMAND = /home/guru/clion-2020.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/guru/clion-2020.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/new-memory_alignment-exception.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/new-memory_alignment-exception.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/new-memory_alignment-exception.dir/flags.make

CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.o: CMakeFiles/new-memory_alignment-exception.dir/flags.make
CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.o: ../memory_alignment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.o -c /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/memory_alignment.cpp

CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/memory_alignment.cpp > CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.i

CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/memory_alignment.cpp -o CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.s

# Object files for target new-memory_alignment-exception
new__memory_alignment__exception_OBJECTS = \
"CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.o"

# External object files for target new-memory_alignment-exception
new__memory_alignment__exception_EXTERNAL_OBJECTS =

new-memory_alignment-exception: CMakeFiles/new-memory_alignment-exception.dir/memory_alignment.cpp.o
new-memory_alignment-exception: CMakeFiles/new-memory_alignment-exception.dir/build.make
new-memory_alignment-exception: CMakeFiles/new-memory_alignment-exception.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable new-memory_alignment-exception"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/new-memory_alignment-exception.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/new-memory_alignment-exception.dir/build: new-memory_alignment-exception

.PHONY : CMakeFiles/new-memory_alignment-exception.dir/build

CMakeFiles/new-memory_alignment-exception.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/new-memory_alignment-exception.dir/cmake_clean.cmake
.PHONY : CMakeFiles/new-memory_alignment-exception.dir/clean

CMakeFiles/new-memory_alignment-exception.dir/depend:
	cd /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug/CMakeFiles/new-memory_alignment-exception.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/new-memory_alignment-exception.dir/depend
