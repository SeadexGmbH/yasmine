cmake_minimum_required(VERSION 2.8)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()


include("${CMAKE_CURRENT_LIST_DIR}/addSeadexOptions.cmake")

# yasmine's preprocessor definitions


set(Y_OPTIMIZE "SPEED" CACHE STRING "Sets the optimize type. Supported values: SPEED and SIZE. Default value is SPEED.")
if( "${Y_OPTIMIZE}" STREQUAL "SIZE" )
	set(extra_flags "${extra_flags} -D \"Y_OPTIMIZE_4_SIZE\"")		
	message(STATUS "Optimizing for size.")
else()
	set(extra_flags "${extra_flags} -D \"Y_OPTIMIZE_4_SPEED\"")	
	message(STATUS "Optimizing for speed.")
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

