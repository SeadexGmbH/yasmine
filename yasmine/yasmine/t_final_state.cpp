//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_final_state.h"

#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_state_visitor.h"
#include "i_region.h"
#include "t_state_machine_defects.h"


namespace sxy
{


t_final_state::t_final_state
(
	const std::string& p_name
):	
	t_state( p_name )	
{
	// Nothing to do...
}


t_final_state::~t_final_state
(
) = default;
	

i_behavior*
t_final_state::get_entry_behavior
(
) const
{
	return( nullptr );
}


i_behavior*
t_final_state::get_exit_behavior
(
) const
{
	return( nullptr );
}


const t_regions&
t_final_state::get_regions
(
) const
{
	static const t_regions l_regions;
	return( l_regions );
}


t_regions&
t_final_state::get_regions
(
)
{
	static t_regions l_regions;

	return( l_regions );
}


bool
t_final_state::check
(
	t_state_machine_defects& p_defects
) const
{	
	auto l_check_ok = true;

	// 15.3.2 Final State -> Constraint [1]: A final state cannot have any outgoing transitions.
	if( !get_outgoing_transitions().empty() )
	{			
		p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Final state '%' have '%' outgoing transitions!", get_name(), get_outgoing_transitions().size() ) );
		l_check_ok = false;
	}

	// 15.3.2 Final State -> Constraint [2]: A final state cannot have regions.
	if( !get_regions().empty() )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Final state '%' have '%' region(s)!", get_name(), get_regions().size() ) );
		l_check_ok = false;
	}

	// 15.3.2 Final State -> Constraint [3]: A final state cannot reference a submachine.
	// Does not apply.
	
	// 15.3.2 Final State -> Constraint [4]: A final state has no entry behavior.	
	if( get_entry_behavior() )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Final state '%' has entry behavior!", get_name() ) );
		l_check_ok = false;
	}

	//  15.3.2 Final State -> Constraint [5]: A final state has no exit behavior.	
	if( get_exit_behavior() )
	{
		p_defects.push_back( std::make_unique< t_state_machine_defect>( *this, "Final state '%' has exit behavior!", get_name() ) );
		l_check_ok = false;
	}

	// 15.3.2 Final State -> Constraint [6]: A final state has no state (doActivity) behavior.
	// Enforced by design.

	return( l_check_ok );
}


void
t_final_state::accept_vertex_visitor
(
	i_const_vertex_visitor& p_visitor
)	const
{
	p_visitor.visit( *this );
}


void
t_final_state::accept_vertex_visitor
(
	i_vertex_visitor& p_visitor
)
{
	p_visitor.visit( *this );
}


void
t_final_state::accept_state_visitor
(
	i_state_visitor& p_visitor
) const
{
	p_visitor.visit( *this );
}


bool
t_final_state::is_event_deferred
(
	const t_event_id& p_event_id
) const 
{
	Y_UNUSED_PARAMETER( p_event_id );
	return ( false );
}


}
