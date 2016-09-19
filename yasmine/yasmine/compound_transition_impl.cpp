//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
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


namespace sxy
{


compound_transition_impl::compound_transition_impl()
	: transition_steps_(),
		sub_compound_transitions_()
{
	// Nothing to do...
}


transition_steps& compound_transition_impl::get_transition_steps()
{
	return( transition_steps_ );
}


const vertex& compound_transition_impl::get_last_target() const
{
	const auto& last_step = transition_steps_.back();
	const auto& transitions = last_step->get_transitions();
	const auto last_transition = transitions.front();
	const auto& target_vertex = last_transition->get_target();
	return( target_vertex );
}


const compound_transitions& compound_transition_impl::get_sub_compound_transitions() const
{
	return( sub_compound_transitions_ );
}


void compound_transition_impl::add_sub_compound_transition( compound_transition_uptr _sub_compound_transition )
{
	sub_compound_transitions_.push_back( std::move( _sub_compound_transition ) );
}


region* compound_transition_impl::get_LCA_region()
{
	const auto& step1 = transition_steps_.front().get();
	const auto& transition1 = step1->get_transitions().front();
	const auto& source = transition1->get_source();
	const auto& step2 = transition_steps_.back();
	const auto& transition2 = step2->get_transitions().back();
	const auto& target = transition2->get_target();
	return( source.LCA_region( target ) );
}


// cppcheck-suppress unusedFunction
composite_state* compound_transition_impl::get_LCA_composite_state()
{
	const auto& step1 = transition_steps_.front().get();
	const auto& transition1 = step1->get_transitions().front();
	const auto& source = transition1->get_source();
	const auto& step2 = transition_steps_.back();
	const auto& transition2 = step2->get_transitions().back();
	const auto& target = transition2->get_target();
	return( source.LCA_composite_state( target ) );
}


transition_kind compound_transition_impl::get_transition_kind()
{
	auto transition = get_transition_steps().back()->get_transitions().back();
	return( transition->get_kind() );
}


bool compound_transition_impl::check_if_starts_with( const transition& _transition )
{
	auto start_with = false;
	const auto& transition_steps = get_transition_steps();
	if( !transition_steps.empty() )
	{
		const auto& first_step = transition_steps.front();
		const auto& transitions = first_step->get_transitions();

		for( const auto transition : transitions )
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
	const event& _event )
{
	auto current_transition = &_start_transition;
	auto reached_end_of_transition = true;
	while( current_transition != nullptr )
	{
		const auto& target = current_transition->get_target();
		build_transition_steps_visitor build_transition_steps_visitor( *current_transition, transition_steps_, _event );
		target.accept_vertex_visitor( build_transition_steps_visitor );
		current_transition = build_transition_steps_visitor.get_next_transition();
		reached_end_of_transition = build_transition_steps_visitor.reached_end_of_transition();
	}

	return( reached_end_of_transition );
}


}
