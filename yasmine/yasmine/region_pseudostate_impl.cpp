//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "region_pseudostate_impl.h"

#include "log.h"
#include "region.h"
#include "composite_state.h"
#include "exception.h"


namespace sxy
{


region_pseudostate_impl::region_pseudostate_impl( const std::string& _name )
	: pseudostate_impl( _name ),
		parent_()
{
}


region_pseudostate_impl::~region_pseudostate_impl() = default;


const state_machine_element* region_pseudostate_impl::get_parent() const
{
	return( get_parent_region() );
}


region* region_pseudostate_impl::get_parent_region() const
{
	return( parent_ );
}


void region_pseudostate_impl::set_parent_region( region* const _parent_region )
{
	Y_LOG( log_level::LL_SPAM, "Setting '%' as parent region of '%'.", _parent_region->get_name(), get_name() );
	parent_ = _parent_region;
}


raw_composite_states region_pseudostate_impl::get_ancestors( composite_state* const _final_ancestor ) const
{
	raw_composite_states ancestors;
	Y_LOG( log_level::LL_SPAM, "Getting parent region for '%'.", get_name() );
	const auto parent_region = get_parent_region();
	if( parent_region )
	{
		Y_LOG( log_level::LL_SPAM, "Parent region '%' found for '%'.", parent_region->get_name(), get_name() );
		auto& parent_state = parent_region->get_parent_state();
		Y_LOG( log_level::LL_SPAM, "Found parent state '%' for region '%'.",
			parent_state.get_name(), parent_region->get_name() );
		ancestors.push_back( &parent_state );
		Y_LOG( log_level::LL_SPAM, "Search for ancestor(s) of '%'.", parent_state.get_name() );
		const auto ancestors_of_parent_state = parent_state.get_ancestors( _final_ancestor );
		Y_LOG( log_level::LL_SPAM, "Found % ancestor(s) of '%'.", ancestors_of_parent_state.size(),
			parent_state.get_name() );
		ancestors.insert( ancestors.end(), ancestors_of_parent_state.begin(), ancestors_of_parent_state.end() );
	}

	return( ancestors );
}


raw_regions region_pseudostate_impl::get_ancestors_as_regions() const
{
	raw_regions ancestor_regions;
	const auto parent_region = get_parent_region();
	if( parent_region )
	{
		ancestor_regions.push_back( parent_region );
		const auto parent_regions_of_parent_region = parent_region->get_parent_state().get_ancestors_as_regions();
		ancestor_regions.insert( ancestor_regions.end(), parent_regions_of_parent_region.begin(), 
			parent_regions_of_parent_region.end() );
	}

	return( ancestor_regions );
}


}
