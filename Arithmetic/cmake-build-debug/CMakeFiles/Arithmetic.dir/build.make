# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = "C:\OTHER\Tucodec\software\clion\install\CLion 2016.3.5\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\OTHER\Tucodec\software\clion\install\CLion 2016.3.5\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\OTHER\Tucodec\Arithmetic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\OTHER\Tucodec\Arithmetic\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Arithmetic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Arithmetic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Arithmetic.dir/flags.make

CMakeFiles/Arithmetic.dir/main.c.obj: CMakeFiles/Arithmetic.dir/flags.make
CMakeFiles/Arithmetic.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\OTHER\Tucodec\Arithmetic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Arithmetic.dir/main.c.obj"
	C:\OTHER\Tucodec\software\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Arithmetic.dir\main.c.obj   -c C:\OTHER\Tucodec\Arithmetic\main.c

CMakeFiles/Arithmetic.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Arithmetic.dir/main.c.i"
	C:\OTHER\Tucodec\software\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\OTHER\Tucodec\Arithmetic\main.c > CMakeFiles\Arithmetic.dir\main.c.i

CMakeFiles/Arithmetic.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Arithmetic.dir/main.c.s"
	C:\OTHER\Tucodec\software\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\OTHER\Tucodec\Arithmetic\main.c -o CMakeFiles\Arithmetic.dir\main.c.s

CMakeFiles/Arithmetic.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Arithmetic.dir/main.c.obj.requires

CMakeFiles/Arithmetic.dir/main.c.obj.provides: CMakeFiles/Arithmetic.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Arithmetic.dir\build.make CMakeFiles/Arithmetic.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Arithmetic.dir/main.c.obj.provides

CMakeFiles/Arithmetic.dir/main.c.obj.provides.build: CMakeFiles/Arithmetic.dir/main.c.obj


# Object files for target Arithmetic
Arithmetic_OBJECTS = \
"CMakeFiles/Arithmetic.dir/main.c.obj"

# External object files for target Arithmetic
Arithmetic_EXTERNAL_OBJECTS =

Arithmetic.exe: CMakeFiles/Arithmetic.dir/main.c.obj
Arithmetic.exe: CMakeFiles/Arithmetic.dir/build.make
Arithmetic.exe: CMakeFiles/Arithmetic.dir/linklibs.rsp
Arithmetic.exe: CMakeFiles/Arithmetic.dir/objects1.rsp
Arithmetic.exe: CMakeFiles/Arithmetic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\OTHER\Tucodec\Arithmetic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Arithmetic.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Arithmetic.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Arithmetic.dir/build: Arithmetic.exe

.PHONY : CMakeFiles/Arithmetic.dir/build

CMakeFiles/Arithmetic.dir/requires: CMakeFiles/Arithmetic.dir/main.c.obj.requires

.PHONY : CMakeFiles/Arithmetic.dir/requires

CMakeFiles/Arithmetic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Arithmetic.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Arithmetic.dir/clean

CMakeFiles/Arithmetic.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\OTHER\Tucodec\Arithmetic C:\OTHER\Tucodec\Arithmetic C:\OTHER\Tucodec\Arithmetic\cmake-build-debug C:\OTHER\Tucodec\Arithmetic\cmake-build-debug C:\OTHER\Tucodec\Arithmetic\cmake-build-debug\CMakeFiles\Arithmetic.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Arithmetic.dir/depend
