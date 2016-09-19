//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_transition_priority.h"
#include "i_compound_transition.h"
#include "t_composite_state.h"
#include "i_transition.h"
#include "i_region.h"
#include "i_deep_history.h"
#include "i_shallow_history.h"
#include "i_behavior.h"


namespace sxy
{


t_transition_priority::t_transition_priority( i_compound_transition& p_compound_transition )
	: m_compound_transition( &p_compound_transition ),
		m_priority( p_compound_transition.get_LCA_region()->get_parent_state().get_nesting_level() )
{
	// Nothing to do...
}


t_transition_priority::~t_transition_priority() = default;


std::size_t t_transition_priority::get_priority() const
{
	return( m_priority );
}


i_compound_transition& t_transition_priority::get_compound_transition() const
{
	return( *m_compound_transition );
}


bool t_transition_priority::operator<( const t_transition_priority& p_compare_member )  const
{
	return( m_priority > p_compare_member.get_priority() );
}


}
