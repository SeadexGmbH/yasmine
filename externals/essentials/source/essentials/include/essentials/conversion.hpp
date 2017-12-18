//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CONVERSION_99CAC61B_DD8A_43E2_8612_0F42873A5741
#define CONVERSION_99CAC61B_DD8A_43E2_8612_0F42873A5741


#include "compatibility/compatibility.hpp"


namespace sxe
{


	//!\brief Converts a number from string to int.
	//!\param _int_as_string Number in string format.
	//!\param _result Variable where the result will be stored.
	//!\return True on success, false otherwise.
	bool string_to_int( const char* const _int_as_string, int& _result );

	//!\brief Converts a number from unsigned int 32 to string.
	//!\param _value Number to be converted.
	//!\return Number as string.
	std::string to_string( const sxe::uint32_t _value );

	//!\brief Converts a number from int to string.
	//!\param _value Number to be converted.
	//!\return Number as string.
	std::string to_string( const int _value );

	//!\brief Converts a string to uppercase.
	//!\param _value String to be converted.
	//!\return String in uppercase format.
	//!\sa to_lower
	std::string to_upper( const std::string& _value );

	//!\brief Converts a string to lowercase.
	//!\param _value String to be converted.
	//!\return String in lowercase format.
	//!\sa to_upper
	std::string to_lower( const std::string& _value );

}


#endif
