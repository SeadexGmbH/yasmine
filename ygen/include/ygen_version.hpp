//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef YGEN_VERSION_222818B9_7102_4223_9009_208C9C53544A
#define YGEN_VERSION_222818B9_7102_4223_9009_208C9C53544A


#include "essentials/compatibility/compatibility.hpp"


namespace version
{


void log_version();


sxe::uint16_t get_major_version();
sxe::uint16_t get_minor_version();
sxe::uint16_t get_patch_version();
sxe::uint16_t get_build_number();


}


#endif
