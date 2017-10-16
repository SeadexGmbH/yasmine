cmake_minimum_required(VERSION 2.8)

project(genesis)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

file(GLOB genesis_SRC "include/*.hpp" "source/*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addYasmineOptions.cmake)

include_directories("./include")
include_directories("./../externals/essentials/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libgenesis ${LINK_TYPE} ${genesis_SRC})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(genesis STATIC ${genesis_SRC})
endif()

file(GLOB genesis_hpp "include/*.hpp")
install(FILES ${genesis_hpp} DESTINATION include/genesis/include)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	install(TARGETS libgenesis DESTINATION lib)
	set_target_properties(libgenesis PROPERTIES PREFIX "")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	install(TARGETS genesis DESTINATION lib)
	set_target_properties(genesis PROPERTIES PREFIX "")
endif()
