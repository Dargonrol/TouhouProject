# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = X:\user\programming\projects\projects\TouhouProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = X:\user\programming\projects\projects\TouhouProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TouhouProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TouhouProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TouhouProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TouhouProject.dir/flags.make

CMakeFiles/TouhouProject.dir/main.cpp.obj: CMakeFiles/TouhouProject.dir/flags.make
CMakeFiles/TouhouProject.dir/main.cpp.obj: CMakeFiles/TouhouProject.dir/includes_CXX.rsp
CMakeFiles/TouhouProject.dir/main.cpp.obj: X:/user/programming/projects/projects/TouhouProject/main.cpp
CMakeFiles/TouhouProject.dir/main.cpp.obj: CMakeFiles/TouhouProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=X:\user\programming\projects\projects\TouhouProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TouhouProject.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TouhouProject.dir/main.cpp.obj -MF CMakeFiles\TouhouProject.dir\main.cpp.obj.d -o CMakeFiles\TouhouProject.dir\main.cpp.obj -c X:\user\programming\projects\projects\TouhouProject\main.cpp

CMakeFiles/TouhouProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TouhouProject.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\user\programming\projects\projects\TouhouProject\main.cpp > CMakeFiles\TouhouProject.dir\main.cpp.i

CMakeFiles/TouhouProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TouhouProject.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\user\programming\projects\projects\TouhouProject\main.cpp -o CMakeFiles\TouhouProject.dir\main.cpp.s

# Object files for target TouhouProject
TouhouProject_OBJECTS = \
"CMakeFiles/TouhouProject.dir/main.cpp.obj"

# External object files for target TouhouProject
TouhouProject_EXTERNAL_OBJECTS =

TouhouProject.exe: CMakeFiles/TouhouProject.dir/main.cpp.obj
TouhouProject.exe: CMakeFiles/TouhouProject.dir/build.make
TouhouProject.exe: X:/user/programming/projects/projects/TouhouProject/SDL2/x86_64-w64-mingw32/lib/libSDL2main.a
TouhouProject.exe: X:/user/programming/projects/projects/TouhouProject/SDL2/x86_64-w64-mingw32/lib/libSDL2.dll.a
TouhouProject.exe: CMakeFiles/TouhouProject.dir/linkLibs.rsp
TouhouProject.exe: CMakeFiles/TouhouProject.dir/objects1.rsp
TouhouProject.exe: CMakeFiles/TouhouProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=X:\user\programming\projects\projects\TouhouProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TouhouProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TouhouProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TouhouProject.dir/build: TouhouProject.exe
.PHONY : CMakeFiles/TouhouProject.dir/build

CMakeFiles/TouhouProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TouhouProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TouhouProject.dir/clean

CMakeFiles/TouhouProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" X:\user\programming\projects\projects\TouhouProject X:\user\programming\projects\projects\TouhouProject X:\user\programming\projects\projects\TouhouProject\cmake-build-debug X:\user\programming\projects\projects\TouhouProject\cmake-build-debug X:\user\programming\projects\projects\TouhouProject\cmake-build-debug\CMakeFiles\TouhouProject.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TouhouProject.dir/depend
