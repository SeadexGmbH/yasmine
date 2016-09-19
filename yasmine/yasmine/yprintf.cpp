//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "yprintf.h"

#include <cctype>

#include "base.h"
#include "conversion.h"


namespace sxy
{


namespace 
{


const std::string MISSING_PARAMETERS_MESSAGE = "[Missing parameter!]";
const std::string MISSING_TERMINATOR = "[Missing output modifier terminator!]";
const std::string ILLEGAL_MODIFIER = "[Illegal output modifier!]";
const char POINT = '.';
const char ZERO = '0';
const char X = 'x';
const char CAPS_X = 'X';


}



std::ostream&
operator<<
(
	std::ostream& p_os,
	const sxy::t_format_settings& p_format
)
{
	if( !p_format.m_correct )
	{
		p_os << ILLEGAL_MODIFIER;
	}
	else
	if( p_format.m_missing_closing_bracket )
	{
		p_os << MISSING_TERMINATOR;
	}
	else
	{
		if( p_format.m_hex )
		{
			p_os << std::hex;
			p_os << std::showbase;
			p_os.fill( '0' );
		}
		else
		{
			if( p_format.m_pad_zeros )
			{
				p_os.fill( '0' );
			}

			if( p_format.m_places_set )
			{
				p_os.width( p_format.m_places );
			}

			if( p_format.m_decimal_places_set )
			{
				p_os.precision( p_format.m_decimal_places );
			}
		}
	}

	return( p_os );
}


bool
is_allowed_char
(
	const char p_char
)
{
	const bool success = ( std::isdigit( p_char ) || ( X == p_char ) || ( CAPS_X == p_char ) );
	return( success );
}


sxy::t_format_settings
parse_format_string
(		
	const char * * const p_format
)
{
	sxy::t_format_settings format_settings;
	format_settings.m_correct = true;
	Y_ASSERT_NO_LOG( ( OPENING_SQUARE_BRACKET == **p_format ), "Format string to parse doesn't start with [." );
	++*p_format;
	format_settings.m_missing_closing_bracket = true;
	auto point_found = false;
	const char* text_before_point = *p_format;
	size_t text_before_point_size = 0;
	const char* text_after_point = nullptr;
	size_t text_after_point_size = 0;
	while( **p_format )
	{
		if( CLOSING_SQUARE_BRACKET == **p_format )
		{
			format_settings.m_missing_closing_bracket = false;
			break;
		}
		else if( POINT == **p_format )
		{
			if( point_found )
			{
				format_settings.m_correct = false;
				break;				
			}
			else
			{
				point_found = true;
				text_after_point = ( *p_format ) + 1;
				text_after_point_size = 0;
			}
		}
		else
		{
			const char p_text_char = **p_format;
			if( is_allowed_char( p_text_char ) )
			{
				if( point_found )
				{
					++text_after_point_size;
				}
				else
				{
					++text_before_point_size;
				}
			}
			else
			{
				format_settings.m_correct = false;
				break;
			}
		}

		++( *p_format );
	}

	Y_ASSERT_NO_LOG( text_before_point, "Logic error parsing format string!" );
	if( ( 0 == text_before_point_size ) && ( 0 == text_after_point_size ) )
	{
		format_settings.m_correct = false;
	}

	if( ( !format_settings.m_missing_closing_bracket ) && format_settings.m_correct )
	{
		if( ( 0 < text_before_point_size ) && ( ( X == text_before_point[ 0 ] ) || ( CAPS_X == text_before_point[ 0 ] ) ) )
		{
			format_settings.m_hex = true;
			++text_before_point;
			--text_before_point_size;
		}

		if( ( 0 < text_before_point_size ) && ( ZERO == text_before_point[ 0 ] ) )
		{
			format_settings.m_pad_zeros = true;
			++text_before_point;
			--text_before_point_size;
		}

		if( 0 < text_before_point_size )
		{
			format_settings.m_places_set = true;
			if( !string_to_int( text_before_point, format_settings.m_places ) )
			{
				format_settings.m_correct = false;
			}
		}

		if( 0 < text_after_point_size )
		{
			Y_ASSERT_NO_LOG( text_after_point, "Logic error parsing format string!" );
			format_settings.m_decimal_places_set = true;
			if( !string_to_int( text_after_point, format_settings.m_decimal_places ) )
			{
				format_settings.m_correct = false;
			}
		}
	}

	return( format_settings );
}


void
yprintf
(
	std::ostream& p_os,
	const char* p_format
)
{
	while( *p_format )
	{
		if( PLACE_HOLDER == *p_format )
		{
			if( PLACE_HOLDER == *( p_format + 1 ) )
			{
				++p_format;
			}
			else
			{
				p_os << MISSING_PARAMETERS_MESSAGE;
			}
		}

		p_os << *p_format++;
	}
}


}
