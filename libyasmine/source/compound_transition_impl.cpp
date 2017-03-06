//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "compound_transition_impl.hpp"

#include "vertex.hpp"
#include "transition.hpp"
#include "transition_step.hpp"
#include "build_transition_steps_visitor.hpp"
#include "algorithm_parameters.hpp"


namespace sxy
{


compound_transition_impl::compound_transition_impl()
	: transition_steps_(),
		sub_compound_transitions_()
{
	transition_steps_.reserve( TRANSITION_STEPS_VECTOR_SIZE );
	sub_compound_transitions_.reserve( COMPOUND_TRANSITIONS_VECTOR_SIZE );
}


compound_transition_impl::~compound_transition_impl() Y_NOEXCEPT
{
	// Nothing to do...
}


transition_steps& compound_transition_impl::get_transition_steps()
{
	return( transition_steps_ );
}


const vertex& compound_transition_impl::get_last_target() const
{
	const transition_step_uptr& last_step = transition_steps_.back();
	const raw_transitions& transitions = last_step->get_transitions();
	const transition* const last_transition = transitions.front();
	const vertex& target_vertex = last_transition->get_target();
	return( target_vertex );
}


const compound_transitions& compound_transition_impl::get_sub_compound_transitions() const
{
	return( sub_compound_transitions_ );
}


void compound_transition_impl::add_sub_compound_transition( compound_transition_uptr _sub_compound_transition )
{
	sub_compound_transitions_.push_back( sxy::move( _sub_compound_transition ) );
}


region* compound_transition_impl::get_LCA_region()
{
	const transition_step* const step1 = transition_steps_.front().get();
	const transition* const transition1 = step1->get_transitions().front();
	const vertex& source = transition1->get_source();
	const transition_step_uptr& step2 = transition_steps_.back();
	const transition* const transition2 = step2->get_transitions().back();
	const vertex& target = transition2->get_target();
	return( source.LCA_region( target ) );
}


composite_state* compound_transition_impl::get_LCA_composite_state()
{
	const transition_step* const step1 = transition_steps_.front().get();
	const transition* const transition1 = step1->get_transitions().front();
	const vertex& source = transition1->get_source();
	const transition_step_uptr& step2 = transition_steps_.back();
	const transition* const transition2 = step2->get_transitions().back();
	const vertex& target = transition2->get_target();
	return( source.LCA_composite_state( target ) );
}


transition_kind compound_transition_impl::get_transition_kind()
{
	const transition* const transition = get_transition_steps().back()->get_transitions().back();
	return( transition->get_kind() );
}


bool compound_transition_impl::check_if_starts_with( const transition& _transition )
{
	bool start_with = false;
	const transition_steps& transition_steps = get_transition_steps();
	if( !transition_steps.empty() )
	{
		const transition_step_uptr& first_step = transition_steps.front();
		const raw_transitions& transitions = first_step->get_transitions();

		Y_FOR( const transition* const transition, transitions )
		{
			if( transition == &_transition )
			{
				start_with = true;
				break;
			}
		}
	}

	return( start_with );
}


bool compound_transition_impl::create_and_check_transition_path( transition& _start_transition,	
	const event& _event, event_collector& _event_collector )
{
	transition* current_transition = &_start_transition;
	bool reached_end_of_transition = true;
	while( current_transition != Y_NULLPTR )
	{
		const vertex& target = current_transition->get_target();
		build_transition_steps_visitor build_transition_steps_visitor( *current_transition, transition_steps_, _event, 
			_event_collector );
		target.accept_vertex_visitor( build_transition_steps_visitor );
		current_transition = build_transition_steps_visitor.get_next_transition();
		reached_end_of_transition = build_transition_steps_visitor.reached_end_of_transition();
	}

	return( reached_end_of_transition );
}


}
