cmake_minimum_required(VERSION 2.8)

project(yasmine_model)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

use_rapid_JSON()

file(GLOB yasmine_model_SRC "include/*.hpp" "source/*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addYasmineOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

include_directories("./../yasmine_model/include")
include_directories("./../externals/essentials/include")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libyasmine_model ${LINK_TYPE} ${yasmine_model_SRC})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(yasmine_model STATIC ${yasmine_model_SRC})
endif()

set(link_libraries_list "")
use_pthread(link_libraries_list)

if("${CPP_VERSION}" STREQUAL "03")	
	use_boost_libraries(link_libraries_list)
endif()

message(STATUS "libyasmine_model linking to libraries: ${link_libraries_list}" )
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	target_link_libraries(libyasmine_model LINK_PUBLIC ${link_libraries_list})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	target_link_libraries(yasmine_model LINK_PUBLIC ${link_libraries_list})
endif()


file(GLOB yasmine_model_hpp "include/*.hpp")
install(FILES ${yasmine_model_hpp} DESTINATION include/yasmine_model/include)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	install(TARGETS libyasmine_model DESTINATION lib)
	set_target_properties(libyasmine_model PROPERTIES PREFIX "")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	install(TARGETS yasmine_model DESTINATION lib)
	set_target_properties(yasmine_model PROPERTIES PREFIX "")
endif()
