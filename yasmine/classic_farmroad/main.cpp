//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_intersection.h"

#include <iostream>

#include "log.h"
#include "t_cout_logger.h"
#include "utils.h"
#include "version.h"


#ifdef WIN32
void
wait_for_quit_input
(
)
{		
	const HANDLE input_handle = GetStdHandle( STD_INPUT_HANDLE );

	bool continue_running = TRUE;
	while( continue_running )
	{
		INPUT_RECORD input_record;
		DWORD number_read;
		ReadConsoleInput
		( 
				input_handle,
				&input_record,
				1,
				&number_read
		);

		switch( input_record.EventType )
		{
		case KEY_EVENT:		
			if( input_record.Event.KeyEvent.uChar.AsciiChar == 'q' )
			{								
				continue_running = FALSE;
			}
			break;

		default:
			break;
		}
	}
}

#else
void
wait_for_quit_input
(
)
{
	while( true )
	{

		std::string a = "";
		std::cin >> a;
		if( a == "q" )
		{
			break;
		}
	}
}
#endif


int
main
(
)
{
	auto l_error_code = 0;

	sxy::utils::set_window_size( 250, 9999 );
	sxy::utils::maximize_window();
	
	sxy::t_log_manager& log_manager = sxy::t_log_manager::get_instance();
	log_manager.set_log_level( sxy::t_log_level::LL_DEBUG );
	log_manager.add_logger( std::make_unique< sxy::t_cout_logger >() );

	log_manager.start();

	yasmine::version::log_version();


	try
	{
		sxy::t_intersection l_intersection;

		if( l_intersection.start() )
		{
			std::cout << "To quit press 'q'." << std::endl;

			wait_for_quit_input();

			l_intersection.stop();
		}
		else
		{
			Y_LOG( sxy::t_log_level::LL_FATAL, "The intersection could not be started." );
			l_error_code = 1;
		}
	}
	catch( const std::exception& p_exception )
	{			
		Y_LOG( sxy::t_log_level::LL_FATAL, "Unhandled exception: '%'.", p_exception.what() );
		l_error_code = 2;
	}
	catch( ... )
	{		
		Y_LOG( sxy::t_log_level::LL_FATAL, "Unknown exception!" );
		l_error_code = 3;
	}

	log_manager.stop();
	log_manager.join();

	return( l_error_code );
}
