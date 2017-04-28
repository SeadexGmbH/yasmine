//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "essentials/conversion.hpp"

#include <stdexcept>
#include <algorithm>

#ifndef SX_CPP03_BOOST
	#include <string>
#else
	#include <sstream>
#endif


namespace sxe
{


bool string_to_int( const char* const _int_as_string, int& _result )
{
	bool success = false;
	try
	{
#ifndef SX_CPP03_BOOST
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


std::string to_string( const sxe::uint32_t _value )
{
#ifndef SX_CPP03_BOOST
	return( std::to_string( _value ) );
#else
	std::ostringstream ostr;
	ostr << _value;
	return( ostr.str() );
#endif
}


std::string to_string( const int _value )
{
#ifndef SX_CPP03_BOOST
	return( std::to_string( _value ) );
#else
	std::ostringstream ostr;
	ostr << _value;
	return( ostr.str() );
#endif
}


// cppcheck-suppress unusedFunction
std::string to_upper( const std::string& _value )
{
	std::string value_caps = _value;
	std::transform( value_caps.begin(), value_caps.end(), value_caps.begin(), ::toupper );
	return( value_caps );
}


// cppcheck-suppress unusedFunction
std::string to_lower( const std::string& _value )
{
	std::string value_to_lower = _value;
	std::transform( value_to_lower.begin(), value_to_lower.end(), value_to_lower.begin(), ::tolower );
	return( value_to_lower );
}


}
