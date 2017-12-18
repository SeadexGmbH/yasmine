cmake_minimum_required(VERSION 2.8)

project(html_page_generator)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

file(GLOB html_page_generator_SRC "./*.hpp" "./*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../../CMakeHelpers/addSpecificFlags.cmake)
include(./../../CMakeHelpers/addSeadexOptions.cmake)

include_directories("./../../externals/essentials/source/essentials/include")
include_directories("./../../genesis/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

add_executable(html_page_generator ${html_page_generator_SRC})

set(link_libraries_list "")
use_boost_libraries(link_libraries_list)
add_library_for_linking(link_libraries_list libgenesis)
use_pthread(link_libraries_list)
message(STATUS "html_page_generator linking to libraries: ${link_libraries_list}" )

target_link_libraries(html_page_generator LINK_PUBLIC ${link_libraries_list})

install(TARGETS html_page_generator DESTINATION bin)
