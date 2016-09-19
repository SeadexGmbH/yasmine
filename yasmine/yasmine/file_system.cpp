//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "file_system.hpp"


namespace sxy
{


size_t get_file_size( const std::string& _file_name )
{
	std::ifstream in( _file_name, std::ios::binary | std::ios::ate );
	return( static_cast< size_t >( in.tellg() ) );
}


bool does_file_exist( const std::string& _file_name )
{
	auto file_exists = false;
	std::ifstream in( _file_name );
	if( in )
	{
		file_exists = true;
		in.close();
	}

	return( file_exists );
}


std::string add_trailing_slash_to_directory_path( const std::string& _path )
{
	auto log_file_directory_with_trailing_slash = _path;
	if( !log_file_directory_with_trailing_slash.empty() && ( *log_file_directory_with_trailing_slash.rbegin() != '/' ) &&
			( *log_file_directory_with_trailing_slash.rbegin() != '\\' ) )
	{
		log_file_directory_with_trailing_slash += '/';
	}

	if( !log_file_directory_with_trailing_slash.empty() && ( *log_file_directory_with_trailing_slash.rbegin() != '\\' ) )
	{
		*log_file_directory_with_trailing_slash.rbegin() = '/';
	}

	if( log_file_directory_with_trailing_slash.empty() )
	{
		log_file_directory_with_trailing_slash = "./";
	}

	return( log_file_directory_with_trailing_slash );
}


}
