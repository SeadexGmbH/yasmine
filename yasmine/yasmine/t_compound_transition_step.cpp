//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_compound_transition_step.h"

#include "i_transition.h"
#include "i_entry_point.h"
#include "i_exit_point.h"


namespace sxy
{


t_compound_transition_step::t_compound_transition_step( const t_raw_transitions& p_transitions )
	: i_transition_step(),
		m_transitions( p_transitions )
{
	// Nothing to do...
}


t_compound_transition_step::~t_compound_transition_step() = default;


const t_raw_transitions& t_compound_transition_step::get_transitions() const
{
	return( m_transitions );
}


const i_vertex& t_compound_transition_step::get_unique_source() const
{
	const auto unique_transition = m_transitions.front();
	const auto& source_vertex = unique_transition->get_source();
	return( source_vertex );
}


const i_vertex& t_compound_transition_step::get_unique_target() const
{
	const auto unique_transition = m_transitions.front();
	const auto& target_vertex = unique_transition->get_target();
	return( target_vertex );
}


const i_exit_point* t_compound_transition_step::get_exit_point() const
{
	const auto l_exit_point = dynamic_cast< const i_exit_point* >( &get_unique_target() );
	return( l_exit_point );
}


const i_entry_point* t_compound_transition_step::get_entry_point() const
{
	const auto l_entry_point = dynamic_cast< const i_entry_point* >( &get_unique_source() );
	return( l_entry_point );
}


// cppcheck-suppress unusedFunction
const t_raw_const_vertices t_compound_transition_step::get_target_vertices()
{
	t_raw_const_vertices target_vertices;

	for( const auto & transition : m_transitions )
	{
		const auto& target_vertex = transition->get_source();
		target_vertices.push_back( &target_vertex );
	}

	return( target_vertices );
}


// cppcheck-suppress unusedFunction
void t_compound_transition_step::execute_transition_behaviors( const i_event& p_event ) const
{
	for( const auto transition : m_transitions )
	{
		transition->on_transition_behavior( p_event );
	}
}


}
