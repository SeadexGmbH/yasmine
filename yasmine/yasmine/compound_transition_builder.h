//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOUND_TRANSITION_BUILDER_C7111HB4_8573_9C38_866E_6GG11C57C802
#define COMPOUND_TRANSITION_BUILDER_C7111HB4_8573_9C38_866E_6GG11C57C802


#include "compound_transition_fwd.h"


namespace sxy
{


class transition;
class event;


bool try_to_build_compound_transition( transition& _enabled_transition,
	compound_transitions& _enabled_compound_transitions,	const event& _event );
compound_transition_uptr build_compound_transition( transition& _first_transition, const event& _event );


}


#endif
