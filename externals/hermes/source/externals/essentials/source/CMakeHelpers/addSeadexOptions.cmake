cmake_minimum_required(VERSION 2.8)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

# Seadex preprocessor definitions


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


option("SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG" "Sets to use a workaround for bug in GCC with expansion of template parameter pack that appears in a lambda-expression (bug reported for GCC 4.8.4)")	
if( "${SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG}" )
	set(extra_flags "${extra_flags} -D \"SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG\"")
	message(STATUS "SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG is defined.")
endif()