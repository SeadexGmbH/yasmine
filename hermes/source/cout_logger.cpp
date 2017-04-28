//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING


#include "hermes/cout_logger.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>

#include "essentials/conversion.hpp"

#include "hermes/log_message.hpp"


#ifdef WIN32


#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef SX_NO_WINDOWS_H
	#include <windows.h>
#endif


#endif

#include "hermes/globals.hpp"


namespace hermes
{


cout_logger::cout_logger()
	: logger(),
		color_mapping_()
{
	// Nothing to do...
}


void cout_logger::log( const log_message& _log_message )
{
	std::stringstream log_stream;
	log_level_as_message( _log_message.log_level_ );
	log_stream << " " << _log_message.time_stamp_;
	log_stream << " [" << _log_message.file_;
	log_stream << "@" << sxe::to_string( _log_message.line_ );
	log_stream << "]: " << _log_message.message_;
	std::cout << log_stream.str() << std::endl;
}


void cout_logger::log_level_as_message( const hermes::log_level _log_level ) const
{
	const std::string& log_level = log_level_to_string( _log_level );

#ifdef WIN32

	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
	GetConsoleScreenBufferInfo( handle, &console_screen_buffer_info );
	const color color_of_log_level = color_mapping_.get_color( _log_level );
#ifndef SX_CPP03_BOOST
	SetConsoleTextAttribute( handle, static_cast< WORD >( color_of_log_level ) );
#else
	SetConsoleTextAttribute(handle, static_cast< WORD >( color_of_log_level.value_ ));
#endif
	std::cout << " " << std::setw( LOG_LEVEL_BLOCK_WIDTH ) << std::setfill( ' ' ) << std::left << log_level;
	SetConsoleTextAttribute( handle, console_screen_buffer_info.wAttributes );

#else

	std::cout << " " << std::setw( LOG_LEVEL_BLOCK_WIDTH ) << std::setfill( ' ' ) << std::left << log_level;

#endif


}


}


#endif
