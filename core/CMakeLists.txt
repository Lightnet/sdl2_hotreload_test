cmake_minimum_required(VERSION 3.26)

project(core C)

SET(CORE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET(CORE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CORE_HEADERS "")
set(CORE_SOURCE_FILES "")
# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake

list(APPEND CORE_SOURCE_FILES ${CORE_SOURCE_DIR}/core.c)
#list(APPEND CORE_SOURCE_FILES ${CORE_SOURCE_DIR}/test.c)

list(APPEND CORE_HEADERS ${CORE_INCLUDE_DIR}/core.h)
#list(APPEND CORE_HEADERS ${CORE_INCLUDE_DIR}/test.h)
#include_directories(${CORE_INCLUDE_DIR})

IF(BUILD_SHARED_LIBS)
  add_library(core STATIC ${CORE_SOURCE_FILES})
else()
  add_library(core SHARED ${CORE_SOURCE_FILES})
endif()

#MESSAGE(STATUS "=== :: raylib_SOURCE_DIR: " ${raylib_SOURCE_DIR})
#MESSAGE(STATUS "=== :: SDL_SOURCE_DIR: " ${SDL_SOURCE_DIR})
target_include_directories(core PUBLIC ${CORE_INCLUDE_DIR})
target_include_directories(core PUBLIC ${SDL_SOURCE_DIR}/include)
target_link_libraries(core INTERFACE SDL2::SDL2)
target_link_libraries(core PUBLIC SDL2::SDL2)

install(
    TARGETS core
    LIBRARY DESTINATION ${destination}/lib
    RUNTIME DESTINATION ${destination}/lib
    COMPONENT Libraries)
install(
    FILES ${CORE_HEADERS}
    DESTINATION ${destination}/include
    COMPONENT Headers)