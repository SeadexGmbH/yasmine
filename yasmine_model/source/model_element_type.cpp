//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "model_element_type.hpp"

#include "essentials/base.hpp"
#include "consts.hpp"


namespace sxy
{


namespace model
{


#ifdef SX_CPP03_BOOST

	bool operator==( const sxy::model::model_element_type& _lhs, const sxy::model::model_element_type::inner _rhs )
	{
		return( _lhs.value_ == _rhs );
	}


	bool operator==( const sxy::model::model_element_type::inner _lhs, const sxy::model::model_element_type& _rhs )
	{
		return( _lhs == _rhs.value_ );
	}


	bool operator<( const sxy::model::model_element_type _lhs, const sxy::model::model_element_type _rhs )
	{
		return ( _lhs.value_ < _rhs.value_ );
	}

#endif


model_element_type model_element_type_from_string( const std::string& _type_as_string )
{
	model_element_type element_type;

	if( _type_as_string == TYPE_TRANSITION )
	{
		element_type = model_element_type::TYE_TRANSITION;
	}
	else if( _type_as_string == TYPE_SIMPLE_STATE )
	{
		element_type = model_element_type::TYE_SIMPLE_STATE;
	}
	else if( _type_as_string == TYPE_ASYNC_SIMPLE_STATE )
	{
		element_type = model_element_type::TYE_ASYNC_SIMPLE_STATE;
	}
	else if( _type_as_string == TYPE_COMPOSITE_STATE )
	{
		element_type = model_element_type::TYE_COMPOSITE_STATE;
	}
	else if( _type_as_string == TYPE_FINAL_STATE )
	{
		element_type = model_element_type::TYE_FINAL_STATE;
	}
	else if( _type_as_string == TYPE_INITIAL_PSEUDOSTATE )
	{
		element_type = model_element_type::TYE_INITIAL_PSEUDOSTATE;
	}
	else if( _type_as_string == TYPE_TERMINATE_PSEUDOSTATE )
	{
		element_type = model_element_type::TYE_TERMINATE_PSEUDOSTATE;
	}
	else if( _type_as_string == TYPE_ENTRY_POINT )
	{
		element_type = model_element_type::TYE_ENTRY_POINT;
	}
	else if( _type_as_string == TYPE_EXIT_POINT )
	{
		element_type = model_element_type::TYE_EXIT_POINT;
	}
	else if( _type_as_string == TYPE_DEEP_HISTORY )
	{
		element_type = model_element_type::TYE_DEEP_HISTORY;
	}
	else if( _type_as_string == TYPE_SHALLOW_HISTORY )
	{
		element_type = model_element_type::TYE_SHALLOW_HISTORY;
	}
	else if( _type_as_string == TYPE_JOIN )
	{
		element_type = model_element_type::TYE_JOIN;
	}
	else if( _type_as_string == TYPE_JUNCTION )
	{
		element_type = model_element_type::TYE_JUNCTION;
	}
	else if( _type_as_string == TYPE_FORK )
	{
		element_type = model_element_type::TYE_FORK;
	}
	else if( _type_as_string == TYPE_CHOICE )
	{
		element_type = model_element_type::TYE_CHOICE;
	}
	else if( _type_as_string == TYPE_REGION )
	{
		element_type = model_element_type::TYE_REGION;
	}
	else
	{
		element_type = model_element_type::TYE_UNKNOWN;
	}


	return( element_type );
}


const std::string model_element_type_to_string( const model_element_type& _type )
{
	std::string type;

#ifndef SX_CPP03_BOOST
		switch( _type )
#else
		switch( _type.value_ )
#endif
	{
		case model_element_type::TYE_TRANSITION:
		type = TYPE_TRANSITION;
		break;
	
	case model_element_type::TYE_SIMPLE_STATE:
		type = TYPE_SIMPLE_STATE;
		break;

	case model_element_type::TYE_ASYNC_SIMPLE_STATE:
		type = TYPE_ASYNC_SIMPLE_STATE;
		break;

	case model_element_type::TYE_COMPOSITE_STATE:
		type = TYPE_COMPOSITE_STATE;
		break;

	case model_element_type::TYE_FINAL_STATE:
		type = TYPE_FINAL_STATE;
		break;
	
	case model_element_type::TYE_INITIAL_PSEUDOSTATE:
		type = TYPE_INITIAL_PSEUDOSTATE;
		break;

	case model_element_type::TYE_TERMINATE_PSEUDOSTATE:
		type = TYPE_TERMINATE_PSEUDOSTATE;
		break;

	case model_element_type::TYE_ENTRY_POINT:
		type = TYPE_ENTRY_POINT;
		break;

	case model_element_type::TYE_EXIT_POINT:
		type = TYPE_EXIT_POINT;
		break;

	case model_element_type::TYE_DEEP_HISTORY:
		type = TYPE_DEEP_HISTORY;
		break;

	case model_element_type::TYE_SHALLOW_HISTORY:
		type = TYPE_SHALLOW_HISTORY;
		break;

	case model_element_type::TYE_JOIN:
		type = TYPE_JOIN;
		break;

	case model_element_type::TYE_JUNCTION:
		type = TYPE_JUNCTION;
		break;

	case model_element_type::TYE_FORK:
		type = TYPE_FORK;
		break;

	case model_element_type::TYE_CHOICE:
		type = TYPE_CHOICE;
		break;

	case model_element_type::TYE_REGION:
		type = TYPE_REGION;
		break;

	default:
		SX_ASSERT( false, "No corresponding type!" );
		break;
	}


	return ( type );
}


}

}
