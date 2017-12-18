cmake_minimum_required(VERSION 2.8)

project(libyasmine CXX)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

file(GLOB yasmine_SRC "include/*.hpp" "include_impl/*.hpp" "source/*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories("./include" "./include_impl")
include_directories("./../externals/essentials" "./../externals/essentials/source/essentials/include")
include_directories("./../externals/hermes" "./../externals/hermes/source/hermes/include")

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addYasmineOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libyasmine ${LINK_TYPE} ${yasmine_SRC})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(libyasmine STATIC ${yasmine_SRC})
endif()

set(link_libraries_list "")
use_pthread(link_libraries_list)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library_for_linking(link_libraries_list libessentials)
	add_library_for_linking(link_libraries_list libhermes)
else()
	add_library_for_linking(link_libraries_list essentials)
	add_library_for_linking(link_libraries_list hermes)
endif()
message(STATUS "libyasmine linking to libraries: ${link_libraries_list}" )
target_link_libraries(libyasmine LINK_PUBLIC ${link_libraries_list})

SET_TARGET_PROPERTIES ( libyasmine PROPERTIES
  VERSION 1.3.1
  SOVERSION 1.3 )

install(TARGETS libyasmine DESTINATION lib)
file(GLOB yasmine_hpp "include/*.hpp")
file(GLOB yasmine_hpp_impl "include_impl/*.hpp")
file(GLOB essentials_hpp "../externals/essentials/include/essentials/*.hpp" "../externals/essentials/include/essentials/compatibility/*.hpp")
file(GLOB essentials_compatibility_hpp "../externals/essentials/include/essentials/compatibility/*.hpp")
file(GLOB hermes_hpp "../externals/hermes/include/hermes/*.hpp")
install(FILES ${yasmine_hpp} DESTINATION include/yasmine/include)
install(FILES ${yasmine_hpp_impl} DESTINATION include/yasmine/include_impl)
install(FILES ${essentials_hpp} DESTINATION include/yasmine/essentials/include/essentials)
install(FILES ${essentials_compatibility_hpp} DESTINATION include/yasmine/essentials/include/essentials/compatibility)
install(FILES ${hermes_hpp} DESTINATION include/yasmine/hermes/include)
set_target_properties(libyasmine PROPERTIES PREFIX "")
