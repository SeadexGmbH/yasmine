//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef PSEUDOSTATE_FWD_64C5B45A_A614_4CE6_8634_E96D6DF41F04
#define PSEUDOSTATE_FWD_64C5B45A_A614_4CE6_8634_E96D6DF41F04


#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class pseudostate;
typedef sxe::SX_UNIQUE_PTR< pseudostate > pseudostate_uptr;
typedef std::vector< pseudostate_uptr > pseudostates;
typedef std::vector< const pseudostate* > raw_const_pseudostates;


}


#endif
