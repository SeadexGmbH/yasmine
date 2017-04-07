cmake_minimum_required(VERSION 3.5)

project(forty_two)

set(CMAKE_VERBOSE_MAKEFILE, 1)

set(HEADER_FILES "./*.hpp" "./../../libyasmine/include/*.hpp" "./../../externals/essentials/include/essentials/*.hpp" "./../../externals/essentials/include/compatibility/*.hpp" "./../../externals/hermes/include/hermes/*.hpp")
file(GLOB forty_two_SRC "./*.cpp" ${HEADER_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	if( "${CMAKE_CXX_FLAGS}" STREQUAL "-m64" )
		set(extra_flags "${extra_flags} -m64")
		message(STATUS "setting platform x64")
	else()
		set(extra_flags "${extra_flags} -m32")
		message(STATUS "setting platform x86")
	endif()
		
	if("${CPP_VERSION}" STREQUAL "03")
		set(extra_flags "${extra_flags} -std=c++03 -Wall -Wpedantic -g -Wno-unknown-pragmas -D \"SX_CPP03_BOOST\" -D \"SX_NO_VARIADIC_MACRO\"")
	else()
		set(extra_flags "${extra_flags} -std=c++14 -Wall -Wpedantic -g")
	endif()
	
	# yasmine's preprocessor definitions
	set(Y_OPTIMIZE "SPEED" CACHE STRING "Sets the optimize type. Supported values: SPEED and SIZE. Default value is SPEED.")
	if( "${Y_OPTIMIZE}" STREQUAL "SIZE" )
		set(extra_flags "${extra_flags} -D \"Y_OPTIMIZE_4_SIZE\"")			
	else()
		set(extra_flags "${extra_flags} -D \"Y_OPTIMIZE_4_SPEED\"")			
	endif()

	option("SX_NO_LOGGING" "Use when you want to use no logging at all (no logging code is created).")
	if( "${SX_NO_LOGGING}" )
		set(extra_flags "${extra_flags} -D \"SX_NO_LOGGING\"")
	endif()
	
	option("SX_NO_STD_MAKE_UNIQUE" "When the standard make_unique is not available (e.g. no C++14 support), you have to define this preprocessor definition. A yasmine drop-in replacement template will be used instead then.")		
	if( "${SX_NO_STD_MAKE_UNIQUE}" )
		set(extra_flags "${extra_flags} -D \"SX_NO_STD_MAKE_UNIQUE\"")	
	endif()

	option("Y_LEAN_AND_MEAN" "If you compile the library with Y_LEAN_AND_MEAN being defined or if you define the macro locally before including yasmine.hpp, all the state pseudostates and the asynchronous simple state (with the asynchronous behavior) are excluded (i.e. those headers are not included). This can reduce compile time.")	
	if( "${Y_LEAN_AND_MEAN}" )
		set(extra_flags "${extra_flags} -D \"Y_LEAN_AND_MEAN\"")	
	endif()

	option("Y_PROFILER" "If Y_PROFILER is defined, the state machine will count the number of events that were processed. The user can query the counter by calling the 'get_number_of_processed_events' method.")	
	if( "${Y_PROFILER}" )
		set(extra_flags "${extra_flags} -D \"Y_PROFILER\"")	
	endif()
	
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# Checks buffer security.
	set(extra_flags "${extra_flags} /GS")
	
	#Sets output warning level.
	set(extra_flags "${extra_flags} /W4")
	
	#Disable specific Warnings.
	set(extra_flags "${extra_flags} /wd\"4127\" /wd\"4250\"")
	
	#Defines constants and macros.
	set(extra_flags "${extra_flags} /D \"_CRT_SECURE_NO_WARNINGS\"")
	
	#Enables function-level linking.
	set(extra_flags "${extra_flags} /Gy")
	
	#Specifies standard behavior under /Ze.
	set(extra_flags "${extra_flags} /Zc:wchar_t /Zc:inline")
	
	#Disable minimal rebuild.
	set(extra_flags "${extra_flags} /Gm-")
	
	#Enables additional security features and warnings.
	set(extra_flags "${extra_flags} /sdl")
			
	#Specifies floating-point behavior.
	set(extra_flags "${extra_flags} /fp:precise")
		
	#Multibyte character sets macro.
	set(extra_flags "${extra_flags} /D \"_MBCS\"")
		
	#Enables you to provide internal compiler error (ICE) information directly to the Visual C++ team.
	set(extra_flags "${extra_flags} /errorReport:prompt")
	
	#Treats warnings as errors.
	set(extra_flags "${extra_flags} /WX")
	
	#Generates intrinsic functions.
	set(extra_flags "${extra_flags} /Oi")
	
	#Specifies the model of exception handling.
	set(extra_flags "${extra_flags} /EHsc")
	
	#Creates an object file.
	set(extra_flags "${extra_flags} /Fo")
	
	#Marks an executable as verified to be compatible with the Windows Data Execution Prevention feature.
	#set(extra_flags "${extra_flags} /NXCOMPAT")
	
# yasmine's preprocessor definitions
	set(Y_OPTIMIZE "SPEED" CACHE STRING "Sets the optimize type. Supported values: SPEED and SIZE. Default value is SPEED.")
	if( "${Y_OPTIMIZE}" STREQUAL "SIZE" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"Y_OPTIMIZE_4_SIZE\"")			
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"Y_OPTIMIZE_4_SPEED\"")			
	endif()
	
	option("SX_NO_LOGGING" "Use when you want to use no logging at all (no logging code is created).")
	if( "${SX_NO_LOGGING}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"SX_NO_LOGGING\"")
	endif()
	
	option("SX_NO_STD_MAKE_UNIQUE" "When the standard make_unique is not available (e.g. no C++14 support), you have to define this preprocessor definition. A yasmine drop-in replacement template will be used instead then.")		
	if( "${SX_NO_STD_MAKE_UNIQUE}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"SX_NO_STD_MAKE_UNIQUE\"")	
	endif()
	
	option("Y_LEAN_AND_MEAN" "If you compile the library with Y_LEAN_AND_MEAN being defined or if you define the macro locally before including yasmine.hpp, all the state pseudostates and the asynchronous simple state (with the asynchronous behavior) are excluded (i.e. those headers are not included). This can reduce compile time.")	
	if( "${Y_LEAN_AND_MEAN}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"Y_LEAN_AND_MEAN\"")	
	endif()
	
	option("Y_PROFILER" "If Y_PROFILER is defined, the state machine will count the number of events that were processed. The user can query the counter by calling the 'get_number_of_processed_events' method.")	
	if( "${Y_PROFILER}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"Y_PROFILER\"")	
	endif()
		
endif()

# for release
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
	#Creates fast code.
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
	
	#Controls LINK optimizations.
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /OPT:REF /OPT:ICF")
	
# for debug
elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
	#Creates a program database (PDB) file.
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /PDB")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

add_executable(forty_two ${forty_two_SRC})
include_directories("./../../libyasmine/include" "./../../externals/essentials/include" "./../../externals/hermes/include")

#using boost
if("${CPP_VERSION}" STREQUAL "03")
	if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")		
		link_directories("${Y_BOOST_LIB_PATH}")
	endif()
endif()


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	if("${CPP_VERSION}" STREQUAL "03")
		target_link_libraries (forty_two LINK_PUBLIC libyasmine pthread boost_system boost_thread boost_chrono)
	else()
		target_link_libraries (forty_two LINK_PUBLIC libyasmine pthread)
	endif()
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	target_link_libraries (forty_two LINK_PUBLIC libyasmine)
endif()


if("${CPP_VERSION}" STREQUAL "03")
	if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
		SET(Boost_USE_STATIC_LIBS ON)		
		SET(BOOST_ROOT "${Y_BOOST_LIB_INCLUDE}")		
		SET(Boost_INCLUDE_DIRS "${Y_BOOST_LIB_INCLUDE}")
		include_directories(${Boost_INCLUDE_DIRS})		
		target_link_libraries(forty_two LINK_PUBLIC ${Boost_LIBRARIES})
	endif()
endif()

install(TARGETS forty_two DESTINATION bin)
