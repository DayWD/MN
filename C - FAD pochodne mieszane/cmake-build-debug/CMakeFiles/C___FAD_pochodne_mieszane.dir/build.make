# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/C___FAD_pochodne_mieszane.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C___FAD_pochodne_mieszane.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C___FAD_pochodne_mieszane.dir/flags.make

CMakeFiles/C___FAD_pochodne_mieszane.dir/main.cpp.obj: CMakeFiles/C___FAD_pochodne_mieszane.dir/flags.make
CMakeFiles/C___FAD_pochodne_mieszane.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C___FAD_pochodne_mieszane.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\C___FAD_pochodne_mieszane.dir\main.cpp.obj -c "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane\main.cpp"

CMakeFiles/C___FAD_pochodne_mieszane.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C___FAD_pochodne_mieszane.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane\main.cpp" > CMakeFiles\C___FAD_pochodne_mieszane.dir\main.cpp.i

CMakeFiles/C___FAD_pochodne_mieszane.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C___FAD_pochodne_mieszane.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane\main.cpp" -o CMakeFiles\C___FAD_pochodne_mieszane.dir\main.cpp.s

# Object files for target C___FAD_pochodne_mieszane
C___FAD_pochodne_mieszane_OBJECTS = \
"CMakeFiles/C___FAD_pochodne_mieszane.dir/main.cpp.obj"

# External object files for target C___FAD_pochodne_mieszane
C___FAD_pochodne_mieszane_EXTERNAL_OBJECTS =

C___FAD_pochodne_mieszane.exe: CMakeFiles/C___FAD_pochodne_mieszane.dir/main.cpp.obj
C___FAD_pochodne_mieszane.exe: CMakeFiles/C___FAD_pochodne_mieszane.dir/build.make
C___FAD_pochodne_mieszane.exe: CMakeFiles/C___FAD_pochodne_mieszane.dir/linklibs.rsp
C___FAD_pochodne_mieszane.exe: CMakeFiles/C___FAD_pochodne_mieszane.dir/objects1.rsp
C___FAD_pochodne_mieszane.exe: CMakeFiles/C___FAD_pochodne_mieszane.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C___FAD_pochodne_mieszane.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C___FAD_pochodne_mieszane.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C___FAD_pochodne_mieszane.dir/build: C___FAD_pochodne_mieszane.exe

.PHONY : CMakeFiles/C___FAD_pochodne_mieszane.dir/build

CMakeFiles/C___FAD_pochodne_mieszane.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C___FAD_pochodne_mieszane.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C___FAD_pochodne_mieszane.dir/clean

CMakeFiles/C___FAD_pochodne_mieszane.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane" "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane" "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane\cmake-build-debug" "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane\cmake-build-debug" "C:\Users\Dawid\CLionProjects\MN\C - FAD pochodne mieszane\cmake-build-debug\CMakeFiles\C___FAD_pochodne_mieszane.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/C___FAD_pochodne_mieszane.dir/depend

