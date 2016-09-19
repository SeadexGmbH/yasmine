//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_region_pseudostate.h"

#include "log.h"
#include "i_region.h"
#include "i_composite_state.h"
#include "t_exception.h"


namespace sxy
{


t_region_pseudostate::t_region_pseudostate
(
	const std::string& p_name
): t_pseudostate( p_name ),
	 m_parent()
{

}


t_region_pseudostate::~t_region_pseudostate
(
) = default;


const i_state_machine_element*
t_region_pseudostate::get_parent
(
) const
{
	return( get_parent_region() );
}


i_region*
t_region_pseudostate::get_parent_region
(
) const
{
	return ( m_parent );
}


void
t_region_pseudostate::set_parent_region
(
	i_region* const p_parent_region
)
{
	Y_LOG( t_log_level::LL_SPAM, "Setting '%' as parent region of '%'.", p_parent_region->get_name(), get_name() );
	m_parent = p_parent_region;
}


t_raw_composite_states
t_region_pseudostate::get_ancestors
(
	i_composite_state* const p_final_ancestor
) const
{
	t_raw_composite_states ancestors;

	Y_LOG( t_log_level::LL_SPAM, "Getting parent region for '%'.", get_name() );
	const auto parent_region = get_parent_region();

	if( parent_region )
	{
		Y_LOG( t_log_level::LL_SPAM, "Parent region '%' found for '%'.", parent_region->get_name(), get_name() );

		auto& parent_state = parent_region->get_parent_state();
		Y_LOG( t_log_level::LL_SPAM, "Found parent state '%' for region '%'.", parent_state.get_name(), parent_region->get_name() );
		ancestors.push_back( &parent_state );

		Y_LOG( t_log_level::LL_SPAM, "Search for ancestor(s) of '%'.", parent_state.get_name() );
		const auto ancestors_of_parent_state = parent_state.get_ancestors( p_final_ancestor );
		Y_LOG( t_log_level::LL_SPAM, "Found % ancestor(s) of '%'.", ancestors_of_parent_state.size(), parent_state.get_name() );
		ancestors.insert( ancestors.end(), ancestors_of_parent_state.begin(), ancestors_of_parent_state.end() );		
	}

	return( ancestors );
}


t_raw_regions
t_region_pseudostate::get_ancestors_as_regions
(
) const
{		 
	t_raw_regions ancestor_regions;

	const auto parent_region = get_parent_region();
	if( parent_region )
	{
		ancestor_regions.push_back( parent_region );
		const auto parent_regions_of_parent_region = parent_region->get_parent_state().get_ancestors_as_regions();
		ancestor_regions.insert( ancestor_regions.end(), parent_regions_of_parent_region.begin(), parent_regions_of_parent_region.end() );
	}

	return( ancestor_regions );
}		 


}
										