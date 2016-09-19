//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "conversion.h"

#include <string>
#include <stdexcept>


namespace sxy
{


bool
string_to_int
(
	const char* const p_int_as_string,
	int& p_result
)
{
	auto success = false;

	try
	{
		p_result = std::stoi( std::string( p_int_as_string ) );
		success = true;
	}
	catch( const std::invalid_argument& )
	{
		success = false;
	}
	catch( const std::out_of_range& )
	{
		success = false;
	}

	return( success );
}


}
