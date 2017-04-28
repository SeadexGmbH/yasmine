cmake_minimum_required(VERSION 3.5)

project(libygen)

set(CMAKE_VERBOSE_MAKEFILE, 1)

file(GLOB libygen_SRC "include/*.hpp" "source/*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	if( "${CMAKE_CXX_FLAGS}" STREQUAL "-m64" )
		set(extra_flags "${extra_flags} -m64")
		message(STATUS "setting platform x64")
	elseif("${CMAKE_CXX_FLAGS}" STREQUAL "-m32")
		set(extra_flags "${extra_flags} -m32")
		message(STATUS "setting platform x86")
	endif()	
	

	if("${CPP_VERSION}" STREQUAL "03")		
		set(extra_flags "${extra_flags} -std=c++03 -Wall -Wpedantic -g -Wno-unknown-pragmas -D \"SX_CPP03_BOOST\" -D \"SX_NO_VARIADIC_MACRO\"")
	else()
		set(extra_flags "${extra_flags} -std=c++14 -Wall -Wpedantic -g")
	endif()

endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# for release
	if( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )	
		#Creates fast code.
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /PDB-")
		
		#Controls LINK optimizations.
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /OPT:REF /OPT:ICF")
		
	# for debug
	elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )	
		#Creates a program database (PDB) file.
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /PDB")
	endif()
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

include_directories("./include")
include_directories("/usr/include/rapidjson")
include_directories("./../libyasmine" "./../genesis" "./../yasmine_model")
include_directories("./../libyasmine/include" "./../genesis/include" "./../yasmine_model/include")
include_directories("./../externals/essentials/include")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libygen SHARED ${libygen_SRC})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(libygen STATIC ${libygen_SRC})
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	if("${CPP_VERSION}" STREQUAL "03")
		target_link_libraries (libygen LINK_PUBLIC libyasmine libgenesis libyasmine_model pthread boost_system boost_thread boost_chrono)
	else()
		target_link_libraries (libygen LINK_PUBLIC libyasmine libgenesis libyasmine_model pthread)
	endif()
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	target_link_libraries (libygen LINK_PUBLIC libyasmine genesis yasmine_model)
endif()

install(TARGETS libygen DESTINATION lib)
file(GLOB libygen_hpp "include/*.hpp")
install(FILES ${libygen_hpp} DESTINATION include/libygen/include)
set_target_properties(libygen PROPERTIES PREFIX "")