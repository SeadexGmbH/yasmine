
if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

include(./CMakeHelpers/setVariables.cmake)

include(./CMakeHelpers/addBoost.cmake)
include(./CMakeHelpers/functions.cmake)
include(./CMakeHelpers/functionsAddCompilerFlags.cmake)

add_subdirectory(externals)
add_subdirectory(genesis)
add_subdirectory(examples)