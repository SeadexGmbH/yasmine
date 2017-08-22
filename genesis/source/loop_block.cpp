//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "loop_block.hpp"

#include "recipe_callback.hpp"


namespace sx
{


namespace genesis
{


loop_block::loop_block( const std::string& _loop_name ) :
	recipe_block(),
	loop_name_( _loop_name )
{
	// Nothing to do...
}


loop_block::~loop_block() SX_NOEXCEPT
{
	// Nothing to do...
}


void loop_block::create( recipe_callback& _recipe_callback, std::stringstream& _ostream )
{
	_recipe_callback.before_loop( loop_name_ );
			
	while( _recipe_callback.check_loop_condition( loop_name_ ) )
	{
		_recipe_callback.before_loop_iteration( loop_name_ );
		create_children( _recipe_callback, _ostream );
		_recipe_callback.after_loop_iteration( loop_name_ );
	}
	_recipe_callback.after_loop( loop_name_ );
}


}


}
