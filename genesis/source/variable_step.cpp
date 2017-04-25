//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "variable_step.hpp"

#include "recipe_callback.hpp"


namespace sx
{


namespace genesis
{


variable_step::variable_step( const std::string& _variable_name ) :
	recipe_step(),
	variable_name_( _variable_name )
{
	// Nothing to do...
}


variable_step::~variable_step() SX_NOEXCEPT
{
	// Nothing to do...
}

			
void variable_step::create( recipe_callback& _recipe_callback, std::stringstream& _ostream )
{
	_ostream << _recipe_callback.get_variable_content( variable_name_ );
}


}


}
