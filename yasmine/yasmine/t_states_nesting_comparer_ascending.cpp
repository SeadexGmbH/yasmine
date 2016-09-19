//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_states_nesting_comparer_ascending.h"

#include "i_state.h"


namespace sxy
{


t_states_nesting_comparer_ascending::t_states_nesting_comparer_ascending
(
) = default;


t_states_nesting_comparer_ascending::~t_states_nesting_comparer_ascending
(
) = default;


bool
t_states_nesting_comparer_ascending::operator()
(		
	const i_state& p_lhs,
	const i_state& p_rhs
) const
{
	auto l_lhs_smaller_then_rhs = false;

	if( p_lhs.get_nesting_level() > p_rhs.get_nesting_level() )
	{
		l_lhs_smaller_then_rhs = true;
	}
	else if( p_lhs.get_nesting_level() < p_rhs.get_nesting_level() )
	{
		l_lhs_smaller_then_rhs = false;
	}
	else if( p_lhs.get_parent_region_index() > p_rhs.get_parent_region_index() )
	{
		l_lhs_smaller_then_rhs = true;
	}
	else if( p_lhs.get_parent_region_index() < p_rhs.get_parent_region_index() )
	{
		l_lhs_smaller_then_rhs = false;
	} else 
	{
		l_lhs_smaller_then_rhs = &p_lhs < &p_rhs;
	}

	return( l_lhs_smaller_then_rhs );
}


bool
t_states_nesting_comparer_ascending::operator()
(		
	const i_state* const p_lhs,
	const i_state* const p_rhs
) const
{
	return( operator()( *p_lhs, *p_rhs ) );
}


}
