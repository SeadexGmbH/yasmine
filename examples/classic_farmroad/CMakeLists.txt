cmake_minimum_required(VERSION 2.8)

project(classic_farmroad)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

set(HEADER_FILES "./*.hpp")
file(GLOB classic_farmroad_SRC "./*.cpp" ${HEADER_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../../CMakeHelpers/addSpecificFlags.cmake)
include(./../../CMakeHelpers/addYasmineOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

add_executable(classic_farmroad ${classic_farmroad_SRC})
include_directories("./../../libyasmine/include")
include_directories("./../../externals/essentials/source/essentials/include")
include_directories("./../../externals/hermes/source/hermes/include")

set(link_libraries_list "")

if("${CPP_VERSION}" STREQUAL "03")	
	use_boost_libraries(link_libraries_list)
endif()

use_pthread(link_libraries_list)
add_library_for_linking(link_libraries_list libyasmine)
message(STATUS "classic_farmroad linking to libraries: ${link_libraries_list}" )
target_link_libraries(classic_farmroad LINK_PUBLIC ${link_libraries_list})

install(TARGETS classic_farmroad DESTINATION bin)
