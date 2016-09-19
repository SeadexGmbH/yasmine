//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_check_if_all_incoming_transitions_sources_are_active_visitor.h"

#include "i_composite_state.h"
#include "i_simple_state.h"


namespace sxy
{


t_check_if_all_incoming_transitions_sources_are_active_visitor::t_check_if_all_incoming_transitions_sources_are_active_visitor():
	i_complex_state_visitor(), m_source_is_finished( false )
{
	// Nothing to do...
}


t_check_if_all_incoming_transitions_sources_are_active_visitor::~t_check_if_all_incoming_transitions_sources_are_active_visitor() = default;


void t_check_if_all_incoming_transitions_sources_are_active_visitor::visit( const i_composite_state& p_composite_state )
{
	m_source_is_finished = p_composite_state.is_active();
	if( m_source_is_finished )
	{
		m_source_is_finished = p_composite_state.check_if_regions_are_completed();
	}
}


void t_check_if_all_incoming_transitions_sources_are_active_visitor::visit( const i_simple_state& p_simple_state )
{
	m_source_is_finished = p_simple_state.is_active();
}


bool t_check_if_all_incoming_transitions_sources_are_active_visitor::get_result() const
{
	return( m_source_is_finished );
}


}
