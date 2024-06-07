cmake_minimum_required(VERSION 3.26)

project(sdl2_app C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/libs)

set(BUILD_SHARED_LIBS OFF)
SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
MESSAGE(STATUS "BUILD_SHARED_LIBS ::>> " ${BUILD_SHARED_LIBS})
#MESSAGE(STATUS ">>>>>>>>>>>>>>>>>>>>> " ${CMAKE_CXX_COMPILER_ID})
#MESSAGE(STATUS ">>>>>>>>>>>>>>>>>>>>> " ${CMAKE_C_COMPILER})
MESSAGE(STATUS ">>>>>>CMAKE_SYSTEM_NAME> " ${CMAKE_SYSTEM_NAME})

# IF (WIN32)
#   MESSAGE(STATUS ">>>>WIN32 ")
# ELSE()
#   MESSAGE(STATUS ">>>>NOT WIN32 ")
# ENDIF()
#https://www.aloneguid.uk/posts/2021/11/cmake-hot-reload/
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(CMAKE_CXX_FLAGS_DEBUG "/MDd /ZI /Ob0 /Od /RTC1")
  MESSAGE(STATUS ">>>>>>>>>>>>>>>>>>>>> CMAKE_CXX_FLAGS_DEBUG" )
endif()

# main entry file
set(MAIN_APP 
  #src/sdl2_image.cpp
  app/src/game.c
)

# dependency management
file(
    DOWNLOAD
    https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.39.0/CPM.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
    EXPECTED_HASH SHA256=66639bcac9dd2907b2918de466783554c1334446b9874e90d38e3778d404c2ef
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

CPMAddPackage("gh:libsdl-org/SDL#release-2.30.3")

if(SDL_ADDED)
  MESSAGE(STATUS "=================")
  MESSAGE(STATUS "ADDED SDL???")
endif(SDL_ADDED)

add_subdirectory(core)

#add_executable(${PROJECT_NAME}_test ${MAIN_APP})
#add_executable(${PROJECT_NAME} ${MAIN_APP})
#target_link_libraries(${PROJECT_NAME} PUBLIC core)

message(status "FILE ====: " ${CMAKE_CURRENT_BINARY_DIR})
# https://stackoverflow.com/questions/13067401/cmake-check-that-a-local-file-exists
# for build once for dll reload for recompile
if(EXISTS "${CMAKE_CURRENT_BINARY_DIR}/bin/Debug/${PROJECT_NAME}.exe")
  message(status "FOUND BINARY")
else()
  message(status "NOT FOUND BINARY")
  add_executable(${PROJECT_NAME} ${MAIN_APP})
  target_link_libraries(${PROJECT_NAME} PUBLIC core)
endif()