//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_EXIT_POINT_FWD_7358F91A_C52C_47DC_9CF0_BB37E354B382
#define I_EXIT_POINT_FWD_7358F91A_C52C_47DC_9CF0_BB37E354B382


#include <vector>
#include <memory>


namespace sxy
{


class i_exit_point;
using i_exit_point_uptr = std::unique_ptr< i_exit_point >;
using t_exit_points = std::vector< i_exit_point_uptr >;
using t_raw_const_exit_points = std::vector< const i_exit_point* >;


}


#endif
