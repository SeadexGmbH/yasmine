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

#include "t_state_machine.h"
#include "t_cout_logger.h"
#include "version.h"

#include "t_event.h"
#include "t_transition.h"
#include "i_region.h"
#include "i_composite_state.h"
#include "i_simple_state.h"
#include "i_initial_pseudostate.h"


const sxy::t_event_id g_hello_event = 1;
using t_state_machine_uptr = std::unique_ptr< sxy::t_state_machine >;


t_state_machine_uptr
setup_state_machine
(
	const std::string& p_name
)
{		
	auto l_state_machine = std::make_unique< sxy::t_state_machine >( p_name );
	auto& l_root_state = l_state_machine->get_root_state();
	auto& l_main_region = l_root_state.add_region( "main region" );

	auto l_waiting = [] ( const sxy::i_event& p_event ) { Y_UNUSED_PARAMETER( p_event ); std::cout << "waiting" << std::endl;  };
	auto l_replying = [] ( const sxy::i_event& p_event ) { Y_UNUSED_PARAMETER( p_event ); std::cout << "Hello, yasmine!" << std::endl;  };

	auto& l_initial_pseudostate = l_main_region.add_initial_pseudostate( "initial" );
	auto& l_simple_state_waiting = l_main_region.add_simple_state( "waiting", l_waiting );
	auto& l_simple_state_replying = l_main_region.add_simple_state( "replying", l_replying );	
	
	l_state_machine->add_transition( "initial_transition", sxy::COMPLETION_EVENT, l_initial_pseudostate, l_simple_state_waiting );
	l_state_machine->add_transition( "waiting_to_replying_on_hello", g_hello_event, l_simple_state_waiting, l_simple_state_replying );
	l_state_machine->add_transition( "replying_to_waiting_on_completion", sxy::COMPLETION_EVENT, l_simple_state_replying, l_simple_state_waiting );
	
	return ( std::move( l_state_machine ) );
}


bool
check_state_machine_for_defects
(
	const sxy::t_state_machine& p_state_machine
)
{
	sxy::t_state_machine_defects l_defects;
	const auto l_state_machine_has_defects = p_state_machine.check( l_defects );

	if( !l_state_machine_has_defects )
	{
		write_defects_to_log( l_defects );
	}

	return( l_state_machine_has_defects );	
}


int 
main
(
)
{	 
	auto l_error_code = 0;

	sxy::t_log_manager& log_manager = sxy::t_log_manager::get_instance();
	log_manager.set_log_level( sxy::t_log_level::LL_INFO );
	log_manager.add_logger( std::make_unique< sxy::t_cout_logger >() );
	log_manager.start();
	yasmine::version::log_version();

	const auto l_state_machine = setup_state_machine( "hello yasmine state machine" );

	if( check_state_machine_for_defects( *l_state_machine.get() ) )
	{		
		l_state_machine->start_state_machine();
		try
		{
			l_state_machine->fire_event( sxy::t_event::create_event( g_hello_event ) );
			l_state_machine->fire_event( sxy::t_event::create_event( g_hello_event ) );
			l_state_machine->fire_event( sxy::t_event::create_event( g_hello_event ) );
		}
		catch( const std::exception& p_exception )
		{
			Y_LOG( sxy::t_log_level::LL_FATAL, "Unhandled exception: '%'.", p_exception.what() );
			l_error_code = 1;
		}
		catch( ... )
		{				
			Y_LOG( sxy::t_log_level::LL_FATAL, "Unknown exception!" );
			l_error_code = 2;
		}		
	}
	else
	{			
		l_error_code = 3;		
	}

	log_manager.stop();
	log_manager.join();

	return ( l_error_code );
}
