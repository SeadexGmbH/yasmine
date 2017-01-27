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
#include "algorithm_parameters.hpp"


namespace sxy
{


state_pseudostate_impl::state_pseudostate_impl( const std::string& _name )
	: pseudostate_impl( _name ),
		parent_()
#ifdef Y_OPTIMIZE_4_SPEED
		, ancestors_(),
			ancestors_as_regions_()
#endif
{
#ifdef Y_OPTIMIZE_4_SPEED
	ancestors_as_regions_.reserve( ANCESTORS_VECTOR_SIZE );
	ancestors_.reserve( ANCESTORS_VECTOR_SIZE );
#endif	
}


state_pseudostate_impl::~state_pseudostate_impl() Y_NOEXCEPT
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


raw_composite_states state_pseudostate_impl::get_ancestors( composite_state* const _final_ancestor,
	bool _include_final_ancestor ) const
{
#ifdef Y_OPTIMIZE_4_SPEED
	if( ancestors_.empty() )
	{
		collect_ancestors( ancestors_, _final_ancestor, _include_final_ancestor );
	}
	return( ancestors_ );	
#else
	raw_composite_states ancestors;
	collect_ancestors( ancestors, _final_ancestor, _include_final_ancestor );
	return( ancestors );
#endif 
}


raw_regions state_pseudostate_impl::get_ancestors_as_regions() const
{
#ifdef Y_OPTIMIZE_4_SPEED
	if( ancestors_as_regions_.empty() )
	{
		ancestors_as_regions_ = get_parent_state().get_ancestors_as_regions();
	}
	return( ancestors_as_regions_ );
#else
	return( get_parent_state().get_ancestors_as_regions() );	
#endif 	
}


void state_pseudostate_impl::collect_ancestors( raw_composite_states& _ancestors, 
	composite_state* const _final_ancestor, bool _include_final_ancestor ) const
{
	_ancestors.push_back( &get_parent_state() );
	const raw_composite_states& ancestors_of_parent_state = get_parent_state().get_ancestors( _final_ancestor );
	_ancestors.insert( _ancestors.end(), ancestors_of_parent_state.begin(), ancestors_of_parent_state.end() );
	if( !_include_final_ancestor )
	{			
		_ancestors.erase( _ancestors.end() );		
	}
}


}
