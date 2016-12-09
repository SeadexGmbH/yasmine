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

#include "version.hpp"
#include "build_number.hpp"
#include "log.hpp"
#include "compatibility.hpp"


namespace yasmine
{


namespace version
{


namespace
{


const sxy::uint16_t VERSION_MAJOR( 0 );
const sxy::uint16_t VERSION_MINOR( 6 );
const sxy::uint16_t VERSION_PATCH( 0 );


}


#ifndef Y_NO_LOGGING

// cppcheck-suppress unusedFunction
void log_version()
{
	Y_LOG( sxy::log_level::LL_INFO, "yasmine library version %.%.%.%.", get_major_version(),
		get_minor_version(), get_patch_version(), get_build_number() );
}


#endif

sxy::uint16_t get_major_version()
{
	return( VERSION_MAJOR );
}


sxy::uint16_t get_minor_version()
{
	return( VERSION_MINOR );
}


sxy::uint16_t get_patch_version()
{
	return( VERSION_PATCH );
}


sxy::uint16_t get_build_number()
{
	return( BUILD_NUMBER );
}


}


}
