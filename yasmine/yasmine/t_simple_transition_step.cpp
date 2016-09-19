//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_simple_transition_step.h"

#include "i_transition.h"
#include "i_entry_point.h"
#include "i_exit_point.h"


namespace sxy
{


t_simple_transition_step::t_simple_transition_step
(
	i_transition& p_transition
): i_transition_step(),
	 m_transition( p_transition ),
	 m_transition_step()	 
{
	m_transition_step.push_back( &m_transition );
}


t_simple_transition_step::~t_simple_transition_step
(
) = default;


const t_raw_transitions&
t_simple_transition_step::get_transitions
(
) const
{
	return( m_transition_step );
}


const i_vertex&
t_simple_transition_step::get_unique_source
(
) const
{
	const auto& source_vertex = m_transition.get_source();
	return( source_vertex );
}


const i_vertex&
t_simple_transition_step::get_unique_target
(
) const
{
	const auto& target_vertex = m_transition.get_target();
	return( target_vertex );
}
	 	 

const i_exit_point*
t_simple_transition_step::get_exit_point
(
) const
{
	const auto l_exit_point = dynamic_cast< const i_exit_point* >( &get_unique_target() );
	return( l_exit_point );
}


const i_entry_point*
t_simple_transition_step::get_entry_point
(
) const
{		
	const auto l_vertex = dynamic_cast< const i_entry_point* >( &get_transitions().front()->get_source() );
	return( l_vertex );
}

 
const t_raw_const_vertices
t_simple_transition_step::get_target_vertices
(
)
{
	t_raw_const_vertices target_vertices;

	const auto& target_vertex = m_transition.get_target();	
	target_vertices.push_back( &target_vertex );
	
	return( target_vertices );
}


void
t_simple_transition_step::execute_transition_behaviors
(
	const i_event& p_event
) const
{
	for( const auto& transition : m_transition_step )
	{
		transition->on_transition_behavior( p_event );
	}
}


}
