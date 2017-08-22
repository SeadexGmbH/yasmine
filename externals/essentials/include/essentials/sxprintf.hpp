//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef PRINTF_2B6FD3F2_C084_486B_805B_5F0E05B743E4
#define PRINTF_2B6FD3F2_C084_486B_805B_5F0E05B743E4


#include <string>
#include <sstream>


#ifdef SX_CPP03_BOOST
	#include <vector>
	#include <boost/variant.hpp>
#endif

#include "compatibility/compatibility.hpp"
#include "format_settings.hpp"


namespace sxe
{


#ifdef SX_CPP03_BOOST
	typedef boost::variant< bool, int, unsigned int, sxe::int8_t, sxe::uint8_t, sxe::uint16_t, sxe::uint32_t,
		std::string, std::size_t, const char*, int_least64_t, double > value_type;
	typedef std::vector< value_type > value_types;
#endif


extern const char PLACE_HOLDER;
extern const char* const SUPERFLUOUS_PARAMETER_START;
extern const char SUPERFLUOUS_PARAMETER_END;
extern const char OPENING_SQUARE_BRACKET;
extern const char CLOSING_SQUARE_BRACKET;


template< typename value > 
struct stream_writer
{
	static void print( std::ostream& _os, const value& _value )
	{
		_os << _value;
	}
};


template< >
struct stream_writer< sxe::uint8_t >
{
	static void print(std::ostream& _os, const sxe::uint8_t& _value)
	{
		_os << static_cast<unsigned int>( _value );
	}
};


// cppcheck-suppress unusedFunction
std::ostream& operator<<( std::ostream& _os, const sxe::format_settings& _format );
sxe::format_settings parse_format_string( const char** const _format );


#ifdef SX_CPP03_BOOST

void print_value_type_value( std::ostream& _os, const value_type& _value );


#endif


template< typename value > 
void print_superfluous_parameters( std::ostream& _os, const value& _value )
{
	_os << SUPERFLUOUS_PARAMETER_START;
#ifndef SX_CPP03_BOOST
	stream_writer< value >::print( _os, _value );
#else	
	print_value_type_value( _os, _value );
#endif
	_os << SUPERFLUOUS_PARAMETER_END;
}


#ifndef SX_CPP03_BOOST


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


void sxprintf(	std::ostream& _os, const char* _format );

#ifndef SX_CPP03_BOOST
template< typename value, typename ... args >
void sxprintf(	std::ostream& _os,	const char* _format, const value& _value, args ... _args )
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
					const sxe::format_settings format_settings = sxe::parse_format_string( &_format );
					const std::ios_base::fmtflags stream_flags = _os.flags();
					const char streafill_ = _os.fill();
					if( format_settings.correct_ )
					{
						_os << format_settings;
						stream_writer< value >::print( _os, _value );						
					}
					else
					{
						while( CLOSING_SQUARE_BRACKET != *( _format ) )
						{
							++_format;
						}
						stream_writer< value >::print( _os, _value );
						_os << format_settings;
					}
					_os.flags( stream_flags );
					_os.fill( streafill_ );
				}
				else
				{
					stream_writer< value >::print( _os, _value );
				}

				sxprintf( _os, _format + 1, _args ... );
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
std::string sxprintf(const char* const _format, args ... _args)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _args ...);
	return( target_string_stream.str() );
}

#else

std::string sxprintf(const char* const _format);
std::string sxprintf(const char* const _format, const value_type& _value1);
std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2);
std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3);
std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4);
std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5);
std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6);
std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6, const value_type& _value);
std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6, const value_type& _value7, const value_type& _value8);
std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6, const value_type& _value7, const value_type& _value8,
	const value_type& _value9);
std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6, const value_type& _value7, const value_type& _value8,
	const value_type& _value9, const value_type& _value10);


void sxprintf(std::ostream& _os, const char* const _format);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2, 
	const value_type& _value3);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2, 
	const value_type& _value3, const value_type& _value4);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2,
	const value_type& _value3, const value_type& _value4, const value_type& _value5);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2,
	const value_type& _value3, const value_type& _value4, const value_type& _value5, const value_type& _value6);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2,
	const value_type& _value3, const value_type& _value4, const value_type& _value5, const value_type& _value6,
	const value_type& _value7);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2,
	const value_type& _value3, const value_type& _value4, const value_type& _value5, const value_type& _value6,
	const value_type& _value7, const value_type& _value8);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2,
	const value_type& _value3, const value_type& _value4, const value_type& _value5, const value_type& _value6,
	const value_type& _value7, const value_type& _value8, const value_type& _value9);
void sxprintf(std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2,
	const value_type& _value3, const value_type& _value4, const value_type& _value5, const value_type& _value6,
	const value_type& _value7, const value_type& _value8, const value_type& _value9, const value_type& _value10);

	void sxprintf(std::ostream& _os, const char* const _format, const value_types& _values);

#endif
		 

}

#endif
