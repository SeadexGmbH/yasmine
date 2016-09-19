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

#include "t_format_settings.h"


namespace sxy
{


namespace
{


const char PLACE_HOLDER = '%';
const std::string SUPERFLUOUS_PARAMETER_START = "[Superfluous parameter: ";
const std::string SUPERFLUOUS_PARAMETER_END = "]";
const char OPENING_SQUARE_BRACKET = '[';
const char CLOSING_SQUARE_BRACKET = ']';


}


template< typename tt_value >
struct t_stream_writer
{
	static void
	print
	(
		std::ostream& p_os,
		const tt_value& p_value
	)
	{
		p_os << p_value;
	}


};


template<>
struct t_stream_writer< uint8_t >
{
	static void
	print
	(
		std::ostream& p_os,
		const uint8_t& p_value
	)
	{
		p_os << static_cast< unsigned int >( p_value );
	}


};


std::ostream& operator<<
(
	std::ostream& p_os,
	const sxy::t_format_settings& p_format
);

								
sxy::t_format_settings parse_format_string
(
	const char * * const p_format
);


template< typename tt_value >
void
print_superfluous_parameters
(
	std::ostream& p_os,
	const tt_value& p_value
)
{
	p_os << SUPERFLUOUS_PARAMETER_START;
	t_stream_writer< tt_value >::print( p_os, p_value );
	p_os << SUPERFLUOUS_PARAMETER_END;
}


template< typename tt_value, typename ... tt_args >
void
print_superfluous_parameters
(
	std::ostream& p_os,
	const tt_value& p_value,
	tt_args ... p_args
)
{
	p_os << SUPERFLUOUS_PARAMETER_START;
	t_stream_writer< tt_value >::print( p_os, p_value );
	p_os << SUPERFLUOUS_PARAMETER_END;
	print_superfluous_parameters( p_os, p_args ... );
}


void yprintf
(
	std::ostream& p_os,
	const char* p_format
);


template< typename tt_value, typename ... tt_args >
void
yprintf
(
	std::ostream& p_os,
	const char* p_format,
	const tt_value& p_value,
	tt_args ... p_args
)
{
	while( *p_format )
	{
		if( PLACE_HOLDER == *p_format )
		{
			if( PLACE_HOLDER == *( p_format + 1 ) )
			{
				++p_format; // skip first place holder
				p_os << *p_format++; // output of the second place holder
			}
			else
			{
				if( OPENING_SQUARE_BRACKET == *( p_format + 1 ) )
				{
					++p_format;
					const auto format_settings = sxy::parse_format_string( &p_format );
					const auto stream_flags = p_os.flags();
					const auto stream_fill = p_os.fill();
					p_os << format_settings;
					t_stream_writer< tt_value >::print( p_os, p_value );
					p_os.flags( stream_flags );
					p_os.fill( stream_fill );
				}
				else
				{
					t_stream_writer< tt_value >::print( p_os, p_value );
				}

				yprintf( p_os, p_format + 1, p_args ... );
				return;
			}
		}
		else
		{
			p_os << *p_format++;
		}
	}

	print_superfluous_parameters( p_os, p_value, p_args ... );
}


//!\brief Creates a formatted message. The format string can contain placeholders ('%'s) that will be replaced with the parameters by this function. To emit
//! a '%' use two percent signs ("%%").
//!\param p_format The format string in which will the placeholders will be replaced (if there are any).
//!\param p_args The arguments that will replace the placeholders in the format string.	The number of parameters in p_args has to be equal to the number of 
//! placeholders in the format string.
//! If you pass too few or too many arguments, the resulting string will contain diagnostics in the resulting string ([Missing parameter!] or [Superfluous parameter: x]).
//!\return String containing the complete formatted message.
template< typename ... tt_args >
std::string
yprintf
(
	const char* const p_format,
	tt_args ... p_args
)
{
	std::stringstream target_string_stream;
	yprintf( target_string_stream, p_format, p_args ... );
	return( target_string_stream.str() );
}


}


#endif
