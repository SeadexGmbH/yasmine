cmake_minimum_required(VERSION 2.8)

project(hermes)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

file(GLOB hermes_SRC "./include/hermes/*.hpp" "./source/*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addSeadexOptions.cmake)

include_directories("./include")
include_directories("./../externals/essentials/source/essentials/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

set(link_libraries_list "")

if("${CPP_VERSION}" STREQUAL "03")	
	use_boost_libraries(link_libraries_list)
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library_for_linking(link_libraries_list libessentials)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library_for_linking(link_libraries_list essentials)
endif()

message(STATUS "hermes linking to libraries: ${link_libraries_list}" )


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libhermes ${LINK_TYPE} ${hermes_SRC})
	target_link_libraries(libhermes LINK_PUBLIC ${link_libraries_list})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(hermes STATIC ${hermes_SRC})
	target_link_libraries(hermes LINK_PUBLIC ${link_libraries_list})
endif()

file(GLOB hermes_hpp "./include/*.hpp")
install(FILES ${hermes_hpp} DESTINATION include/hermes/include)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	install(TARGETS libhermes DESTINATION lib)
	set_target_properties(libhermes PROPERTIES PREFIX "")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	install(TARGETS hermes DESTINATION lib)
	set_target_properties(hermes PROPERTIES PREFIX "")
endif()
