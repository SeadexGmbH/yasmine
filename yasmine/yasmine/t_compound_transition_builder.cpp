//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_compound_transition_builder.h"

#include "log.h"
#include "i_vertex.h"
#include "i_transition.h"
#include "t_compound_transition.h"
#include "t_try_to_build_compound_transition_visitor.h"
#include "t_event.h"


namespace sxy
{


bool try_to_build_compound_transition( i_transition& p_enabled_transition, 
	t_compound_transitions& p_enabled_compound_transitions, const i_event& p_event )
{
	Y_LOG( t_log_level::LL_TRACE, "Try to build compound transition for transition '%'.",
		p_enabled_transition.get_name() );
	auto built = false;
	t_try_to_build_compound_transition_visitor try_to_build_compound_transition_visitor( p_enabled_transition,
		p_enabled_compound_transitions, built, p_event );
	auto& target_vertex = p_enabled_transition.get_target();
	Y_LOG( t_log_level::LL_SPAM, "Target vertex of transition '%' is '%'.",
		p_enabled_transition.get_name(), target_vertex.get_name() );
	target_vertex.accept_vertex_visitor( try_to_build_compound_transition_visitor );
	if( built )
	{
		Y_LOG( t_log_level::LL_SPAM, "Compound transition built for target vertex '%'.", target_vertex.get_name() );
	}
	else
	{
		Y_LOG( t_log_level::LL_SPAM, "Compound transition not built for target vertex '%'.", target_vertex.get_name() );
	}

	return( built );
}


i_compound_transition_uptr build_compound_transition( i_transition& p_first_transition,	const i_event& p_event )
{
#ifdef _MSC_VER
#if _MSC_VER >= 1900
	auto new_compound_transition = std::make_unique< t_compound_transition >();
#elif _MSC_VER <= 1800
	auto new_compound_transition = std::make_shared< t_compound_transition >();
#endif
#else
	auto new_compound_transition = std::make_unique< t_compound_transition >();
#endif

	Y_LOG( t_log_level::LL_SPAM, "Crate and check transition path for transition '%'.", p_first_transition.get_name() );
	const auto built_compound_transition = new_compound_transition->create_and_check_transition_path( p_first_transition,
		p_event );
	if( !built_compound_transition )
	{
		new_compound_transition = nullptr;
		Y_LOG( t_log_level::LL_SPAM, "Crate and check transition path for transition '%' faild.",
			p_first_transition.get_name() );
	}
	else
	{
		Y_LOG( t_log_level::LL_SPAM, "Crate and check transition path for transition '%' passed (ok).",
			p_first_transition.get_name() );
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
