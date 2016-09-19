//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_deep_history.h"

#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_pseudostate_visitor.h"
#include "t_state_machine_defects.h"
#include "i_composite_state.h"
#include "i_transition.h"
#include "i_region.h"


namespace sxy
{


t_deep_history::t_deep_history
(
	const std::string& p_name
): t_history( p_name )	
{
	// Nothing to do...
}


t_deep_history::~t_deep_history
(
) = default;


bool
t_deep_history::check
(
	t_state_machine_defects& p_defects
)	const
{	
	auto l_check_ok = true;

	// check if all default transitions having target in distinct regions
	std::set<const i_region*> l_target_regions;
	for( const auto l_default_transition : get_default_transitions() )
	{
		auto l_target_region = l_default_transition->get_target().get_parent();
		const auto l_region = dynamic_cast< const i_region* >( l_target_region );
		if( l_region )
		{
			auto l_result = l_target_regions.insert( l_region );
			if( !l_result.second )
			{
				p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Deep history '%' has default transition(s) that has the same target region '%'.", get_name(), l_region->get_name() ) );
				l_check_ok = false;
				break;
			}
		}
	}

	// transitions exiting pseudostates cannot have a trigger
	if( !t_pseudostate::check( p_defects ) )
	{
		l_check_ok = false;
	}

	return( l_check_ok );
}


void
t_deep_history::accept_vertex_visitor
(
	i_const_vertex_visitor& p_visitor
) const
{
	p_visitor.visit( *this );
}


void
t_deep_history::accept_vertex_visitor
(
	i_vertex_visitor& p_visitor
)
{
	p_visitor.visit( *this );
}


void
t_deep_history::accept_pseudostate_visitor
(
	i_pseudostate_visitor& p_visitor
) const
{
	p_visitor.visit( *this );
}


}
