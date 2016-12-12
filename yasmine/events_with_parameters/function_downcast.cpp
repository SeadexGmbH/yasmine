//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "function_downcast.hpp"

#include <iostream>

#include "events.hpp"


namespace
{


typedef sxy::Y_UNIQUE_PTR< sxy::state_machine > state_machine_uptr;


#ifndef Y_CPP03_BOOST
void do_something_event_0_parameters( const sxy::completion_event& _event )
{
	std::cout << "Completion event has no parameters." << std::endl;
}
#else
void do_something_event_0_parameters( const sxy::event& _event )
{
	const sxy::completion_event* specialized_event = dynamic_cast< const sxy::completion_event* >( &_event );
	if( specialized_event )
	{
		std::cout << "Completion event has no parameters." << std::endl;
	}
	else
	{
		throw sxy::exception( "Invalid event type!" );
	}
}
#endif


#ifndef Y_CPP03_BOOST
void do_something_event_1_parameter( const sxy::event_1& _event )
{
	std::cout << "Parameter of event " << _event.get_name() << " is: " << _event.get_param() << std::endl;
}
#else
void do_something_event_1_parameter( const sxy::event& _event )
{
	const sxy::event_1* specialized_event = dynamic_cast< const sxy::event_1* >( &_event );
	if( specialized_event )
	{
		std::cout << "Parameter of event " << specialized_event->get_name() << " is: " << specialized_event->get_param() << std::endl;
	}
	else
	{
		throw sxy::exception( "Invalid event type!" );
	}
}
#endif


#ifndef Y_CPP03_BOOST
void do_something_event_2_parameters( const sxy::event_2& _event )
{
	std::cout << "Parameters of event " << _event.get_name() << " are:\n" << _event.get_param_1() << "\n" <<
		_event.get_param_2() << std::endl;
}
#else
void do_something_event_2_parameters( const sxy::event& _event )
{
	const sxy::event_2* specialized_event = dynamic_cast< const sxy::event_2* >( &_event );
	if( specialized_event )
	{
		std::cout << "Parameters of event " << specialized_event->get_name() << " are:\n" << specialized_event->get_param_1() << "\n" <<
			specialized_event->get_param_2() << std::endl;
	}
	else
	{
		const sxy::completion_event* specialized_event2 = dynamic_cast< const sxy::completion_event* >( &_event );
		if( specialized_event2 )
		{
			do_something_event_0_parameters( _event );
		}
		else
		{
			throw sxy::exception( "Invalid event type!" );
		}
	}
}
#endif


state_machine_uptr setup_state_machine2( const std::string& _name )
{
	state_machine_uptr state_machine = Y_MAKE_UNIQUE< sxy::state_machine >( _name );
	sxy::composite_state& root_state = state_machine->get_root_state();
	sxy::region& main_region = root_state.add_region( "main region" );
	sxy::initial_pseudostate& initial_pseudostate = main_region.add_initial_pseudostate( "initial" );
#ifndef Y_CPP03_BOOST
	sxy::simple_state& simple_state_1 =	main_region.add_simple_state( "1",
			Y_BEHAVIOR_FUNCTION_EVENT( &do_something_event_0_parameters, &do_something_event_2_parameters ),
			Y_BEHAVIOR_FUNCTION_EVENT( &do_something_event_0_parameters, &do_something_event_2_parameters ),
			Y_BEHAVIOR_FUNCTION_EVENT( &do_something_event_1_parameter ) );
	sxy::simple_state& simple_state_2 =	main_region.add_simple_state( "2", 
			Y_BEHAVIOR_FUNCTION_EVENT( &do_something_event_1_parameter ),
			Y_BEHAVIOR_FUNCTION_EVENT( &do_something_event_1_parameter ),
			Y_BEHAVIOR_FUNCTION_EVENT( &do_something_event_2_parameters ) );

	state_machine->add_transition( sxy::COMPLETION_EVENT_ID, initial_pseudostate, simple_state_1,
		Y_BEHAVIOR_FUNCTION_EVENT( &do_something_event_0_parameters ) );
	state_machine->add_transition( sxy::EVENT_1, simple_state_1, simple_state_2,
		Y_BEHAVIOR_FUNCTION_EVENT( &do_something_event_1_parameter ) );
	state_machine->add_transition( sxy::EVENT_2, simple_state_2, simple_state_1,
		Y_BEHAVIOR_FUNCTION_EVENT( &do_something_event_2_parameters ) );
#else
	sxy::simple_state& simple_state_1 = main_region.add_simple_state( "1",
		sxy::behavior_function( sxy::bind( &do_something_event_2_parameters, sxy::_1 ) ),
		sxy::behavior_function( sxy::bind( &do_something_event_2_parameters, sxy::_1 ) ),
		sxy::behavior_function( sxy::bind( &do_something_event_1_parameter, sxy::_1 ) ) );
	sxy::simple_state& simple_state_2 = main_region.add_simple_state( "2",
		sxy::behavior_function( sxy::bind( &do_something_event_1_parameter, sxy::_1 ) ),
		sxy::behavior_function( sxy::bind( &do_something_event_1_parameter, sxy::_1 ) ),
		sxy::behavior_function( sxy::bind( &do_something_event_2_parameters, sxy::_1 ) ) );

	state_machine->add_transition( COMPLETION_EVENT_ID, initial_pseudostate, simple_state_1,
		sxy::behavior_function( sxy::bind( &do_something_event_0_parameters, sxy::_1 ) ) );
	state_machine->add_transition( EVENT_1, simple_state_1, simple_state_2,
		sxy::behavior_function( sxy::bind( &do_something_event_1_parameter, sxy::_1 ) ) );
	state_machine->add_transition( EVENT_2, simple_state_2, simple_state_1,
		sxy::behavior_function( sxy::bind( &do_something_event_2_parameters, sxy::_1 ) ) );
#endif

	
	return( sxy::move( state_machine ) );
}


}


namespace sxy
{


void use_function_downcast()
{
	state_machine_uptr state_machine = setup_state_machine2( "downcast_event_state_machine" );
	state_machine->start_state_machine();
	state_machine->fire_event( event_1::create( "parameter 1 test" ) );
	state_machine->fire_event( event_2::create( 2, 3.4 ) );
	state_machine->stop_state_machine();
}


}
