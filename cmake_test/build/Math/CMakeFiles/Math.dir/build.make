# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = C:\Users\admin\Documents\graphics\cmake_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\admin\Documents\graphics\cmake_test\build

# Include any dependencies generated for this target.
include Math/CMakeFiles/Math.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Math/CMakeFiles/Math.dir/compiler_depend.make

# Include the progress variables for this target.
include Math/CMakeFiles/Math.dir/progress.make

# Include the compile flags for this target's objects.
include Math/CMakeFiles/Math.dir/flags.make

Math/CMakeFiles/Math.dir/src/sub.cpp.obj: Math/CMakeFiles/Math.dir/flags.make
Math/CMakeFiles/Math.dir/src/sub.cpp.obj: Math/CMakeFiles/Math.dir/includes_CXX.rsp
Math/CMakeFiles/Math.dir/src/sub.cpp.obj: ../Math/src/sub.cpp
Math/CMakeFiles/Math.dir/src/sub.cpp.obj: Math/CMakeFiles/Math.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\admin\Documents\graphics\cmake_test\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Math/CMakeFiles/Math.dir/src/sub.cpp.obj"
	cd /d C:\Users\admin\Documents\graphics\cmake_test\build\Math && C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Math/CMakeFiles/Math.dir/src/sub.cpp.obj -MF CMakeFiles\Math.dir\src\sub.cpp.obj.d -o CMakeFiles\Math.dir\src\sub.cpp.obj -c C:\Users\admin\Documents\graphics\cmake_test\Math\src\sub.cpp

Math/CMakeFiles/Math.dir/src/sub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Math.dir/src/sub.cpp.i"
	cd /d C:\Users\admin\Documents\graphics\cmake_test\build\Math && C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\admin\Documents\graphics\cmake_test\Math\src\sub.cpp > CMakeFiles\Math.dir\src\sub.cpp.i

Math/CMakeFiles/Math.dir/src/sub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Math.dir/src/sub.cpp.s"
	cd /d C:\Users\admin\Documents\graphics\cmake_test\build\Math && C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\admin\Documents\graphics\cmake_test\Math\src\sub.cpp -o CMakeFiles\Math.dir\src\sub.cpp.s

# Object files for target Math
Math_OBJECTS = \
"CMakeFiles/Math.dir/src/sub.cpp.obj"

# External object files for target Math
Math_EXTERNAL_OBJECTS =

Math/libMath.dll: Math/CMakeFiles/Math.dir/src/sub.cpp.obj
Math/libMath.dll: Math/CMakeFiles/Math.dir/build.make
Math/libMath.dll: Math/CMakeFiles/Math.dir/linklibs.rsp
Math/libMath.dll: Math/CMakeFiles/Math.dir/objects1.rsp
Math/libMath.dll: Math/CMakeFiles/Math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\admin\Documents\graphics\cmake_test\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libMath.dll"
	cd /d C:\Users\admin\Documents\graphics\cmake_test\build\Math && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Math.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Math/CMakeFiles/Math.dir/build: Math/libMath.dll
.PHONY : Math/CMakeFiles/Math.dir/build

Math/CMakeFiles/Math.dir/clean:
	cd /d C:\Users\admin\Documents\graphics\cmake_test\build\Math && $(CMAKE_COMMAND) -P CMakeFiles\Math.dir\cmake_clean.cmake
.PHONY : Math/CMakeFiles/Math.dir/clean

Math/CMakeFiles/Math.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\admin\Documents\graphics\cmake_test C:\Users\admin\Documents\graphics\cmake_test\Math C:\Users\admin\Documents\graphics\cmake_test\build C:\Users\admin\Documents\graphics\cmake_test\build\Math C:\Users\admin\Documents\graphics\cmake_test\build\Math\CMakeFiles\Math.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Math/CMakeFiles/Math.dir/depend
