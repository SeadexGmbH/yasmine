//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_COMPOUND_TRANSITION_BUILDER_C7111HB4_8573_9C38_866E_6GG11C57C802
#define T_COMPOUND_TRANSITION_BUILDER_C7111HB4_8573_9C38_866E_6GG11C57C802


#include "t_compound_transition_fwd.h"


namespace sxy
{


class i_transition;
class i_event;


bool try_to_build_compound_transition( i_transition& p_enabled_transition,
	t_compound_transitions& p_enabled_compound_transitions,	const i_event& p_event );
i_compound_transition_uptr build_compound_transition( i_transition& p_first_transition, const i_event& p_event );
}


#endif
