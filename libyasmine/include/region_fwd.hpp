//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef REGION_FWD_DFB0F2A6_B441_4314_BB3D_18DCDE9ADF7B
#define REGION_FWD_DFB0F2A6_B441_4314_BB3D_18DCDE9ADF7B


#include <vector>
#include <set>

#include "compatibility.hpp"


namespace sxy
{


class region;
typedef Y_UNIQUE_PTR< region > region_uptr;
typedef std::vector< region_uptr > regions;
typedef std::vector< region* > raw_regions;
typedef std::set< const region* > raw_const_region_set;


}


#endif
