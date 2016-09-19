//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_build_transition_steps_visitor.h"

#include "base.h"
#include "t_log_and_throw.h"


#include "i_composite_state.h"

#include "i_join.h"
#include "i_fork.h"
#include "i_shallow_history.h"
#include "i_deep_history.h"
#include "i_junction.h"
#include "i_entry_point.h"
#include "i_exit_point.h"

#include "i_transition.h"

#include "t_simple_transition_step.h"
#include "t_compound_transition_step.h"


namespace sxy
{


t_build_transition_steps_visitor::t_build_transition_steps_visitor
(
	i_transition& p_current_transition,
	t_transition_steps& p_transitions_steps,
	const i_event& p_event
):
	i_const_vertex_visitor(),
	m_current_transition( p_current_transition ),
	m_transition_steps( p_transitions_steps ),
	m_next_transition( nullptr ),
	m_reached_end_of_transition( true ),
	m_event( p_event )
{
	// Nothing to do...
}


t_build_transition_steps_visitor::~t_build_transition_steps_visitor
(
) = default;


void
t_build_transition_steps_visitor::visit
(
	const i_composite_state& p_composite_state
)
{
	Y_UNUSED_PARAMETER( p_composite_state );

	create_simple_transition_step();
}


void
t_build_transition_steps_visitor::visit
(
	const i_simple_state& p_simple_state
)
{
	Y_UNUSED_PARAMETER( p_simple_state );

	create_simple_transition_step();
}


void
t_build_transition_steps_visitor::visit
(
	const i_final_state& p_final_state
)
{
	Y_UNUSED_PARAMETER( p_final_state );

	create_simple_transition_step();
}


void
t_build_transition_steps_visitor::visit
(
	const i_initial_pseudostate& p_initial_pseudostate
)
{
	Y_UNUSED_PARAMETER( p_initial_pseudostate );

	Y_ASSERT( false, "An initial pseudo state cannot be the target of a transition!" );
}


void
t_build_transition_steps_visitor::visit
(
	const i_choice& p_choice
)
{
	Y_UNUSED_PARAMETER( p_choice );

	create_simple_transition_step();
}


void
t_build_transition_steps_visitor::visit
(
	const i_junction& p_junction
)
{
	handle_as_junction( p_junction );
}


void
t_build_transition_steps_visitor::visit
(
	const i_join& p_join
)
{
	handle_as_join( p_join );
}


void
t_build_transition_steps_visitor::visit
(
	const i_fork& p_fork
)
{
	handle_as_fork( p_fork );
}


void
t_build_transition_steps_visitor::visit
(
	const i_entry_point& p_entry_point
)
{
	handle_entry_point( p_entry_point );	
}


void
t_build_transition_steps_visitor::visit
(
	const i_exit_point& p_exit_point
)
{
	handle_exit_point( p_exit_point );	
}


void
t_build_transition_steps_visitor::visit
(
	const i_deep_history& p_deep_history
)
{
	handle_history_pseudostate( p_deep_history );
}


void
t_build_transition_steps_visitor::visit
(
	const i_shallow_history& p_shallow_history
)
{
	handle_history_pseudostate( p_shallow_history );
}


void
t_build_transition_steps_visitor::visit
(
	const i_terminate_pseudostate& p_terminate_pseudostate
)
{
	Y_UNUSED_PARAMETER( p_terminate_pseudostate );

	auto simple_step = std::make_unique<t_simple_transition_step>( m_current_transition );
	m_transition_steps.push_back( std::move( simple_step ) );
}


i_transition* 
t_build_transition_steps_visitor::get_next_transition
(
)	const 
{
	return( m_next_transition );
}


bool
t_build_transition_steps_visitor::reached_end_of_transition
(
) const
{
	return( m_reached_end_of_transition );
}


i_transition* 
t_build_transition_steps_visitor::find_next_transition
(
	const i_pseudostate& p_target_pseudostate,
	const i_event& p_event
)
{
	i_transition* enabled_transition = nullptr;

	const auto& transitions = p_target_pseudostate.get_outgoing_transitions();

	for( const auto& transition : transitions )
	{
		const auto guard_is_ok = transition->check_guard( p_event );
		if( guard_is_ok )
		{
			enabled_transition = transition ;
			break;
		}
	}

	if( nullptr == enabled_transition )
	{
		m_reached_end_of_transition = false;
	}

	return( enabled_transition );
}


t_raw_transitions
t_build_transition_steps_visitor::get_default_transition_if_state_was_not_active_before
(
	const i_history& p_history
)
{
	t_raw_transitions default_transitions = {};

	const auto& state_was_active_before = p_history.check_if_state_was_active_before();

	if( !state_was_active_before )
	{
		default_transitions = p_history.get_default_transitions();
		if( default_transitions.empty() )
		{	
			LOG_AND_THROW( t_log_level::LL_FATAL, "History pseudostate '%' has no default transition!", p_history.get_name() );
		}
	}

	return( default_transitions );
}


void
t_build_transition_steps_visitor::handle_history_pseudostate
(
	const i_history& p_history
)
{
	auto simple_step = std::make_unique<t_simple_transition_step>( m_current_transition );

	m_transition_steps.push_back( std::move( simple_step ) );

	const auto default_transitions = get_default_transition_if_state_was_not_active_before( p_history );
	if( !default_transitions.empty() )
	{
		for( const auto default_transition : default_transitions )
		{
			auto default_step = std::make_unique<t_simple_transition_step>( *default_transition );
			m_transition_steps.push_back( std::move( default_step ) );
		}
	}	
}


void
t_build_transition_steps_visitor::handle_as_junction
(
	const i_pseudostate& p_pseudostate
)
{
	auto simple_step = std::make_unique<t_simple_transition_step>( m_current_transition );

	m_transition_steps.push_back( std::move( simple_step ) );
	m_next_transition = find_next_transition( p_pseudostate, m_event );
	if(!m_next_transition)
	{
		LOG_AND_THROW( t_log_level::LL_FATAL, "There is no enabled transition for the junction '%'!", p_pseudostate.get_name() );		
	}
}


void
t_build_transition_steps_visitor::handle_as_fork
(
	const i_pseudostate& p_pseudostate
) const
{
	auto simple_step = std::make_unique<t_simple_transition_step>( m_current_transition );

	m_transition_steps.push_back( std::move( simple_step ) );

	const auto& exiting_transitions = p_pseudostate.get_outgoing_transitions();
	t_raw_transitions transitions_of_fork;
	for( const auto& transition : exiting_transitions )
	{
		transitions_of_fork.push_back( transition );
	}

	auto final_step = std::make_unique<t_compound_transition_step>( transitions_of_fork );

	m_transition_steps.push_back( std::move( final_step ) );
}


void
t_build_transition_steps_visitor::handle_as_join
(
	const i_pseudostate& p_pseudostate
)
{
	const auto& incoming_transitions = p_pseudostate.get_incoming_transitions();

	auto step = std::make_unique<t_compound_transition_step>( incoming_transitions );

	m_transition_steps.push_back( std::move( step ) );
	m_next_transition = find_next_transition( p_pseudostate, m_event );
}


void
t_build_transition_steps_visitor::handle_entry_point
(
	const i_entry_point& p_entry_point
)
{
	const auto& parent_state = p_entry_point.get_parent_state();

	const auto is_orthogonal = parent_state.is_orthogonal();
	if( is_orthogonal )
	{
		handle_as_fork( p_entry_point );
	}
	else
	{
		handle_as_junction( p_entry_point );
	}
}


void
t_build_transition_steps_visitor::handle_exit_point
(
	const i_exit_point& p_exit_point
)
{
	const auto& parent_state = p_exit_point.get_parent_state();

	const auto is_orthogonal = parent_state.is_orthogonal();
	if( is_orthogonal )
	{
		handle_as_join( p_exit_point );
	}
	else
	{
		handle_as_junction( p_exit_point );
	}
}


void 
t_build_transition_steps_visitor::create_simple_transition_step
(
)
{
	auto simple_step = std::make_unique<t_simple_transition_step>( m_current_transition );

	m_transition_steps.push_back( std::move( simple_step ) );
}


}
