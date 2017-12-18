
if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

include(./CMakeHelpers/setVariables.cmake)

include(./CMakeHelpers/addBoost.cmake)
include(./CMakeHelpers/functions.cmake)
include(./CMakeHelpers/functionsAddCompilerFlags.cmake)

add_subdirectory(essentials)

if(EXISTS essentials_unit_tests)
add_subdirectory(essentials_unit_tests)
endif()
