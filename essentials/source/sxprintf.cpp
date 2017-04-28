//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "essentials/sxprintf.hpp"

#include <cctype>

#include "essentials/base.hpp"
#include "essentials/conversion.hpp"


namespace sxe
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


const char PLACE_HOLDER = '%';
const char* const SUPERFLUOUS_PARAMETER_START = "[Superfluous parameter: ";
const char SUPERFLUOUS_PARAMETER_END = ']';
const char OPENING_SQUARE_BRACKET = '[';
const char CLOSING_SQUARE_BRACKET = ']';


// cppcheck-suppress unusedFunction 
std::ostream& operator<<( std::ostream& _os, const sxe::format_settings& _format )
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


sxe::format_settings parse_format_string( const char** const _format )
{
	sxe::format_settings format_settings;
	format_settings.correct_ = true;
	SX_ASSERT( ( OPENING_SQUARE_BRACKET == **_format ), "Format string to parse doesn't start with [." );
	++*_format;
	format_settings.missing_closing_bracket_ = true;
	bool point_found = false;
	const char* text_before_point = *_format;
	std::size_t text_before_point_size = 0;
	const char* text_after_point = SX_NULLPTR;
	std::size_t text_after_point_size = 0;
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

	SX_ASSERT( text_before_point, "Logic error parsing format string!" );
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
			SX_ASSERT( text_after_point, "Logic error parsing format string!" );
			format_settings.decimal_places_set_ = true;
			if( !string_to_int( text_after_point, format_settings.decimal_places_ ) )
			{
				format_settings.correct_ = false;
			}
		}
	}

	return( format_settings );
}


#ifdef SX_CPP03_BOOST


void print_superfluous_parameters( std::ostream& _os, const value_types& _values, value_types::const_iterator& _position )
{
	while( _position != _values.end() )
	{
		print_superfluous_parameters( _os, *_position );
		++_position;
	}
}


#endif


void sxprintf( std::ostream& _os, const char* _format )
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


#ifdef SX_CPP03_BOOST


std::string sxprintf(const char* const _format)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1, _value2);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1, _value2, _value3);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3, 
	const value_type& _value4)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1, _value2, _value3, _value4);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6, const value_type& _value7)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6, _value7);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6, const value_type& _value7, const value_type& _value8)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6, const value_type& _value7, const value_type& _value8, 
	const value_type& _value9)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9);
	return( target_string_stream.str() );
}


std::string sxprintf(const char* const _format, const value_type& _value1, const value_type& _value2, const value_type& _value3,
	const value_type& _value4, const value_type& _value5, const value_type& _value6, const value_type& _value7, const value_type& _value8,
	const value_type& _value9, const value_type& _value10)
{
	std::stringstream target_string_stream;
	sxprintf(target_string_stream, _format, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10);
	return( target_string_stream.str() );
}


void sxprintf( std::ostream& _os, const char* const _format, const value_type& _value1 )
{
	value_types values;
	values.push_back( _value1 );
	sxprintf( _os, _format, values );
}


void sxprintf( std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2 )
{
	value_types values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	sxprintf( _os, _format, values );
}


void sxprintf( std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2, 
	const value_type& _value3 )
{
	value_types values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	sxprintf( _os, _format, values );
}


void sxprintf( std::ostream& _os, const char* const _format, const value_type& _value1, const value_type& _value2,
	const value_type& _value3,	const value_type& _value4 )
{
	value_types values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	sxprintf( _os, _format, values );
}


void sxprintf( std::ostream& _os, const char* const _format,	const value_type& _value1,	const value_type& _value2,
	const value_type& _value3,	const value_type& _value4,	const value_type& _value5 )
{
	value_types values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	sxprintf( _os, _format, values );
}


void sxprintf(	std::ostream& _os, const char* const _format,	const value_type& _value1,	const value_type& _value2,
	const value_type& _value3,	const value_type& _value4,	const value_type& _value5,	const value_type& _value6 )
{
	value_types values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	values.push_back( _value6 );
	sxprintf( _os, _format, values );
}


void sxprintf(	std::ostream& _os, const char* const _format,	const value_type& _value1,	const value_type& _value2,
	const value_type& _value3,	const value_type& _value4,	const value_type& _value5,	const value_type& _value6,
	const value_type& _value7 )
{
	value_types values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	values.push_back( _value6 );
	values.push_back( _value7 );
	sxprintf( _os, _format, values );
}


void sxprintf( std::ostream& _os, const char* const _format,	const value_type& _value1,	const value_type& _value2,
	const value_type& _value3,	const value_type& _value4,	const value_type& _value5,	const value_type& _value6,
	const value_type& _value7,	const value_type& _value8 )
{
	value_types values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	values.push_back( _value6 );
	values.push_back( _value7 );
	values.push_back( _value8 );
	sxprintf( _os, _format, values );
}


void sxprintf( std::ostream& _os, const char* const _format,	const value_type& _value1,	const value_type& _value2,
	const value_type& _value3,	const value_type& _value4,	const value_type& _value5,	const value_type& _value6,
	const value_type& _value7,	const value_type& _value8,	const value_type& _value9 )
{
	value_types values;
	values.push_back( _value1 );
	values.push_back( _value2 );
	values.push_back( _value3 );
	values.push_back( _value4 );
	values.push_back( _value5 );
	values.push_back( _value6 );
	values.push_back( _value7 );
	values.push_back( _value8 );
	values.push_back( _value9 );
	sxprintf( _os, _format, values );
}


void sxprintf( std::ostream& _os, const char* const _format,	const value_type& _value1,	const value_type& _value2,
	const value_type& _value3,	const value_type& _value4,	const value_type& _value5,	const value_type& _value6,
	const value_type& _value7,	const value_type& _value8,	const value_type& _value9,	const value_type& _value10 )
{
	value_types values;
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
	sxprintf( _os, _format, values );
}


const char* sxprintf_impl( std::ostream& _os, const char* _format, value_types::const_iterator& _position,
	const value_types::const_iterator _end, bool& printed )
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
					const sxe::format_settings format_settings = sxe::parse_format_string(&_format);
					const std::ios_base::fmtflags stream_flags = _os.flags();
					const char streafill_ = _os.fill();
					_os << format_settings;					
					print_value_type_value( _os, *_position );
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
					print_value_type_value( _os, *_position );
					printed = true;
					++_format;
					break;
				}			
				
				if( _position + 1 != _end )
				{						
					if( *_format != '\0' )
					{
						++_position;
						_format = sxprintf_impl( _os, _format, _position, _end, printed );
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


void sxprintf( std::ostream& _os, const char * const _format,	const value_types& _values )
{		
	SX_ASSERT( _format, "No format string to parse was passed!" );
	const char* current_position = _format;

	value_types::const_iterator _end = _values.end();
	value_types::const_iterator _position = _values.begin();			
	while( _position != _end )
	{	 	
		bool printed = false;
		current_position = sxprintf_impl( _os, current_position, _position, _end, printed );
		if( printed )
		{
			++_position;
		}
		if( current_position[0] == '\0' )
		{					
			break;
		}				
	}
	
	sxprintf( _os, current_position );

	if( _position != _end )
	{
		print_superfluous_parameters( _os, _values, _position );
	}
}


void print_value_type_value( std::ostream& _os, const value_type& _value )
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
	else if( type_info == typeid ( sxe::int8_t ) )
	{
		stream_writer< sxe::int8_t >::print( _os, boost::get< sxe::int8_t >( _value ) );
	}
	else if (type_info == typeid ( sxe::uint8_t ))
	{
		stream_writer< sxe::uint8_t >::print(_os, boost::get< sxe::uint8_t >(_value));
	}
	else if( type_info == typeid ( sxe::uint16_t ) )
	{
		stream_writer< sxe::uint16_t >::print( _os, boost::get< sxe::uint16_t >( _value ) );
	}
	else if( type_info == typeid ( sxe::uint32_t ) )
	{
		stream_writer< sxe::uint32_t >::print( _os, boost::get< sxe::uint32_t >( _value ) );
	}
	else if( type_info == typeid ( std::string ) )
	{
		stream_writer< std::string >::print( _os, boost::get< std::string >( _value ) );
	}
	else if( type_info == typeid ( std::size_t ) )
	{
		stream_writer< std::size_t >::print( _os, boost::get< std::size_t >( _value ) );
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
