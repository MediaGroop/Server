# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alastar/projects/RakAuthServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alastar/projects/RakAuthServer/build

# Include any dependencies generated for this target.
include CMakeFiles/rakauthserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rakauthserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rakauthserver.dir/flags.make

CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o: ../AddCharacterPacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o -c /home/alastar/projects/RakAuthServer/AddCharacterPacket.cpp

CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/AddCharacterPacket.cpp > CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.i

CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/AddCharacterPacket.cpp -o CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.s

CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o.requires

CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o.provides: CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o.provides

CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o


CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o: ../AddServerPacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o -c /home/alastar/projects/RakAuthServer/AddServerPacket.cpp

CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/AddServerPacket.cpp > CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.i

CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/AddServerPacket.cpp -o CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.s

CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o.requires

CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o.provides: CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o.provides

CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o


CMakeFiles/rakauthserver.dir/AuthClient.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/AuthClient.cpp.o: ../AuthClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rakauthserver.dir/AuthClient.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/AuthClient.cpp.o -c /home/alastar/projects/RakAuthServer/AuthClient.cpp

CMakeFiles/rakauthserver.dir/AuthClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/AuthClient.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/AuthClient.cpp > CMakeFiles/rakauthserver.dir/AuthClient.cpp.i

CMakeFiles/rakauthserver.dir/AuthClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/AuthClient.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/AuthClient.cpp -o CMakeFiles/rakauthserver.dir/AuthClient.cpp.s

CMakeFiles/rakauthserver.dir/AuthClient.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/AuthClient.cpp.o.requires

CMakeFiles/rakauthserver.dir/AuthClient.cpp.o.provides: CMakeFiles/rakauthserver.dir/AuthClient.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/AuthClient.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/AuthClient.cpp.o.provides

CMakeFiles/rakauthserver.dir/AuthClient.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/AuthClient.cpp.o


CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o: ../AuthResponsePacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o -c /home/alastar/projects/RakAuthServer/AuthResponsePacket.cpp

CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/AuthResponsePacket.cpp > CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.i

CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/AuthResponsePacket.cpp -o CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.s

CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o.requires

CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o.provides: CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o.provides

CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o


CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o: ../CheckNickPacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o -c /home/alastar/projects/RakAuthServer/CheckNickPacket.cpp

CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/CheckNickPacket.cpp > CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.i

CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/CheckNickPacket.cpp -o CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.s

CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o.requires

CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o.provides: CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o.provides

CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o


CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o: ../NetworkListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o -c /home/alastar/projects/RakAuthServer/NetworkListener.cpp

CMakeFiles/rakauthserver.dir/NetworkListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/NetworkListener.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/NetworkListener.cpp > CMakeFiles/rakauthserver.dir/NetworkListener.cpp.i

CMakeFiles/rakauthserver.dir/NetworkListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/NetworkListener.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/NetworkListener.cpp -o CMakeFiles/rakauthserver.dir/NetworkListener.cpp.s

CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o.requires

CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o.provides: CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o.provides

CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o


CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o: ../RemoveCharacter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o -c /home/alastar/projects/RakAuthServer/RemoveCharacter.cpp

CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/RemoveCharacter.cpp > CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.i

CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/RemoveCharacter.cpp -o CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.s

CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o.requires

CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o.provides: CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o.provides

CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o


CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o: ../ServerInfoPacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o -c /home/alastar/projects/RakAuthServer/ServerInfoPacket.cpp

CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/ServerInfoPacket.cpp > CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.i

CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/ServerInfoPacket.cpp -o CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.s

CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o.requires

CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o.provides: CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o.provides

CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o


CMakeFiles/rakauthserver.dir/stdafx.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/stdafx.cpp.o: ../stdafx.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/rakauthserver.dir/stdafx.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/stdafx.cpp.o -c /home/alastar/projects/RakAuthServer/stdafx.cpp

CMakeFiles/rakauthserver.dir/stdafx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/stdafx.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/stdafx.cpp > CMakeFiles/rakauthserver.dir/stdafx.cpp.i

CMakeFiles/rakauthserver.dir/stdafx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/stdafx.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/stdafx.cpp -o CMakeFiles/rakauthserver.dir/stdafx.cpp.s

CMakeFiles/rakauthserver.dir/stdafx.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/stdafx.cpp.o.requires

CMakeFiles/rakauthserver.dir/stdafx.cpp.o.provides: CMakeFiles/rakauthserver.dir/stdafx.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/stdafx.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/stdafx.cpp.o.provides

CMakeFiles/rakauthserver.dir/stdafx.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/stdafx.cpp.o


CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o: ../VerifyResponsePacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o -c /home/alastar/projects/RakAuthServer/VerifyResponsePacket.cpp

CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/VerifyResponsePacket.cpp > CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.i

CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/VerifyResponsePacket.cpp -o CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.s

CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o.requires

CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o.provides: CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o.provides

CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o


CMakeFiles/rakauthserver.dir/FileManager.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/FileManager.cpp.o: ../FileManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/rakauthserver.dir/FileManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/FileManager.cpp.o -c /home/alastar/projects/RakAuthServer/FileManager.cpp

CMakeFiles/rakauthserver.dir/FileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/FileManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/FileManager.cpp > CMakeFiles/rakauthserver.dir/FileManager.cpp.i

CMakeFiles/rakauthserver.dir/FileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/FileManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/FileManager.cpp -o CMakeFiles/rakauthserver.dir/FileManager.cpp.s

CMakeFiles/rakauthserver.dir/FileManager.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/FileManager.cpp.o.requires

CMakeFiles/rakauthserver.dir/FileManager.cpp.o.provides: CMakeFiles/rakauthserver.dir/FileManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/FileManager.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/FileManager.cpp.o.provides

CMakeFiles/rakauthserver.dir/FileManager.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/FileManager.cpp.o


CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o: ../ConfigLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o -c /home/alastar/projects/RakAuthServer/ConfigLoader.cpp

CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/ConfigLoader.cpp > CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.i

CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/ConfigLoader.cpp -o CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.s

CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o.requires

CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o.provides: CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o.provides

CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o


CMakeFiles/rakauthserver.dir/Client.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/rakauthserver.dir/Client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/Client.cpp.o -c /home/alastar/projects/RakAuthServer/Client.cpp

CMakeFiles/rakauthserver.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/Client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/Client.cpp > CMakeFiles/rakauthserver.dir/Client.cpp.i

CMakeFiles/rakauthserver.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/Client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/Client.cpp -o CMakeFiles/rakauthserver.dir/Client.cpp.s

CMakeFiles/rakauthserver.dir/Client.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/Client.cpp.o.requires

CMakeFiles/rakauthserver.dir/Client.cpp.o.provides: CMakeFiles/rakauthserver.dir/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/Client.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/Client.cpp.o.provides

CMakeFiles/rakauthserver.dir/Client.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/Client.cpp.o


CMakeFiles/rakauthserver.dir/RakAuth.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/RakAuth.cpp.o: ../RakAuth.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/rakauthserver.dir/RakAuth.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/RakAuth.cpp.o -c /home/alastar/projects/RakAuthServer/RakAuth.cpp

CMakeFiles/rakauthserver.dir/RakAuth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/RakAuth.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/RakAuth.cpp > CMakeFiles/rakauthserver.dir/RakAuth.cpp.i

CMakeFiles/rakauthserver.dir/RakAuth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/RakAuth.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/RakAuth.cpp -o CMakeFiles/rakauthserver.dir/RakAuth.cpp.s

CMakeFiles/rakauthserver.dir/RakAuth.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/RakAuth.cpp.o.requires

CMakeFiles/rakauthserver.dir/RakAuth.cpp.o.provides: CMakeFiles/rakauthserver.dir/RakAuth.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/RakAuth.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/RakAuth.cpp.o.provides

CMakeFiles/rakauthserver.dir/RakAuth.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/RakAuth.cpp.o


CMakeFiles/rakauthserver.dir/Server.cpp.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/rakauthserver.dir/Server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/Server.cpp.o -c /home/alastar/projects/RakAuthServer/Server.cpp

CMakeFiles/rakauthserver.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/Server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/Server.cpp > CMakeFiles/rakauthserver.dir/Server.cpp.i

CMakeFiles/rakauthserver.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/Server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/Server.cpp -o CMakeFiles/rakauthserver.dir/Server.cpp.s

CMakeFiles/rakauthserver.dir/Server.cpp.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/Server.cpp.o.requires

CMakeFiles/rakauthserver.dir/Server.cpp.o.provides: CMakeFiles/rakauthserver.dir/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/Server.cpp.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/Server.cpp.o.provides

CMakeFiles/rakauthserver.dir/Server.cpp.o.provides.build: CMakeFiles/rakauthserver.dir/Server.cpp.o


CMakeFiles/rakauthserver.dir/minIni.c.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/minIni.c.o: ../minIni.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/rakauthserver.dir/minIni.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/rakauthserver.dir/minIni.c.o   -c /home/alastar/projects/RakAuthServer/minIni.c

CMakeFiles/rakauthserver.dir/minIni.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rakauthserver.dir/minIni.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alastar/projects/RakAuthServer/minIni.c > CMakeFiles/rakauthserver.dir/minIni.c.i

CMakeFiles/rakauthserver.dir/minIni.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rakauthserver.dir/minIni.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alastar/projects/RakAuthServer/minIni.c -o CMakeFiles/rakauthserver.dir/minIni.c.s

CMakeFiles/rakauthserver.dir/minIni.c.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/minIni.c.o.requires

CMakeFiles/rakauthserver.dir/minIni.c.o.provides: CMakeFiles/rakauthserver.dir/minIni.c.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/minIni.c.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/minIni.c.o.provides

CMakeFiles/rakauthserver.dir/minIni.c.o.provides.build: CMakeFiles/rakauthserver.dir/minIni.c.o


CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o: ../AccountInfo-odb.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o -c /home/alastar/projects/RakAuthServer/AccountInfo-odb.cxx

CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/AccountInfo-odb.cxx > CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.i

CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/AccountInfo-odb.cxx -o CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.s

CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o.requires

CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o.provides: CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o.provides

CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o.provides.build: CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o


CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o: CMakeFiles/rakauthserver.dir/flags.make
CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o: ../CharacterLink-odb.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o -c /home/alastar/projects/RakAuthServer/CharacterLink-odb.cxx

CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alastar/projects/RakAuthServer/CharacterLink-odb.cxx > CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.i

CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alastar/projects/RakAuthServer/CharacterLink-odb.cxx -o CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.s

CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o.requires:

.PHONY : CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o.requires

CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o.provides: CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o.requires
	$(MAKE) -f CMakeFiles/rakauthserver.dir/build.make CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o.provides.build
.PHONY : CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o.provides

CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o.provides.build: CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o


# Object files for target rakauthserver
rakauthserver_OBJECTS = \
"CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o" \
"CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o" \
"CMakeFiles/rakauthserver.dir/AuthClient.cpp.o" \
"CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o" \
"CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o" \
"CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o" \
"CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o" \
"CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o" \
"CMakeFiles/rakauthserver.dir/stdafx.cpp.o" \
"CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o" \
"CMakeFiles/rakauthserver.dir/FileManager.cpp.o" \
"CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o" \
"CMakeFiles/rakauthserver.dir/Client.cpp.o" \
"CMakeFiles/rakauthserver.dir/RakAuth.cpp.o" \
"CMakeFiles/rakauthserver.dir/Server.cpp.o" \
"CMakeFiles/rakauthserver.dir/minIni.c.o" \
"CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o" \
"CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o"

# External object files for target rakauthserver
rakauthserver_EXTERNAL_OBJECTS =

rakauthserver: CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/AuthClient.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/stdafx.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/FileManager.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/Client.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/RakAuth.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/Server.cpp.o
rakauthserver: CMakeFiles/rakauthserver.dir/minIni.c.o
rakauthserver: CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o
rakauthserver: CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o
rakauthserver: CMakeFiles/rakauthserver.dir/build.make
rakauthserver: ../libraknetcat.a
rakauthserver: CMakeFiles/rakauthserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alastar/projects/RakAuthServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable rakauthserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rakauthserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rakauthserver.dir/build: rakauthserver

.PHONY : CMakeFiles/rakauthserver.dir/build

CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/AddCharacterPacket.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/AddServerPacket.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/AuthClient.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/AuthResponsePacket.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/CheckNickPacket.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/NetworkListener.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/RemoveCharacter.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/ServerInfoPacket.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/stdafx.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/VerifyResponsePacket.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/FileManager.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/ConfigLoader.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/Client.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/RakAuth.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/Server.cpp.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/minIni.c.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/AccountInfo-odb.cxx.o.requires
CMakeFiles/rakauthserver.dir/requires: CMakeFiles/rakauthserver.dir/CharacterLink-odb.cxx.o.requires

.PHONY : CMakeFiles/rakauthserver.dir/requires

CMakeFiles/rakauthserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rakauthserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rakauthserver.dir/clean

CMakeFiles/rakauthserver.dir/depend:
	cd /home/alastar/projects/RakAuthServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alastar/projects/RakAuthServer /home/alastar/projects/RakAuthServer /home/alastar/projects/RakAuthServer/build /home/alastar/projects/RakAuthServer/build /home/alastar/projects/RakAuthServer/build/CMakeFiles/rakauthserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rakauthserver.dir/depend
