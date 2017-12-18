//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

#include "essentials/compatibility/compatibility.hpp"
#include "essentials/sxprintf.hpp"

#include "hermes/hermes_version.hpp"
#include "hermes/build_number.hpp"


namespace hermes
{


namespace version
{


namespace
{


const sxe::uint16_t VERSION_MAJOR( 1 );
const sxe::uint16_t VERSION_MINOR( 2 );
const sxe::uint16_t VERSION_PATCH( 0 );


}


// cppcheck-suppress unusedFunction
void log_version()
{
	std::cout << sxe::sxprintf( "hermes library version %.%.%.%.", hermes::version::get_major_version(),
		hermes::version::get_minor_version(), hermes::version::get_patch_version(), hermes::version::get_build_number() )
		<< std::endl;
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
	return( hermes::version::BUILD_NUMBER );
}


}


}
