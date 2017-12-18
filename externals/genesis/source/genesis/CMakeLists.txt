cmake_minimum_required(VERSION 2.8)

project(genesis)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

file(GLOB genesis_SRC "include/*.hpp" "source/*.cpp")

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

message(STATUS "genesis linking to libraries: ${link_libraries_list}" )

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libgenesis SHARED ${genesis_SRC})
	target_link_libraries(libgenesis LINK_PUBLIC ${link_libraries_list})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(genesis STATIC ${genesis_SRC})
	target_link_libraries(genesis LINK_PUBLIC ${link_libraries_list})
endif()

file(GLOB genesis_hpp "./include/*.hpp")
install(FILES ${genesis_hpp} DESTINATION include/genesis/include)


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	install(TARGETS libgenesis DESTINATION lib)
	set_target_properties(libgenesis PROPERTIES PREFIX "")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	install(TARGETS genesis DESTINATION lib)
	set_target_properties(genesis PROPERTIES PREFIX "")
endif()
