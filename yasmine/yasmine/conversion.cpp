//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "conversion.hpp"

#include <string>
#include <stdexcept>


namespace sxy
{


bool string_to_int(
	const char* const _int_as_string,
	int& _result )
{
	auto success = false;
	try
	{
		_result = std::stoi( std::string( _int_as_string ) );
		success = true;
	}
	catch ( const std::invalid_argument& )
	{
		success = false;
	}
	catch ( const std::out_of_range& )
	{
		success = false;
	}
	return( success );
}


}
