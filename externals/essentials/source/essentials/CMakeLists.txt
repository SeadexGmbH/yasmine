cmake_minimum_required(VERSION 2.8)

project(essentials)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

file(GLOB essentials_SRC "include/essentials/*.hpp" "include/essentials/compatibility/*.hpp" "source/*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addSeadexOptions.cmake)

include_directories("./include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libessentials ${LINK_TYPE} ${essentials_SRC})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(essentials STATIC ${essentials_SRC})
endif()


file(GLOB essentials_hpp "include/essentials/*.hpp" "include/essentials/compatibility/*.hpp")
install(FILES ${essentials_hpp} DESTINATION include/essentials/include)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	install(TARGETS libessentials DESTINATION lib)
	set_target_properties(libessentials PROPERTIES PREFIX "")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	install(TARGETS essentials DESTINATION lib)
	set_target_properties(essentials PROPERTIES PREFIX "")
endif()
