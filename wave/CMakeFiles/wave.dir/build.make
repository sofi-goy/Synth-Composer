# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sof/source/wave

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sof/source/wave

# Include any dependencies generated for this target.
include src/wave/CMakeFiles/wave.dir/depend.make

# Include the progress variables for this target.
include src/wave/CMakeFiles/wave.dir/progress.make

# Include the compile flags for this target's objects.
include src/wave/CMakeFiles/wave.dir/flags.make

src/wave/CMakeFiles/wave.dir/header/data_header.cc.o: src/wave/CMakeFiles/wave.dir/flags.make
src/wave/CMakeFiles/wave.dir/header/data_header.cc.o: src/wave/header/data_header.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sof/source/wave/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/wave/CMakeFiles/wave.dir/header/data_header.cc.o"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wave.dir/header/data_header.cc.o -c /home/sof/source/wave/src/wave/header/data_header.cc

src/wave/CMakeFiles/wave.dir/header/data_header.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wave.dir/header/data_header.cc.i"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sof/source/wave/src/wave/header/data_header.cc > CMakeFiles/wave.dir/header/data_header.cc.i

src/wave/CMakeFiles/wave.dir/header/data_header.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wave.dir/header/data_header.cc.s"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sof/source/wave/src/wave/header/data_header.cc -o CMakeFiles/wave.dir/header/data_header.cc.s

src/wave/CMakeFiles/wave.dir/header/riff_header.cc.o: src/wave/CMakeFiles/wave.dir/flags.make
src/wave/CMakeFiles/wave.dir/header/riff_header.cc.o: src/wave/header/riff_header.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sof/source/wave/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/wave/CMakeFiles/wave.dir/header/riff_header.cc.o"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wave.dir/header/riff_header.cc.o -c /home/sof/source/wave/src/wave/header/riff_header.cc

src/wave/CMakeFiles/wave.dir/header/riff_header.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wave.dir/header/riff_header.cc.i"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sof/source/wave/src/wave/header/riff_header.cc > CMakeFiles/wave.dir/header/riff_header.cc.i

src/wave/CMakeFiles/wave.dir/header/riff_header.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wave.dir/header/riff_header.cc.s"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sof/source/wave/src/wave/header/riff_header.cc -o CMakeFiles/wave.dir/header/riff_header.cc.s

src/wave/CMakeFiles/wave.dir/header/fmt_header.cc.o: src/wave/CMakeFiles/wave.dir/flags.make
src/wave/CMakeFiles/wave.dir/header/fmt_header.cc.o: src/wave/header/fmt_header.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sof/source/wave/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/wave/CMakeFiles/wave.dir/header/fmt_header.cc.o"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wave.dir/header/fmt_header.cc.o -c /home/sof/source/wave/src/wave/header/fmt_header.cc

src/wave/CMakeFiles/wave.dir/header/fmt_header.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wave.dir/header/fmt_header.cc.i"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sof/source/wave/src/wave/header/fmt_header.cc > CMakeFiles/wave.dir/header/fmt_header.cc.i

src/wave/CMakeFiles/wave.dir/header/fmt_header.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wave.dir/header/fmt_header.cc.s"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sof/source/wave/src/wave/header/fmt_header.cc -o CMakeFiles/wave.dir/header/fmt_header.cc.s

src/wave/CMakeFiles/wave.dir/header/wave_header.cc.o: src/wave/CMakeFiles/wave.dir/flags.make
src/wave/CMakeFiles/wave.dir/header/wave_header.cc.o: src/wave/header/wave_header.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sof/source/wave/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/wave/CMakeFiles/wave.dir/header/wave_header.cc.o"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wave.dir/header/wave_header.cc.o -c /home/sof/source/wave/src/wave/header/wave_header.cc

src/wave/CMakeFiles/wave.dir/header/wave_header.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wave.dir/header/wave_header.cc.i"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sof/source/wave/src/wave/header/wave_header.cc > CMakeFiles/wave.dir/header/wave_header.cc.i

src/wave/CMakeFiles/wave.dir/header/wave_header.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wave.dir/header/wave_header.cc.s"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sof/source/wave/src/wave/header/wave_header.cc -o CMakeFiles/wave.dir/header/wave_header.cc.s

src/wave/CMakeFiles/wave.dir/header.cc.o: src/wave/CMakeFiles/wave.dir/flags.make
src/wave/CMakeFiles/wave.dir/header.cc.o: src/wave/header.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sof/source/wave/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/wave/CMakeFiles/wave.dir/header.cc.o"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wave.dir/header.cc.o -c /home/sof/source/wave/src/wave/header.cc

src/wave/CMakeFiles/wave.dir/header.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wave.dir/header.cc.i"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sof/source/wave/src/wave/header.cc > CMakeFiles/wave.dir/header.cc.i

src/wave/CMakeFiles/wave.dir/header.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wave.dir/header.cc.s"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sof/source/wave/src/wave/header.cc -o CMakeFiles/wave.dir/header.cc.s

src/wave/CMakeFiles/wave.dir/header_list.cc.o: src/wave/CMakeFiles/wave.dir/flags.make
src/wave/CMakeFiles/wave.dir/header_list.cc.o: src/wave/header_list.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sof/source/wave/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/wave/CMakeFiles/wave.dir/header_list.cc.o"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wave.dir/header_list.cc.o -c /home/sof/source/wave/src/wave/header_list.cc

src/wave/CMakeFiles/wave.dir/header_list.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wave.dir/header_list.cc.i"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sof/source/wave/src/wave/header_list.cc > CMakeFiles/wave.dir/header_list.cc.i

src/wave/CMakeFiles/wave.dir/header_list.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wave.dir/header_list.cc.s"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sof/source/wave/src/wave/header_list.cc -o CMakeFiles/wave.dir/header_list.cc.s

src/wave/CMakeFiles/wave.dir/file.cc.o: src/wave/CMakeFiles/wave.dir/flags.make
src/wave/CMakeFiles/wave.dir/file.cc.o: src/wave/file.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sof/source/wave/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/wave/CMakeFiles/wave.dir/file.cc.o"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wave.dir/file.cc.o -c /home/sof/source/wave/src/wave/file.cc

src/wave/CMakeFiles/wave.dir/file.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wave.dir/file.cc.i"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sof/source/wave/src/wave/file.cc > CMakeFiles/wave.dir/file.cc.i

src/wave/CMakeFiles/wave.dir/file.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wave.dir/file.cc.s"
	cd /home/sof/source/wave/src/wave && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sof/source/wave/src/wave/file.cc -o CMakeFiles/wave.dir/file.cc.s

# Object files for target wave
wave_OBJECTS = \
"CMakeFiles/wave.dir/header/data_header.cc.o" \
"CMakeFiles/wave.dir/header/riff_header.cc.o" \
"CMakeFiles/wave.dir/header/fmt_header.cc.o" \
"CMakeFiles/wave.dir/header/wave_header.cc.o" \
"CMakeFiles/wave.dir/header.cc.o" \
"CMakeFiles/wave.dir/header_list.cc.o" \
"CMakeFiles/wave.dir/file.cc.o"

# External object files for target wave
wave_EXTERNAL_OBJECTS =

src/wave/libwave.a: src/wave/CMakeFiles/wave.dir/header/data_header.cc.o
src/wave/libwave.a: src/wave/CMakeFiles/wave.dir/header/riff_header.cc.o
src/wave/libwave.a: src/wave/CMakeFiles/wave.dir/header/fmt_header.cc.o
src/wave/libwave.a: src/wave/CMakeFiles/wave.dir/header/wave_header.cc.o
src/wave/libwave.a: src/wave/CMakeFiles/wave.dir/header.cc.o
src/wave/libwave.a: src/wave/CMakeFiles/wave.dir/header_list.cc.o
src/wave/libwave.a: src/wave/CMakeFiles/wave.dir/file.cc.o
src/wave/libwave.a: src/wave/CMakeFiles/wave.dir/build.make
src/wave/libwave.a: src/wave/CMakeFiles/wave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sof/source/wave/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libwave.a"
	cd /home/sof/source/wave/src/wave && $(CMAKE_COMMAND) -P CMakeFiles/wave.dir/cmake_clean_target.cmake
	cd /home/sof/source/wave/src/wave && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/wave/CMakeFiles/wave.dir/build: src/wave/libwave.a

.PHONY : src/wave/CMakeFiles/wave.dir/build

src/wave/CMakeFiles/wave.dir/clean:
	cd /home/sof/source/wave/src/wave && $(CMAKE_COMMAND) -P CMakeFiles/wave.dir/cmake_clean.cmake
.PHONY : src/wave/CMakeFiles/wave.dir/clean

src/wave/CMakeFiles/wave.dir/depend:
	cd /home/sof/source/wave && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sof/source/wave /home/sof/source/wave/src/wave /home/sof/source/wave /home/sof/source/wave/src/wave /home/sof/source/wave/src/wave/CMakeFiles/wave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/wave/CMakeFiles/wave.dir/depend

