//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "shallow_history_impl.hpp"

#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "pseudostate_visitor.hpp"
#include "state_machine_defect.hpp"
#include "transition.hpp"
#include "region.hpp"


namespace sxy
{


shallow_history_impl::shallow_history_impl( const std::string& _name )
	: history_impl( _name )
{
	// Nothing to do...
}


shallow_history_impl::~shallow_history_impl() Y_NOEXCEPT
{
	// Nothing to do...
}


bool shallow_history_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// check if all default transitions having target in distinct regions
	std::set< const region* > target_regions;

	Y_FOR( const transition* const default_transition, get_default_transitions() )
	{
		const state_machine_element* const target_region = default_transition->get_target().get_parent();
		const region* const l_region = dynamic_cast< const region* >( target_region );
		if( l_region )
		{
			std::pair< std::set< const region* >::const_iterator, bool > result = target_regions.insert( l_region );
			if( !result.second )
			{
				_defects.push_back( state_machine_defect( *this,
						"Shallow history '%' has default transition(s) that has the same target region '%'.", get_name(),
						l_region->get_name() ) );
				check_ok = false;
				break;
			}
		}
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !pseudostate_impl::check( _defects ) )
	{
		check_ok = false;
	}

	return( check_ok );
}


void shallow_history_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void shallow_history_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void shallow_history_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


}
