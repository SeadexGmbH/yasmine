//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TEXT_STEP_56DA4C34_9848_4123_AB65_1C9839E009A2
#define TEXT_STEP_56DA4C34_9848_4123_AB65_1C9839E009A2


#include "recipe_step.hpp"


namespace sx
{


namespace genesis
{


//!\class test_step
//!\brief Class representing a text step of the recipe.
class text_step SX_FINAL 
	: public recipe_step
{
public:
	//!\brief Constructor
	//!\param _text Content of the text block.
	explicit text_step( const std::string& _text );
	virtual ~text_step() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( text_step )

	//!\brief Create the output for a step.
	//!\param _recipe_callback Generator callback
	//!\param _ostream Stream to which the generator writes.
	virtual void create( recipe_callback& _recipe_callback, std::stringstream& _ostream ) SX_OVERRIDE;


private:
	const std::string text_;
};


}


}


#endif
