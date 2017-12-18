//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "file_reader.hpp"

#include <sstream>
#include <fstream>


namespace sx
{

namespace genesis
{


bool read( const std::string& _file_path, std::string& _content )
{
	bool read = false;
	std::ostringstream outputString;
	std::ifstream inputFile( _file_path.c_str(), std::ios::in );
	if( inputFile )
	{
		outputString << inputFile.rdbuf();
		inputFile.close();
		read = true;
	}
	_content = outputString.str();
	return ( read );
}


}


}
