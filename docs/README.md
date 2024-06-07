# sdl2_hotreload_test

# info:
 - working for dll
 - need to add reload

# License: MIT

# Packages:
 - cpm-cmake/CPM.cmake v0.39.0
 - libsdl-org/SDL#release-2.30.3
 - libsdl-org/SDL_image#release-2.8.2
 - libsdl-org/SDL_ttf#release-2.22.0
 - libsdl-org/SDL_mixer#release-2.8.0
 - libsdl-org/SDL_net#release-2.2.0
 - imgui #67cf8c96b77e6729e720a376757964ff2d2e78c0

# Information:
 Set up for CMakeLists.txt with CPM.cmake. To able to download github repo and build binaries and libs.

 Note it may take a while to build.

 VS2022 tool. Note it take +2.5 GB.

 The build folder once compile is 1.70 GB.

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
 - 
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

https://coderefinery.github.io/cmake-workshop/environment/



# let the preprocessor know about the system name
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_compile_definitions(example PUBLIC "IS_LINUX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  target_compile_definitions(example PUBLIC "IS_MACOS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(example PUBLIC "IS_WINDOWS")
endif()







https://stackoverflow.com/questions/14199708/cmake-include-library-dependencies-in-a-static-library

https://stackoverflow.com/questions/14468678/cmake-link-a-library-to-library



