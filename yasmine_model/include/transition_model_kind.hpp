//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_MODEL_KIND_BD2A7DB6_BB45_4A4C_A6AA_5F3A3ECA8532
#define TRANSITION_MODEL_KIND_BD2A7DB6_BB45_4A4C_A6AA_5F3A3ECA8532


#include <string>


namespace sxy
{


namespace model
{


#ifndef SX_CPP03_BOOST


	enum class transition_model_kind
	{
		EXTERNAL = 0, INTERNAL = 1, LOCAL = 2
	};


#else


	struct transition_model_kind
	{

		enum inner 
		{
			EXTERNAL = 0, INTERNAL = 1, LOCAL = 2
		};


		// cppcheck-suppress noExplicitConstructor
		transition_model_kind() : value_( EXTERNAL )
		{
			// Nothing to do...
		}


		// cppcheck-suppress noExplicitConstructor
		transition_model_kind( const inner _value ) : value_( _value )
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


std::string to_string( const transition_model_kind _kind );


#ifdef SX_CPP03_BOOST


bool operator==( const transition_model_kind& _lhs, const transition_model_kind::inner _rhs );
bool operator==( const transition_model_kind::inner _lhs, const transition_model_kind& _rhs );
bool operator<( const transition_model_kind _lhs, const transition_model_kind _rhs );



#endif

}


}


#endif
