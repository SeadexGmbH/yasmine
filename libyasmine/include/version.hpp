//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERSION_53B7B4DC_2A8B_4736_B190_6348C9D8F8F2
#define VERSION_53B7B4DC_2A8B_4736_B190_6348C9D8F8F2


#include "essentials/base.hpp"
#include "essentials/compatibility/compatibility.hpp"
#include "hermes/hermes_backward_compatibility.hpp"


namespace sxy
{


namespace version
{

#ifndef SX_NO_LOGGING

void log_version();

#endif


sxe::uint16_t get_major_version();
sxe::uint16_t get_minor_version();
sxe::uint16_t get_patch_version();
sxe::uint16_t get_build_number();


}


}


#endif
