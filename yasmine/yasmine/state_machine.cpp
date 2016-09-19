//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_machine.h"

#include <memory>

#include "base.h"
#include "log_and_throw.h"
#include "event_processing_callback.h"
#include "composite_state_impl.h"
#include "event_impl.h"
#include "transition_controller.h"
#include "uri.h"
#include "region.h"
#include "composite_state_fwd.h"
#include "behavior_impl.h"
#include "constraint_impl.h"
#include "transition_impl.h"
#include "exception.h"
#include "async_simple_state_impl.h"


namespace sxy
{


state_machine::state_machine( const std::string& _name,
	event_processing_callback* const _event_processing_callback )
	: name_( _name ),
		event_processing_callback_( _event_processing_callback ),
		root_state_( std::make_unique< composite_state_impl >( _name ) ),
		transitions_(),
		deferred_events_(),
		state_machine_is_running_( false )
{
	Y_LOG( sxy::log_level::LL_DEBUG, "Creating state_machine '%'.", _name );
	if( event_processing_callback_ )
	{
		event_processing_callback_->add_state_machine_introspection( *this );
	}

	Y_LOG( sxy::log_level::LL_DEBUG, "Created state_machine '%'.", _name );
}


state_machine::~state_machine()
{
	Y_ASSERT( !state_machine_is_running_, "State machine is still running on destructor call!" );
	Y_LOG( sxy::log_level::LL_DEBUG, "Destroyed state_machine '%'.", name_ );
}


composite_state& state_machine::get_root_state() const
{
	Y_ASSERT( root_state_, "No root state!" );
	return( *root_state_ );
}


// cppcheck-suppress unusedFunction
transition& state_machine::add_transition( transition_uptr _transition )
{
	auto& transition = *_transition;
	transitions_.push_back( std::move( _transition ) );
	return( transition );
}


transition& state_machine::add_transition( const std::string& _transition_name, const event_id _event_id,
	vertex& _source, vertex& _target, const sxy::transition_kind _kind, const constraint_function& _guard,
	const behavior_function& _behavior )
{
	auto l_transition =
		std::make_unique< sxy::transition_impl >( _event_id, _source, _target, _kind, _transition_name,
			( _guard ? ( constraint_impl::create_constraint( _guard ) ) : nullptr ),
			( _behavior ? ( behavior_impl::create_behavior( _behavior ) ) : nullptr ) );
	auto& transition = *l_transition;
	transitions_.push_back( std::move( l_transition ) );
	return( transition );
}


transition& state_machine::add_transition( const std::string& _transition_name, const event_ids _event_ids,
	vertex& _source, vertex& _target, const sxy::transition_kind _kind, const constraint_function& _guard,
	const behavior_function& _behavior )
{
	auto l_transition =
		std::make_unique< sxy::transition_impl >( _event_ids, _source, _target, _kind, _transition_name,
			( _guard ? ( constraint_impl::create_constraint( _guard ) ) : nullptr ),
			( _behavior ? ( behavior_impl::create_behavior( _behavior ) ) : nullptr ) );
	auto& transition = *l_transition;
	transitions_.push_back( std::move( l_transition ) );
	return( transition );
}


bool state_machine::fire_event( const event_sptr& _event )
{
	Y_LOG( log_level::LL_INFO, "Firing event '%'.", _event->get_id() );
	const auto terminate_pseudostate_has_been_reached = process_event( _event, nullptr );
	Y_LOG( log_level::LL_INFO, "Event '%' has been fired.", _event->get_id() );
	return( terminate_pseudostate_has_been_reached );
}


bool state_machine::check( state_machine_defects& _defects ) const
{

	auto check_ok = root_state_->check( _defects );
	if( check_ok )
	{
		for( const auto & transition : transitions_ )
		{
			if( !transition->check( _defects ) )
			{
				check_ok = false;
				break;
			}
		}
	}

	return( check_ok );
}


bool state_machine::start_state_machine()
{
	return ( start_state_machine( nullptr ) );
}


void state_machine::stop_state_machine()
{		 
	Y_ASSERT( state_machine_is_running_, "State machine is not running!" );
	stop_all_async_states( *root_state_ );
	state_machine_is_running_ = false;
}


bool state_machine::start_state_machine( async_event_handler* const _async_event_handler )
{
	Y_ASSERT( root_state_, "No root state!" );
	auto terminate_pseudostate_has_been_reached = true;
	state_machine_is_running_ = true;
	try
	{
		if( event_processing_callback_ )
		{
			event_processing_callback_->before_event( COMPLETION_EVENT );
		}

		transition_controller transition_controller;
		terminate_pseudostate_has_been_reached = transition_controller.start_state_machine( *root_state_,
			event_processing_callback_, _async_event_handler );
		if( event_processing_callback_ )
		{
			event_processing_callback_->after_event( COMPLETION_EVENT );
		}

		if( terminate_pseudostate_has_been_reached )
		{
			Y_LOG( sxy::log_level::LL_INFO, "Terminate pseudostate reached. The state machine is stopping." );
			state_machine_is_running_ = false;
		}
	}
	catch( const std::exception& exception )
	{
		Y_LOG( sxy::log_level::LL_FATAL, "State machine cannot start: %.", exception.what() );
		state_machine_is_running_ = false;
		throw;
	}
	catch( ... )
	{
		Y_LOG( sxy::log_level::LL_FATAL, "State machine can not start: Unknown exception occurred." );
		state_machine_is_running_ = false;
		throw;
	}
	return( terminate_pseudostate_has_been_reached );
}


bool state_machine::process_event( const event_sptr& _event, async_event_handler* const _async_event_handler )
{
	Y_ASSERT( state_machine_is_running_, "State machine is not running!" );
	auto terminate_pseudostate_has_been_reached = true;
	Y_LOG( log_level::LL_DEBUG, "Starting executing event '%'.", _event->get_id() );
	try
	{
		if( event_processing_callback_ )
		{
			event_processing_callback_->before_event( _event->get_id() );
		}
		
		transition_controller transition_controller;
		auto event_is_deferred = false;
		terminate_pseudostate_has_been_reached = transition_controller.process_event( *_event, *root_state_,
			event_processing_callback_, event_is_deferred, _async_event_handler );
		Y_LOG( log_level::LL_DEBUG, "Event '%' has been processed.", _event->get_id() );
		if( event_processing_callback_ )
		{
			event_processing_callback_->after_event( _event->get_id() );
		}

		if( terminate_pseudostate_has_been_reached )
		{
			Y_LOG( sxy::log_level::LL_FATAL, "An event could not be processed! The state machine is stopping." );			
			state_machine_is_running_ = false;
		}
		else
		{
			if( event_is_deferred )
			{
				add_deferred_event( _event );
			}
			else
			{
				terminate_pseudostate_has_been_reached = process_deferred_events( _async_event_handler );
			}
		}

		if( terminate_pseudostate_has_been_reached )
		{
			Y_LOG( sxy::log_level::LL_FATAL, "An event could not be processed! The state machine is stopping." );			
			state_machine_is_running_ = false;
		}
	}
	catch( const std::exception& exception )
	{
		Y_LOG( sxy::log_level::LL_FATAL, "State machine cannot run: %", exception.what() );		
		state_machine_is_running_ = false;
		throw;
	}
	catch( ... )
	{
		Y_LOG( sxy::log_level::LL_FATAL, "State machine cannot run: Unknown exception occured!" );		
		state_machine_is_running_ = false;
		throw;
	}
	return( terminate_pseudostate_has_been_reached );
}


// cppcheck-suppress unusedFunction
const events& state_machine::get_deferred_events() const
{
	return( deferred_events_ );
}


// cppcheck-suppress unusedFunction
raw_const_states state_machine::get_active_state_configuration() const
{
	raw_const_states active_state_configuration = {};
	const auto& root = get_root_state();
	check_regions_for_active_states( active_state_configuration, root );
	return( active_state_configuration );
}


void state_machine::get_active_states_from_region( raw_const_states& _active_state_configuration,
	const region& _region ) const
{
	const auto active_state = _region.get_active_state();
	if( active_state )
	{
		_active_state_configuration.push_back( active_state );
		check_regions_for_active_states( _active_state_configuration, *active_state );
	}
}


void state_machine::check_regions_for_active_states( raw_const_states& _active_state_configuration,
	const state& _state ) const
{
	for( const auto & region : _state.get_regions() )
	{
		get_active_states_from_region( _active_state_configuration, *region );
	}
}


void state_machine::add_deferred_event( const event_sptr& _event_id )
{
	deferred_events_.push_back( _event_id );
}


bool state_machine::process_deferred_events( async_event_handler* const _async_event_handler )
{
	const auto deferred_events = deferred_events_;
	deferred_events_.clear();
	auto terminate_pseudostate_has_been_reached = false;
	transition_controller transition_controller;

	for( const auto deferred_event : deferred_events )
	{
		if( event_processing_callback_ )
		{
			event_processing_callback_->before_event( deferred_event->get_id() );
		}

		auto event_is_deferred = false;
		terminate_pseudostate_has_been_reached = transition_controller.process_event( *deferred_event, *root_state_,
			event_processing_callback_, event_is_deferred, _async_event_handler );
		if( event_processing_callback_ )
		{
			event_processing_callback_->after_event( deferred_event->get_id() );
		}

		if( terminate_pseudostate_has_been_reached )
		{
			Y_LOG( sxy::log_level::LL_FATAL, "An event could not be processed! The state machine is stopping." );
			break;
		}
		else
		{
			if( event_is_deferred )
			{
				deferred_events_.push_back( deferred_event );
			}
		}
	}

	return( terminate_pseudostate_has_been_reached );
}


void state_machine::stop_all_async_states( state& _state )
{		
	for( auto& region : _state.get_regions())
	{
		stop_all_async_states_from_region( region );
	}
}


void state_machine::stop_all_async_states_from_region( region_uptr& _region)
{
	auto active_state = _region->get_active_state();
	if( active_state )
	{
		auto async_state = dynamic_cast< async_simple_state_impl* >( active_state );
		if( async_state )
		{
			async_state->stop_do_behavior();
		}
		else
		{
			stop_all_async_states( *active_state );
		}
	}
}


}
