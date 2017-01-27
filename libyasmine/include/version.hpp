//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERSION_53B7B4DC_2A8B_4736_B190_6348C9D8F8F2
#define VERSION_53B7B4DC_2A8B_4736_B190_6348C9D8F8F2


#include "base.hpp"
#include "compatibility.hpp"


namespace sxy
{


namespace version
{

#ifndef Y_NO_LOGGING

void log_version();

#endif


sxy::uint16_t get_major_version();
sxy::uint16_t get_minor_version();
sxy::uint16_t get_patch_version();
sxy::uint16_t get_build_number();


}


}


#endif
