# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/joshuatan/Documents/Programming/C++/Pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/joshuatan/Documents/Programming/C++/Pong/build

# Include any dependencies generated for this target.
include CMakeFiles/Pong++.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Pong++.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Pong++.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pong++.dir/flags.make

CMakeFiles/Pong++.dir/src/Ball.cpp.o: CMakeFiles/Pong++.dir/flags.make
CMakeFiles/Pong++.dir/src/Ball.cpp.o: /Users/joshuatan/Documents/Programming/C++/Pong/src/Ball.cpp
CMakeFiles/Pong++.dir/src/Ball.cpp.o: CMakeFiles/Pong++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pong++.dir/src/Ball.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pong++.dir/src/Ball.cpp.o -MF CMakeFiles/Pong++.dir/src/Ball.cpp.o.d -o CMakeFiles/Pong++.dir/src/Ball.cpp.o -c /Users/joshuatan/Documents/Programming/C++/Pong/src/Ball.cpp

CMakeFiles/Pong++.dir/src/Ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pong++.dir/src/Ball.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshuatan/Documents/Programming/C++/Pong/src/Ball.cpp > CMakeFiles/Pong++.dir/src/Ball.cpp.i

CMakeFiles/Pong++.dir/src/Ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pong++.dir/src/Ball.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshuatan/Documents/Programming/C++/Pong/src/Ball.cpp -o CMakeFiles/Pong++.dir/src/Ball.cpp.s

CMakeFiles/Pong++.dir/src/Draw.cpp.o: CMakeFiles/Pong++.dir/flags.make
CMakeFiles/Pong++.dir/src/Draw.cpp.o: /Users/joshuatan/Documents/Programming/C++/Pong/src/Draw.cpp
CMakeFiles/Pong++.dir/src/Draw.cpp.o: CMakeFiles/Pong++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Pong++.dir/src/Draw.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pong++.dir/src/Draw.cpp.o -MF CMakeFiles/Pong++.dir/src/Draw.cpp.o.d -o CMakeFiles/Pong++.dir/src/Draw.cpp.o -c /Users/joshuatan/Documents/Programming/C++/Pong/src/Draw.cpp

CMakeFiles/Pong++.dir/src/Draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pong++.dir/src/Draw.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshuatan/Documents/Programming/C++/Pong/src/Draw.cpp > CMakeFiles/Pong++.dir/src/Draw.cpp.i

CMakeFiles/Pong++.dir/src/Draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pong++.dir/src/Draw.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshuatan/Documents/Programming/C++/Pong/src/Draw.cpp -o CMakeFiles/Pong++.dir/src/Draw.cpp.s

CMakeFiles/Pong++.dir/src/Game.cpp.o: CMakeFiles/Pong++.dir/flags.make
CMakeFiles/Pong++.dir/src/Game.cpp.o: /Users/joshuatan/Documents/Programming/C++/Pong/src/Game.cpp
CMakeFiles/Pong++.dir/src/Game.cpp.o: CMakeFiles/Pong++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Pong++.dir/src/Game.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pong++.dir/src/Game.cpp.o -MF CMakeFiles/Pong++.dir/src/Game.cpp.o.d -o CMakeFiles/Pong++.dir/src/Game.cpp.o -c /Users/joshuatan/Documents/Programming/C++/Pong/src/Game.cpp

CMakeFiles/Pong++.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pong++.dir/src/Game.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshuatan/Documents/Programming/C++/Pong/src/Game.cpp > CMakeFiles/Pong++.dir/src/Game.cpp.i

CMakeFiles/Pong++.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pong++.dir/src/Game.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshuatan/Documents/Programming/C++/Pong/src/Game.cpp -o CMakeFiles/Pong++.dir/src/Game.cpp.s

CMakeFiles/Pong++.dir/src/InputHandler.cpp.o: CMakeFiles/Pong++.dir/flags.make
CMakeFiles/Pong++.dir/src/InputHandler.cpp.o: /Users/joshuatan/Documents/Programming/C++/Pong/src/InputHandler.cpp
CMakeFiles/Pong++.dir/src/InputHandler.cpp.o: CMakeFiles/Pong++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Pong++.dir/src/InputHandler.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pong++.dir/src/InputHandler.cpp.o -MF CMakeFiles/Pong++.dir/src/InputHandler.cpp.o.d -o CMakeFiles/Pong++.dir/src/InputHandler.cpp.o -c /Users/joshuatan/Documents/Programming/C++/Pong/src/InputHandler.cpp

CMakeFiles/Pong++.dir/src/InputHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pong++.dir/src/InputHandler.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshuatan/Documents/Programming/C++/Pong/src/InputHandler.cpp > CMakeFiles/Pong++.dir/src/InputHandler.cpp.i

CMakeFiles/Pong++.dir/src/InputHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pong++.dir/src/InputHandler.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshuatan/Documents/Programming/C++/Pong/src/InputHandler.cpp -o CMakeFiles/Pong++.dir/src/InputHandler.cpp.s

CMakeFiles/Pong++.dir/src/Interface.cpp.o: CMakeFiles/Pong++.dir/flags.make
CMakeFiles/Pong++.dir/src/Interface.cpp.o: /Users/joshuatan/Documents/Programming/C++/Pong/src/Interface.cpp
CMakeFiles/Pong++.dir/src/Interface.cpp.o: CMakeFiles/Pong++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Pong++.dir/src/Interface.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pong++.dir/src/Interface.cpp.o -MF CMakeFiles/Pong++.dir/src/Interface.cpp.o.d -o CMakeFiles/Pong++.dir/src/Interface.cpp.o -c /Users/joshuatan/Documents/Programming/C++/Pong/src/Interface.cpp

CMakeFiles/Pong++.dir/src/Interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pong++.dir/src/Interface.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshuatan/Documents/Programming/C++/Pong/src/Interface.cpp > CMakeFiles/Pong++.dir/src/Interface.cpp.i

CMakeFiles/Pong++.dir/src/Interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pong++.dir/src/Interface.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshuatan/Documents/Programming/C++/Pong/src/Interface.cpp -o CMakeFiles/Pong++.dir/src/Interface.cpp.s

CMakeFiles/Pong++.dir/src/Paddle.cpp.o: CMakeFiles/Pong++.dir/flags.make
CMakeFiles/Pong++.dir/src/Paddle.cpp.o: /Users/joshuatan/Documents/Programming/C++/Pong/src/Paddle.cpp
CMakeFiles/Pong++.dir/src/Paddle.cpp.o: CMakeFiles/Pong++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Pong++.dir/src/Paddle.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pong++.dir/src/Paddle.cpp.o -MF CMakeFiles/Pong++.dir/src/Paddle.cpp.o.d -o CMakeFiles/Pong++.dir/src/Paddle.cpp.o -c /Users/joshuatan/Documents/Programming/C++/Pong/src/Paddle.cpp

CMakeFiles/Pong++.dir/src/Paddle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pong++.dir/src/Paddle.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshuatan/Documents/Programming/C++/Pong/src/Paddle.cpp > CMakeFiles/Pong++.dir/src/Paddle.cpp.i

CMakeFiles/Pong++.dir/src/Paddle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pong++.dir/src/Paddle.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshuatan/Documents/Programming/C++/Pong/src/Paddle.cpp -o CMakeFiles/Pong++.dir/src/Paddle.cpp.s

CMakeFiles/Pong++.dir/src/TextureManager.cpp.o: CMakeFiles/Pong++.dir/flags.make
CMakeFiles/Pong++.dir/src/TextureManager.cpp.o: /Users/joshuatan/Documents/Programming/C++/Pong/src/TextureManager.cpp
CMakeFiles/Pong++.dir/src/TextureManager.cpp.o: CMakeFiles/Pong++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Pong++.dir/src/TextureManager.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pong++.dir/src/TextureManager.cpp.o -MF CMakeFiles/Pong++.dir/src/TextureManager.cpp.o.d -o CMakeFiles/Pong++.dir/src/TextureManager.cpp.o -c /Users/joshuatan/Documents/Programming/C++/Pong/src/TextureManager.cpp

CMakeFiles/Pong++.dir/src/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pong++.dir/src/TextureManager.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshuatan/Documents/Programming/C++/Pong/src/TextureManager.cpp > CMakeFiles/Pong++.dir/src/TextureManager.cpp.i

CMakeFiles/Pong++.dir/src/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pong++.dir/src/TextureManager.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshuatan/Documents/Programming/C++/Pong/src/TextureManager.cpp -o CMakeFiles/Pong++.dir/src/TextureManager.cpp.s

CMakeFiles/Pong++.dir/src/main.cpp.o: CMakeFiles/Pong++.dir/flags.make
CMakeFiles/Pong++.dir/src/main.cpp.o: /Users/joshuatan/Documents/Programming/C++/Pong/src/main.cpp
CMakeFiles/Pong++.dir/src/main.cpp.o: CMakeFiles/Pong++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Pong++.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pong++.dir/src/main.cpp.o -MF CMakeFiles/Pong++.dir/src/main.cpp.o.d -o CMakeFiles/Pong++.dir/src/main.cpp.o -c /Users/joshuatan/Documents/Programming/C++/Pong/src/main.cpp

CMakeFiles/Pong++.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pong++.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshuatan/Documents/Programming/C++/Pong/src/main.cpp > CMakeFiles/Pong++.dir/src/main.cpp.i

CMakeFiles/Pong++.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pong++.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshuatan/Documents/Programming/C++/Pong/src/main.cpp -o CMakeFiles/Pong++.dir/src/main.cpp.s

# Object files for target Pong++
Pong_______OBJECTS = \
"CMakeFiles/Pong++.dir/src/Ball.cpp.o" \
"CMakeFiles/Pong++.dir/src/Draw.cpp.o" \
"CMakeFiles/Pong++.dir/src/Game.cpp.o" \
"CMakeFiles/Pong++.dir/src/InputHandler.cpp.o" \
"CMakeFiles/Pong++.dir/src/Interface.cpp.o" \
"CMakeFiles/Pong++.dir/src/Paddle.cpp.o" \
"CMakeFiles/Pong++.dir/src/TextureManager.cpp.o" \
"CMakeFiles/Pong++.dir/src/main.cpp.o"

# External object files for target Pong++
Pong_______EXTERNAL_OBJECTS =

Pong++: CMakeFiles/Pong++.dir/src/Ball.cpp.o
Pong++: CMakeFiles/Pong++.dir/src/Draw.cpp.o
Pong++: CMakeFiles/Pong++.dir/src/Game.cpp.o
Pong++: CMakeFiles/Pong++.dir/src/InputHandler.cpp.o
Pong++: CMakeFiles/Pong++.dir/src/Interface.cpp.o
Pong++: CMakeFiles/Pong++.dir/src/Paddle.cpp.o
Pong++: CMakeFiles/Pong++.dir/src/TextureManager.cpp.o
Pong++: CMakeFiles/Pong++.dir/src/main.cpp.o
Pong++: CMakeFiles/Pong++.dir/build.make
Pong++: CMakeFiles/Pong++.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Pong++"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pong++.dir/link.txt --verbose=$(VERBOSE)
	/opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E copy_directory /Users/joshuatan/Documents/Programming/C++/Pong/assets /Users/joshuatan/Documents/Programming/C++/Pong/build/assets

# Rule to build all files generated by this target.
CMakeFiles/Pong++.dir/build: Pong++
.PHONY : CMakeFiles/Pong++.dir/build

CMakeFiles/Pong++.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pong++.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pong++.dir/clean

CMakeFiles/Pong++.dir/depend:
	cd /Users/joshuatan/Documents/Programming/C++/Pong/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/joshuatan/Documents/Programming/C++/Pong /Users/joshuatan/Documents/Programming/C++/Pong /Users/joshuatan/Documents/Programming/C++/Pong/build /Users/joshuatan/Documents/Programming/C++/Pong/build /Users/joshuatan/Documents/Programming/C++/Pong/build/CMakeFiles/Pong++.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Pong++.dir/depend

