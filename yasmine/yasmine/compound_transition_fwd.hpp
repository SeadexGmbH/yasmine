//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOUND_TRANSITION_FWD_79254C3C_069E_410C_93A7_AD53E8D21487
#define COMPOUND_TRANSITION_FWD_79254C3C_069E_410C_93A7_AD53E8D21487


#include <vector>

#include "compatibility.hpp"


namespace sxy
{


class compound_transition;
class compound_transition_consumer;


typedef sxy::Y_UNIQUE_PTR< compound_transition > compound_transition_uptr;

typedef std::vector< compound_transition* > raw_compound_transitions;
typedef std::vector< compound_transition_uptr > compound_transitions;


}


#endif
