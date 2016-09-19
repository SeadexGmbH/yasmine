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
#include <memory>


namespace sxy
{


class compound_transition;
class compound_transition_consumer;


#ifdef _MSC_VER
#if _MSC_VER >= 1900
using compound_transition_uptr = std::unique_ptr< compound_transition >;
#elif _MSC_VER <= 1800
using compound_transition_uptr = std::shared_ptr< compound_transition >;
#endif
#else
using compound_transition_uptr = std::unique_ptr< compound_transition >;
#endif


using raw_compound_transitions = std::vector< compound_transition* >;
using compound_transitions = std::vector< compound_transition_uptr >;


}


#endif
