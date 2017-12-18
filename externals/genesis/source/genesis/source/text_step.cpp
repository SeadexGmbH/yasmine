//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "text_step.hpp"

#include "essentials/base.hpp"

#include "recipe_callback.hpp"


namespace sx
{


namespace genesis
{


text_step::text_step( const std::string& _text ) :
	recipe_step(),
	text_( _text )
{
	// Nothing to do...
}


text_step::~text_step() SX_NOEXCEPT
{
	// Nothing to do...
}


void text_step::create( recipe_callback& _recipe_callback, std::stringstream& _ostream )
{
	SX_UNUSED_PARAMETER( _recipe_callback );
	_ostream << text_;
}


}


}
