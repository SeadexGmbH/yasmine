//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LIBYGEN_VERSION_53D2B2F3_5C60_4E6A_8DB5_20E64ED9A906
#define LIBYGEN_VERSION_53D2B2F3_5C60_4E6A_8DB5_20E64ED9A906


#include "essentials/compatibility/compatibility.hpp"


namespace sxy
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
