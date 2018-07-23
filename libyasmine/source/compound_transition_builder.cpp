//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "compound_transition_builder.hpp"

#include "hermes/log.hpp"

#include "vertex.hpp"
#include "transition.hpp"
#include "compound_transition_impl.hpp"
#include "try_to_build_compound_transition_visitor.hpp"
#include "event_impl.hpp"


namespace sxy
{


bool try_to_build_compound_transition( transition& _enabled_transition, 
	compound_transitions& _enabled_compound_transitions, const event& _event, event_collector& _event_collector )
{
	SX_LOG( hermes::log_level::LL_TRACE, "Trying to build compound transition for transition '%'.",
		_enabled_transition.get_name() );
	bool built = false;
	try_to_build_compound_transition_visitor try_to_build_compound_transition_visitor( _enabled_transition,
		_enabled_compound_transitions, built, _event, _event_collector );
	const vertex& target_vertex = _enabled_transition.get_target();
	SX_LOG( hermes::log_level::LL_SPAM, "Target vertex of transition '%' is '%'.",
		_enabled_transition.get_name(), target_vertex.get_name() );
	target_vertex.accept_vertex_visitor( try_to_build_compound_transition_visitor );
	if( built )
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Compound transition built for target vertex '%'.", target_vertex.get_name() );
	}
	else
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Compound transition not built for target vertex '%'.", target_vertex.get_name() );
	}

	return( built );
}


compound_transition_uptr build_compound_transition( transition& _first_transition,	const event& _event, 
	event_collector& _event_collector )
{
	compound_transition_uptr new_compound_transition = SX_MAKE_UNIQUE< compound_transition_impl >();

	SX_LOG( hermes::log_level::LL_SPAM, "Create and check transition path for transition '%'.", _first_transition.get_name() );
	const bool built_compound_transition = new_compound_transition->create_and_check_transition_path( _first_transition,
		_event, _event_collector );
	if( !built_compound_transition )
	{
		new_compound_transition.reset();
		SX_LOG( hermes::log_level::LL_SPAM, "Create and check transition path for transition '%' failed.",
			_first_transition.get_name() );
	}
	else
	{
		SX_LOG( hermes::log_level::LL_SPAM, "Create and check transition path for transition '%' succeeded.",
			_first_transition.get_name() );
	}

	return( new_compound_transition );
}


}
