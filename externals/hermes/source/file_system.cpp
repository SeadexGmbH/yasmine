//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "hermes/file_system.hpp"


namespace hermes
{


size_t get_file_size( const std::string& _file_name )
{
#ifndef SX_CPP03_BOOST
	std::ifstream in( _file_name, std::ios::binary | std::ios::ate );
#else
	std::ifstream in( _file_name.c_str(), std::ios::binary | std::ios::ate );
#endif
	return( static_cast< size_t >( in.tellg() ) );
}


bool does_file_exist( const std::string& _file_name )
{
	bool file_exists = false;
#ifndef SX_CPP03_BOOST
	std::ifstream in( _file_name );
#else
	std::ifstream in( _file_name.c_str() );
#endif
	if( in )
	{
		file_exists = true;
		in.close();
	}

	return( file_exists );
}


std::string add_trailing_slash_to_directory_path( const std::string& _path )
{
	std::string log_file_directory_with_trailing_slash = _path;
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
