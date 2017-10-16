cmake_minimum_required(VERSION 2.8)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

function(use_rapid_JSON)
if(SX_RAPIDJSON)
	message("SX_RAPIDJSON is set by user.")
else()
	message("SX_RAPIDJSON is not set by user. Setting default value.")
	if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
		set(SX_RAPIDJSON "/usr/include/rapidjson")
	elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
		set(SX_RAPIDJSON "C:\\Program Files\\rapidjson")
	endif()
endif()

include_directories(${SX_RAPIDJSON})

message(STATUS "include rapidJSON from: ${SX_RAPIDJSON}")

endfunction()
