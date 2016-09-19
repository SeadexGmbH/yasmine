//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include <memory>
#include <iostream>

#include "yasmine.h"
#include "version.h"


const sxy::event_id HELLO_EVENT = 1;
using state_machine_uptr = std::unique_ptr< sxy::state_machine >;


state_machine_uptr setup_state_machine( const std::string& _name )
{
	auto l_state_machine = std::make_unique< sxy::state_machine >( _name );

	auto& l_root_state = l_state_machine->get_root_state();
	auto& l_main_region = l_root_state.add_region( "main region" );
	auto l_waiting =	[ ] ( const sxy::event& _event ) 
										{ 
											Y_UNUSED_PARAMETER( _event ); 
											std::cout << "waiting" << std::endl;  
										};

	auto l_replying = [ ] ( const sxy::event& _event )
										{
											Y_UNUSED_PARAMETER( _event );
											std::cout << "Hello, yasmine!" << std::endl;
										};
	auto& l_initial_pseudostate = l_main_region.add_initial_pseudostate( "initial" );
	auto& l_simple_state_waiting = l_main_region.add_simple_state( "waiting", l_waiting );
	auto& l_simple_state_replying = l_main_region.add_simple_state( "replying", l_replying );

	l_state_machine->add_transition( "initial_transition", sxy::COMPLETION_EVENT, l_initial_pseudostate,
		l_simple_state_waiting );
	l_state_machine->add_transition( "waiting_to_replying_on_hello", HELLO_EVENT, l_simple_state_waiting,
		l_simple_state_replying );
	l_state_machine->add_transition( "replying_to_waiting_on_completion", sxy::COMPLETION_EVENT, l_simple_state_replying,
		l_simple_state_waiting );

	return( std::move( l_state_machine ) );
}


bool check_state_machine_for_defects( const sxy::state_machine& _state_machine )
{
	sxy::state_machine_defects defects;
	const auto state_machine_has_defects = _state_machine.check( defects );
	if( !state_machine_has_defects )
	{
		write_defects_to_log( defects );
	}

	return( state_machine_has_defects );
}


int main()
{
	auto error_code = 0;

	sxy::log_manager& log_manager = sxy::log_manager::get_instance();
	log_manager.set_log_level( sxy::log_level::LL_INFO );
	log_manager.add_logger( std::make_unique< sxy::cout_logger >() );
	log_manager.start();
	yasmine::version::log_version();

	const auto l_state_machine = setup_state_machine( "hello yasmine state machine" );
	if( check_state_machine_for_defects( *l_state_machine.get() ) )
	{
		l_state_machine->start_state_machine();
		try
		{
			l_state_machine->fire_event( sxy::event_impl::create_event( HELLO_EVENT ) );
			l_state_machine->fire_event( sxy::event_impl::create_event( HELLO_EVENT ) );
			l_state_machine->fire_event( sxy::event_impl::create_event( HELLO_EVENT ) );
			l_state_machine->stop_state_machine();
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
