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
CMAKE_SOURCE_DIR = /home/fancy/文档/cpp_project/Magic+

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fancy/文档/cpp_project/Magic+/build

# Include any dependencies generated for this target.
include src/CMakeFiles/admin.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/admin.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/admin.dir/flags.make

src/CMakeFiles/admin.dir/Admin.cpp.o: src/CMakeFiles/admin.dir/flags.make
src/CMakeFiles/admin.dir/Admin.cpp.o: ../src/Admin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fancy/文档/cpp_project/Magic+/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/admin.dir/Admin.cpp.o"
	cd /home/fancy/文档/cpp_project/Magic+/build/src && /bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/admin.dir/Admin.cpp.o -c /home/fancy/文档/cpp_project/Magic+/src/Admin.cpp

src/CMakeFiles/admin.dir/Admin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/admin.dir/Admin.cpp.i"
	cd /home/fancy/文档/cpp_project/Magic+/build/src && /bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fancy/文档/cpp_project/Magic+/src/Admin.cpp > CMakeFiles/admin.dir/Admin.cpp.i

src/CMakeFiles/admin.dir/Admin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/admin.dir/Admin.cpp.s"
	cd /home/fancy/文档/cpp_project/Magic+/build/src && /bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fancy/文档/cpp_project/Magic+/src/Admin.cpp -o CMakeFiles/admin.dir/Admin.cpp.s

# Object files for target admin
admin_OBJECTS = \
"CMakeFiles/admin.dir/Admin.cpp.o"

# External object files for target admin
admin_EXTERNAL_OBJECTS =

../lib/libadmin.a: src/CMakeFiles/admin.dir/Admin.cpp.o
../lib/libadmin.a: src/CMakeFiles/admin.dir/build.make
../lib/libadmin.a: src/CMakeFiles/admin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fancy/文档/cpp_project/Magic+/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libadmin.a"
	cd /home/fancy/文档/cpp_project/Magic+/build/src && $(CMAKE_COMMAND) -P CMakeFiles/admin.dir/cmake_clean_target.cmake
	cd /home/fancy/文档/cpp_project/Magic+/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/admin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/admin.dir/build: ../lib/libadmin.a

.PHONY : src/CMakeFiles/admin.dir/build

src/CMakeFiles/admin.dir/clean:
	cd /home/fancy/文档/cpp_project/Magic+/build/src && $(CMAKE_COMMAND) -P CMakeFiles/admin.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/admin.dir/clean

src/CMakeFiles/admin.dir/depend:
	cd /home/fancy/文档/cpp_project/Magic+/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fancy/文档/cpp_project/Magic+ /home/fancy/文档/cpp_project/Magic+/src /home/fancy/文档/cpp_project/Magic+/build /home/fancy/文档/cpp_project/Magic+/build/src /home/fancy/文档/cpp_project/Magic+/build/src/CMakeFiles/admin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/admin.dir/depend

