//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "recipe_block.hpp"


namespace sx
{


namespace genesis
{


recipe_block::recipe_block() :
	recipe_step(),
	child_recipes_()
{
	// Nothing to do...
}


recipe_block::~recipe_block() SX_NOEXCEPT
{
	// Nothing to do...
}


void recipe_block::create_children( recipe_callback& _recipe_callback, std::stringstream& _ostream )
{
	SX_FOR( sxe::SX_UNIQUE_PTR<recipe_step>& child, child_recipes_ )
	{
		child->create( _recipe_callback, _ostream );
	}
}


void recipe_block::add_child( sxe::SX_UNIQUE_PTR<recipe_step> _child )
{
	child_recipes_.push_back( sxe::move( _child ) );
}


}


}
