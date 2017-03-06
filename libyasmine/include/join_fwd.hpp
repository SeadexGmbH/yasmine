//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef JOIN_FWD_62FA1B0B_2997_4645_A325_BD9ED4C1EC7D
#define JOIN_FWD_62FA1B0B_2997_4645_A325_BD9ED4C1EC7D


#include <vector>

#include "compatibility.hpp"


namespace sxy
{


class join;
typedef Y_UNIQUE_PTR< join > join_uptr;
typedef std::vector< join_uptr > joins;
typedef std::vector< const join* > raw_const_joins;


}


#endif
