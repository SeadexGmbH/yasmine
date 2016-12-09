//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

#include "yasmine.hpp"
#include "version.hpp"


const sxy::event_id HELLO_EVENT = 1;
typedef sxy::Y_UNIQUE_PTR< sxy::state_machine > state_machine_uptr;



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
	state_machine_uptr state_machine = Y_MAKE_UNIQUE< sxy::state_machine >(_name);
	sxy::composite_state& root_state = state_machine->get_root_state();
	sxy::region& main_region = root_state.add_region( "main region" );
	sxy::initial_pseudostate& initial_pseudostate = main_region.add_initial_pseudostate( "initial" );
	sxy::simple_state& simple_state_waiting = main_region.add_simple_state( "waiting", Y_BEHAVIOUR_FUNCTION_NO_EVENT( wait ) );
	sxy::simple_state& simple_state_replying = main_region.add_simple_state( "replying", Y_BEHAVIOUR_FUNCTION_NO_EVENT( reply ) );
	
	state_machine->add_transition( HELLO_EVENT, simple_state_waiting, simple_state_replying );

#ifdef Y_CPP03_BOOST
	state_machine->add_transition( COMPLETION_EVENT_ID, initial_pseudostate, simple_state_waiting );
	state_machine->add_transition( COMPLETION_EVENT_ID, simple_state_replying, simple_state_waiting );
#else
	state_machine->add_transition( sxy::COMPLETION_EVENT_ID, initial_pseudostate, simple_state_waiting );
	state_machine->add_transition( sxy::COMPLETION_EVENT_ID, simple_state_replying, simple_state_waiting );
#endif
					
	return( sxy::move( state_machine ) );
}


bool check_state_machine_for_defects( const sxy::state_machine& _state_machine )
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

	sxy::log_manager_template<sxy::std_timestamp_policy>& log_manager = sxy::log_manager::get_instance();
	log_manager.set_log_level( sxy::log_level::LL_FATAL );
	log_manager.add_logger( Y_MAKE_UNIQUE< sxy::cout_logger >() );
	log_manager.start();
	yasmine::version::log_version();

	const state_machine_uptr hello_yasmine_state_machine = setup_state_machine( "hello yasmine state machine" );
	if( check_state_machine_for_defects( *hello_yasmine_state_machine ) )
	{
		hello_yasmine_state_machine->start_state_machine();
		try
		{
			hello_yasmine_state_machine->fire_event( sxy::event_impl::create( HELLO_EVENT ) );
			hello_yasmine_state_machine->fire_event( sxy::event_impl::create( HELLO_EVENT ) );
			hello_yasmine_state_machine->fire_event( sxy::event_impl::create( HELLO_EVENT ) );
			hello_yasmine_state_machine->stop_state_machine();
		}
		catch( const std::exception& exception )
		{
			Y_LOG( sxy::log_level::LL_FATAL, "Unhandled exception: '%'.", exception.what() );
			error_code = 1;
		}
		catch( ... )
		{
			Y_LOG( sxy::log_level::LL_FATAL, "Unknown exception!" );
			error_code = 2;
		}
	}
	else
	{
		error_code = 3;
	}

	log_manager.stop();
	log_manager.join();
	
	return( error_code );
}
