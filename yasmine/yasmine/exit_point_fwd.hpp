//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXIT_POINT_FWD_7358F91A_C52C_47DC_9CF0_BB37E354B382
#define EXIT_POINT_FWD_7358F91A_C52C_47DC_9CF0_BB37E354B382


#include <vector>
#include <memory>


namespace sxy
{


class exit_point;
using exit_point_uptr = std::unique_ptr< exit_point >;
using exit_points = std::vector< exit_point_uptr >;
using raw_const_exit_points = std::vector< const exit_point* >;


}


#endif
