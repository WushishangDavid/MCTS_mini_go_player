# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wushishang/Desktop/VM/shared/go

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wushishang/Desktop/VM/shared/go/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Go_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Go_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Go_test.dir/flags.make

CMakeFiles/Go_test.dir/main.cpp.o: CMakeFiles/Go_test.dir/flags.make
CMakeFiles/Go_test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Go_test.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Go_test.dir/main.cpp.o -c /Users/wushishang/Desktop/VM/shared/go/main.cpp

CMakeFiles/Go_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_test.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wushishang/Desktop/VM/shared/go/main.cpp > CMakeFiles/Go_test.dir/main.cpp.i

CMakeFiles/Go_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_test.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wushishang/Desktop/VM/shared/go/main.cpp -o CMakeFiles/Go_test.dir/main.cpp.s

CMakeFiles/Go_test.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Go_test.dir/main.cpp.o.requires

CMakeFiles/Go_test.dir/main.cpp.o.provides: CMakeFiles/Go_test.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Go_test.dir/build.make CMakeFiles/Go_test.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Go_test.dir/main.cpp.o.provides

CMakeFiles/Go_test.dir/main.cpp.o.provides.build: CMakeFiles/Go_test.dir/main.cpp.o


CMakeFiles/Go_test.dir/Board.cpp.o: CMakeFiles/Go_test.dir/flags.make
CMakeFiles/Go_test.dir/Board.cpp.o: ../Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Go_test.dir/Board.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Go_test.dir/Board.cpp.o -c /Users/wushishang/Desktop/VM/shared/go/Board.cpp

CMakeFiles/Go_test.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_test.dir/Board.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wushishang/Desktop/VM/shared/go/Board.cpp > CMakeFiles/Go_test.dir/Board.cpp.i

CMakeFiles/Go_test.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_test.dir/Board.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wushishang/Desktop/VM/shared/go/Board.cpp -o CMakeFiles/Go_test.dir/Board.cpp.s

CMakeFiles/Go_test.dir/Board.cpp.o.requires:

.PHONY : CMakeFiles/Go_test.dir/Board.cpp.o.requires

CMakeFiles/Go_test.dir/Board.cpp.o.provides: CMakeFiles/Go_test.dir/Board.cpp.o.requires
	$(MAKE) -f CMakeFiles/Go_test.dir/build.make CMakeFiles/Go_test.dir/Board.cpp.o.provides.build
.PHONY : CMakeFiles/Go_test.dir/Board.cpp.o.provides

CMakeFiles/Go_test.dir/Board.cpp.o.provides.build: CMakeFiles/Go_test.dir/Board.cpp.o


CMakeFiles/Go_test.dir/Player.cpp.o: CMakeFiles/Go_test.dir/flags.make
CMakeFiles/Go_test.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Go_test.dir/Player.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Go_test.dir/Player.cpp.o -c /Users/wushishang/Desktop/VM/shared/go/Player.cpp

CMakeFiles/Go_test.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_test.dir/Player.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wushishang/Desktop/VM/shared/go/Player.cpp > CMakeFiles/Go_test.dir/Player.cpp.i

CMakeFiles/Go_test.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_test.dir/Player.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wushishang/Desktop/VM/shared/go/Player.cpp -o CMakeFiles/Go_test.dir/Player.cpp.s

CMakeFiles/Go_test.dir/Player.cpp.o.requires:

.PHONY : CMakeFiles/Go_test.dir/Player.cpp.o.requires

CMakeFiles/Go_test.dir/Player.cpp.o.provides: CMakeFiles/Go_test.dir/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/Go_test.dir/build.make CMakeFiles/Go_test.dir/Player.cpp.o.provides.build
.PHONY : CMakeFiles/Go_test.dir/Player.cpp.o.provides

CMakeFiles/Go_test.dir/Player.cpp.o.provides.build: CMakeFiles/Go_test.dir/Player.cpp.o


CMakeFiles/Go_test.dir/HumanPlayer.cpp.o: CMakeFiles/Go_test.dir/flags.make
CMakeFiles/Go_test.dir/HumanPlayer.cpp.o: ../HumanPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Go_test.dir/HumanPlayer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Go_test.dir/HumanPlayer.cpp.o -c /Users/wushishang/Desktop/VM/shared/go/HumanPlayer.cpp

CMakeFiles/Go_test.dir/HumanPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_test.dir/HumanPlayer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wushishang/Desktop/VM/shared/go/HumanPlayer.cpp > CMakeFiles/Go_test.dir/HumanPlayer.cpp.i

CMakeFiles/Go_test.dir/HumanPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_test.dir/HumanPlayer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wushishang/Desktop/VM/shared/go/HumanPlayer.cpp -o CMakeFiles/Go_test.dir/HumanPlayer.cpp.s

CMakeFiles/Go_test.dir/HumanPlayer.cpp.o.requires:

.PHONY : CMakeFiles/Go_test.dir/HumanPlayer.cpp.o.requires

CMakeFiles/Go_test.dir/HumanPlayer.cpp.o.provides: CMakeFiles/Go_test.dir/HumanPlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Go_test.dir/build.make CMakeFiles/Go_test.dir/HumanPlayer.cpp.o.provides.build
.PHONY : CMakeFiles/Go_test.dir/HumanPlayer.cpp.o.provides

CMakeFiles/Go_test.dir/HumanPlayer.cpp.o.provides.build: CMakeFiles/Go_test.dir/HumanPlayer.cpp.o


CMakeFiles/Go_test.dir/AIPlayer.cpp.o: CMakeFiles/Go_test.dir/flags.make
CMakeFiles/Go_test.dir/AIPlayer.cpp.o: ../AIPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Go_test.dir/AIPlayer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Go_test.dir/AIPlayer.cpp.o -c /Users/wushishang/Desktop/VM/shared/go/AIPlayer.cpp

CMakeFiles/Go_test.dir/AIPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_test.dir/AIPlayer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wushishang/Desktop/VM/shared/go/AIPlayer.cpp > CMakeFiles/Go_test.dir/AIPlayer.cpp.i

CMakeFiles/Go_test.dir/AIPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_test.dir/AIPlayer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wushishang/Desktop/VM/shared/go/AIPlayer.cpp -o CMakeFiles/Go_test.dir/AIPlayer.cpp.s

CMakeFiles/Go_test.dir/AIPlayer.cpp.o.requires:

.PHONY : CMakeFiles/Go_test.dir/AIPlayer.cpp.o.requires

CMakeFiles/Go_test.dir/AIPlayer.cpp.o.provides: CMakeFiles/Go_test.dir/AIPlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Go_test.dir/build.make CMakeFiles/Go_test.dir/AIPlayer.cpp.o.provides.build
.PHONY : CMakeFiles/Go_test.dir/AIPlayer.cpp.o.provides

CMakeFiles/Go_test.dir/AIPlayer.cpp.o.provides.build: CMakeFiles/Go_test.dir/AIPlayer.cpp.o


CMakeFiles/Go_test.dir/Game.cpp.o: CMakeFiles/Go_test.dir/flags.make
CMakeFiles/Go_test.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Go_test.dir/Game.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Go_test.dir/Game.cpp.o -c /Users/wushishang/Desktop/VM/shared/go/Game.cpp

CMakeFiles/Go_test.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_test.dir/Game.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wushishang/Desktop/VM/shared/go/Game.cpp > CMakeFiles/Go_test.dir/Game.cpp.i

CMakeFiles/Go_test.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_test.dir/Game.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wushishang/Desktop/VM/shared/go/Game.cpp -o CMakeFiles/Go_test.dir/Game.cpp.s

CMakeFiles/Go_test.dir/Game.cpp.o.requires:

.PHONY : CMakeFiles/Go_test.dir/Game.cpp.o.requires

CMakeFiles/Go_test.dir/Game.cpp.o.provides: CMakeFiles/Go_test.dir/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/Go_test.dir/build.make CMakeFiles/Go_test.dir/Game.cpp.o.provides.build
.PHONY : CMakeFiles/Go_test.dir/Game.cpp.o.provides

CMakeFiles/Go_test.dir/Game.cpp.o.provides.build: CMakeFiles/Go_test.dir/Game.cpp.o


CMakeFiles/Go_test.dir/Node.cpp.o: CMakeFiles/Go_test.dir/flags.make
CMakeFiles/Go_test.dir/Node.cpp.o: ../Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Go_test.dir/Node.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Go_test.dir/Node.cpp.o -c /Users/wushishang/Desktop/VM/shared/go/Node.cpp

CMakeFiles/Go_test.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_test.dir/Node.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wushishang/Desktop/VM/shared/go/Node.cpp > CMakeFiles/Go_test.dir/Node.cpp.i

CMakeFiles/Go_test.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_test.dir/Node.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wushishang/Desktop/VM/shared/go/Node.cpp -o CMakeFiles/Go_test.dir/Node.cpp.s

CMakeFiles/Go_test.dir/Node.cpp.o.requires:

.PHONY : CMakeFiles/Go_test.dir/Node.cpp.o.requires

CMakeFiles/Go_test.dir/Node.cpp.o.provides: CMakeFiles/Go_test.dir/Node.cpp.o.requires
	$(MAKE) -f CMakeFiles/Go_test.dir/build.make CMakeFiles/Go_test.dir/Node.cpp.o.provides.build
.PHONY : CMakeFiles/Go_test.dir/Node.cpp.o.provides

CMakeFiles/Go_test.dir/Node.cpp.o.provides.build: CMakeFiles/Go_test.dir/Node.cpp.o


CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o: CMakeFiles/Go_test.dir/flags.make
CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o: ../LP_AIPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o -c /Users/wushishang/Desktop/VM/shared/go/LP_AIPlayer.cpp

CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wushishang/Desktop/VM/shared/go/LP_AIPlayer.cpp > CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.i

CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wushishang/Desktop/VM/shared/go/LP_AIPlayer.cpp -o CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.s

CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o.requires:

.PHONY : CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o.requires

CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o.provides: CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Go_test.dir/build.make CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o.provides.build
.PHONY : CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o.provides

CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o.provides.build: CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o


# Object files for target Go_test
Go_test_OBJECTS = \
"CMakeFiles/Go_test.dir/main.cpp.o" \
"CMakeFiles/Go_test.dir/Board.cpp.o" \
"CMakeFiles/Go_test.dir/Player.cpp.o" \
"CMakeFiles/Go_test.dir/HumanPlayer.cpp.o" \
"CMakeFiles/Go_test.dir/AIPlayer.cpp.o" \
"CMakeFiles/Go_test.dir/Game.cpp.o" \
"CMakeFiles/Go_test.dir/Node.cpp.o" \
"CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o"

# External object files for target Go_test
Go_test_EXTERNAL_OBJECTS =

Go_test: CMakeFiles/Go_test.dir/main.cpp.o
Go_test: CMakeFiles/Go_test.dir/Board.cpp.o
Go_test: CMakeFiles/Go_test.dir/Player.cpp.o
Go_test: CMakeFiles/Go_test.dir/HumanPlayer.cpp.o
Go_test: CMakeFiles/Go_test.dir/AIPlayer.cpp.o
Go_test: CMakeFiles/Go_test.dir/Game.cpp.o
Go_test: CMakeFiles/Go_test.dir/Node.cpp.o
Go_test: CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o
Go_test: CMakeFiles/Go_test.dir/build.make
Go_test: CMakeFiles/Go_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Go_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Go_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Go_test.dir/build: Go_test

.PHONY : CMakeFiles/Go_test.dir/build

CMakeFiles/Go_test.dir/requires: CMakeFiles/Go_test.dir/main.cpp.o.requires
CMakeFiles/Go_test.dir/requires: CMakeFiles/Go_test.dir/Board.cpp.o.requires
CMakeFiles/Go_test.dir/requires: CMakeFiles/Go_test.dir/Player.cpp.o.requires
CMakeFiles/Go_test.dir/requires: CMakeFiles/Go_test.dir/HumanPlayer.cpp.o.requires
CMakeFiles/Go_test.dir/requires: CMakeFiles/Go_test.dir/AIPlayer.cpp.o.requires
CMakeFiles/Go_test.dir/requires: CMakeFiles/Go_test.dir/Game.cpp.o.requires
CMakeFiles/Go_test.dir/requires: CMakeFiles/Go_test.dir/Node.cpp.o.requires
CMakeFiles/Go_test.dir/requires: CMakeFiles/Go_test.dir/LP_AIPlayer.cpp.o.requires

.PHONY : CMakeFiles/Go_test.dir/requires

CMakeFiles/Go_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Go_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Go_test.dir/clean

CMakeFiles/Go_test.dir/depend:
	cd /Users/wushishang/Desktop/VM/shared/go/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wushishang/Desktop/VM/shared/go /Users/wushishang/Desktop/VM/shared/go /Users/wushishang/Desktop/VM/shared/go/cmake-build-debug /Users/wushishang/Desktop/VM/shared/go/cmake-build-debug /Users/wushishang/Desktop/VM/shared/go/cmake-build-debug/CMakeFiles/Go_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Go_test.dir/depend

