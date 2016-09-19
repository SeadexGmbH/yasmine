//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_cout_logger.h"

#include <iostream>
#include <iomanip>
#include <sstream>

#ifdef WIN32


#define WIN32_LEAN_AND_MEAN
#include <windows.h>


#endif

#include "globals.h"
#include "t_color_mapping.h"


namespace sxy
{


t_cout_logger::t_cout_logger()
	: i_logger()
{
}


void t_cout_logger::log( const t_log_message& p_log_message )
{
	std::stringstream log_stream;
	log_level_as_message( p_log_message.m_log_level_message );
	log_stream << " " << p_log_message.m_log_time_stamp;
	log_stream << " [" << p_log_message.m_log_file;
	log_stream << "@" << std::to_string( p_log_message.m_log_line );
	log_stream << "]: " << p_log_message.m_log_message;
	std::cout << log_stream.str() << std::endl;
}


void t_cout_logger::log_level_as_message( const sxy::t_log_level p_log_level )
{
	const auto l_log_level = log_level_to_string( p_log_level );

#ifdef WIN32

	CONSOLE_SCREEN_BUFFER_INFO l_console_screen_buffer_info;
	HANDLE l_handle = GetStdHandle( STD_OUTPUT_HANDLE );
	GetConsoleScreenBufferInfo( l_handle, &l_console_screen_buffer_info );
	const auto l_color = t_color_mapping().get_color( p_log_level );
	SetConsoleTextAttribute( l_handle, static_cast< WORD >( l_color ) );
	std::cout << " " << std::setw( g_log_level_block_width ) << std::setfill( ' ' ) << std::left << l_log_level;
	SetConsoleTextAttribute( l_handle, l_console_screen_buffer_info.wAttributes );

#else

	std::cout << " " << std::setw( g_log_level_block_width ) << std::setfill( ' ' ) << std::left << l_log_level;

#endif
}


}
