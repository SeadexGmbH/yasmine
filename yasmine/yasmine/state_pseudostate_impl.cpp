//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_pseudostate_impl.hpp"

#include "region.hpp"
#include "exception.hpp"


namespace sxy
{


state_pseudostate_impl::state_pseudostate_impl( const std::string& _name )
	: pseudostate_impl( _name ),
		parent_()
{
	// Nothing to do...
}
																								

const state_machine_element* state_pseudostate_impl::get_parent() const
{
	return( &get_parent_state() );
}


composite_state& state_pseudostate_impl::get_parent_state() const
{
	return( *parent_ );
}


void state_pseudostate_impl::set_parent_state( composite_state* const _parent_state )
{
	parent_ = _parent_state;
}


raw_composite_states state_pseudostate_impl::get_ancestors( composite_state* const _final_ancestor ) const
{
	raw_composite_states ascending_path = { &get_parent_state() };
	const auto ancestors_of_parent_state = get_parent_state().get_ancestors( _final_ancestor );
	ascending_path.insert( ascending_path.end(), ancestors_of_parent_state.begin(), ancestors_of_parent_state.end() );
	return( ascending_path );
}


raw_regions state_pseudostate_impl::get_ancestors_as_regions() const
{
	return( get_parent_state().get_ancestors_as_regions() );
}


}
