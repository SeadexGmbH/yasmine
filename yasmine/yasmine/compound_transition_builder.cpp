//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "compound_transition_builder.h"

#include "log.h"
#include "vertex.h"
#include "transition.h"
#include "compound_transition_impl.h"
#include "try_to_build_compound_transition_visitor.h"
#include "event_impl.h"


namespace sxy
{


bool try_to_build_compound_transition( transition& _enabled_transition, 
	compound_transitions& _enabled_compound_transitions, const event& _event )
{
	Y_LOG( log_level::LL_TRACE, "Try to build compound transition for transition '%'.",
		_enabled_transition.get_name() );
	auto built = false;
	try_to_build_compound_transition_visitor try_to_build_compound_transition_visitor( _enabled_transition,
		_enabled_compound_transitions, built, _event );
	auto& target_vertex = _enabled_transition.get_target();
	Y_LOG( log_level::LL_SPAM, "Target vertex of transition '%' is '%'.",
		_enabled_transition.get_name(), target_vertex.get_name() );
	target_vertex.accept_vertex_visitor( try_to_build_compound_transition_visitor );
	auto message = yprintf( "Compound transition not built for target vertex '%'.", target_vertex.get_name() );
	if( built )
	{
		message = yprintf( "Compound transition built for target vertex '%'.", target_vertex.get_name() );
	}
	Y_LOG( log_level::LL_SPAM, message );

	return( built );
}


compound_transition_uptr build_compound_transition( transition& _first_transition,	const event& _event )
{
#ifdef _MSC_VER
#if _MSC_VER >= 1900
	auto new_compound_transition = std::make_unique< compound_transition_impl >();
#elif _MSC_VER <= 1800
	auto new_compound_transition = std::make_shared< compound_transition_impl >();
#endif
#else
	auto new_compound_transition = std::make_unique< compound_transition_impl >();
#endif

	Y_LOG( log_level::LL_SPAM, "Crate and check transition path for transition '%'.", _first_transition.get_name() );
	const auto built_compound_transition = new_compound_transition->create_and_check_transition_path( _first_transition,
		_event );
	if( !built_compound_transition )
	{
		new_compound_transition = nullptr;
		Y_LOG( log_level::LL_SPAM, "Crate and check transition path for transition '%' faild.",
			_first_transition.get_name() );
	}
	else
	{
		Y_LOG( log_level::LL_SPAM, "Crate and check transition path for transition '%' passed (ok).",
			_first_transition.get_name() );
	}

#ifdef _MSC_VER
#if _MSC_VER >= 1900
	return( std::move( new_compound_transition ) );
#elif _MSC_VER <= 1800
	return( new_compound_transition );
#endif
#else
	return( std::move( new_compound_transition ) );
#endif
}


}
