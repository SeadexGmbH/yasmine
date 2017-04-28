//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING


#include "hermes/file_logger.hpp"

#include <iostream>
#include <iomanip>
#include <cstdio>

#include "essentials/conversion.hpp"

#include "hermes/file_system.hpp"
#include "hermes/globals.hpp"
#include "hermes/log_message.hpp"


namespace hermes
{


file_logger::file_logger( const size_t _max_file_size_in_bytes, const std::string& _log_files_directory, 
	const std::string& _name_suffix, const std::string& _name_extension, const unsigned _max_file_number, 
	const bool _throw_on_error ) : 
		max_file_size_in_bytes_( _max_file_size_in_bytes ),
		log_files_directory_( add_trailing_slash_to_directory_path( _log_files_directory ) ),
		name_sufix_( _name_suffix ),
		name_extension_( _name_extension ),
		max_file_number_( _max_file_number ),
		throw_on_error_( _throw_on_error ),
		working_file_()
{
	// Set member here to avoid future trouble with initialization order.
	working_file_ = get_working_log_file_name();
	rotate_if_necessary();
}


file_logger::~file_logger() SX_NOEXCEPT
{
	// Nothing to do...
}


void file_logger::log( const log_message& _log_message )
{
	const std::string log_level = log_level_to_string( _log_message.log_level_ );
	std::stringstream log_message_stream;
	log_message_stream << std::setw( LOG_LEVEL_BLOCK_WIDTH ) << std::setfill( ' ' ) << std::left << log_level <<
		" " << _log_message.time_stamp_ << " [" << _log_message.file_ << "@" << _log_message.line_ <<
		"]: " << _log_message.message_;
	log_into_file( log_message_stream.str() );
	rotate_if_necessary();
}


void file_logger::log_into_file( const std::string& _message ) const
{
	const bool append = does_file_exist( working_file_ );
	std::ios_base::openmode open_mode_flag;
	if( append )
	{
		open_mode_flag = std::ios::app;
	}
	else
	{
		open_mode_flag = std::ios::trunc;
	}

#ifndef SX_CPP03_BOOST
	std::ofstream file( working_file_, open_mode_flag );
#else
	std::ofstream file( working_file_.c_str(), open_mode_flag );
#endif
	if( !file )
	{
		const std::string error_message = sxe::sxprintf( "Failed to open file '%'.", working_file_ );
		if( throw_on_error_ )
		{
			throw exception( error_message );
		}
		else
		{
			std::cerr << error_message;
		}
	}

	file << _message << std::endl;
	file.close();
}


std::string file_logger::get_log_file_name_with_index( const unsigned _index ) const
{
	std::stringstream file_name_stream;
	file_name_stream << log_files_directory_ << name_sufix_ << sxe::to_string( _index ) << "." << name_extension_;
	return( file_name_stream.str() );
}


std::string file_logger::get_working_log_file_name() const
{
	return( log_files_directory_ + name_sufix_ + "." + name_extension_ );
}


void file_logger::rotate_if_necessary() const
{
	const size_t file_size = get_file_size( working_file_ );
	if( file_size > max_file_size_in_bytes_ )
	{
		rename_files();
	}
}


void file_logger::rename_files() const
{
	for( unsigned i = max_file_number_ - 1; i > 0; --i )
	{
		const std::string old_name = get_log_file_name_with_index( i - 1 );
		const std::string new_name = get_log_file_name_with_index( i );
		rename_file_if_exists( old_name, new_name );
	}

	// rename from foo.log to foo0.log
	rename_file_if_exists( working_file_, get_log_file_name_with_index( 0 ) );
}


void file_logger::rename_file_if_exists( const std::string& _old_name, const std::string& _new_name ) const
{
	if( does_file_exist( _old_name ) )
	{
		if( does_file_exist( _new_name ) )
		{
			delete_file( _new_name );
		}

		const int renamed = std::rename( _old_name.c_str(), _new_name.c_str() );
		if( renamed )
		{
			const std::string error_message = sxe::sxprintf( "File '%' could not be renamed!", _old_name );
			if( throw_on_error_ )
			{
				throw exception( error_message );
			}
			else
			{
				std::cerr << error_message;
			}
		}
	}
}


void file_logger::delete_file( const std::string& _file_name ) const
{
	const int removed = std::remove( _file_name.c_str() );
	if( removed > 0 )
	{
		const std::string error_message = sxe::sxprintf( "File '%' could not be deleted!\n", _file_name );
		if( throw_on_error_ )
		{
			throw exception( error_message );
		}
		else
		{
			std::cerr << error_message;
		}
	}
}


}


#endif
