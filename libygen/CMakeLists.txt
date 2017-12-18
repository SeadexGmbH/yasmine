cmake_minimum_required(VERSION 2.8)

project(libygen)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

use_rapid_JSON()

file(GLOB libygen_SRC "include/*.hpp" "source/*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addYasmineOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

include_directories("./include")
include_directories("./../libyasmine/include")
include_directories("./../yasmine_model/include")
include_directories("./../externals/essentials/source/essentials/include")
include_directories("./../externals/genesis/source/genesis/include")


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libygen ${LINK_TYPE} ${libygen_SRC})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(libygen STATIC ${libygen_SRC})
endif()

set(link_libraries_list "")

if("${CPP_VERSION}" STREQUAL "03")	
	use_boost_libraries(link_libraries_list)
endif()

use_pthread(link_libraries_list)

add_library_for_linking(link_libraries_list libyasmine)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library_for_linking(link_libraries_list libessentials)
	add_library_for_linking(link_libraries_list libgenesis)
	add_library_for_linking(link_libraries_list libyasmine_model)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library_for_linking(link_libraries_list essentials)
	add_library_for_linking(link_libraries_list genesis)
	add_library_for_linking(link_libraries_list yasmine_model)
endif()

message(STATUS "libygen linking to libraries: ${link_libraries_list}" )
target_link_libraries(libygen LINK_PUBLIC ${link_libraries_list})

install(TARGETS libygen DESTINATION lib)
file(GLOB libygen_hpp "include/*.hpp")
install(FILES ${libygen_hpp} DESTINATION include/libygen/include)
set_target_properties(libygen PROPERTIES PREFIX "")
