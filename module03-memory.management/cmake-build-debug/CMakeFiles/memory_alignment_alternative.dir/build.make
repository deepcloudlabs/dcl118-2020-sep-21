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
include CMakeFiles/memory_alignment_alternative.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/memory_alignment_alternative.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memory_alignment_alternative.dir/flags.make

CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.o: CMakeFiles/memory_alignment_alternative.dir/flags.make
CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.o: ../memory_alignment_alternative.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.o -c /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/memory_alignment_alternative.cpp

CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/memory_alignment_alternative.cpp > CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.i

CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/memory_alignment_alternative.cpp -o CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.s

# Object files for target memory_alignment_alternative
memory_alignment_alternative_OBJECTS = \
"CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.o"

# External object files for target memory_alignment_alternative
memory_alignment_alternative_EXTERNAL_OBJECTS =

memory_alignment_alternative: CMakeFiles/memory_alignment_alternative.dir/memory_alignment_alternative.cpp.o
memory_alignment_alternative: CMakeFiles/memory_alignment_alternative.dir/build.make
memory_alignment_alternative: CMakeFiles/memory_alignment_alternative.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable memory_alignment_alternative"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memory_alignment_alternative.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/memory_alignment_alternative.dir/build: memory_alignment_alternative

.PHONY : CMakeFiles/memory_alignment_alternative.dir/build

CMakeFiles/memory_alignment_alternative.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memory_alignment_alternative.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memory_alignment_alternative.dir/clean

CMakeFiles/memory_alignment_alternative.dir/depend:
	cd /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug /home/guru/CLionProjects/2020/dcl118-sep-21/module03-memory.management/cmake-build-debug/CMakeFiles/memory_alignment_alternative.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/memory_alignment_alternative.dir/depend

