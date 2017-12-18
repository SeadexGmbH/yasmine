//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "condition_block.hpp"

#include "essentials/exception.hpp"

#include "recipe_callback.hpp"


namespace sx
{


namespace genesis
{


condition_block::condition_block( const std::string& _condition_name, const condition_modifier& _modifier ) :
	recipe_block(),
	condition_name_( _condition_name ),
	modifier_( _modifier )
{
	// Nothing to do...
}


condition_block::~condition_block() SX_NOEXCEPT
{
	// Nothing to do...
}


void condition_block::create( recipe_callback& _recipe_callback, std::stringstream& _ostream )
{
	_recipe_callback.condition_begin( condition_name_ );
	bool result = _recipe_callback.check_condition( condition_name_ );
	apply_modifier( result );
	if( result )
	{
		create_children( _recipe_callback, _ostream );
		_recipe_callback.condition_end( condition_name_ );
	}
}


void condition_block::apply_modifier( bool& _result ) const
{
	switch( modifier_ )
	{
	case sx::genesis::condition_modifier::NOT:
		_result = !_result;
		break;

	case sx::genesis::condition_modifier::NONE:
		// Nothing to do...
		break;

	default:
		sxe::exception( "Incompatible value for condition modifier!" );
		break;
	}
}


}


}