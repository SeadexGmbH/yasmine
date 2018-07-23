//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "class_method_downcast.hpp"

#include <iostream>

#include "event_collector.hpp"


namespace examples
{


class_method_downcast::class_method_downcast()
{
	state_machine_uptr state_machine = setup_state_machine( "downcast_event_state_machine" );
	state_machine->run();
	state_machine->fire_event( event_1::create( "parameter 1 test" ) );
	state_machine->fire_event( event_2::create( 2, 3.4 ) );
	state_machine->halt();
}


class_method_downcast::~class_method_downcast() SX_NOEXCEPT
{
	// Nothing to do...
}


void class_method_downcast::do_something_event_2_parameters( const event_2& _event, sxy::event_collector& _event_collector )
{
	SX_UNUSED_PARAMETER( _event_collector );
	std::cout << "Parameters of event " << _event.get_name() << " are:\n" << _event.get_param_1() << "\n" <<
		_event.get_param_2() << std::endl;
}


void class_method_downcast::do_something_event_1_parameter( const event_1& _event, sxy::event_collector& _event_collector )
{
	SX_UNUSED_PARAMETER( _event_collector );
	std::cout << "Parameter of event " << _event.get_name() << " is: " << _event.get_param() << std::endl;
}


void class_method_downcast::do_something_event_0_parameters( const sxy::completion_event& _event, sxy::event_collector& _event_collector )
{
	SX_UNUSED_PARAMETER( _event );
	SX_UNUSED_PARAMETER( _event_collector );
	std::cout << "Completion event has no parameters." << std::endl;
}


state_machine_uptr class_method_downcast::setup_state_machine( const std::string& _name )
{
	state_machine_uptr state_machine = SX_MAKE_UNIQUE< sxy::sync_state_machine >( _name );
	sxy::composite_state& root_state = state_machine->get_root_state();
	sxy::region& main_region = root_state.add_region( "main region" );
	sxy::initial_pseudostate& initial_pseudostate = main_region.add_initial_pseudostate( "initial" );
#ifndef SX_CPP03_BOOST
	sxy::simple_state& simple_state_1 = main_region.add_simple_state( "1",
		Y_BEHAVIOR_METHOD2( this, &class_method_downcast::do_something_event_2_parameters,
			&class_method_downcast::do_something_event_0_parameters ),
		Y_BEHAVIOR_METHOD2( this, &class_method_downcast::do_something_event_2_parameters,
				&class_method_downcast::do_something_event_0_parameters),
#else
	sxy::simple_state& simple_state_1 = main_region.add_simple_state( "1",
		Y_BEHAVIOR_METHOD2_2( this, &class_method_downcast::do_something_event_2_parameters,
			&class_method_downcast::do_something_event_0_parameters ),
		Y_BEHAVIOR_METHOD2_2( this, &class_method_downcast::do_something_event_2_parameters,
			&class_method_downcast::do_something_event_0_parameters ),
#endif
		Y_BEHAVIOR_METHOD2( this, &class_method_downcast::do_something_event_1_parameter ) );

	sxy::simple_state& simple_state_2 = main_region.add_simple_state( "2",
		Y_BEHAVIOR_METHOD2( this, &class_method_downcast::do_something_event_1_parameter ),
		Y_BEHAVIOR_METHOD2( this, &class_method_downcast::do_something_event_1_parameter ),
		Y_BEHAVIOR_METHOD2( this, &class_method_downcast::do_something_event_2_parameters ) );

	state_machine->add_transition( sxy::Y_COMPLETION_EVENT_ID, initial_pseudostate, simple_state_1,
		Y_BEHAVIOR_METHOD2( this, &class_method_downcast::do_something_event_0_parameters ) );
	state_machine->add_transition( EVENT_1, simple_state_1, simple_state_2,
		Y_BEHAVIOR_METHOD2( this, &class_method_downcast::do_something_event_1_parameter ) );
	state_machine->add_transition( EVENT_2, simple_state_2, simple_state_1,
		Y_BEHAVIOR_METHOD2( this, &class_method_downcast::do_something_event_2_parameters ) );

	return( state_machine );
}


void use_method_downcast()
{
	class_method_downcast method_downcast;
}


}
