cmake_minimum_required(VERSION 2.8)

project(events_with_parameters)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

set(HEADER_FILES "./*.hpp" "./../../libyasmine/include/*.hpp" "./../../externals/essentials/include/essentials/*.hpp" "./../../externals/essentials/include/compatibility/*.hpp" "./../../externals/hermes/include/hermes/*.hpp")
file(GLOB events_with_parameters_SRC "./*.cpp" ${HEADER_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../../CMakeHelpers/addSpecificFlags.cmake)
include(./../../CMakeHelpers/addYasmineOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

add_executable(events_with_parameters ${events_with_parameters_SRC})
include_directories("./../../libyasmine/include" "./../../externals/essentials/include" "./../../externals/hermes/include")

set(link_libraries_list "")

if("${CPP_VERSION}" STREQUAL "03")	
	use_boost_libraries(link_libraries_list)
endif()

use_pthread(link_libraries_list)
add_library_for_linking(link_libraries_list libyasmine)
message(STATUS "events_with_parameters linking to libraries: ${link_libraries_list}" )
target_link_libraries(events_with_parameters LINK_PUBLIC ${link_libraries_list})

install(TARGETS events_with_parameters DESTINATION bin)
