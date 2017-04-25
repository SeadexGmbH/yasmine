//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CONDITION_MODIFIER_5286AF53_4751_4FDE_B4C9_E097AC8FB331
#define CONDITION_MODIFIER_5286AF53_4751_4FDE_B4C9_E097AC8FB331


#include <string>


namespace sx
{


namespace genesis
{


#ifndef SX_CPP03_BOOST

//!\enum condition_modifier
//!\brief Modifier for conditions. E.g. negate the result of a check.
enum class condition_modifier
{
	NONE = 0, NOT = 1
};


#else


	//!\struct condition_modifier
	//!\brief Structure representing a predefined modifier for conditions (enum wrapper for C++11 enum class like behavior).
	struct condition_modifier
	{
		//!\enum condition_modifier
		//!\brief Enumeration for predefined modifier for conditions.
		enum inner
		{
			NONE = 0, NOT = 1
		};


		//!\brief Constructor. Default value is white.
		condition_modifier() : value_( NONE )
		{
			// Nothing to do...
		}


		//!\brief Constructor
		//!\param _value Given modifier for conditions value that is represented by the structure.
		condition_modifier( const inner _value ) : value_( _value )
		{
			// Nothing to do...
		}


		//!\brief Constructor
		//!\param _condition_modifier Given modifier for conditions structure containing the modifier for conditions that is represented by the structure.
		condition_modifier( const condition_modifier& _condition_modifier ) : value_( _condition_modifier.value_ )
		{
			// Nothing to do...
		}


		//!\brief Get the modifier for conditions value represented by the structure.
		operator inner() const
		{
			return ( value_ );
		}


		//!\brief Modifier for conditions represented by the structure.
		inner value_;

	};


#endif


//!\fn
//!\brief Get the condition modifier value from a string.
//!\param _condition_modifier Modifier as a string, generally read from template files.
//!\return Condition modifier enum value corresponding to the given value.
condition_modifier get_condition_modifier_from_string( const std::string& _condition_modifier );


}


}


#endif
