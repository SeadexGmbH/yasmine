//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "compound_transition_builder.hpp"

#include "log.hpp"
#include "vertex.hpp"
#include "transition.hpp"
#include "compound_transition_impl.hpp"
#include "try_to_build_compound_transition_visitor.hpp"
#include "event_impl.hpp"


namespace sxy
{


bool try_to_build_compound_transition( transition& _enabled_transition, 
	compound_transitions& _enabled_compound_transitions, const event& _event )
{
	Y_LOG( log_level::LL_TRACE, "Trying to build compound transition for transition '%'.",
		_enabled_transition.get_name() );
	bool built = false;
	try_to_build_compound_transition_visitor try_to_build_compound_transition_visitor( _enabled_transition,
		_enabled_compound_transitions, built, _event );
	const vertex& target_vertex = _enabled_transition.get_target();
	Y_LOG( log_level::LL_SPAM, "Target vertex of transition '%' is '%'.",
		_enabled_transition.get_name(), target_vertex.get_name() );
	target_vertex.accept_vertex_visitor( try_to_build_compound_transition_visitor );
	if( built )
	{
		Y_LOG( log_level::LL_SPAM, "Compound transition built for target vertex '%'.", target_vertex.get_name() );
	}
	else
	{
		Y_LOG( log_level::LL_SPAM, "Compound transition not built for target vertex '%'.", target_vertex.get_name() );
	}

	return( built );
}


compound_transition_uptr build_compound_transition( transition& _first_transition,	const event& _event )
{
#ifdef _MSC_VER
#if _MSC_VER >= 1900
	Y_UNIQUE_PTR< compound_transition_impl > new_compound_transition = Y_MAKE_UNIQUE< compound_transition_impl >();
#elif _MSC_VER <= 1800
	sxy::shared_ptr< compound_transition_impl > new_compound_transition = Y_MAKE_SHARED< compound_transition_impl >();
#endif
#else
	Y_UNIQUE_PTR< compound_transition_impl > new_compound_transition = Y_MAKE_UNIQUE< compound_transition_impl >();
#endif

	Y_LOG( log_level::LL_SPAM, "Create and check transition path for transition '%'.", _first_transition.get_name() );
	const bool built_compound_transition = new_compound_transition->create_and_check_transition_path( _first_transition,
		_event );
	if( !built_compound_transition )
	{
		new_compound_transition.reset();
		Y_LOG( log_level::LL_SPAM, "Create and check transition path for transition '%' failed.",
			_first_transition.get_name() );
	}
	else
	{
		Y_LOG( log_level::LL_SPAM, "Create and check transition path for transition '%' succeeded.",
			_first_transition.get_name() );
	}

#ifdef _MSC_VER
#if _MSC_VER >= 1900
	return( sxy::move( new_compound_transition ) );
#elif _MSC_VER <= 1800
	return( new_compound_transition );
#endif
#else
	return( sxy::move( new_compound_transition ) );
#endif
}


}
