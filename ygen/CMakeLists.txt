cmake_minimum_required(VERSION 2.8)

project(ygen)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

file(GLOB ygen_SRC "source/*.cpp" "include/*.hpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addYasmineOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

include(./../CMakeHelpers/addBoost.cmake)

add_executable(ygen ${ygen_SRC})

set(link_libraries_list "")
use_boost_libraries(link_libraries_list)
use_pthread(link_libraries_list)
add_library_for_linking(link_libraries_list libygen)
message(STATUS "ygen linking to libraries: ${link_libraries_list}" )
target_link_libraries(ygen LINK_PUBLIC ${link_libraries_list})

include_directories("./include")
include_directories("./../externals/essentials/source/essentials/include")
include_directories("./../externals/genesis/source/genesis/include")
include_directories("./../libygen/include")

install(TARGETS ygen DESTINATION bin)
