//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_state_machine.h" 

#include <memory>

#include "base.h"
#include "t_log_and_throw.h"
#include "i_event_processing_callback.h"
#include "t_composite_state.h"
#include "i_event.h"
#include "t_transition_controller.h"
#include "t_uri.h"
#include "i_region.h"
#include "i_composite_state_fwd.h"
#include "t_behavior.h"
#include "t_constraint.h"
#include "t_transition.h"
#include "t_exception.h"


namespace sxy
{


t_state_machine::t_state_machine
(
	const std::string& p_name,
	i_event_processing_callback* const p_event_processing_callback
):	
	m_name( p_name ),
	m_event_processing_callback( p_event_processing_callback ),
	m_root_state( std::make_unique< t_composite_state >( p_name ) ),
	m_transitions(),
	m_deferred_events(),
	m_state_machine_is_running( false )
{		
	Y_LOG( sxy::t_log_level::LL_DEBUG, "Creating t_state_machine '%'.", p_name );

	if( m_event_processing_callback )
	{
		m_event_processing_callback->add_state_machine_introspection( *this );
	}

	Y_LOG( sxy::t_log_level::LL_DEBUG, "Created t_state_machine '%'.", p_name );
}


t_state_machine::~t_state_machine
(
)
{
	Y_LOG( sxy::t_log_level::LL_DEBUG, "Destroying t_state_machine '%'.", m_name );
	// Nothing to do...
	Y_LOG( sxy::t_log_level::LL_DEBUG, "Destroyed t_state_machine '%'.", m_name );
}


i_composite_state&
t_state_machine::get_root_state
(
)	const
{	
	Y_ASSERT( m_root_state, "No root state!" );
	return( *m_root_state );
}


i_transition&
// cppcheck-suppress unusedFunction
t_state_machine::add_transition
(
	i_transition_uptr p_transition
)
{
	auto& transition = *p_transition;
	
	m_transitions.push_back( std::move( p_transition ) );

	return( transition );
}


i_transition&
t_state_machine::add_transition
(
	const std::string& p_transition_name,
	const t_event_id p_event_id,
	i_vertex& p_source,
	i_vertex& p_target,
	const sxy::t_transition_kind p_kind,
	const t_constraint_function& p_guard,
	const t_behavior_function& p_behavior
)
{	
	auto l_transition = std::make_unique<sxy::t_transition>( p_event_id, p_source, p_target, p_kind, p_transition_name, ( p_guard ? ( t_constraint::create_constraint( p_guard ) ) : nullptr ), ( p_behavior ? ( t_behavior::create_behavior( p_behavior ) ) : nullptr ) );

	auto& transition = *l_transition;
	m_transitions.push_back( std::move( l_transition ) );
	return( transition );
}


i_transition&
t_state_machine::add_transition
(
	const std::string& p_transition_name,
	const t_event_ids p_event_ids,
	i_vertex& p_source,
	i_vertex& p_target,
	const sxy::t_transition_kind p_kind,
	const t_constraint_function& p_guard,
	const t_behavior_function& p_behavior
)
{
	auto l_transition = std::make_unique<sxy::t_transition>( p_event_ids, p_source, p_target, p_kind, p_transition_name, ( p_guard ? ( t_constraint::create_constraint( p_guard ) ) : nullptr ), ( p_behavior ? ( t_behavior::create_behavior( p_behavior ) ) : nullptr ) );

	auto& transition = *l_transition;
	m_transitions.push_back( std::move( l_transition ) );
	return( transition );
}


bool
t_state_machine::fire_event
(
	const t_event_sptr& p_event
)
{
	Y_LOG( t_log_level::LL_INFO, "Firing event '%'.", p_event->get_id() );	
	const auto l_terminate_pseudostate_has_been_reached = process_event( p_event );
	Y_LOG( t_log_level::LL_INFO, "Event '%' has been fired.", p_event->get_id() );
	
	return( l_terminate_pseudostate_has_been_reached );
}


bool
t_state_machine::check
(
	t_state_machine_defects& p_defects
)	const
{
	auto l_check_ok = m_root_state->check( p_defects );

	if(l_check_ok)
	{
		for(const auto& l_transition : m_transitions)
		{
			if(!l_transition->check(p_defects))
			{
				l_check_ok = false;
				break;
			}
		}
	}

	return( l_check_ok );
}


bool
t_state_machine::start_state_machine
(
)
{
	Y_ASSERT( m_root_state, "No root state!" );

	auto l_terminate_pseudostate_has_been_reached = true;

	m_state_machine_is_running = true;

	try
	{

		if( m_event_processing_callback )
		{
			m_event_processing_callback->before_event( COMPLETION_EVENT );
		}

		t_transition_controller transition_controller;
		l_terminate_pseudostate_has_been_reached =
			transition_controller.start_state_machine( *m_root_state, m_event_processing_callback );

		if( m_event_processing_callback )
		{
			m_event_processing_callback->after_event( COMPLETION_EVENT );
		}


		if( l_terminate_pseudostate_has_been_reached )
		{
			Y_LOG( sxy::t_log_level::LL_INFO, "Terminate pseudostate reached. The state machine is stopping." );
			m_state_machine_is_running = false;
		}
	}
	catch( const std::exception& exception )
	{
		Y_LOG( sxy::t_log_level::LL_FATAL, "State machine cannot start: %.", exception.what() );
		m_state_machine_is_running = false;
		throw;
	}
	catch( ... )
	{
		Y_LOG( sxy::t_log_level::LL_FATAL, "State machine can not start: Unknown exception occurred." );
		m_state_machine_is_running = false;
		throw;
	}

	return( l_terminate_pseudostate_has_been_reached );
}
 

bool
t_state_machine::process_event
(		
	const t_event_sptr& p_event
)
{
	Y_ASSERT( m_state_machine_is_running, "State machine is not running!" );

	auto l_terminate_pseudostate_has_been_reached = true;
	Y_LOG( t_log_level::LL_DEBUG, "Starting executing event '%'.", p_event->get_id() );
	try
	{	
			if( m_event_processing_callback )
			{
				m_event_processing_callback->before_event( p_event->get_id() );
			}

			t_transition_controller transition_controller;
			auto l_event_is_deferred = false;
			l_terminate_pseudostate_has_been_reached = transition_controller.process_event( *p_event, *m_root_state, m_event_processing_callback, l_event_is_deferred );
			Y_LOG( t_log_level::LL_DEBUG, "Event '%' has been processed.", p_event->get_id() );

			if( m_event_processing_callback )
			{
				m_event_processing_callback->after_event( p_event->get_id() );
			}

			if( l_terminate_pseudostate_has_been_reached )
			{
				Y_LOG( sxy::t_log_level::LL_FATAL, "An event could not be processed! The state machine is stopping." );
				l_terminate_pseudostate_has_been_reached = false;
				m_state_machine_is_running = false;
			}
			else
			{	 							
				if( l_event_is_deferred )
				{
					add_deferred_event( p_event );
				}
				else
				{
					l_terminate_pseudostate_has_been_reached = process_deferred_events();
				}							
			}
			if( l_terminate_pseudostate_has_been_reached )
			{
				Y_LOG( sxy::t_log_level::LL_FATAL, "An event could not be processed! The state machine is stopping." );
				l_terminate_pseudostate_has_been_reached = false;
				m_state_machine_is_running = false;
			}

	}
	catch( const std::exception& exception )
	{
		Y_LOG( sxy::t_log_level::LL_FATAL, "State machine cannot run: %", exception.what() );				
		m_state_machine_is_running = false;
		throw;
	}
	catch( ... )
	{
		Y_LOG( sxy::t_log_level::LL_FATAL, "State machine cannot run: Unknown exception occured!" );				
		m_state_machine_is_running = false;		
		throw;
	}	 

	return( l_terminate_pseudostate_has_been_reached );
}


const t_events&
// cppcheck-suppress unusedFunction
t_state_machine::get_deferred_events
(
) const
{
	return( m_deferred_events );
}


t_raw_const_states
// cppcheck-suppress unusedFunction
t_state_machine::get_active_state_configuration
(
)	const
{
	t_raw_const_states l_active_state_configuration = {};

	const auto& l_root = get_root_state();	 	
	check_regions_for_active_states( l_active_state_configuration, l_root );

	return( l_active_state_configuration );
}
																				

void
t_state_machine::get_active_states_from_region
(
	t_raw_const_states& p_active_state_configuration,
	const i_region& p_region
)	const
{
	const auto l_active_state = p_region.get_active_state();
	if( l_active_state )
	{
		p_active_state_configuration.push_back( l_active_state );
		check_regions_for_active_states( p_active_state_configuration, *l_active_state );
	}
}


void
t_state_machine::check_regions_for_active_states
(
	t_raw_const_states& p_active_state_configuration,
	const i_state& p_state
) const
{
	for( const auto& l_region : p_state.get_regions() )
	{
		get_active_states_from_region( p_active_state_configuration, *l_region );
	}

}

	
void
t_state_machine::add_deferred_event
(
	const t_event_sptr& p_event_id
)
{
	m_deferred_events.push_back( p_event_id );
}


bool
t_state_machine::process_deferred_events
(
)
{		
	const auto l_deferred_events = m_deferred_events;
	m_deferred_events.clear();

	auto l_terminate_pseudostate_has_been_reached = false;
	t_transition_controller transition_controller;
	for( const auto l_deferred_event : l_deferred_events )
	{			
		if( m_event_processing_callback )
		{
			m_event_processing_callback->before_event( l_deferred_event->get_id() );
		}

		auto l_event_is_deferred = false;		
		l_terminate_pseudostate_has_been_reached = transition_controller.process_event( *l_deferred_event, *m_root_state, m_event_processing_callback, l_event_is_deferred );
		

		if( m_event_processing_callback )
		{
			m_event_processing_callback->after_event( l_deferred_event->get_id() );
		}

		if( l_terminate_pseudostate_has_been_reached )
		{
			Y_LOG( sxy::t_log_level::LL_FATAL, "An event could not be processed! The state machine is stopping." );
			break;
		}
		else
		{
			if( l_event_is_deferred )
			{
				m_deferred_events.push_back( l_deferred_event );
			}
		}
	}

	return( l_terminate_pseudostate_has_been_reached );
}


}
