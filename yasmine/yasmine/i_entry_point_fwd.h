//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_ENTRY_POINT_FWD_058240BC_C6BC_49D2_AEB5_CFF4935EC599
#define I_ENTRY_POINT_FWD_058240BC_C6BC_49D2_AEB5_CFF4935EC599


#include <vector>
#include <memory>


namespace sxy
{


class i_entry_point;
using i_entry_point_uptr = std::unique_ptr< i_entry_point >;
using t_entry_points = std::vector< i_entry_point_uptr >;
using t_raw_const_entry_points = std::vector< const i_entry_point* >;


}


#endif
