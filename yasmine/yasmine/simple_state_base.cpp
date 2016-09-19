//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "simple_state_base.h"

#include "base.h"
#include "const_vertex_visitor.h"
#include "vertex_visitor.h"
#include "state_visitor.h"
#include "complex_state_visitor.h"
#include "state_machine_defect.h"
#include "region.h"


namespace sxy
{


simple_state_base::simple_state_base( const std::string& _name, behavior_uptr _entry_action,
	behavior_uptr _exit_action, const event_ids& _deferred_events, behavior_exception_uptr _error_event)
	: complex_state_impl( _name, std::move( _entry_action ), std::move( _exit_action ), _deferred_events ),
	error_event_( std::move(_error_event) )
{
	// Nothing to do...
}
	
	
simple_state_base::~simple_state_base
(
) = default;


const regions& simple_state_base::get_regions() const
{
	static const regions regions;
	return( regions );
}


regions& simple_state_base::get_regions()
{
	static regions regions;
	return( regions );
}


void simple_state_base::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void simple_state_base::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void simple_state_base::accept_complex_state_visitor( complex_state_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void simple_state_base::accept_state_visitor( state_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


bool simple_state_base::check( state_machine_defects& _defects ) const
{
	Y_UNUSED_PARAMETER( _defects );
	auto check_ok = true;

	// 15.3.11 State -> Constraint [4]: A simple state is a state without any regions.
	// Enforced by design.
	// a state cannot defer an event that triggers a transition
	if( complex_state_impl::check_if_one_of_the_deferred_events_triggers_a_transition() )
	{
		_defects.push_back( std::make_unique< state_machine_defect >( *this,
			"Simple state '%' defer event that triggers a outgoing transition!", get_name() ) );
		check_ok = false;
	}

	return( check_ok );
}


bool simple_state_base::has_error_event() const
{		
	const auto state_has_error_event = ( error_event_ != nullptr );
	return( state_has_error_event );
}


const behavior_exception* const simple_state_base::get_error_event() const
{
	return( error_event_.get() );
}


}
