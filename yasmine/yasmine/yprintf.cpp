//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "yprintf.hpp"

#include <cctype>

#include "base.hpp"
#include "conversion.hpp"


namespace sxy
{


namespace
{


const char MISSING_PARAMETERS_MESSAGE[] = "[Missing parameter!]";
const char MISSING_TERMINATOR[] = "[Missing output modifier terminator!]";
const char ILLEGAL_MODIFIER[] = "[Illegal output modifier!]";
const char POINT = '.';
const char ZERO = '0';
const char X = 'x';
const char CAPS_X = 'X';


}


std::ostream& operator<<( std::ostream& _os,	const sxy::format_settings& _format )
{
	if( !_format.correct_ )
	{
		_os << ILLEGAL_MODIFIER;
	}
	else
	if( _format.missing_closing_bracket_ )
	{
		_os << MISSING_TERMINATOR;
	}
	else
	{
		if( _format.hex_ )
		{
			_os << std::hex;
			_os << std::showbase;
			_os.fill( '0' );
		}
		else
		{
			if( _format.pad_zeros_ )
			{
				_os.fill( '0' );
			}

			if( _format.places_set_ )
			{
				_os.width( _format.places_ );
			}

			if( _format.decimal_places_set_ )
			{
				_os.precision( _format.decimal_places_ );
			}
		}
	}

	return( _os );
}


bool is_allowed_char( const char _char )
{
	const bool success = ( std::isdigit( _char ) || ( X == _char ) || ( CAPS_X == _char ) );
	return( success );
}


sxy::format_settings parse_format_string( const char** const _format )
{
	sxy::format_settings format_settings;
	format_settings.correct_ = true;
	Y_ASSERT_NO_LOG( ( OPENING_SQUARE_BRACKET == **_format ), "Format string to parse doesn't start with [." );
	++*_format;
	format_settings.missing_closing_bracket_ = true;
	auto point_found = false;
	const char* text_before_point = *_format;
	size_t text_before_point_size = 0;
	const char* text_after_point = nullptr;
	size_t text_after_point_size = 0;
	while( **_format )
	{
		if( CLOSING_SQUARE_BRACKET == **_format )
		{
			format_settings.missing_closing_bracket_ = false;
			break;
		}
		else
		if( POINT == **_format )
		{
			if( point_found )
			{
				format_settings.correct_ = false;
				break;
			}
			else
			{
				point_found = true;
				text_after_point = ( *_format ) + 1;
				text_after_point_size = 0;
			}
		}
		else
		{
			const char _text_char = **_format;
			if( is_allowed_char( _text_char ) )
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
				format_settings.correct_ = false;
				break;
			}
		}

		++( *_format );
	}

	Y_ASSERT_NO_LOG( text_before_point, "Logic error parsing format string!" );
	if( ( 0 == text_before_point_size ) && ( 0 == text_after_point_size ) )
	{
		format_settings.correct_ = false;
	}

	if( ( !format_settings.missing_closing_bracket_ ) && format_settings.correct_ )
	{
		if( ( 0 < text_before_point_size ) && ( ( X == text_before_point[ 0 ] ) || ( CAPS_X == text_before_point[ 0 ] ) ) )
		{
			format_settings.hex_ = true;
			++text_before_point;
			--text_before_point_size;
		}

		if( ( 0 < text_before_point_size ) && ( ZERO == text_before_point[ 0 ] ) )
		{
			format_settings.pad_zeros_ = true;
			++text_before_point;
			--text_before_point_size;
		}

		if( 0 < text_before_point_size )
		{
			format_settings.places_set_ = true;
			if( !string_to_int( text_before_point, format_settings.places_ ) )
			{
				format_settings.correct_ = false;
			}
		}

		if( 0 < text_after_point_size )
		{
			Y_ASSERT_NO_LOG( text_after_point, "Logic error parsing format string!" );
			format_settings.decimal_places_set_ = true;
			if( !string_to_int( text_after_point, format_settings.decimal_places_ ) )
			{
				format_settings.correct_ = false;
			}
		}
	}

	return( format_settings );
}


void yprintf(	std::ostream& _os,	const char* _format )
{
	while( *_format )
	{
		if( PLACE_HOLDER == *_format )
		{
			if( PLACE_HOLDER == *( _format + 1 ) )
			{
				++_format;
			}
			else
			{
				_os << MISSING_PARAMETERS_MESSAGE;
			}
		}

		_os << *_format++;
	}
}


}
