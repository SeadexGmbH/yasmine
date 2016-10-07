//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef PRINTF_2B6FD3F2_C084_486B_805B_5F0E05B743E4
#define PRINTF_2B6FD3F2_C084_486B_805B_5F0E05B743E4


#include <string>
#include <sstream>
#include <cstdint>

#include "format_settings.hpp"


namespace sxy
{


namespace
{


const char PLACE_HOLDER = '%';
const auto SUPERFLUOUS_PARAMETER_START = "[Superfluous parameter: ";
const auto SUPERFLUOUS_PARAMETER_END = "]";
const char OPENING_SQUARE_BRACKET = '[';
const char CLOSING_SQUARE_BRACKET = ']';


}


template< typename value > 
struct stream_writer
{
	static void print( std::ostream& _os, const value& _value )
	{
		_os << _value;
	}
};


template< > 
struct stream_writer< uint8_t >
{
	static void print( std::ostream& _os, const uint8_t& _value )
	{
		_os << static_cast< unsigned int >( _value );
	}
};


std::ostream& operator<<( std::ostream& _os,	const sxy::format_settings& _format );
sxy::format_settings parse_format_string( const char** const _format );

template< typename value > 
void print_superfluous_parameters( std::ostream& _os, const value& _value )
{
	_os << SUPERFLUOUS_PARAMETER_START;
	stream_writer< value >::print( _os, _value );
	_os << SUPERFLUOUS_PARAMETER_END;
}


template< typename value, typename ... args > 
void print_superfluous_parameters( std::ostream& _os, 
	const value& _value, args ... _args )
{
	_os << SUPERFLUOUS_PARAMETER_START;
	stream_writer< value >::print( _os, _value );
	_os << SUPERFLUOUS_PARAMETER_END;
	print_superfluous_parameters( _os, _args ... );
}


void yprintf(	std::ostream& _os,	const char* _format );

template< typename value, typename ... args > 
void yprintf(	std::ostream& _os,	const char* _format,
	const value& _value, args ... _args )
{
	while( *_format )
	{
		if( PLACE_HOLDER == *_format )
		{
			if( PLACE_HOLDER == *( _format + 1 ) )
			{
				++_format; // skip first place holder
				_os << *_format++; // output of the second place holder
			}
			else
			{
				if( OPENING_SQUARE_BRACKET == *( _format + 1 ) )
				{
					++_format;
					const auto format_settings = sxy::parse_format_string( &_format );
					const auto streaflags_ = _os.flags();
					const auto streafill_ = _os.fill();
					_os << format_settings;
					stream_writer< value >::print( _os, _value );
					_os.flags( streaflags_ );
					_os.fill( streafill_ );
				}
				else
				{
					stream_writer< value >::print( _os, _value );
				}

				yprintf( _os, _format + 1, _args ... );
				return;
			}
		}
		else
		{
			_os << *_format++;
		}
	}

	print_superfluous_parameters( _os, _value, _args ... );
}


//!\brief Creates a formatted message. The format string can contain placeholders ('%'s) that will be replaced with
//!the parameters by this function. To emit a '%' use two percent signs ("%%").
//!\param _format The format string in which will the placeholders will be replaced (if there are any).
//!\param _args The arguments that will replace the placeholders in the format string.	The number of parameters in
//!_args has to be equal to the number of placeholders in the format string. If you pass too few or too many 
//!arguments, the resulting string will contain diagnostics in the resulting string
//!([Missing parameter!] or [Superfluous parameter: x]).
//!\return String containing the complete formatted message.
template< typename ... args > 
std::string yprintf(	const char* const _format,	args ... _args )
{
	std::stringstream target_string_stream;
	yprintf( target_string_stream, _format, _args ... );
	return( target_string_stream.str() );
}


}

#endif
