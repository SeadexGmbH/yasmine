//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ENTRY_POINT_FWD_058240BC_C6BC_49D2_AEB5_CFF4935EC599
#define ENTRY_POINT_FWD_058240BC_C6BC_49D2_AEB5_CFF4935EC599


#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class entry_point;
typedef sxe::SX_UNIQUE_PTR< entry_point > entry_point_uptr;
typedef std::vector< entry_point_uptr > entry_points;
typedef std::vector< const entry_point* > raw_const_entry_points;


}


#endif
