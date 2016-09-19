//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "cout_logger.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>

#ifdef WIN32


#define WIN32_LEAN_AND_MEAN
#include <windows.h>


#endif

#include "globals.hpp"
#include "color_mapping.hpp"


namespace sxy
{


cout_logger::cout_logger()
	: logger()
{
}


void cout_logger::log( const log_message& _log_message )
{
	std::stringstream log_stream;
	log_level_as_message( _log_message.log_level_ );
	log_stream << " " << _log_message.time_stamp_;
	log_stream << " [" << _log_message.file_;
	log_stream << "@" << std::to_string( _log_message.line_ );
	log_stream << "]: " << _log_message.message_;
	std::cout << log_stream.str() << std::endl;
}


void cout_logger::log_level_as_message( const sxy::log_level _log_level )
{
	const auto log_level = log_level_to_string( _log_level );

#ifdef WIN32

	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
	GetConsoleScreenBufferInfo( handle, &console_screen_buffer_info );
	const auto color = color_mapping().get_color( _log_level );
	SetConsoleTextAttribute( handle, static_cast< WORD >( color ) );
	std::cout << " " << std::setw( LOG_LEVEL_BLOCK_WIDTH ) << std::setfill( ' ' ) << std::left << log_level;
	SetConsoleTextAttribute( handle, console_screen_buffer_info.wAttributes );

#else

	std::cout << " " << std::setw( LOG_LEVEL_BLOCK_WIDTH ) << std::setfill( ' ' ) << std::left << log_level;

#endif
}


}
