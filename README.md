# sdl2_hotreload_test

# info:
 - working for dll
 - need to add reload

# License: MIT

# Packages:
 - cpm-cmake/CPM.cmake v0.39.0
 - libsdl-org/SDL#release-2.30.3

# c/c++:
  Need to test build both?

# Required:
 - VS2022
 - cmake
 - pkg-config
 - python
 - nasm ???
 - perl ???

 You can use package manger program like scoop.

# Build (windows):
```
./build.bat
```
Run once for set up.

```
./compile.bat
```
Run Cmake build without need to mkdir build folder.

# run app (windows):
```
./debug_run.bat
```

# Refs:
 - https://github.com/InfiniBrains/SDL2-CPM-CMake-Example
 - https://www.youtube.com/watch?v=XfZ6WrV5Z7Y  Creating a Game Loop with C & SDL (Tutorial)
 - https://stackoverflow.com/questions/10383021/how-do-i-run-a-bat-file-from-cmake


# Note: 
  - If you get error check the build logs. Some toolchain is required to build it for c.
  

# imgui:
  There are two imgui github repo for c and c++.

  - if you have security protect program it error in imgui. As well other program which required compile with support third parties.

# build:

```
@echo off
echo 'init build'
mkdir build
cd build
cmake ..
cmake --build .
```
