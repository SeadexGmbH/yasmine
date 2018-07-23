//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ACCESS_OPERATOR_9C58972C_7917_4BBD_8CF2_B2DF69D4F0AC
#define ACCESS_OPERATOR_9C58972C_7917_4BBD_8CF2_B2DF69D4F0AC


namespace sxy
{


#ifndef SX_CPP03_BOOST

	//!\enum access_operator
	//!\brief Enumeration for predefined access operator.
	enum class access_operator
	{
		AO_NO_ACCESS_OPERATOR = 0, AO_THIS_ACCESS = 1, AO_POINTER_ACCESS = 2, AO_REFERENCE_ACCESS = 3, AO_FUNCTION_ACCESS = 4
	};


#else


	//!\struct access_operator
	//!\brief Structure representing a predefined access operator (enum wrapper for C++11 enum class like behavior).
	struct access_operator
	{
		//!\enum access_operator
		//!\brief Enumeration for predefined access operator.
		enum inner
		{
			AO_NO_ACCESS_OPERATOR = 0, AO_THIS_ACCESS = 1, AO_POINTER_ACCESS = 2, AO_REFERENCE_ACCESS = 3, AO_FUNCTION_ACCESS = 4
		};


		//!\brief Constructor. Default value is no access operator.
		access_operator() : value_( AO_NO_ACCESS_OPERATOR )
		{
			// Nothing to do...
		}


		//!\brief Constructor
		//!\param _value Given access operator value that is represented by the structure.
		access_operator( const inner _value ) : value_( _value )
		{
			// Nothing to do...
		}


		//!\brief Constructor
		//!\param _access_operator Given access operator structure containing the access operator that is represented by the structure.
		access_operator( const access_operator& _access_operator ) : value_( _access_operator.value_ )
		{
			// Nothing to do...
		}


		//!\brief Get the access operator value represented by the structure.
		operator inner() const
		{
			return ( value_ );
		}


		//!\brief Access operator represented by the structure.
		inner value_;

	};


#endif


}


#endif
