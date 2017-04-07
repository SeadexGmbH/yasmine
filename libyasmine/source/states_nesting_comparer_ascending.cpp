//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "states_nesting_comparer_ascending.hpp"

#include "state.hpp"


namespace sxy
{


states_nesting_comparer_ascending::states_nesting_comparer_ascending()
{
	// Nothing to do...
}


states_nesting_comparer_ascending::~states_nesting_comparer_ascending() SX_NOEXCEPT
{
	// Nothing to do...
}


bool states_nesting_comparer_ascending::operator()(	const state& _lhs,	const state& _rhs ) const
{
	bool lhs_smaller_than_rhs = false;
	if( _lhs.get_nesting_level() > _rhs.get_nesting_level() )
	{
		lhs_smaller_than_rhs = true;
	}
	else
	if( _lhs.get_nesting_level() < _rhs.get_nesting_level() )
	{
		lhs_smaller_than_rhs = false;
	}
	else
	if( _lhs.get_parent_region_index() > _rhs.get_parent_region_index() )
	{
		lhs_smaller_than_rhs = true;
	}
	else
	if( _lhs.get_parent_region_index() < _rhs.get_parent_region_index() )
	{
		lhs_smaller_than_rhs = false;
	}
	else
	{
		lhs_smaller_than_rhs = &_lhs < &_rhs;
	}

	return( lhs_smaller_than_rhs );
}


bool states_nesting_comparer_ascending::operator()(	const state* const _lhs,	const state* const _rhs ) const
{
	return( operator()( *_lhs, *_rhs ) );
}


}
