cmake_minimum_required(VERSION 3.5)

project(libyasmine)

set(CMAKE_VERBOSE_MAKEFILE, 1)

file(GLOB yasmine_SRC "include/*.hpp" "include_impl/*.hpp" "source/*.cpp" "../externals/essentials/include/essentials/*.hpp" "../externals/essentials/include/essentials/compatibility/*.hpp" "../externals/hermes/include/hermes/*.hpp" "../externals/essentials/source/*.cpp" "../externals/hermes/source/*.cpp")

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
	elseif("${CPP_VERSION}" STREQUAL "14")
		set(extra_flags "${extra_flags} -std=c++14 -Wall -Wpedantic -g")
	else()
		set(extra_flags "${extra_flags} -std=c++11 -Wall -Wpedantic -g -D \"SX_NO_STD_MAKE_UNIQUE\"")
	endif()
	
# yasmine's preprocessor definitions
	set(Y_OPTIMIZE "SPEED" CACHE STRING "Sets the optimize type. Supported values: SPEED and SIZE. Default value is SPEED.")
	if( "${Y_OPTIMIZE}" STREQUAL "SIZE" )
		set(extra_flags "${extra_flags} -D \"Y_OPTIMIZE_4_SIZE\"")		
		message(STATUS "Optimizing for size.")
	else()
		set(extra_flags "${extra_flags} -D \"Y_OPTIMIZE_4_SPEED\"")	
		message(STATUS "Optimizing for speed.")
	endif()

	option("SX_NO_LOGGING" "Use when you want to use no logging at all (no logging code is created).")
	if( "${SX_NO_LOGGING}" )
		set(extra_flags "${extra_flags} -D \"SX_NO_LOGGING\"")
		message(STATUS "No logging used.")
	else()	
		message(STATUS "Logger is used.")
	endif()

	option("SX_NO_STD_MAKE_UNIQUE" "When the standard make_unique is not available (e.g. no C++14 support), you have to define this preprocessor definition. A yasmine drop-in replacement template will be used instead then.")		
	if( "${SX_NO_STD_MAKE_UNIQUE}" )
		set(extra_flags "${extra_flags} -D \"SX_NO_STD_MAKE_UNIQUE\"")
		message(STATUS "SX_NO_STD_MAKE_UNIQUE is defined.")
	endif()

	option("Y_LEAN_AND_MEAN" "If you compile the library with Y_LEAN_AND_MEAN being defined or if you define the macro locally before including yasmine.hpp, all the state pseudostates and the asynchronous simple state (with the asynchronous behaviour) are excluded (i.e. those headers are not included). This can reduce compile time.")	
	if( "${Y_LEAN_AND_MEAN}" )
		set(extra_flags "${extra_flags} -D \"Y_LEAN_AND_MEAN\"")
		message(STATUS "Y_LEAN_AND_MEAN is defined.")	
	endif()
	
	option("Y_PROFILER" "If Y_PROFILER is defined, the state machine will count the number of events that were processed. The user can query the counter by calling the 'get_number_of_processed_events' method.")	
	if( "${Y_PROFILER}" )
		set(extra_flags "${extra_flags} -D \"Y_PROFILER\"")
		message(STATUS "Y_PROFILER is defined.")
	endif()
	
	option("SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG" "Sets to use a workaround for bug in GCC with expansion of template parameter pack that appears in a lambda-expression (bug reported for GCC 4.8.4)")	
	if( "${SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG}" )
		set(extra_flags "${extra_flags} -D \"SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG\"")
		message(STATUS "SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG is defined.")
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
	
	#Specifies standard behaviour under /Ze.
	set(extra_flags "${extra_flags} /Zc:wchar_t /Zc:inline")
	
	#Disable minimal rebuild.
	set(extra_flags "${extra_flags} /Gm-")
	
	#Enables additional security features and warnings.
	set(extra_flags "${extra_flags} /sdl")
			
	#Specifies floating-point behaviour.
	set(extra_flags "${extra_flags} /fp:precise")
		
	#Multibyte character sets macro.
	set(extra_flags "${extra_flags} /D \"_MBCS\"")
		
	#Enables you to provide internal compiler error (ICE) information directly to the Visual C++ team.
	set(extra_flags "${extra_flags} /errorReport:prompt")
	
	#Treats warnings as errors.
	if( "${MSVC_VERSION}" STRGREATER "1800" )
		set(extra_flags "${extra_flags} /WX")
	#else( "${MSVC_VERSION}" STRLESS "1900" )
	else()
		set(extra_flags "${extra_flags} /WX-")
	endif()
		
	
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
		message(STATUS "Optimizing for size.")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"Y_OPTIMIZE_4_SPEED\"")	
		message(STATUS "Optimizing for speed.")
	endif()

	option("SX_NO_LOGGING" "Use when you want to use no logging at all (no logging code is created).")
	if( "${SX_NO_LOGGING}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"SX_NO_LOGGING\"")
		message(STATUS "No logging used.")
	else()	
		message(STATUS "Logger is used.")
	endif()

	option("SX_NO_STD_MAKE_UNIQUE" "When the standard make_unique is not available (e.g. no C++14 support), you have to define this preprocessor definition. A yasmine drop-in replacement template will be used instead then.")		
	if( "${SX_NO_STD_MAKE_UNIQUE}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"SX_NO_STD_MAKE_UNIQUE\"")
		message(STATUS "SX_NO_STD_MAKE_UNIQUE is defined.")
	endif()

	option("Y_LEAN_AND_MEAN" "If you compile the library with Y_LEAN_AND_MEAN being defined or if you define the macro locally before including yasmine.hpp, all the state pseudostates and the asynchronous simple state (with the asynchronous behaviour) are excluded (i.e. those headers are not included). This can reduce compile time.")	
	if( "${Y_LEAN_AND_MEAN}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"Y_LEAN_AND_MEAN\"")
		message(STATUS "Y_LEAN_AND_MEAN is defined.")	
	endif()
	
	option("Y_PROFILER" "If Y_PROFILER is defined, the state machine will count the number of events that were processed. The user can query the counter by calling the 'get_number_of_processed_events' method.")	
	if( "${Y_PROFILER}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"Y_PROFILER\"")
		message(STATUS "Y_PROFILER is defined.")
	endif()
	
	option("SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG" "Sets to use a workaround for bug in GCC with expansion of template parameter pack that appears in a lambda-expression (bug reported for GCC 4.8.4)")	
	if( "${SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG\"")
		message(STATUS "SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG is defined.")
	endif()

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

include_directories("./include" "./include_impl" "../externals/essentials/include" "../externals/hermes/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libyasmine SHARED ${yasmine_SRC})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(libyasmine STATIC ${yasmine_SRC})
endif()

SET_TARGET_PROPERTIES ( libyasmine PROPERTIES
  VERSION 1.2.3
  SOVERSION 1.2 )

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