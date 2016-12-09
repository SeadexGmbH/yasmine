//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "downcast_event.hpp"

#include <iostream>

#include "events.hpp"


namespace
{

typedef sxy::Y_UNIQUE_PTR< sxy::state_machine > state_machine_uptr;

						 
void do_something_event_2_parameters( const sxy::event& _event )
{
	const sxy::event_2* event_with_param = dynamic_cast< const sxy::event_2* >( &_event );

	if( event_with_param )
	{
		std::cout << "Parameters of event " << event_with_param->get_name() << " are:\n" <<
			event_with_param->get_param_1() << "\n" << event_with_param->get_param_2() << std::endl;
	}
	else
	{
		std::cout << "No event parameter.\n";
	}
}


void do_something_event_1_parameter( const sxy::event& _event )
{
	const sxy::event_1* event_with_param = dynamic_cast< const sxy::event_1* >( &_event );

	if( event_with_param )
	{
		std::cout << "Parameter of event " << event_with_param->get_name() << " is: " << event_with_param->get_param() <<
			std::endl;
	}
	else
	{
		Y_ASSERT( false, "No event parameter" );
	}
}


void do_something_event_0_parameters( const sxy::event& _event )
{
	std::cout << "Event with no parameters." << std::endl;
}


}


namespace sxy
{


state_machine_uptr setup_state_machine( const std::string& _name )
{
	state_machine_uptr state_machine = Y_MAKE_UNIQUE< sxy::state_machine >( _name );
	composite_state& root_state = state_machine->get_root_state();
	region& main_region = root_state.add_region( "main region" );
	initial_pseudostate& initial_pseudostate = main_region.add_initial_pseudostate( "initial" );
	simple_state& simple_state_1 = main_region.add_simple_state( "1", 
		Y_BEHAVIOUR_FUNCTION( do_something_event_2_parameters ), 
		Y_BEHAVIOUR_FUNCTION( do_something_event_2_parameters ),
		Y_BEHAVIOUR_FUNCTION( do_something_event_1_parameter ) );
	simple_state& simple_state_2 = main_region.add_simple_state( "2", 
		Y_BEHAVIOUR_FUNCTION( do_something_event_1_parameter ),
		Y_BEHAVIOUR_FUNCTION( do_something_event_1_parameter ),
		Y_BEHAVIOUR_FUNCTION( do_something_event_2_parameters ) );

	state_machine->add_transition( COMPLETION_EVENT_ID, initial_pseudostate, simple_state_1,
		Y_BEHAVIOUR_FUNCTION( do_something_event_0_parameters ) );
	state_machine->add_transition( EVENT_1, simple_state_1, simple_state_2,
		Y_BEHAVIOUR_FUNCTION( do_something_event_1_parameter ) );
	state_machine->add_transition( EVENT_2, simple_state_2, simple_state_1,
		Y_BEHAVIOUR_FUNCTION( do_something_event_2_parameters ) );
	return( sxy::move( state_machine ) );
}


void downcast_event()
{
	state_machine_uptr state_machine = setup_state_machine( "downcast_event_state_machine" );
	state_machine->start_state_machine();
	state_machine->fire_event( event_1::create( "parameter 1 test" ) );
	state_machine->fire_event( event_2::create( 2, 3.4 ) );
	state_machine->stop_state_machine();
}


}
