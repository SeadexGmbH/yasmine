//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

#include "yasmine.hpp"


const sxy::event_id HELLO_EVENT = 1;
typedef sxe::SX_UNIQUE_PTR< sxy::sync_state_machine > state_machine_uptr;



void reply()
{
	std::cout << "Hello, yasmine!" << std::endl;
}


void wait()
{
	std::cout << "waiting" << std::endl;
}


state_machine_uptr setup_state_machine( const std::string& _name )
{
	state_machine_uptr state_machine = SX_MAKE_UNIQUE< sxy::sync_state_machine >( _name );	
	sxy::composite_state& root_state = state_machine->get_root_state();
	sxy::region& main_region = root_state.add_region( "main region" );
	sxy::initial_pseudostate& initial_pseudostate = main_region.add_initial_pseudostate( "initial" );
	sxy::simple_state& simple_state_waiting = main_region.add_simple_state( "waiting", Y_BEHAVIOR_FUNCTION2( wait ) );
	sxy::simple_state& simple_state_replying = main_region.add_simple_state( "replying", Y_BEHAVIOR_FUNCTION2( reply ) );
	state_machine->add_transition( HELLO_EVENT, simple_state_waiting, simple_state_replying );
	state_machine->add_transition( sxy::Y_COMPLETION_EVENT_ID, initial_pseudostate, simple_state_waiting );
	state_machine->add_transition( sxy::Y_COMPLETION_EVENT_ID, simple_state_replying, simple_state_waiting );

	return( state_machine );
}


bool check_state_machine_for_defects( const sxy::sync_state_machine& _state_machine )
{
	sxy::state_machine_defects defects;
	const bool state_machine_has_no_defects = _state_machine.check( defects );
	if( !state_machine_has_no_defects )
	{
		sxy::write_defects_to_log( defects );
	}

	return( state_machine_has_no_defects );
}


int main()
{
	int error_code = 0;
#ifndef SX_NO_LOGGING
	hermes::log_manager_template<hermes::std_timestamp_policy>& log_manager = hermes::log_manager::get_instance();
	log_manager.set_log_level( hermes::log_level::LL_FATAL );
	log_manager.add_logger( SX_MAKE_UNIQUE< hermes::cout_logger >() );
	log_manager.run();
	sxy::version::log_version();
#endif

	const state_machine_uptr hello_yasmine_state_machine = setup_state_machine( "hello yasmine state machine" );
	if( check_state_machine_for_defects( *hello_yasmine_state_machine ) )
	{
		hello_yasmine_state_machine->run();
		try
		{
			hello_yasmine_state_machine->fire_event( sxy::event_impl::create( HELLO_EVENT ) );
			hello_yasmine_state_machine->fire_event( sxy::event_impl::create( HELLO_EVENT ) );
			hello_yasmine_state_machine->fire_event( sxy::event_impl::create( HELLO_EVENT ) );
			hello_yasmine_state_machine->halt();
		}
		catch( const std::exception& exception )
		{
			SX_LOG( hermes::log_level::LL_FATAL, "Unhandled exception: '%'.", exception.what() );
			error_code = 1;
		}
		catch( ... )
		{
			SX_LOG( hermes::log_level::LL_FATAL, "Unknown exception!" );
			error_code = 2;
		}
	}
	else
	{
		error_code = 3;
	}

#ifndef SX_NO_LOGGING
	log_manager.halt_and_join();
#endif

	return( error_code );
}
