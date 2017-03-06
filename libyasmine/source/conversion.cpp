//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "conversion.hpp"

#include <stdexcept>

#ifndef Y_CPP03_BOOST
	#include <string>
#else
	#include <sstream>
#endif


namespace sxy
{


bool string_to_int( const char* const _int_as_string, int& _result )
{
	bool success = false;
	try
	{
#ifndef Y_CPP03_BOOST
		_result = std::stoi( std::string( _int_as_string ) );
		success = true;
#else
		std::istringstream is( _int_as_string );
		if (is >> _result)
		{
			success = true;
		}
		else
		{
			success = false;
		}
#endif
		
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


std::string to_string( sxy::uint32_t _value )
{
#ifndef Y_CPP03_BOOST
	return( std::to_string( _value ) );
#else
	std::ostringstream ostr;
	ostr << _value;
	return( ostr.str() );
#endif
}


std::string to_string( int _value )
{
#ifndef Y_CPP03_BOOST
	return( std::to_string( _value ) );
#else
	std::ostringstream ostr;
	ostr << _value;
	return( ostr.str() );
#endif
}


}
