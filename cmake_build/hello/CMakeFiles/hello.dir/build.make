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
CMAKE_SOURCE_DIR = /mnt/f/C++/FFmpegDemo/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/f/C++/FFmpegDemo/cmake_build

# Include any dependencies generated for this target.
include hello/CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include hello/CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include hello/CMakeFiles/hello.dir/flags.make

hello/CMakeFiles/hello.dir/hello.cpp.o: hello/CMakeFiles/hello.dir/flags.make
hello/CMakeFiles/hello.dir/hello.cpp.o: /mnt/f/C++/FFmpegDemo/src/hello/hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/C++/FFmpegDemo/cmake_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hello/CMakeFiles/hello.dir/hello.cpp.o"
	cd /mnt/f/C++/FFmpegDemo/cmake_build/hello && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello.dir/hello.cpp.o -c /mnt/f/C++/FFmpegDemo/src/hello/hello.cpp

hello/CMakeFiles/hello.dir/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/hello.cpp.i"
	cd /mnt/f/C++/FFmpegDemo/cmake_build/hello && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/C++/FFmpegDemo/src/hello/hello.cpp > CMakeFiles/hello.dir/hello.cpp.i

hello/CMakeFiles/hello.dir/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/hello.cpp.s"
	cd /mnt/f/C++/FFmpegDemo/cmake_build/hello && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/C++/FFmpegDemo/src/hello/hello.cpp -o CMakeFiles/hello.dir/hello.cpp.s

hello/CMakeFiles/hello.dir/hello.cpp.o.requires:

.PHONY : hello/CMakeFiles/hello.dir/hello.cpp.o.requires

hello/CMakeFiles/hello.dir/hello.cpp.o.provides: hello/CMakeFiles/hello.dir/hello.cpp.o.requires
	$(MAKE) -f hello/CMakeFiles/hello.dir/build.make hello/CMakeFiles/hello.dir/hello.cpp.o.provides.build
.PHONY : hello/CMakeFiles/hello.dir/hello.cpp.o.provides

hello/CMakeFiles/hello.dir/hello.cpp.o.provides.build: hello/CMakeFiles/hello.dir/hello.cpp.o


# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/hello.cpp.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

/mnt/f/C++/FFmpegDemo/lib/libhello.so: hello/CMakeFiles/hello.dir/hello.cpp.o
/mnt/f/C++/FFmpegDemo/lib/libhello.so: hello/CMakeFiles/hello.dir/build.make
/mnt/f/C++/FFmpegDemo/lib/libhello.so: hello/CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/f/C++/FFmpegDemo/cmake_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /mnt/f/C++/FFmpegDemo/lib/libhello.so"
	cd /mnt/f/C++/FFmpegDemo/cmake_build/hello && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hello/CMakeFiles/hello.dir/build: /mnt/f/C++/FFmpegDemo/lib/libhello.so

.PHONY : hello/CMakeFiles/hello.dir/build

hello/CMakeFiles/hello.dir/requires: hello/CMakeFiles/hello.dir/hello.cpp.o.requires

.PHONY : hello/CMakeFiles/hello.dir/requires

hello/CMakeFiles/hello.dir/clean:
	cd /mnt/f/C++/FFmpegDemo/cmake_build/hello && $(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : hello/CMakeFiles/hello.dir/clean

hello/CMakeFiles/hello.dir/depend:
	cd /mnt/f/C++/FFmpegDemo/cmake_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/f/C++/FFmpegDemo/src /mnt/f/C++/FFmpegDemo/src/hello /mnt/f/C++/FFmpegDemo/cmake_build /mnt/f/C++/FFmpegDemo/cmake_build/hello /mnt/f/C++/FFmpegDemo/cmake_build/hello/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hello/CMakeFiles/hello.dir/depend

