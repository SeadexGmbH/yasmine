//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_file_logger.h"

#include <iostream>
#include <iomanip>
#include <cstdio>

#include "file_system.h"
#include "globals.h"


namespace sxy
{


t_file_logger::t_file_logger
(
	const size_t p_max_file_size_in_bytes,
	const std::string& p_log_files_directory,
	const std::string& p_name_suffix,
	const std::string& p_name_extension,
	const unsigned p_max_file_number,
	const bool p_throw_on_error
):
	m_max_file_size_in_bytes( p_max_file_size_in_bytes ),
	m_log_files_directory( add_trailing_slash_to_directory_path( p_log_files_directory ) ),
	m_name_sufix( p_name_suffix ),
	m_name_extension( p_name_extension ),
	m_max_file_number( p_max_file_number ),	
	m_throw_on_error(p_throw_on_error),
	m_working_file()
{
	// Set member here to avoid future trouble with initialization order.
	m_working_file = get_working_log_file_name();
	rotate_if_necessary();
}


void
t_file_logger::log
(
	const t_log_message& p_log_message
)
{		
	const auto l_log_level = log_level_to_string( p_log_message.m_log_level_message );

	std::stringstream log_message_stream;
	log_message_stream << std::setw( g_log_level_block_width ) << std::setfill( ' ' ) << std::left << l_log_level << " " << p_log_message.m_log_time_stamp << " [" << p_log_message.m_log_file << "@" << p_log_message.m_log_line << "]: " << p_log_message.m_log_message;

	log_into_file( log_message_stream.str() );
	rotate_if_necessary();
}


void
t_file_logger::log_into_file
(		
	const std::string& p_message
) const
{
	const bool append = does_file_exist( m_working_file );

	std::ios_base::openmode l_open_mode_flag;
	if( append )
	{
		l_open_mode_flag = std::ios::app;
	}
	else
	{
		l_open_mode_flag = std::ios::trunc;
	}

	std::ofstream file( m_working_file, l_open_mode_flag );

	if( !file )
	{
		auto l_error_message = yprintf( "Failed to open file '%'.", m_working_file );
		if( m_throw_on_error )
		{
			throw t_exception( l_error_message );
		}
		else
		{
			std::cerr << l_error_message;
		}
	}

	file << p_message << std::endl;
	file.close();
}


std::string
t_file_logger::get_log_file_name_with_index
(
	const unsigned p_index
) const
{
	std::stringstream l_file_name_stream;
	l_file_name_stream << m_log_files_directory << m_name_sufix << std::to_string( p_index ) << "." << m_name_extension;	

	return( l_file_name_stream.str() );
}


std::string
t_file_logger::get_working_log_file_name
(
) const
{
	return( m_log_files_directory + m_name_sufix + "." + m_name_extension );
}


void
t_file_logger::rotate_if_necessary
(
) const
{		
	const auto l_file_size = get_file_size( m_working_file );
	if( l_file_size  > m_max_file_size_in_bytes )
	{
		rename_files();
	}
}


void
t_file_logger::rename_files
(
) const
{
	for( unsigned i = m_max_file_number - 1; i > 0; --i )
	{
		const auto l_old_name = get_log_file_name_with_index( i - 1 );
		const auto l_new_name = get_log_file_name_with_index( i );

		rename_file_if_exists( l_old_name, l_new_name );
	}

	// rename from foo.log to foo0.log
	rename_file_if_exists( m_working_file, get_log_file_name_with_index( 0 ) );
}


void 
t_file_logger::rename_file_if_exists
(
	const std::string& p_old_name,
	const std::string& p_new_name
) const
{		
	if( does_file_exist( p_old_name ) )
	{
		if( does_file_exist( p_new_name ) )
		{
			delete_file( p_new_name );
		}

		const auto l_renamed = std::rename( p_old_name.c_str(), p_new_name.c_str() );
		if( l_renamed )
		{
			const auto l_error_message = yprintf( "File '%' could not be renamed!", p_old_name );
			if( m_throw_on_error )
			{
				throw t_exception( l_error_message );
			}
			else
			{
				std::cerr << l_error_message;
			}
		}
	}
}


void
t_file_logger::delete_file
(
	const std::string& p_file_name
) const
{
	const auto l_removed = std::remove( p_file_name.c_str() );
	if( l_removed > 0 )
	{
		const auto l_error_message = yprintf( "File '%' could not be deleted!\n", p_file_name );
		if( m_throw_on_error )
		{
			throw t_exception( l_error_message );
		}
		else
		{
			std::cerr << l_error_message;
		}
	}
}


}
