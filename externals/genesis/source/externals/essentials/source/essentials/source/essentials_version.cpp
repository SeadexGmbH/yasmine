//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "essentials/essentials_version.hpp"

#include <iostream>

#include "essentials/compatibility/compatibility.hpp"
#include "essentials/build_number.hpp"
#include "essentials/sxprintf.hpp"


namespace sxe
{


namespace version
{


namespace
{


const sxe::uint16_t VERSION_MAJOR( 1 );
const sxe::uint16_t VERSION_MINOR( 3 );
const sxe::uint16_t VERSION_PATCH( 2 );


}


// cppcheck-suppress unusedFunction
void log_version()
{
	std::cout << sxe::sxprintf( "essentials library version %.%.%.%.", get_major_version(),
		get_minor_version(), get_patch_version(), get_build_number() ) << std::endl;
}


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
