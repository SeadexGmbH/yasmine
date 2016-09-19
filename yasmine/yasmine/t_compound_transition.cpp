//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_compound_transition.h"

#include "i_vertex.h"
#include "i_transition.h"
#include "i_transition_step.h"
#include "t_build_transition_steps_visitor.h"


namespace sxy
{


t_compound_transition::t_compound_transition
(
):
	m_transition_steps(),	
	m_sub_compound_transitions()
{
	// Nothing to do...
}


t_compound_transition::~t_compound_transition
(
) = default;


t_transition_steps&
t_compound_transition::get_transition_steps
(
)
{
	return( m_transition_steps );
}


const i_vertex&
t_compound_transition::get_last_target
(
) const
{
	const auto& last_step = m_transition_steps.back();
	const auto& transitions = last_step->get_transitions();
	const auto last_transition = transitions.front();
	const auto& target_vertex = last_transition->get_target();

	return( target_vertex );
}


const t_compound_transitions&
t_compound_transition::get_sub_compound_transitions
(
) const
{
	return( m_sub_compound_transitions );
}


void
t_compound_transition::add_sub_compound_transition
(
		i_compound_transition_uptr p_sub_compound_transition
)
{
	m_sub_compound_transitions.push_back( std::move( p_sub_compound_transition ) );
}


i_region*
t_compound_transition::get_LCA_region
(
)
{	
	const auto& l_step1 = m_transition_steps.front().get();
	const auto& l_transition1 = l_step1->get_transitions().front();
	const auto& l_source = l_transition1->get_source();
															
	const auto& l_step2 = m_transition_steps.back();
	const auto& l_transition2 = l_step2->get_transitions().back();
	const auto& l_target = l_transition2->get_target();

	return ( l_source.LCA_region( l_target ) );
}


i_composite_state*
// cppcheck-suppress unusedFunction
t_compound_transition::get_LCA_composite_state
(
)
{
	const auto& l_step1 = m_transition_steps.front().get();
	const auto& l_transition1 = l_step1->get_transitions().front();
	const auto& l_source = l_transition1->get_source();

	const auto& l_step2 = m_transition_steps.back();
	const auto& l_transition2 = l_step2->get_transitions().back();
	const auto& l_target = l_transition2->get_target();

	return ( l_source.LCA_composite_state( l_target ) );
}


t_transition_kind
t_compound_transition::get_transition_kind
(
)
{		
	auto l_transition = get_transition_steps().back()->get_transitions().back();

	return( l_transition->get_kind() );
}


bool
t_compound_transition::check_if_starts_with
(
	const i_transition& p_transition
)
{
	auto start_with = false;

	const auto& transition_steps = get_transition_steps();
	if( !transition_steps.empty() )
	{
		const auto& first_step = transition_steps.front();
		const auto& transitions = first_step->get_transitions();

		for( const auto transition : transitions )
		{
			if( transition == &p_transition )
			{
				start_with = true;
				break;
			}
		}
	}

	return( start_with );
}
 

bool
t_compound_transition::create_and_check_transition_path
(
	i_transition& p_start_transition,
	const i_event& p_event
)
{
	auto current_transition = &p_start_transition;
	auto reached_end_of_transition = true;
	while( current_transition != nullptr )
	{
		const auto& target = current_transition->get_target();
		t_build_transition_steps_visitor build_transition_steps_visitor( *current_transition, m_transition_steps, p_event );
		target.accept_vertex_visitor( build_transition_steps_visitor );

		current_transition = build_transition_steps_visitor.get_next_transition();
		reached_end_of_transition = build_transition_steps_visitor.reached_end_of_transition();
	}

	return( reached_end_of_transition );
}


}
