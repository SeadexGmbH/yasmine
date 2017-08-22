//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "state_machine_type.hpp"

#include <algorithm>

#include "essentials/exception.hpp"
#include "essentials/conversion.hpp"

#include "generator_grammar.hpp"


namespace sxy
{


// cppcheck-suppress unusedFunction
state_machine_type sm_type_from_string( const std::string& _type )
{
	state_machine_type type( state_machine_type::SMT_SYNC );
	const std::string string_type = sxe::to_lower( _type );

	if( string_type == VARIABLE_SM_SYNC )
	{
		type = state_machine_type::SMT_SYNC;
	}
	else if( string_type == VARIABLE_SM_ASYNC )
	{
		type = state_machine_type::SMT_ASYNC;
	}
	else
	{
		// Default value will be set as 'sync'
	}

	return( type );
}


const std::string sm_type_to_string( const state_machine_type& _type )
{
	std::string type( "" );
	if( _type == state_machine_type::SMT_SYNC )
	{
		type = VARIABLE_SM_SYNC;
	}
	else if( _type == state_machine_type::SMT_ASYNC )
	{
		type = VARIABLE_SM_ASYNC;
	}
	else
	{
		throw sxe::exception( "Unknown state machine type!" );
	}

	return ( type );
}


const std::string get_state_machine_class_as_string( const state_machine_type& _type )
{
	std::string type( "" );
	if( _type == state_machine_type::SMT_SYNC )
	{
		type = VARIABLE_SYNC_SM_CLASS;
	}
	else if( _type == state_machine_type::SMT_ASYNC )
	{
		type = VARIABLE_ASYNC_SM_CLASS;
	}
	else
	{
		throw sxe::exception( "Unknown state machine type!" );
	}

	return ( type );
}


// cppcheck-suppress unusedFunction
std::istream& operator>>( std::istream& _in_stream, sxy::state_machine_type& _sm_type )
{
	std::string token;
	_in_stream >> token;
	if( token == VARIABLE_SM_SYNC )
	{
		_sm_type = sxy::state_machine_type::SMT_SYNC;
	}
	else if( token == VARIABLE_SM_ASYNC )
	{
		_sm_type = sxy::state_machine_type::SMT_ASYNC;
	}
	else
	{
		_in_stream.setstate( std::ios_base::failbit );
	}

	return(_in_stream);
}


}
