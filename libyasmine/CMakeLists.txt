cmake_minimum_required(VERSION 2.8)

project(libyasmine CXX)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

file(GLOB yasmine_SRC "include/*.hpp" "include_impl/*.hpp" "source/*.cpp" "../externals/essentials/include/essentials/*.hpp" "../externals/essentials/include/essentials/compatibility/*.hpp" "../externals/hermes/include/hermes/*.hpp" "../externals/essentials/source/*.cpp" "../externals/hermes/source/*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories("./include" "./include_impl" "../externals/essentials/include" "../externals/hermes/include")

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addYasmineOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libyasmine ${LINK_TYPE} ${yasmine_SRC})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(libyasmine STATIC ${yasmine_SRC})
endif()

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
