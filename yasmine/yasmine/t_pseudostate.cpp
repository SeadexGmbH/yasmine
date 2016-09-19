//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_pseudostate.h"

#include "base.h"
#include "i_region.h"
#include "i_transition.h"
#include "t_state_machine_defects.h"


namespace sxy
{


t_pseudostate::t_pseudostate
(		
	const std::string& p_name
): t_vertex( p_name )
{	
		// Nothing to do...
}


t_pseudostate::~t_pseudostate
(
) = default;


bool
t_pseudostate::check
(
	t_state_machine_defects& p_defects
) const
{
	auto l_check_ok = true;

	for(const auto l_outgoing_transition: get_outgoing_transitions())
	{
		if( !l_outgoing_transition->can_accept_event( COMPLETION_EVENT ) )
		{
			p_defects.push_back( std::make_unique< t_state_machine_defect >( *this, "'%' has outgoing transition with trigger!", get_name() ) );
			l_check_ok = false;
		}
	}

	return( l_check_ok );
}


}
