# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\fleek\CProjects\lib-io

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\fleek\CProjects\lib-io\build

# Include any dependencies generated for this target.
include CMakeFiles/libio.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libio.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libio.dir/flags.make

CMakeFiles/libio.dir/src/main.c.obj: CMakeFiles/libio.dir/flags.make
CMakeFiles/libio.dir/src/main.c.obj: CMakeFiles/libio.dir/includes_C.rsp
CMakeFiles/libio.dir/src/main.c.obj: C:/Users/fleek/CProjects/lib-io/src/main.c
CMakeFiles/libio.dir/src/main.c.obj: CMakeFiles/libio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\fleek\CProjects\lib-io\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/libio.dir/src/main.c.obj"
	C:\msys64\ucrt64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/libio.dir/src/main.c.obj -MF CMakeFiles\libio.dir\src\main.c.obj.d -o CMakeFiles\libio.dir\src\main.c.obj -c C:\Users\fleek\CProjects\lib-io\src\main.c

CMakeFiles/libio.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/libio.dir/src/main.c.i"
	C:\msys64\ucrt64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\fleek\CProjects\lib-io\src\main.c > CMakeFiles\libio.dir\src\main.c.i

CMakeFiles/libio.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/libio.dir/src/main.c.s"
	C:\msys64\ucrt64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\fleek\CProjects\lib-io\src\main.c -o CMakeFiles\libio.dir\src\main.c.s

CMakeFiles/libio.dir/src/libio.c.obj: CMakeFiles/libio.dir/flags.make
CMakeFiles/libio.dir/src/libio.c.obj: CMakeFiles/libio.dir/includes_C.rsp
CMakeFiles/libio.dir/src/libio.c.obj: C:/Users/fleek/CProjects/lib-io/src/libio.c
CMakeFiles/libio.dir/src/libio.c.obj: CMakeFiles/libio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\fleek\CProjects\lib-io\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/libio.dir/src/libio.c.obj"
	C:\msys64\ucrt64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/libio.dir/src/libio.c.obj -MF CMakeFiles\libio.dir\src\libio.c.obj.d -o CMakeFiles\libio.dir\src\libio.c.obj -c C:\Users\fleek\CProjects\lib-io\src\libio.c

CMakeFiles/libio.dir/src/libio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/libio.dir/src/libio.c.i"
	C:\msys64\ucrt64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\fleek\CProjects\lib-io\src\libio.c > CMakeFiles\libio.dir\src\libio.c.i

CMakeFiles/libio.dir/src/libio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/libio.dir/src/libio.c.s"
	C:\msys64\ucrt64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\fleek\CProjects\lib-io\src\libio.c -o CMakeFiles\libio.dir\src\libio.c.s

# Object files for target libio
libio_OBJECTS = \
"CMakeFiles/libio.dir/src/main.c.obj" \
"CMakeFiles/libio.dir/src/libio.c.obj"

# External object files for target libio
libio_EXTERNAL_OBJECTS =

libio.exe: CMakeFiles/libio.dir/src/main.c.obj
libio.exe: CMakeFiles/libio.dir/src/libio.c.obj
libio.exe: CMakeFiles/libio.dir/build.make
libio.exe: CMakeFiles/libio.dir/linkLibs.rsp
libio.exe: CMakeFiles/libio.dir/objects1.rsp
libio.exe: CMakeFiles/libio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\fleek\CProjects\lib-io\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable libio.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\libio.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libio.dir/build: libio.exe
.PHONY : CMakeFiles/libio.dir/build

CMakeFiles/libio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\libio.dir\cmake_clean.cmake
.PHONY : CMakeFiles/libio.dir/clean

CMakeFiles/libio.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\fleek\CProjects\lib-io C:\Users\fleek\CProjects\lib-io C:\Users\fleek\CProjects\lib-io\build C:\Users\fleek\CProjects\lib-io\build C:\Users\fleek\CProjects\lib-io\build\CMakeFiles\libio.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/libio.dir/depend
