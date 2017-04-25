//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "switch_block.hpp"

#include "recipe_callback.hpp"


namespace sx
{


namespace genesis
{


switch_block::switch_block( const std::string& _switch_name ) :
	recipe_block(),
	switch_name_( _switch_name ),
	current_case_index_(),
	switch_cases_(),
	default_()
{
	// Nothing to do...
}


switch_block::~switch_block() SX_NOEXCEPT
{
	// Nothing to do...
}


void switch_block::create( recipe_callback& _recipe_callback, std::stringstream& _ostream )
{
	current_case_index_ = _recipe_callback.get_switch_case( switch_name_ );
	create_children( _recipe_callback, _ostream );
}


void switch_block::create_children( recipe_callback& _recipe_callback, std::stringstream& _ostream )
{
	if( current_case_index_ >= 0 )
	{
		std::vector< sxe::SX_UNIQUE_PTR<recipe_step> >& children_steps = switch_cases_[current_case_index_];
		SX_FOR( sxe::SX_UNIQUE_PTR<recipe_step>& child , children_steps )
		{
			child->create( _recipe_callback, _ostream );
		}
	}
	else
	{
		SX_FOR( sxe::SX_UNIQUE_PTR<recipe_step>& child , default_ )
		{
			child->create( _recipe_callback, _ostream );
		}
	}	
}


void switch_block::add_child( sxe::SX_UNIQUE_PTR<recipe_step> _child )
{
	if( current_case_index_ >= 0 )
	{
		switch_cases_[current_case_index_].push_back( sxe::move( _child ) );
	}
	else
	{
		default_.push_back( sxe::move( _child ) );
	}
}


void switch_block::set_case_index( const int _index )
{
	current_case_index_ = _index;
}


}


}