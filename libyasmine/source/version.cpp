//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "hermes/log.hpp"
#include "version.hpp"
#include "build_number.hpp"


namespace sxy
{


namespace version
{


namespace
{


const sxe::uint16_t VERSION_MAJOR( 1 );
const sxe::uint16_t VERSION_MINOR( 3 );
const sxe::uint16_t VERSION_PATCH( 5 );


}


#ifndef SX_NO_LOGGING


// cppcheck-suppress unusedFunction
void log_version()
{
	SX_LOG( hermes::log_level::LL_INFO, "yasmine library version %.%.%.%.", get_major_version(),
		get_minor_version(), get_patch_version(), get_build_number() );
}


#endif

sxe::uint16_t get_major_version()
{
	return( VERSION_MAJOR );
}


sxe::uint16_t get_minor_version()
{
	return( VERSION_MINOR );
}


sxe::uint16_t get_patch_version()
{
	return( VERSION_PATCH );
}


sxe::uint16_t get_build_number()
{
	return( BUILD_NUMBER );
}


}


}
