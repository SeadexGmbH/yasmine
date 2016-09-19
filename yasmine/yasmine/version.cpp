//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

#include "version.h"
#include "build_number.h"
#include "log.h"


namespace yasmine
{


namespace version
{


namespace
{


constexpr std::uint16_t g_version_major( 0 );
constexpr std::uint16_t g_version_minor( 1 );
constexpr std::uint16_t g_version_patch( 0 );


}


void
// cppcheck-suppress unusedFunction
log_version
(
)
{
	Y_LOG( sxy::t_log_level::LL_INFO, "yasmine library version %.%.%.%.", get_major_version(), get_minor_version(), get_patch_version(), get_build_number() );
}


std::uint16_t
get_major_version
(
)
{
	return( g_version_major );
}


std::uint16_t
get_minor_version
(
)
{
	return( g_version_minor );
}


std::uint16_t
get_patch_version
(
)
{
	return( g_version_patch );
}


std::uint16_t
get_build_number
(
)
{
	return( g_build_number );
}


}


}
