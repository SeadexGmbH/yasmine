//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "region_impl.hpp"

#include "base.hpp"
#include "state.hpp"
#include "initial_pseudostate_impl.hpp"
#include "choice_impl.hpp"
#include "fork_impl.hpp"
#include "join_impl.hpp"
#include "junction_impl.hpp"
#include "terminate_pseudostate_impl.hpp"
#include "simple_state_impl.hpp"
#include "composite_state_impl.hpp"
#include "final_state_impl.hpp"
#include "behavior_impl.hpp"
#include "async_simple_state_impl.hpp"
#include "async_behavior.hpp"

#include "state_machine_defect.hpp"
#include "uri.hpp"



namespace sxy
{


region_impl::region_impl( const std::string& _name )
	: state_machine_element_impl( _name ),
		parent_state_(),
		states_(),
		pseudostates_(),
		initial_pseudostate_( Y_NULLPTR ),
		active_state_( Y_NULLPTR ),
		last_active_state_( Y_NULLPTR )
{
	// Nothing to do...
}


region_impl::~region_impl() Y_NOEXCEPT
{
	// Nothing to do...
}
		

void region_impl::set_parent_state( composite_state* const _composite_state )
{
	parent_state_ = _composite_state;
}


raw_const_states region_impl::get_states() const
{
	raw_const_states states;	
	states.reserve( states_.size() );

	Y_FOR( const state_uptr& state, states_ )
	{
		states.push_back( state.get() );
	}

	return( states );
}


const composite_state& region_impl::get_parent_state() const
{
	return( *parent_state_ );
}


composite_state& region_impl::get_parent_state()
{
	return( *parent_state_ );
}


vertex* region_impl::get_vertex( const std::string& _vertex_name ) const
{
	vertex* found_vertex = Y_NULLPTR;

	Y_FOR( const pseudostate_uptr& pseudostate, pseudostates_ )
	{
		if( _vertex_name == pseudostate.get()->get_name() )
		{
			found_vertex = pseudostate.get();
			break;
		}
	}

	Y_FOR( const state_uptr& state, states_ )
	{
		if( _vertex_name == state.get()->get_name() )
		{
			found_vertex = state.get();
			break;
		}
	}

	return( found_vertex );
}


size_t region_impl::get_pseudostate_count() const
{
	return( pseudostates_.size() );
}


vertex* region_impl::get_pseudostate( const std::string& _name ) const
{
	vertex* found_vertex = Y_NULLPTR;

	Y_FOR( const pseudostate_uptr& pseudostate, pseudostates_ )
	{
		if( _name == pseudostate->get_name() )
		{
			found_vertex = pseudostate.get();
			break;
		}
	}

	return( found_vertex );
}


raw_const_pseudostates region_impl::get_pseudostates() const
{
	raw_const_pseudostates pseudostates;
	pseudostates.reserve( pseudostates_.size() );

	Y_FOR( const pseudostate_uptr& pseudostate, pseudostates_ )
	{
		pseudostates.push_back( pseudostate.get() );
	}

	return( pseudostates );
}


initial_pseudostate* region_impl::get_initial_pseudostate() const
{
	return( initial_pseudostate_ );
}


size_t region_impl::get_state_count() const
{
	return( states_.size() );
}


state* region_impl::get_state( const std::string& _name ) const
{
	state* found_vertex = Y_NULLPTR;

	Y_FOR( const state_uptr& state, states_ )
	{
		const std::string name_of_state = state->get_name();
		if( _name == state->get_name() )
		{
			found_vertex = state.get();
			break;
		}
	}

	return( found_vertex );
}


const state* region_impl::get_active_state() const
{
	return( active_state_ );
}


state* region_impl::get_active_state()
{
	return( active_state_ );
}


void region_impl::set_active_state( state* const _active_state )
{
	active_state_ = _active_state;

	if( _active_state )
	{
		Y_LOG( log_level::LL_SPAM, "Set state '%' as 'active state' in region '%'.", _active_state->get_name(),
			get_name() );
	}
	else
	{
		Y_LOG( log_level::LL_SPAM, "Set NO active state in region '%'.", get_name() );
	}
}


void region_impl::set_state_was_active( state* const _active_state )
{
	last_active_state_ = _active_state;
	Y_LOG( log_level::LL_SPAM, "Set state '%' as 'was active state' in region '%'.", _active_state->get_name(), 
		get_name() );
}


const state* region_impl::get_last_active_state() const
{
	return( last_active_state_ );
}


state* region_impl::get_last_active_state()
{
	return( last_active_state_ );
}


initial_pseudostate& region_impl::add_initial_pseudostate( initial_pseudostate_uptr _initial_state )
{
	Y_ASSERT( !initial_pseudostate_, "There is already a initial pseudostate in the region." );
	_initial_state->set_parent_region( this );
	initial_pseudostate_ = _initial_state.get();
	pseudostates_.push_back( sxy::move( _initial_state ) );
	initial_pseudostate& new_initial_state = *initial_pseudostate_;
	return( new_initial_state );
}


initial_pseudostate& region_impl::add_initial_pseudostate( const std::string& _initial_state_name )
{
	Y_ASSERT( !initial_pseudostate_, "There is already a initial pseudostate in the region." );
	Y_UNIQUE_PTR< sxy::initial_pseudostate_impl > initial_state =
		Y_MAKE_UNIQUE< sxy::initial_pseudostate_impl >( _initial_state_name );
	initial_state->set_parent_region( this );
	initial_pseudostate_ = initial_state.get();
	pseudostates_.push_back( sxy::move( initial_state ) );
	initial_pseudostate& new_initial_state = *initial_pseudostate_;
	return( new_initial_state );
}


state& region_impl::add_state( state_uptr _state )
{
	_state->set_parent_region( this );
	state& state = *_state;
	states_.push_back( sxy::move( _state ) );
	return( state );
}


simple_state& region_impl::add_simple_state( const std::string& _name, const behavior_function& _behavior,
	const behavior_function& _entry_behavior,	const behavior_function& _exit_behavior )
{
	behavior_uptr behavior = behavior_impl::create_behavior( _behavior );
	behavior_uptr entry_behavior = behavior_impl::create_behavior( _entry_behavior );
	behavior_uptr exit_behavior = behavior_impl::create_behavior( _exit_behavior );
	Y_UNIQUE_PTR< sxy::simple_state_impl > simple_state = Y_MAKE_UNIQUE< sxy::simple_state_impl >( _name,
		sxy::move( behavior ), sxy::move( entry_behavior ), sxy::move( exit_behavior ) );
	simple_state->set_parent_region( this );
	simple_state_impl& state = *simple_state;
	states_.push_back( sxy::move( simple_state ) );
	return( state );
}	 


simple_state& region_impl::add_simple_state( const std::string& _name, const event_ids& _deferred_events,
	const behavior_function& _behavior,	const behavior_function& _entry_behavior,
	const behavior_function& _exit_behavior, event_sptr _error_event )
{
	Y_UNIQUE_PTR< sxy::simple_state_impl > simple_state =
		Y_MAKE_UNIQUE< sxy::simple_state_impl >( _name,
			( !_behavior ? behavior_uptr() : ( behavior_impl::create_behavior( _behavior ) ) ),
			( !_entry_behavior ? behavior_uptr() : ( behavior_impl::create_behavior( _entry_behavior ) ) ),
			( !_exit_behavior ? behavior_uptr() : ( behavior_impl::create_behavior( _exit_behavior ) ) ), _deferred_events,
			_error_event );
	simple_state->set_parent_region( this );
	simple_state_impl& state = *simple_state;
	states_.push_back( sxy::move( simple_state ) );
	return( state );
}


simple_state& region_impl::add_async_simple_state( const std::string& _name, const event_ids& _deferred_events,
	async_behavior_uptr _do_action,	const behavior_function& _entry_behavior,	const behavior_function& _exit_behavior,
	event_sptr _error_event )
{
	Y_UNIQUE_PTR< sxy::async_simple_state_impl > simple_state = Y_MAKE_UNIQUE< sxy::async_simple_state_impl >( _name,
		sxy::move( _do_action ), 
		( !_entry_behavior ? behavior_uptr() : ( behavior_impl::create_behavior( _entry_behavior ) ) ),
		( !_exit_behavior ? behavior_uptr() : ( behavior_impl::create_behavior( _exit_behavior ) ) ), _deferred_events,
		_error_event );
	simple_state->set_parent_region( this );
	async_simple_state_impl& state = *simple_state;
	states_.push_back( sxy::move( simple_state ) );
	return( state );
}


composite_state& region_impl::add_composite_state( const std::string& _name, const behavior_function& _entry_action,
	const behavior_function& _exit_action )
{
	Y_UNIQUE_PTR< sxy::composite_state_impl > composite_state =
		Y_MAKE_UNIQUE< sxy::composite_state_impl >( _name,
			( !_entry_action ? behavior_uptr() : ( behavior_impl::create_behavior( _entry_action ) ) ),
			( !_exit_action ? behavior_uptr() : ( behavior_impl::create_behavior( _exit_action ) ) ) );
	composite_state->set_parent_region( this );
	composite_state_impl& state = *composite_state;
	states_.push_back( sxy::move( composite_state ) );
	return( state );
}


composite_state& region_impl::add_composite_state( const std::string& _name, const event_ids& _deferred_events,
	const behavior_function& _entry_action, const behavior_function& _exit_action )
{
	Y_UNIQUE_PTR< sxy::composite_state_impl > composite_state =
		Y_MAKE_UNIQUE< sxy::composite_state_impl >( _name,
			( !_entry_action ? behavior_uptr() : ( behavior_impl::create_behavior( _entry_action ) ) ),
			( !_exit_action ? behavior_uptr() : ( behavior_impl::create_behavior( _exit_action ) ) ), _deferred_events );
	composite_state->set_parent_region( this );
	composite_state_impl& state = *composite_state;
	states_.push_back( sxy::move( composite_state ) );
	return( state );
}


final_state& region_impl::add_final_state( const std::string& _name )
{
	Y_UNIQUE_PTR< sxy::final_state_impl > final_state = Y_MAKE_UNIQUE< sxy::final_state_impl >( _name );
	final_state->set_parent_region( this );
	final_state_impl& state = *final_state;
	states_.push_back( sxy::move( final_state ) );
	return( state );
}


choice& region_impl::add_choice( choice_uptr _choice )
{
	_choice->set_parent_region( this );
	choice& choice = *_choice.get();
	pseudostates_.push_back( sxy::move( _choice ) );
	return( choice );
}


choice& region_impl::add_choice( const std::string& _choice_name )
{
	Y_UNIQUE_PTR< sxy::choice_impl > choice = Y_MAKE_UNIQUE< sxy::choice_impl >( _choice_name );
	choice->set_parent_region( this );
	choice_impl& new_choice = *choice.get();
	pseudostates_.push_back( sxy::move( choice ) );
	return( new_choice );
}


fork& region_impl::add_fork( fork_uptr _fork )
{
	_fork->set_parent_region( this );
	fork& fork = *_fork.get();
	pseudostates_.push_back( sxy::move( _fork ) );
	return( fork );
}


fork& region_impl::add_fork( const std::string& _fork_name )
{
	Y_UNIQUE_PTR< sxy::fork_impl > fork = Y_MAKE_UNIQUE< sxy::fork_impl >( _fork_name );
	fork->set_parent_region( this );
	fork_impl& new_fork = *fork.get();
	pseudostates_.push_back( sxy::move( fork ) );
	return( new_fork );
}


join& region_impl::add_join( join_uptr _join )
{
	_join->set_parent_region( this );
	join& join = *_join.get();
	pseudostates_.push_back( sxy::move( _join ) );
	return( join );
}


join& region_impl::add_join( const std::string& _join_name )
{
	Y_UNIQUE_PTR< sxy::join_impl > join = Y_MAKE_UNIQUE< sxy::join_impl >( _join_name );
	join->set_parent_region( this );
	join_impl& new_join = *join.get();
	pseudostates_.push_back( sxy::move( join ) );
	return( new_join );
}


junction& region_impl::add_junction( junction_uptr _junction )
{
	_junction->set_parent_region( this );
	junction& junction = *_junction.get();
	pseudostates_.push_back( sxy::move( _junction ) );
	return( junction );
}


junction& region_impl::add_junction( const std::string& _junction_name )
{
	Y_UNIQUE_PTR< sxy::junction_impl > junction = Y_MAKE_UNIQUE< sxy::junction_impl >( _junction_name );
	junction->set_parent_region( this );
	junction_impl& new_junction = *junction.get();
	pseudostates_.push_back( sxy::move( junction ) );
	return( new_junction );
}

terminate_pseudostate& region_impl::add_terminate_pseudostate( terminate_pseudostate_uptr _terminate_pseudostate )
{
	_terminate_pseudostate->set_parent_region( this );
	terminate_pseudostate& terminate_pseudostate = *_terminate_pseudostate.get();
	pseudostates_.push_back( sxy::move( _terminate_pseudostate ) );
	return( terminate_pseudostate );
}


terminate_pseudostate& region_impl::add_terminate_pseudostate( const std::string& _terminate_pseudostate_name )
{
	Y_UNIQUE_PTR< sxy::terminate_pseudostate_impl > terminate_pseudostate =
		Y_MAKE_UNIQUE< sxy::terminate_pseudostate_impl >( _terminate_pseudostate_name );
	terminate_pseudostate->set_parent_region( this );
	terminate_pseudostate_impl& new_terminate_pseudostate = *terminate_pseudostate.get();
	pseudostates_.push_back( sxy::move( terminate_pseudostate ) );
	return( new_terminate_pseudostate );
}


uri region_impl::get_uri() const
{
	uri uri( get_name() );
	add_ancestor_uri( uri );
	return( uri );
}


void region_impl::add_ancestor_uri( uri& _uri ) const
{
	const composite_state& parent = get_parent_state();
	_uri.push_front( parent.get_name() );
	parent.add_ancestor_uri( _uri );
}


bool region_impl::is_active_state_final() const
{
	bool active_state_is_final_state = false;
	const final_state* const l_final_state = dynamic_cast< const final_state* >( active_state_ );
	if( l_final_state != Y_NULLPTR )
	{
		active_state_is_final_state = true;
	}

	return( active_state_is_final_state );
}


bool region_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// 15.3.10 Region -> Constraint [1]: A region can have at most one initial vertex.
	// Enforced by design.
	// 15.3.10 Region -> Constraint [2]: A region can have at most one deep history vertex. -> deep history belongs to
	// composite state
	// 15.3.10 Region -> Constraint [3]: A region can have at most one shallow history vertex. -> shallow history belongs
	// to composite state
	// 15.3.10 Region -> Constraint [4]: If a Region is owned by a StateMachine, then it cannot also be owned by a State
	// and vice versa.
	// Enforced by design.
	// 15.3.10 Region -> Constraint [5]: The redefinition context of a region is the nearest containing statemachine.
	// Does not apply.
	// region must not be empty
	if( ( 0 == get_state_count() ) && ( 0 == get_pseudostate_count() ) )
	{
		_defects.push_back( state_machine_defect( *this, "Region '%' is empty!", get_name() ) );
		check_ok = false;
	}

	Y_FOR( const state* const state, get_states() )
	{
		if( !state->check( _defects ) )
		{
			check_ok = false;
		}
	}

	Y_FOR( const pseudostate* const pseudostate, get_pseudostates() )
	{
		if( !pseudostate->check( _defects ) )
		{
			check_ok = false;
		}
	}

	return( check_ok );
}


const state_machine_element* region_impl::get_parent() const
{
	return( parent_state_ );
}


}
