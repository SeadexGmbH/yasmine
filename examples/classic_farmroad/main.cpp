//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "intersection.hpp"

#include <iostream>

#include "logging.hpp"
#ifdef WIN32
	#include "utils.hpp"
#endif
#include "version.hpp"


#ifdef WIN32
void wait_for_quit_input()
{
	const HANDLE input_handle = GetStdHandle( STD_INPUT_HANDLE );
	bool continue_running = TRUE;
	while( continue_running )
	{
		INPUT_RECORD input_record;
		DWORD number_read;
		ReadConsoleInput(   input_handle, &input_record, 1, &number_read );

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
void wait_for_quit_input()
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


int main()
{
	int error_code = 0;

#ifdef WIN32
	sxy::utils::set_window_size( 250, 9999 );
	sxy::utils::maximize_window();
#endif	
	hermes::log_manager_template<hermes::std_timestamp_policy>& log_manager = hermes::log_manager::get_instance();
	log_manager.set_log_level( hermes::log_level::LL_DEBUG );
	log_manager.add_logger( SX_MAKE_UNIQUE< hermes::cout_logger >() );
	log_manager.run();
	sxy::version::log_version();

try
{
	examples::intersection intersection_of_roads;
	if( intersection_of_roads.start() )
	{
		std::cout << "To quit press 'q'." << std::endl;
		wait_for_quit_input();
		intersection_of_roads.stop();
	}
	else
	{
		SX_LOG( hermes::log_level::LL_FATAL, "The intersection could not be started." );
		error_code = 1;
	}
}
catch ( const std::exception& _exception )
{
	SX_LOG( hermes::log_level::LL_FATAL, "Unhandled exception: '%'.", _exception.what() );
	error_code = 2;
}
catch ( ... )
{
	SX_LOG( hermes::log_level::LL_FATAL, "Unknown exception!" );
	error_code = 3;
}

log_manager.halt_and_join();

	return( error_code );
}
