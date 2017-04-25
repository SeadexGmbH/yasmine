//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

#include "essentials/sxprintf.hpp"

#include "version.hpp"
#include "build_number.hpp"


namespace sx
{


namespace genesis
{


namespace version
{


namespace
{


const sxe::uint16_t VERSION_MAJOR( 0 );
const sxe::uint16_t VERSION_MINOR( 2 );
const sxe::uint16_t VERSION_PATCH( 0 );


}


// cppcheck-suppress unusedFunction
void log_version()
{
	std::cout << sxe::sxprintf( "genesis library version %.%.%.%.", get_major_version(),
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


}
