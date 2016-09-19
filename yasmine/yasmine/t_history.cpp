//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_history.h"

#include "base.h"
#include "i_composite_state.h"


namespace sxy
{


t_history::t_history
(
	const std::string& p_name
): t_state_pseudostate( p_name )	 
{
	// Nothing to do...
}


t_history::~t_history
(
) = default;
				

t_raw_transitions
t_history::get_default_transitions
(
) const
{		
	return( t_vertex::get_outgoing_transitions() );
}


void
// cppcheck-suppress unusedFunction
t_history::add_default_transition
(
	i_transition& p_default_transition
) 
{
	t_vertex::add_outgoing_transition( p_default_transition );
}


bool
t_history::check_if_state_was_active_before
(
) const
{
	const auto& parent_state = get_parent_state();
	const auto state_was_active = parent_state.was_active();

	return( state_was_active );
}


}
