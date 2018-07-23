//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MODEL_ELEMENT_TYPE_88FF44C0_7912_4212_8E10_42FF3FD556EA
#define MODEL_ELEMENT_TYPE_88FF44C0_7912_4212_8E10_42FF3FD556EA


#include <string>


namespace sxy
{


namespace model
{


#ifndef SX_CPP03_BOOST


enum model_element_type
{
	TYE_UNKNOWN = -1,
	TYE_TRANSITION = 0,
	TYE_SIMPLE_STATE = 1,
	TYE_COMPOSITE_STATE = 2,
	TYE_FINAL_STATE = 3,
	TYE_INITIAL_PSEUDOSTATE = 4,
	TYE_TERMINATE_PSEUDOSTATE = 5,
	TYE_ENTRY_POINT = 6,
	TYE_EXIT_POINT = 7,
	TYE_DEEP_HISTORY = 8,
	TYE_SHALLOW_HISTORY = 9,
	TYE_JOIN = 10,
	TYE_JUNCTION = 11,
	TYE_FORK = 12,
	TYE_CHOICE = 13,
	TYE_REGION = 14,
	TYE_ASYNC_SIMPLE_STATE = 15
};


#else


	struct model_element_type
	{


		enum inner
		{
			TYE_UNKNOWN = -1,
			TYE_TRANSITION = 0,
			TYE_SIMPLE_STATE = 1,
			TYE_COMPOSITE_STATE = 2,
			TYE_FINAL_STATE = 3,
			TYE_INITIAL_PSEUDOSTATE = 4,
			TYE_TERMINATE_PSEUDOSTATE = 5,
			TYE_ENTRY_POINT = 6,
			TYE_EXIT_POINT = 7,
			TYE_DEEP_HISTORY = 8,
			TYE_SHALLOW_HISTORY = 9,
			TYE_JOIN = 10,
			TYE_JUNCTION = 11,
			TYE_FORK = 12,
			TYE_CHOICE = 13,
			TYE_REGION = 14,
			TYE_ASYNC_SIMPLE_STATE = 15
		};


		// cppcheck-suppress noExplicitConstructor
		model_element_type() : value_( TYE_UNKNOWN )
		{
			// Nothing to do...
		}


		// cppcheck-suppress noExplicitConstructor
		model_element_type( const inner _value ) : value_( _value )
		{
			// Nothing to do...
		}


		// cppcheck-suppress functionConst
		operator inner()
		{
			return ( value_ );
		}


		inner value_;

	};


	bool operator==( const sxy::model::model_element_type& _lhs, const sxy::model::model_element_type::inner _rhs );
	bool operator==( const sxy::model::model_element_type::inner _lhs, const sxy::model::model_element_type& _rhs );
	bool operator<( const sxy::model::model_element_type _lhs, const sxy::model::model_element_type _rhs );


#endif


model_element_type model_element_type_from_string( const std::string& _type_as_string );
const std::string model_element_type_to_string( const model_element_type& _type );


}


}


#endif
