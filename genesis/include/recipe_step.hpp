//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef RECIPE_STEP_1A42F342_F0C6_49C9_8FC3_0BAEDFBD05AE
#define RECIPE_STEP_1A42F342_F0C6_49C9_8FC3_0BAEDFBD05AE


#include <sstream>

#include "essentials/compatibility/compatibility.hpp"
#include "essentials/non_copyable.hpp"


namespace sx
{


namespace genesis
{


class recipe_callback;


//!\interface recipe_step
//!\brief A step of a recipe.
class recipe_step
{
public:
	//!\brief Constructor
	recipe_step()
	{
		// Nothing to do...
	}


	virtual ~recipe_step() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY( recipe_step )

	//!\brief Create the output for a step.
	//!\param _recipe_callback Generator callback
	//!\param _ostream Stream to which the generator writes.
	virtual void create( recipe_callback& _recipe_callback, std::stringstream& _ostream ) = 0;
};


}


}

#endif
