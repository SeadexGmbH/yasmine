//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERSION_11BB60D2_9C1A_4102_BBCC_0486F61F9C1C
#define VERSION_11BB60D2_9C1A_4102_BBCC_0486F61F9C1C


#include "essentials/compatibility/compatibility.hpp"


namespace sx
{


namespace genesis
{


namespace version
{


void log_version();


sxe::uint16_t get_major_version();
sxe::uint16_t get_minor_version();
sxe::uint16_t get_patch_version();
sxe::uint16_t get_build_number();


}


}


}


#endif
