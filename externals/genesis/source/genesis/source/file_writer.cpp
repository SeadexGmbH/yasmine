//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "file_writer.hpp"

#include <fstream>

#include "genesis_exception.hpp"
#include "messages.hpp"


namespace sx
{


namespace genesis
{


void write( const std::string& _file_path, const std::ostream& _output_stream )
{
#ifdef SX_CPP03_BOOST
	std::ofstream target_file( _file_path.c_str(), std::ios_base::out );
#else
	std::ofstream target_file( _file_path, std::ios_base::out );
#endif

	if( target_file.is_open() )
	{
		target_file << _output_stream.rdbuf();
		target_file.close();
	}
	else
	{
		throw sx::genesis::genesis_exception( ERROR_WRITE_FILE, _file_path );
	}
}


}


}
