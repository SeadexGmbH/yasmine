//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_KIND_BA4883BC_C6FF_4F55_BA40_3FF8C973631D
#define TRANSITION_KIND_BA4883BC_C6FF_4F55_BA40_3FF8C973631D


#include <string>


namespace sxy
{

#ifndef Y_CPP03_BOOST


	enum class transition_kind
	{
		EXTERNAL = 0, INTERNAL = 1, LOCAL = 2
	};


#else


	struct transition_kind
	{

		enum inner 
		{
			EXTERNAL = 0, INTERNAL = 1, LOCAL = 2
		};


		// cppcheck-suppress noExplicitConstructor
		transition_kind() : value_( EXTERNAL )
		{
			// Nothing to do...
		}


		// cppcheck-suppress noExplicitConstructor
		transition_kind( const inner _value ) : value_( _value )
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

#endif


std::string to_string( const transition_kind _kind );


#ifdef Y_CPP03_BOOST


bool operator==( const sxy::transition_kind& _lhs, const sxy::transition_kind::inner _rhs );
bool operator==( const sxy::transition_kind::inner _lhs, const sxy::transition_kind& _rhs );
bool operator<( const sxy::transition_kind _lhs, const sxy::transition_kind _rhs );



#endif

}


#endif
