cmake_minimum_required(VERSION 2.8)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()


if(("${Y_STATIC}" STREQUAL "ON") OR ("${SX_STATIC}" STREQUAL "ON"))
                set(LINK_TYPE "STATIC")
else()
                set(LINK_TYPE "SHARED")
endif()
