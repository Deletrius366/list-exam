# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "D:\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\CLionProjects\list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\CLionProjects\list\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/std.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/std.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/std.dir/flags.make

CMakeFiles/std.dir/std.cpp.obj: CMakeFiles/std.dir/flags.make
CMakeFiles/std.dir/std.cpp.obj: ../std.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\CLionProjects\list\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/std.dir/std.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\std.dir\std.cpp.obj -c C:\Users\User\CLionProjects\list\std.cpp

CMakeFiles/std.dir/std.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/std.dir/std.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\CLionProjects\list\std.cpp > CMakeFiles\std.dir\std.cpp.i

CMakeFiles/std.dir/std.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/std.dir/std.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\CLionProjects\list\std.cpp -o CMakeFiles\std.dir\std.cpp.s

CMakeFiles/std.dir/mman.cpp.obj: CMakeFiles/std.dir/flags.make
CMakeFiles/std.dir/mman.cpp.obj: ../mman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\CLionProjects\list\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/std.dir/mman.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\std.dir\mman.cpp.obj -c C:\Users\User\CLionProjects\list\mman.cpp

CMakeFiles/std.dir/mman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/std.dir/mman.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\CLionProjects\list\mman.cpp > CMakeFiles\std.dir\mman.cpp.i

CMakeFiles/std.dir/mman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/std.dir/mman.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\CLionProjects\list\mman.cpp -o CMakeFiles\std.dir\mman.cpp.s

# Object files for target std
std_OBJECTS = \
"CMakeFiles/std.dir/std.cpp.obj" \
"CMakeFiles/std.dir/mman.cpp.obj"

# External object files for target std
std_EXTERNAL_OBJECTS =

std.exe: CMakeFiles/std.dir/std.cpp.obj
std.exe: CMakeFiles/std.dir/mman.cpp.obj
std.exe: CMakeFiles/std.dir/build.make
std.exe: CMakeFiles/std.dir/linklibs.rsp
std.exe: CMakeFiles/std.dir/objects1.rsp
std.exe: CMakeFiles/std.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\CLionProjects\list\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable std.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\std.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/std.dir/build: std.exe

.PHONY : CMakeFiles/std.dir/build

CMakeFiles/std.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\std.dir\cmake_clean.cmake
.PHONY : CMakeFiles/std.dir/clean

CMakeFiles/std.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\CLionProjects\list C:\Users\User\CLionProjects\list C:\Users\User\CLionProjects\list\cmake-build-debug C:\Users\User\CLionProjects\list\cmake-build-debug C:\Users\User\CLionProjects\list\cmake-build-debug\CMakeFiles\std.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/std.dir/depend
