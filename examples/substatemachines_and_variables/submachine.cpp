//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "submachine.hpp"

#include <iostream>

#include "sync_state_machine.hpp"
#include "region.hpp"

#include "events.hpp"


namespace examples
{		


submachine::submachine( sxy::sync_state_machine& _parent_state_machine, sxy::region& _parent_region )
:	
#ifndef SX_CPP03_BOOST
	submachine_( _parent_region.add_composite_state( "submachine", 
		Y_BEHAVIOR_METHOD2( this, &submachine::reset_members ) ) ),
#else
	submachine_( _parent_region.add_composite_state( "submachine", 
		Y_BEHAVIOR_METHOD_NO_EVENT( submachine, reset_members ) ) ),
#endif
	i_(),
	s_()
{	
	sxy::region& submachine_region = submachine_.add_region( "submachine region" );
	sxy::initial_pseudostate& submachine_initial_pseudostate = submachine_region.add_initial_pseudostate(
		"submachine_initial_pseudostate" );
#ifndef SX_CPP03_BOOST
	sxy::simple_state& submachine_simple_state_1 = submachine_region.add_simple_state( "submachine simple_state_1",
		Y_BEHAVIOR_METHOD2( this, &submachine::print_members ) );
	sxy::simple_state& submachine_simple_state_2 = submachine_region.add_simple_state( "submachine simple_state_2",
		Y_BEHAVIOR_METHOD2( this, &submachine::change_members ) );
#else
	sxy::simple_state& submachine_simple_state_1 = submachine_region.add_simple_state( "submachine simple_state_1",
		Y_BEHAVIOR_METHOD_NO_EVENT( submachine, print_members ) );
	sxy::simple_state& submachine_simple_state_2 = submachine_region.add_simple_state( "submachine simple_state_2",
		Y_BEHAVIOR_METHOD( submachine, change_members ) );
#endif

	_parent_state_machine.add_transition( sxy::Y_COMPLETION_EVENT_ID, submachine_initial_pseudostate, submachine_simple_state_1 );
	_parent_state_machine.add_transition( EVENT_5, submachine_simple_state_1, submachine_simple_state_2 );
	_parent_state_machine.add_transition( sxy::Y_COMPLETION_EVENT_ID, submachine_simple_state_2, submachine_simple_state_1 );
}


submachine::~submachine() SX_NOEXCEPT
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


#ifndef SX_CPP03_BOOST
void submachine::change_members( const event_5& _event)
#else
void submachine::change_members( const sxy::event& _event )
#endif 
{	
	++i_;
#ifndef SX_CPP03_BOOST
	s_ = _event.get_param();		
#else
	const event_5* event_with_param = dynamic_cast< const event_5* >( &_event );

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
