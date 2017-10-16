cmake_minimum_required(VERSION 2.8)

project(yasmine)


set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

#set variables
include(./CMakeHelpers/setVariables.cmake)

include(./CMakeHelpers/addBoost.cmake)

include(./CMakeHelpers/functions.cmake)
include(./CMakeHelpers/functionsRapidJSON.cmake)
include(./CMakeHelpers/functionsAddCompilerFlags.cmake)


add_subdirectory(libyasmine)
add_subdirectory(yasmine_model)
add_subdirectory(genesis)
add_subdirectory(libygen)
add_subdirectory(ygen)

add_subdirectory(examples)
