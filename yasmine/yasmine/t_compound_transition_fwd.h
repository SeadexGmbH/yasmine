//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_COMPOUND_TRANSITON_FWD
#define T_COMPOUND_TRANSITON_FWD


#include <vector>
#include <memory>


namespace sxy
{


class i_compound_transition;
class i_compound_transition_consumer;


#ifdef _MSC_VER
#if _MSC_VER >= 1900
using i_compound_transition_uptr = std::unique_ptr< i_compound_transition >;
#elif _MSC_VER <= 1800
using i_compound_transition_uptr = std::shared_ptr< i_compound_transition >;
#endif
#else
using i_compound_transition_uptr = std::unique_ptr< i_compound_transition >;
#endif
									

using t_raw_compound_transitions = std::vector< i_compound_transition* >;
using t_compound_transitions = std::vector< i_compound_transition_uptr >;


}


#endif
