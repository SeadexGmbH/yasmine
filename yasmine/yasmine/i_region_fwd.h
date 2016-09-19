//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_REGION_FWD_DFB0F2A6_B441_4314_BB3D_18DCDE9ADF7B
#define I_REGION_FWD_DFB0F2A6_B441_4314_BB3D_18DCDE9ADF7B


#include <vector>
#include <set>
#include <memory>


namespace sxy
{


class i_region;
using i_region_uptr = std::unique_ptr< i_region >;
using t_raw_regions = std::vector< i_region* >;
using t_regions = std::vector< i_region_uptr >;
using t_raw_const_region_set = std::set< const i_region* >;


}


#endif
