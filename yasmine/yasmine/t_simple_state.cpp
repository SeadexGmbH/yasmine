//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_simple_state.h"

#include "base.h"
#include "log.h"
#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_state_visitor.h"
#include "i_complex_state_visitor.h"
#include "i_region.h"
#include "i_behavior.h"
#include "t_state_machine_defects.h"


namespace sxy
{		 


t_simple_state::t_simple_state( const std::string& p_name, i_behavior_uptr do_action, i_behavior_uptr p_entry_action,
	i_behavior_uptr p_exit_action, const t_event_ids& p_deferred_events )
	: t_complex_state( p_name, std::move( p_entry_action ), std::move( p_exit_action ), p_deferred_events ), 
		m_do( std::move( do_action ) )
{
	// Nothing to do...
}


t_simple_state::~t_simple_state() = default;


const i_behavior* t_simple_state::get_do() const
{
	return( m_do.get() );
}


const t_regions& t_simple_state::get_regions() const
{
	static const t_regions l_regions;
	return( l_regions );
}


t_regions& t_simple_state::get_regions()
{
	static t_regions l_regions;
	return( l_regions );
}


void t_simple_state::accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_simple_state::accept_vertex_visitor( i_vertex_visitor& p_visitor )
{
	p_visitor.visit( *this );
}


void t_simple_state::accept_complex_state_visitor( i_complex_state_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_simple_state::accept_state_visitor( i_state_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_simple_state::execute_do_behavior( const i_event& p_event ) const
{
	const auto behavior = get_do();
	if( behavior )
	{
		Y_LOG( sxy::t_log_level::LL_DEBUG, "Executing state '%' behavior.", get_name() );
		( *behavior )( p_event );
	}
}


bool t_simple_state::check( t_state_machine_defects& p_defects ) const
{
	Y_UNUSED_PARAMETER( p_defects );
	auto l_check_ok = true;

	// 15.3.11 State -> Constraint [4]: A simple state is a state without any regions.
	// Enforced by design.
	// a state cannot defer an event that triggers a transition
	if( t_complex_state::check_if_one_of_the_deferred_events_triggers_a_transition() )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect >( *this,
				"Simple state '%' defer event that triggers a outgoing transition!", get_name() ) );
		l_check_ok = false;
	}

	return( l_check_ok );
}


}
