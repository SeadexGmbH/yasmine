//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_region.h"

#include "base.h"
#include "i_state.h"
#include "t_initial_pseudostate.h"
#include "t_choice.h"
#include "t_fork.h"
#include "t_join.h"
#include "t_junction.h"
#include "t_terminate_pseudostate.h"
#include "t_simple_state.h"
#include "t_composite_state.h"
#include "t_final_state.h"
#include "t_behavior.h"

#include "t_state_machine_defects.h"
#include "t_uri.h"


namespace sxy
{


t_region::t_region( const std::string& p_name )
	: t_state_machine_element( p_name ),
		m_parent_state(),
		m_states(),
		m_pseudostates(),
		m_initial_pseudostate( nullptr ),
		m_active_state( nullptr ),
		m_last_active_state( nullptr )
{
	// Nothing to do...
}


t_region::~t_region() = default;


void t_region::set_parent_state( i_composite_state* const p_composite_state )
{
	m_parent_state = p_composite_state;
}


t_raw_const_states t_region::get_states() const
{
	t_raw_const_states states;

	for( const auto & l_state : m_states )
	{
		states.push_back( l_state.get() );
	}

	return( states );
}


const i_composite_state& t_region::get_parent_state() const
{
	return( *m_parent_state );
}


i_composite_state& t_region::get_parent_state()
{
	return( *m_parent_state );
}


// cppcheck-suppress unusedFunction
i_vertex* t_region::get_vertex( const std::string& p_vertex_name ) const
{
	i_vertex* l_found_vertex = nullptr;

	for( const auto & l_pseudostate : m_pseudostates )
	{
		if( p_vertex_name == l_pseudostate.get()->get_name() )
		{
			l_found_vertex = l_pseudostate.get();
			break;
		}
	}

	for( const auto & l_state : m_states )
	{
		if( p_vertex_name == l_state.get()->get_name() )
		{
			l_found_vertex = l_state.get();
			break;
		}
	}

	return( l_found_vertex );
}


size_t t_region::get_pseudostate_count() const
{
	return( m_pseudostates.size() );
}


i_vertex* t_region::get_pseudostate( const std::string& p_name ) const
{
	i_vertex* l_found_vertex = nullptr;

	for( const auto & l_pseudostate : m_pseudostates )
	{
		if( p_name == l_pseudostate->get_name() )
		{
			l_found_vertex = l_pseudostate.get();
			break;
		}
	}

	return( l_found_vertex );
}


t_raw_const_pseudostates t_region::get_pseudostates() const
{
	t_raw_const_pseudostates pseudostates;

	for( const auto & pseudostate : m_pseudostates )
	{
		pseudostates.push_back( pseudostate.get() );
	}

	return( pseudostates );
}


i_initial_pseudostate* t_region::get_initial_pseudostate() const
{
	return( m_initial_pseudostate );
}


size_t t_region::get_state_count() const
{
	return( m_states.size() );
}


i_state* t_region::get_state( const std::string& p_name ) const
{
	i_state* l_found_vertex = nullptr;

	for( const auto & l_state : m_states )
	{
		auto l_name_of_state = l_state->get_name();
		if( p_name == l_state->get_name() )
		{
			l_found_vertex = l_state.get();
			break;
		}
	}

	return( l_found_vertex );
}


const i_state* t_region::get_active_state() const
{
	return( m_active_state );
}


i_state* t_region::get_active_state()
{
	return( m_active_state );
}


void t_region::set_active_state( i_state* const p_active_state )
{
	m_active_state = p_active_state;
	if( p_active_state )
	{
		Y_LOG( t_log_level::LL_SPAM, "Set state '%' as 'active state' in region '%'.", p_active_state->get_name(),
			get_name() );
	}
	else
	{
		Y_LOG( t_log_level::LL_SPAM, "Set NO active state in region '%'.", get_name() );
	}
}


void t_region::set_state_was_active( i_state* const p_active_state )
{
	m_last_active_state = p_active_state;
	Y_LOG( t_log_level::LL_SPAM, "Set state '%' as 'was active state' in region '%'.", p_active_state->get_name(), 
		get_name() );
}


const i_state* t_region::get_last_active_state() const
{
	return( m_last_active_state );
}


i_state* t_region::get_last_active_state()
{
	return( m_last_active_state );
}


// cppcheck-suppress unusedFunction
i_initial_pseudostate& t_region::add_initial_pseudostate( i_initial_pseudostate_uptr p_initial_state )
{
	Y_ASSERT( !m_initial_pseudostate, "There is already a initial pseudostate in the region." );
	p_initial_state->set_parent_region( this );
	m_initial_pseudostate = p_initial_state.get();
	m_pseudostates.push_back( std::move( p_initial_state ) );
	auto& l_new_initial_state = *m_initial_pseudostate;
	return( l_new_initial_state );
}


i_initial_pseudostate& t_region::add_initial_pseudostate( const std::string& p_initial_state_name )
{
	Y_ASSERT( !m_initial_pseudostate, "There is already a initial pseudostate in the region." );
	auto l_initial_state = std::make_unique< sxy::t_initial_pseudostate >( p_initial_state_name );
	l_initial_state->set_parent_region( this );
	m_initial_pseudostate = l_initial_state.get();
	m_pseudostates.push_back( std::move( l_initial_state ) );
	auto& l_new_initial_state = *m_initial_pseudostate;
	return( l_new_initial_state );
}


// cppcheck-suppress unusedFunction
i_state& t_region::add_state( i_state_uptr p_state )
{
	p_state->set_parent_region( this );
	auto& state = *p_state;
	m_states.push_back( std::move( p_state ) );
	return( state );
}


// cppcheck-suppress unusedFunction
i_simple_state& t_region::add_simple_state(
	const std::string& p_name,
	const t_behavior_function& p_behavior,
	const t_behavior_function& p_entry_behavior,
	const t_behavior_function& p_exit_behavior )
{
	auto l_behavior = t_behavior::create_behavior( p_behavior );
	auto l_entry_behavior = t_behavior::create_behavior( p_entry_behavior );
	auto l_exit_behavior = t_behavior::create_behavior( p_exit_behavior );
	auto l_simple_state =
		std::make_unique< sxy::t_simple_state >( p_name, std::move( l_behavior ), std::move( l_entry_behavior ),
			std::move( l_exit_behavior ) );
	l_simple_state->set_parent_region( this );
	auto& state = *l_simple_state;
	m_states.push_back( std::move( l_simple_state ) );
	return( state );
}


i_simple_state& t_region::add_simple_state(
	const std::string& p_name,
	const t_event_ids& p_deferred_events,
	const t_behavior_function& p_behavior,
	const t_behavior_function& p_entry_behavior,
	const t_behavior_function& p_exit_behavior )
{
	auto l_simple_state =
		std::make_unique< sxy::t_simple_state >( p_name,
			( p_behavior == nullptr ? nullptr : ( t_behavior::create_behavior( p_behavior ) ) ),
			( p_behavior == nullptr ? nullptr : ( t_behavior::create_behavior( p_entry_behavior ) ) ),
			( p_behavior == nullptr ? nullptr : ( t_behavior::create_behavior( p_exit_behavior ) ) ), p_deferred_events );
	l_simple_state->set_parent_region( this );
	auto& state = *l_simple_state;
	m_states.push_back( std::move( l_simple_state ) );
	return( state );
}


// cppcheck-suppress unusedFunction
i_composite_state& t_region::add_composite_state(
	const std::string& p_name,
	const t_behavior_function& p_entry_action,
	const t_behavior_function& p_exit_action )
{
	auto l_composite_state =
		std::make_unique< sxy::t_composite_state >( p_name,
			( p_entry_action == nullptr ? nullptr : ( t_behavior::create_behavior( p_entry_action ) ) ),
			( p_exit_action == nullptr ? nullptr : ( t_behavior::create_behavior( p_exit_action ) ) ) );
	l_composite_state->set_parent_region( this );
	auto& state = *l_composite_state;
	m_states.push_back( std::move( l_composite_state ) );
	return( state );
}


i_composite_state& t_region::add_composite_state(
	const std::string& p_name,
	const t_event_ids& p_deferred_events,
	const t_behavior_function& p_entry_action,
	const t_behavior_function& p_exit_action )
{
	auto l_composite_state =
		std::make_unique< sxy::t_composite_state >( p_name,
			( p_entry_action == nullptr ? nullptr : ( t_behavior::create_behavior( p_entry_action ) ) ),
			( p_exit_action == nullptr ? nullptr : ( t_behavior::create_behavior( p_exit_action ) ) ), p_deferred_events );
	l_composite_state->set_parent_region( this );
	auto& state = *l_composite_state;
	m_states.push_back( std::move( l_composite_state ) );
	return( state );
}


// cppcheck-suppress unusedFunction
i_final_state& t_region::add_final_state( const std::string& p_name )
{
	auto l_final_state = std::make_unique< sxy::t_final_state >( p_name );
	l_final_state->set_parent_region( this );
	auto& state = *l_final_state;
	m_states.push_back( std::move( l_final_state ) );
	return( state );
}


// cppcheck-suppress unusedFunction
i_choice& t_region::add_choice( i_choice_uptr p_choice )
{
	p_choice->set_parent_region( this );
	auto& l_choice = *p_choice.get();
	m_pseudostates.push_back( std::move( p_choice ) );
	return( l_choice );
}


i_choice& t_region::add_choice( const std::string& p_choice_name )
{
	auto l_choice = std::make_unique< sxy::t_choice >( p_choice_name );
	l_choice->set_parent_region( this );
	auto& l_new_choice = *l_choice.get();
	m_pseudostates.push_back( std::move( l_choice ) );
	return( l_new_choice );
}


// cppcheck-suppress unusedFunction
i_fork& t_region::add_fork( i_fork_uptr p_fork )
{
	p_fork->set_parent_region( this );
	auto& l_fork = *p_fork.get();
	m_pseudostates.push_back( std::move( p_fork ) );
	return( l_fork );
}


i_fork& t_region::add_fork( const std::string& p_fork_name )
{
	auto l_fork = std::make_unique< sxy::t_fork >( p_fork_name );
	l_fork->set_parent_region( this );
	auto& l_new_fork = *l_fork.get();
	m_pseudostates.push_back( std::move( l_fork ) );
	return( l_new_fork );
}


// cppcheck-suppress unusedFunction
i_join& t_region::add_join( i_join_uptr p_join )
{
	p_join->set_parent_region( this );
	auto& l_join = *p_join.get();
	m_pseudostates.push_back( std::move( p_join ) );
	return( l_join );
}


i_join& t_region::add_join( const std::string& p_join_name )
{
	auto l_join = std::make_unique< sxy::t_join >( p_join_name );
	l_join->set_parent_region( this );
	auto& l_new_join = *l_join.get();
	m_pseudostates.push_back( std::move( l_join ) );
	return( l_new_join );
}


// cppcheck-suppress unusedFunction
i_junction& t_region::add_junction( i_junction_uptr p_junction )
{
	p_junction->set_parent_region( this );
	auto& l_junction = *p_junction.get();
	m_pseudostates.push_back( std::move( p_junction ) );
	return( l_junction );
}


i_junction& t_region::add_junction( const std::string& p_junction_name )
{
	auto l_junction = std::make_unique< sxy::t_junction >( p_junction_name );
	l_junction->set_parent_region( this );
	auto& l_new_junction = *l_junction.get();
	m_pseudostates.push_back( std::move( l_junction ) );
	return( l_new_junction );
}

// cppcheck-suppress unusedFunction
i_terminate_pseudostate& t_region::add_terminate_pseudostate( i_terminate_pseudostate_uptr p_terminate_pseudostate )
{
	p_terminate_pseudostate->set_parent_region( this );
	auto& l_terminate_pseudostate = *p_terminate_pseudostate.get();
	m_pseudostates.push_back( std::move( p_terminate_pseudostate ) );
	return( l_terminate_pseudostate );
}


i_terminate_pseudostate& t_region::add_terminate_pseudostate( const std::string& p_terminate_pseudostate_name )
{
	auto l_terminate_pseudostate = std::make_unique< sxy::t_terminate_pseudostate >( p_terminate_pseudostate_name );
	l_terminate_pseudostate->set_parent_region( this );
	auto& l_new_terminate_pseudostate = *l_terminate_pseudostate.get();
	m_pseudostates.push_back( std::move( l_terminate_pseudostate ) );
	return( l_new_terminate_pseudostate );
}


t_uri t_region::get_uri() const
{
	t_uri l_uri( get_name() );
	add_ancestor_uri( l_uri );
	return( l_uri );
}


void t_region::add_ancestor_uri( t_uri& p_uri ) const
{
	auto& l_parent = get_parent_state();
	p_uri.push_front( l_parent.get_name() );
	l_parent.add_ancestor_uri( p_uri );
}


bool t_region::is_active_state_final() const
{
	auto active_state_is_final_state = false;
	const auto final_state = dynamic_cast< const i_final_state* >( m_active_state );
	if( final_state != nullptr )
	{
		active_state_is_final_state = true;
	}

	return( active_state_is_final_state );
}


bool t_region::check( t_state_machine_defects& p_defects ) const
{
	auto l_check_ok = true;

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
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this, "Region '%' is empty!", get_name() ) );
		l_check_ok = false;
	}

	for( const auto & l_state : get_states() )
	{
		if( !l_state->check( p_defects ) )
		{
			l_check_ok = false;
		}
	}

	for( const auto & l_pseudostates : get_pseudostates() )
	{
		if( !l_pseudostates->check( p_defects ) )
		{
			l_check_ok = false;
		}
	}

	return( l_check_ok );
}


}
