//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TERMINATE_PSEUDOSTATE_FWD_C63AEEFF_DBF1_44D5_961A_A2E4D0BB745B
#define TERMINATE_PSEUDOSTATE_FWD_C63AEEFF_DBF1_44D5_961A_A2E4D0BB745B


#include <vector>

#include "compatibility.hpp"


namespace sxy
{


class terminate_pseudostate;
typedef Y_UNIQUE_PTR< terminate_pseudostate > terminate_pseudostate_uptr;
typedef std::vector< terminate_pseudostate_uptr > terminate_pseudostates;
typedef std::vector< const terminate_pseudostate* > raw_const_terminate_pseudostates;


}


#endif
