//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXIT_POINT_FWD_7358F91A_C52C_47DC_9CF0_BB37E354B382
#define EXIT_POINT_FWD_7358F91A_C52C_47DC_9CF0_BB37E354B382


#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class exit_point;
typedef sxe::SX_UNIQUE_PTR< exit_point > exit_point_uptr;
typedef std::vector< exit_point_uptr > exit_points;
typedef std::vector< const exit_point* > raw_const_exit_points;


}


#endif
