//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "build_transition_steps_visitor.hpp"

#include "make_unique.hpp"
#include "base.hpp"
#include "log_and_throw.hpp"

#include "composite_state.hpp"

#include "join.hpp"
#include "fork.hpp"
#include "shallow_history.hpp"
#include "deep_history.hpp"
#include "junction.hpp"
#include "entry_point.hpp"
#include "exit_point.hpp"

#include "transition.hpp"

#include "simple_transition_step.hpp"
#include "compound_transition_step.hpp"


namespace sxy
{


build_transition_steps_visitor::build_transition_steps_visitor( transition& _current_transition, 
	transition_steps& _transitions_steps, const event& _event )
	: const_vertex_visitor(),
		current_transition_( _current_transition ),
		transition_steps_( _transitions_steps ),
		next_transition_( nullptr ),
		reached_end_of_transition_( true ),
		event_( _event )
{
	// Nothing to do...
}


void build_transition_steps_visitor::visit( const composite_state& _composite_state )
{
	Y_UNUSED_PARAMETER( _composite_state );
	create_simple_transition_step();
}


void build_transition_steps_visitor::visit( const simple_state& _simple_state )
{
	Y_UNUSED_PARAMETER( _simple_state );
	create_simple_transition_step();
}


void build_transition_steps_visitor::visit( const final_state& _final_state )
{
	Y_UNUSED_PARAMETER( _final_state );
	create_simple_transition_step();
}


void build_transition_steps_visitor::visit( const initial_pseudostate& _initial_pseudostate )
{
	Y_UNUSED_PARAMETER( _initial_pseudostate );
	Y_ASSERT( false, "An initial pseudo state cannot be the target of a transition!" );
}


void build_transition_steps_visitor::visit( const choice& _choice )
{
	Y_UNUSED_PARAMETER( _choice );
	create_simple_transition_step();
}


void build_transition_steps_visitor::visit( const junction& _junction )
{
	handle_as_junction( _junction );
}


void build_transition_steps_visitor::visit( const join& _join )
{
	handle_as_join( _join );
}


void build_transition_steps_visitor::visit( const fork& _fork )
{
	handle_as_fork( _fork );
}


void build_transition_steps_visitor::visit( const entry_point& _entry_point )
{
	handle_entry_point( _entry_point );
}


void build_transition_steps_visitor::visit( const exit_point& _exit_point )
{
	handle_exit_point( _exit_point );
}


void build_transition_steps_visitor::visit( const deep_history& _deep_history )
{
	handle_history_pseudostate( _deep_history );
}


void build_transition_steps_visitor::visit( const shallow_history& _shallow_history )
{
	handle_history_pseudostate( _shallow_history );
}


void build_transition_steps_visitor::visit( const terminate_pseudostate& _terminate_pseudostate )
{
	Y_UNUSED_PARAMETER( _terminate_pseudostate );
	auto simple_step = sxy::make_unique< simple_transition_step >( current_transition_ );
	transition_steps_.push_back( std::move( simple_step ) );
}


transition* build_transition_steps_visitor::get_next_transition() const
{
	return( next_transition_ );
}


bool build_transition_steps_visitor::reached_end_of_transition() const
{
	return( reached_end_of_transition_ );
}


transition* build_transition_steps_visitor::find_next_transition( const pseudostate& _target_pseudostate,
	const event& _event )
{
	transition* enabled_transition = nullptr;
	const auto& transitions = _target_pseudostate.get_outgoing_transitions();

	for( const auto & transition : transitions )
	{
		const auto guard_is_ok = transition->check_guard( _event );
		if( guard_is_ok )
		{
			enabled_transition = transition;
			break;
		}
	}

	if( nullptr == enabled_transition )
	{
		reached_end_of_transition_ = false;
	}

	return( enabled_transition );
}


raw_transitions build_transition_steps_visitor::get_default_transition_if_state_was_not_active_before(
	const history& _history )
{
	raw_transitions default_transitions = {};
	const auto& state_was_active_before = _history.check_if_state_was_active_before();
	if( !state_was_active_before )
	{
		default_transitions = _history.get_default_transitions();
		if( default_transitions.empty() )
		{
			LOG_AND_THROW( log_level::LL_FATAL, "History pseudostate '%' has no default transition!",
				_history.get_name() );
		}
	}

	return( default_transitions );
}


void build_transition_steps_visitor::handle_history_pseudostate( const history& _history )
{
	auto simple_step = sxy::make_unique< simple_transition_step >( current_transition_ );
	transition_steps_.push_back( std::move( simple_step ) );
	const auto default_transitions = get_default_transition_if_state_was_not_active_before( _history );
	if( !default_transitions.empty() )
	{
		for( const auto default_transition : default_transitions )
		{
			auto default_step = sxy::make_unique< simple_transition_step >( *default_transition );
			transition_steps_.push_back( std::move( default_step ) );
		}
	}
}


void build_transition_steps_visitor::handle_as_junction( const pseudostate& _pseudostate )
{
	auto simple_step = sxy::make_unique< simple_transition_step >( current_transition_ );
	transition_steps_.push_back( std::move( simple_step ) );
	next_transition_ = find_next_transition( _pseudostate, event_ );
	if( !next_transition_ )
	{
		LOG_AND_THROW( log_level::LL_FATAL, "There is no enabled transition for the junction '%'!",
			_pseudostate.get_name() );
	}
}


void build_transition_steps_visitor::handle_as_fork( const pseudostate& _pseudostate ) const
{
	auto simple_step = sxy::make_unique< simple_transition_step >( current_transition_ );
	transition_steps_.push_back( std::move( simple_step ) );
	const auto& exiting_transitions = _pseudostate.get_outgoing_transitions();
	raw_transitions transitions_of_fork;

	for( const auto & transition : exiting_transitions )
	{
		transitions_of_fork.push_back( transition );
	}

	auto final_step = sxy::make_unique< compound_transition_step >( transitions_of_fork );
	transition_steps_.push_back( std::move( final_step ) );
}


void build_transition_steps_visitor::handle_as_join( const pseudostate& _pseudostate )
{
	const auto& incoming_transitions = _pseudostate.get_incoming_transitions();
	auto step = sxy::make_unique< compound_transition_step >( incoming_transitions );
	transition_steps_.push_back( std::move( step ) );
	next_transition_ = find_next_transition( _pseudostate, event_ );
}


void build_transition_steps_visitor::handle_entry_point( const entry_point& _entry_point )
{
	const auto& parent_state = _entry_point.get_parent_state();
	const auto is_orthogonal = parent_state.is_orthogonal();
	if( is_orthogonal )
	{
		handle_as_fork( _entry_point );
	}
	else
	{
		handle_as_junction( _entry_point );
	}
}


void build_transition_steps_visitor::handle_exit_point( const exit_point& _exit_point )
{
	const auto& parent_state = _exit_point.get_parent_state();
	const auto is_orthogonal = parent_state.is_orthogonal();
	if( is_orthogonal )
	{
		handle_as_join( _exit_point );
	}
	else
	{
		handle_as_junction( _exit_point );
	}
}


void build_transition_steps_visitor::create_simple_transition_step()
{
	auto simple_step = sxy::make_unique< simple_transition_step >( current_transition_ );
	transition_steps_.push_back( std::move( simple_step ) );
}


}
