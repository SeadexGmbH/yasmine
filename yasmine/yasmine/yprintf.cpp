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


std::ostream& operator<<(	std::ostream& _os, const sxy::format_settings& _format )
{
	if( !_format.correct_ )
	{
		_os << ILLEGAL_MODIFIER;
	}
	else if( _format.missing_closing_bracket_ )
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
	bool point_found = false;
	const char* text_before_point = *_format;
	size_t text_before_point_size = 0;
	const char* text_after_point = Y_NULLPTR;
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


#ifdef Y_CPP03_BOOST


void print_superfluous_parameters( std::ostream& _os, const log_values& _values, log_values::const_iterator& _position )
{
	while( _position != _values.end() )
	{
		print_superfluous_parameters( _os, *_position );
		++_position;
	}
}


#endif


void yprintf( std::ostream& _os, const char* _format )
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


#ifdef Y_CPP03_BOOST


std::string yprintf(const char* const _format)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1, _value2);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1, _value2, _value3);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3, 
	const log_value& _value4)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1, _value2, _value3, _value4);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6, _value7);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7, const log_value& _value8)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7, const log_value& _value8, 
	const log_value& _value9)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9);
	return( target_string_stream.str() );
}


std::string yprintf(const char* const _format, const log_value& _value1, const log_value& _value2, const log_value& _value3,
	const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7, const log_value& _value8,
	const log_value& _value9, const log_value& _value10)
{
	std::stringstream target_string_stream;
	yprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10);
	return( target_string_stream.str() );
}


void yprintf( std::ostream& _os, const char* const _format, const log_value& _value1 )
{
	log_values values;
	values.push_back( _value1 );
	yprintf( _os, _format, values );
}


void yprintf( std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2 )
{
	log_values values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	yprintf( _os, _format, values );
}


void yprintf( std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2, 
	const log_value& _value3 )
{
	log_values values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	yprintf( _os, _format, values );
}


void yprintf( std::ostream& _os, const char* const _format, const log_value& _value1, const log_value& _value2,
	const log_value& _value3,	const log_value& _value4 )
{
	log_values values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	yprintf( _os, _format, values );
}


void yprintf( std::ostream& _os, const char* const _format,	const log_value& _value1,	const log_value& _value2,
	const log_value& _value3,	const log_value& _value4,	const log_value& _value5 )
{
	log_values values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	yprintf( _os, _format, values );
}


void yprintf(	std::ostream& _os, const char* const _format,	const log_value& _value1,	const log_value& _value2,
	const log_value& _value3,	const log_value& _value4,	const log_value& _value5,	const log_value& _value6 )
{
	log_values values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	values.push_back( _value6 );
	yprintf( _os, _format, values );
}


void yprintf(	std::ostream& _os, const char* const _format,	const log_value& _value1,	const log_value& _value2,
	const log_value& _value3,	const log_value& _value4,	const log_value& _value5,	const log_value& _value6,
	const log_value& _value7 )
{
	log_values values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	values.push_back( _value6 );
	values.push_back( _value7 );
	yprintf( _os, _format, values );
}


void yprintf( std::ostream& _os, const char* const _format,	const log_value& _value1,	const log_value& _value2,
	const log_value& _value3,	const log_value& _value4,	const log_value& _value5,	const log_value& _value6,
	const log_value& _value7,	const log_value& _value8 )
{
	log_values values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	values.push_back( _value6 );
	values.push_back( _value7 );
	values.push_back( _value8 );
	yprintf( _os, _format, values );
}


void yprintf( std::ostream& _os, const char* const _format,	const log_value& _value1,	const log_value& _value2,
	const log_value& _value3,	const log_value& _value4,	const log_value& _value5,	const log_value& _value6,
	const log_value& _value7,	const log_value& _value8,	const log_value& _value9 )
{
	log_values values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	values.push_back( _value6 );
	values.push_back( _value7 );
	values.push_back( _value8 );
	values.push_back( _value9 );
	yprintf( _os, _format, values );
}


void yprintf( std::ostream& _os, const char* const _format,	const log_value& _value1,	const log_value& _value2,
	const log_value& _value3,	const log_value& _value4,	const log_value& _value5,	const log_value& _value6,
	const log_value& _value7,	const log_value& _value8,	const log_value& _value9,	const log_value& _value10 )
{
	log_values values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	values.push_back( _value6 );
	values.push_back( _value7 );
	values.push_back( _value8 );
	values.push_back( _value9 );
	values.push_back( _value10 );
	yprintf( _os, _format, values );
}


const char* yprintf_impl( std::ostream& _os, const char* _format, log_values::const_iterator& _position,
	const log_values::const_iterator _end, bool& printed )
{		
	while (*_format)
	{
		if (PLACE_HOLDER == *_format)
		{
			if (PLACE_HOLDER == *( _format + 1 ))
			{
				++_format; // skip first place holder
				_os << *_format++; // output of the second place holder
			}
			else
			{
				if (OPENING_SQUARE_BRACKET == *( _format + 1 ))
				{
					++_format;
					const sxy::format_settings format_settings = sxy::parse_format_string(&_format);
					const std::ios_base::fmtflags stream_flags = _os.flags();
					const char streafill_ = _os.fill();
					_os << format_settings;					
					print_log_value( _os, *_position );
					_os.flags(stream_flags);
					_os.fill(streafill_);										
					printed = true;
					if( !format_settings.missing_closing_bracket_ )
					{							
						if( CLOSING_SQUARE_BRACKET == *( _format ) )
						{
							++_format;							
						}
					}
					else
					{
						if( !format_settings.correct_ )
						{
							++_format;
						}	
					}
				}
				else
				{				
					print_log_value( _os, *_position );
					printed = true;
					++_format;
					break;
				}			
				
				if( _position + 1 != _end )
				{						
					if( *_format != '\0' )
					{
						++_position;
						_format = yprintf_impl( _os, _format, _position, _end, printed );
					}
				}				
				return( _format );				
			}
		}
		else
		{	
			_os << *_format++;
		}
	}
	return ( _format );
}


void yprintf( std::ostream& _os, const char*const _format,	const log_values& _values )
{
	log_values::const_iterator _end = _values.end();
	log_values::const_iterator _position = _values.begin();
	const char* current_position = _format;	
		
	bool printed = false;	
	for( ; _position != _end; ++_position )
	{	 	
		printed = false;
		current_position = yprintf_impl( _os, current_position, _position, _end, printed );
		if( ( current_position != NULL ) && ( current_position[0] == '\0' ) )
		{					
			break;
		}				
	}

	if( printed )
	{
		if( _position != _end )
		{				
				++_position;			
		}
	}

	
	if( !(( current_position != NULL ) && ( current_position[0] == '\0' )) )
	{			
		yprintf( _os, current_position );
	}
	else
	{			
		if( _position != _end )
		{
			print_superfluous_parameters( _os, _values, _position );
		}
	}
}


void print_log_value( std::ostream& _os, const log_value& _value )
{
	const std::type_info& type_info = _value.type();	

	if( type_info == typeid ( bool ) )
	{
		stream_writer< bool >::print( _os, boost::get< bool >( _value ) );
	}
	else if( type_info == typeid ( int ) )
	{
		stream_writer< int >::print( _os, boost::get< int >( _value ) );
	}
	else if( type_info == typeid ( unsigned int ) )
	{
		stream_writer< unsigned int >::print( _os, boost::get< unsigned int >( _value ) );
	}
	else if( type_info == typeid ( sxy::int8_t ) )
	{
		stream_writer< sxy::int8_t >::print( _os, boost::get< sxy::int8_t >( _value ) );
	}
	else if (type_info == typeid ( sxy::uint8_t ))
	{
		stream_writer< sxy::uint8_t >::print(_os, boost::get< sxy::uint8_t >(_value));
	}
	else if( type_info == typeid ( sxy::uint16_t ) )
	{
		stream_writer< sxy::uint16_t >::print( _os, boost::get< sxy::uint16_t >( _value ) );
	}
	else if( type_info == typeid ( sxy::uint32_t ) )
	{
		stream_writer< sxy::uint32_t >::print( _os, boost::get< sxy::uint32_t >( _value ) );
	}
	else if( type_info == typeid ( std::string ) )
	{
		stream_writer< std::string >::print( _os, boost::get< std::string >( _value ) );
	}
	else if( type_info == typeid ( size_t ) )
	{
		stream_writer< size_t >::print( _os, boost::get< size_t >( _value ) );
	}
	else if( type_info == typeid ( const char* ) )
	{
		stream_writer< const char* >::print( _os, boost::get< const char* >( _value ) );
	}
	else if( type_info == typeid ( int_least64_t ) )
	{
		stream_writer< int_least64_t >::print( _os, boost::get< int_least64_t >( _value ) );
	}
	else if( type_info == typeid ( double ) )
	{
		stream_writer< double >::print( _os, boost::get< double >( _value ) );
	}
}


#endif


}
