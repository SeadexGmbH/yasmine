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


#ifdef Y_CPP03_BOOST
	#include <vector>
	#include <boost/variant.hpp>
#endif

#include "compatibility.hpp"
#include "format_settings.hpp"


namespace sxy
{


#ifdef Y_CPP03_BOOST
	typedef boost::variant< bool, int, unsigned int, sxy::int8_t, sxy::uint8_t, sxy::uint16_t, sxy::uint32_t,
		std::string, size_t, const char*, int_least64_t, double > log_value;
	typedef std::vector< log_value > log_values;
#endif


namespace
{


const char PLACE_HOLDER = '%';
const char* const SUPERFLUOUS_PARAMETER_START = "[Superfluous parameter: ";
const char SUPERFLUOUS_PARAMETER_END = ']';
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
struct stream_writer< sxy::uint8_t >
{
	static void print(std::ostream& _os, const sxy::uint8_t& _value)
	{
		_os << static_cast<unsigned int>( _value );
	}
};


// cppcheck-suppress unusedFunction
std::ostream& operator<<( std::ostream& _os, const sxy::format_settings& _format );
sxy::format_settings parse_format_string( const char** const _format );


#ifdef Y_CPP03_BOOST

void print_log_value( std::ostream& _os, const log_value& _value );


#endif


template< typename value > 
void print_superfluous_parameters( std::ostream& _os, const value& _value )
{
	_os << SUPERFLUOUS_PARAMETER_START;
#ifndef Y_CPP03_BOOST
	stream_writer< value >::print( _os, _value );
#else	
	print_log_value( _os, _value );
#endif
	_os << SUPERFLUOUS_PARAMETER_END;
}


#ifndef Y_CPP03_BOOST


template< typename value, typename ... args > 
void print_superfluous_parameters( std::ostream& _os, 
	const value& _value, args ... _args )
{
	_os << SUPERFLUOUS_PARAMETER_START;
	stream_writer< value >::print( _os, _value );
	_os << SUPERFLUOUS_PARAMETER_END;
	print_superfluous_parameters( _os, _args ... );
}


#else


#endif

void yprintf(	std::ostream& _os,	const char* _format );

#ifndef Y_CPP03_BOOST
template< typename value, typename ... args >
void yprintf(	std::ostream& _os,	const char* _format, const value& _value, args ... _args )
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
					const sxy::format_settings format_settings = sxy::parse_format_string( &_format );
					const std::ios_base::fmtflags stream_flags = _os.flags();
					const char streafill_ = _os.fill();
					_os << format_settings;
					stream_writer< value >::print( _os, _value );					
					_os.flags( stream_flags );
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
std::string yprintf(const char* const _format, args ... _args)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _args ...);
	return( target_string_stream.str() );
}

#else

std::string yprintf(const char* const _format);
std::string yprintf(const char* const _format, const log_value& _value1);
std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2);
std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3);
std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4);
std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5);
std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6);
std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value);
std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7, const log_value& _value8);
std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7, const log_value& _value8,
	const log_value& _value9);
std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7, const log_value& _value8,
	const log_value& _value9, const log_value& _value10);


void yprintf(std::ostream& _os, const char* const _format);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2, 
	const log_value& _value3);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2, 
	const log_value& _value3, const log_value& _value4);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2,
	const log_value& _value3, const log_value& _value4, const log_value& _value5);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2,
	const log_value& _value3, const log_value& _value4, const log_value& _value5, const log_value& _value6);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2,
	const log_value& _value3, const log_value& _value4, const log_value& _value5, const log_value& _value6,
	const log_value& _value7);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2,
	const log_value& _value3, const log_value& _value4, const log_value& _value5, const log_value& _value6,
	const log_value& _value7, const log_value& _value8);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2,
	const log_value& _value3, const log_value& _value4, const log_value& _value5, const log_value& _value6,
	const log_value& _value7, const log_value& _value8, const log_value& _value9);
void yprintf(std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2,
	const log_value& _value3, const log_value& _value4, const log_value& _value5, const log_value& _value6,
	const log_value& _value7, const log_value& _value8, const log_value& _value9, const log_value& _value10);

	void yprintf(std::ostream& _os, const char* const _format, const log_values& _values);

#endif
		 

}

#endif
