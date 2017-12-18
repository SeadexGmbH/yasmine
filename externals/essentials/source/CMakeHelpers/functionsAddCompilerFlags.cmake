cmake_minimum_required(VERSION 2.8)

include(CheckCXXCompilerFlag)


function(add_compiler_flag varFlag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${varFlag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${varFlag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${varFlag}" PARENT_SCOPE)
        endif()
        unset(flag_supported CACHE)
    endif()
endfunction()
