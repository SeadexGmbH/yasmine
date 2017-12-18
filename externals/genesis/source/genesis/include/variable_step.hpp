//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef VARIABLE_STEP_11B39100_54E6_40E4_85FC_0A642202937C
#define VARIABLE_STEP_11B39100_54E6_40E4_85FC_0A642202937C


#include "recipe_step.hpp"


namespace sx
{


namespace genesis
{


//!\class variable_step
//!\brief Class representing a variable step of the recipe.
class variable_step SX_FINAL 
	: public recipe_step
{
public:
	//!\brief Constructor
	//!\param _variable_name Name of the variable represented by the variable_step.
	explicit variable_step( const std::string& _variable_name );
	virtual ~variable_step() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( variable_step )

	//!\brief Create the output for a step.
	//!\param _recipe_callback Generator callback
	//!\param _ostream Stream to which the generator writes.
	virtual void create( recipe_callback& _recipe_callback, std::stringstream& _ostream ) SX_OVERRIDE;


private:
	const std::string variable_name_;
};


}


}


#endif
