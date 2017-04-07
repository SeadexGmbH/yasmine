//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERSION_3B8BFD66_4CAA_4921_88C4_D49899FE2C59
#define VERSION_3B8BFD66_4CAA_4921_88C4_D49899FE2C59


#include "essentials/compatibility/compatibility.hpp"


namespace hermes
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


#endif
