//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ENTRY_POINT_FWD_058240BC_C6BC_49D2_AEB5_CFF4935EC599
#define ENTRY_POINT_FWD_058240BC_C6BC_49D2_AEB5_CFF4935EC599


#include <vector>
#include <memory>


namespace sxy
{


class entry_point;
using entry_point_uptr = std::unique_ptr< entry_point >;
using entry_points = std::vector< entry_point_uptr >;
using raw_const_entry_points = std::vector< const entry_point* >;


}


#endif
