//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "submachine.hpp"

#include <iostream>

#include "state_machine.hpp"
#include "region.hpp"

#include "events.hpp"


namespace sxy
{		


submachine::submachine( sxy::state_machine& _parent_state_machine, sxy::region& _parent_region )
:	
#ifndef Y_CPP03_BOOST
	submachine_( _parent_region.add_composite_state( "submachine", Y_BEHAVIOR_METHOD_NO_EVENT( reset_members ) ) ),
#else
	submachine_( _parent_region.add_composite_state( "submachine", Y_BEHAVIOR_METHOD_NO_EVENT( submachine, reset_members ) ) ),
#endif
	i_(),
	s_()
{	
	region& submachine_region = submachine_.add_region( "submachine region" );
	initial_pseudostate& submachine_initial_pseudostate = submachine_region.add_initial_pseudostate( 
		"submachine_initial_pseudostate" );
#ifndef Y_CPP03_BOOST
	simple_state& submachine_simple_state_1 = submachine_region.add_simple_state( "submachine simple_state_1",
		Y_BEHAVIOR_METHOD_NO_EVENT( print_members ) );
	simple_state& submachine_simple_state_2 = submachine_region.add_simple_state( "submachine simple_state_2",
		Y_BEHAVIOR_METHOD_EVENT( &submachine::change_members ) );
#else
	simple_state& submachine_simple_state_1 = submachine_region.add_simple_state( "submachine simple_state_1",
		Y_BEHAVIOR_METHOD_NO_EVENT( submachine, print_members ) );
	simple_state& submachine_simple_state_2 = submachine_region.add_simple_state( "submachine simple_state_2",
		sxy::behavior_function( sxy::bind( &submachine::change_members, this, sxy::_1 ) ) );
#endif

	_parent_state_machine.add_transition( COMPLETION_EVENT_ID, submachine_initial_pseudostate, submachine_simple_state_1 );
	_parent_state_machine.add_transition( EVENT_5, submachine_simple_state_1, submachine_simple_state_2 );
	_parent_state_machine.add_transition( COMPLETION_EVENT_ID, submachine_simple_state_2, submachine_simple_state_1 );
}


submachine::~submachine() Y_NOEXCEPT
{
	// Nothing to do...
}


sxy::composite_state& submachine::get_submachine_root_state() const
{
	return( submachine_ );
}


void submachine::reset_members()
{
	i_ = 0;
	s_ = "";
}


void submachine::print_members() const
{
	std::cout << i_ << " " << s_ << std::endl;
}


#ifndef Y_CPP03_BOOST
void submachine::change_members( const event_5& _event )
#else
void submachine::change_members( const event& _event )
#endif 
{
	++i_;
#ifndef Y_CPP03_BOOST
	s_ = _event.get_param();		
#else
	const sxy::event_5* event_with_param = dynamic_cast< const sxy::event_5* >( &_event );

	if( event_with_param )
	{
		s_ = event_with_param->get_param();
	}
	else
	{
		s_ = "";
	}
#endif
}


}
