//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_state_pseudostate.h"

#include "i_region.h"
#include "t_exception.h"


namespace sxy
{


t_state_pseudostate::t_state_pseudostate( const std::string& p_name )
	: t_pseudostate( p_name ),
		m_parent()
{
	// Nothing to do...
}


t_state_pseudostate::~t_state_pseudostate() = default;


const i_state_machine_element* t_state_pseudostate::get_parent() const
{
	return( &get_parent_state() );
}


i_composite_state& t_state_pseudostate::get_parent_state() const
{
	return( *m_parent );
}


void t_state_pseudostate::set_parent_state( i_composite_state* const p_parent_state )
{
	m_parent = p_parent_state;
}


t_raw_composite_states t_state_pseudostate::get_ancestors( i_composite_state* const p_final_ancestor ) const
{
	t_raw_composite_states l_ascending_path = { &get_parent_state() };
	const auto ancestors_of_parent_state = get_parent_state().get_ancestors( p_final_ancestor );
	l_ascending_path.insert( l_ascending_path.end(), ancestors_of_parent_state.begin(), ancestors_of_parent_state.end() );
	return( l_ascending_path );
}


t_raw_regions t_state_pseudostate::get_ancestors_as_regions() const
{
	return( get_parent_state().get_ancestors_as_regions() );
}


}
