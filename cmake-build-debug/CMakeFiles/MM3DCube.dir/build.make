# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\floma\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.8109.174\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\floma\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.8109.174\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\floma\CLionProjects\MM3DCube

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\floma\CLionProjects\MM3DCube\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\MM3DCube.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\MM3DCube.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\MM3DCube.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\MM3DCube.dir\flags.make

CMakeFiles\MM3DCube.dir\main.cpp.obj: CMakeFiles\MM3DCube.dir\flags.make
CMakeFiles\MM3DCube.dir\main.cpp.obj: C:\Users\floma\CLionProjects\MM3DCube\main.cpp
CMakeFiles\MM3DCube.dir\main.cpp.obj: CMakeFiles\MM3DCube.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\floma\CLionProjects\MM3DCube\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MM3DCube.dir/main.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\MM3DCube.dir\main.cpp.obj.d --working-dir=C:\Users\floma\CLionProjects\MM3DCube\cmake-build-debug --filter-prefix="����������: ��������� �����:  " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1432~1.313\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\MM3DCube.dir\main.cpp.obj /FdCMakeFiles\MM3DCube.dir\ /FS -c C:\Users\floma\CLionProjects\MM3DCube\main.cpp
<<

CMakeFiles\MM3DCube.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MM3DCube.dir/main.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1432~1.313\bin\Hostx64\x64\cl.exe > CMakeFiles\MM3DCube.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\floma\CLionProjects\MM3DCube\main.cpp
<<

CMakeFiles\MM3DCube.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MM3DCube.dir/main.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1432~1.313\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MM3DCube.dir\main.cpp.s /c C:\Users\floma\CLionProjects\MM3DCube\main.cpp
<<

# Object files for target MM3DCube
MM3DCube_OBJECTS = \
"CMakeFiles\MM3DCube.dir\main.cpp.obj"

# External object files for target MM3DCube
MM3DCube_EXTERNAL_OBJECTS =

MM3DCube.exe: CMakeFiles\MM3DCube.dir\main.cpp.obj
MM3DCube.exe: CMakeFiles\MM3DCube.dir\build.make
MM3DCube.exe: D:\tools\opencv\build\x64\vc16\lib\opencv_world470d.lib
MM3DCube.exe: D:\tools\opencv\build\x64\vc16\lib\opencv_world470d.lib
MM3DCube.exe: D:\tools\opencv\build\x64\vc16\lib\opencv_world470d.lib
MM3DCube.exe: D:\tools\opencv\build\x64\vc16\lib\opencv_world470d.lib
MM3DCube.exe: CMakeFiles\MM3DCube.dir\objects1
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\floma\CLionProjects\MM3DCube\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MM3DCube.exe"
	C:\Users\floma\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.8109.174\bin\cmake\win\x64\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\MM3DCube.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\mt.exe --manifests -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1432~1.313\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\MM3DCube.dir\objects1 @<<
 /out:MM3DCube.exe /implib:MM3DCube.lib /pdb:C:\Users\floma\CLionProjects\MM3DCube\cmake-build-debug\MM3DCube.pdb /version:0.0 /machine:x64 /debug /INCREMENTAL /subsystem:console  D:\tools\opencv\build\x64\vc16\lib\opencv_world470d.lib D:\tools\opencv\build\x64\vc16\lib\opencv_world470d.lib D:\tools\opencv\build\x64\vc16\lib\opencv_world470d.lib D:\tools\opencv\build\x64\vc16\lib\opencv_world470d.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\MM3DCube.dir\build: MM3DCube.exe
.PHONY : CMakeFiles\MM3DCube.dir\build

CMakeFiles\MM3DCube.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MM3DCube.dir\cmake_clean.cmake
.PHONY : CMakeFiles\MM3DCube.dir\clean

CMakeFiles\MM3DCube.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\floma\CLionProjects\MM3DCube C:\Users\floma\CLionProjects\MM3DCube C:\Users\floma\CLionProjects\MM3DCube\cmake-build-debug C:\Users\floma\CLionProjects\MM3DCube\cmake-build-debug C:\Users\floma\CLionProjects\MM3DCube\cmake-build-debug\CMakeFiles\MM3DCube.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\MM3DCube.dir\depend

