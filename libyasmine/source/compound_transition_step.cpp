//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "compound_transition_step.hpp"

#include "transition.hpp"
#include "entry_point.hpp"
#include "exit_point.hpp"


namespace sxy
{


compound_transition_step::compound_transition_step( const raw_transitions& _transitions )
	: transition_step(),
		transitions_( _transitions )
{
	// Nothing to do...
}


compound_transition_step::~compound_transition_step() SX_NOEXCEPT
{
	// Nothing to do...
}


const raw_transitions& compound_transition_step::get_transitions() const
{
	return( transitions_ );
}


const vertex& compound_transition_step::get_unique_source() const
{
	const transition* const unique_transition = transitions_.front();
	const vertex& source_vertex = unique_transition->get_source();
	return( source_vertex );
}


const vertex& compound_transition_step::get_unique_target() const
{
	const transition* const unique_transition = transitions_.front();
	const vertex& target_vertex = unique_transition->get_target();
	return( target_vertex );
}


const exit_point* compound_transition_step::get_exit_point() const
{
	const exit_point* const l_exit_point = dynamic_cast< const exit_point* >( &get_unique_target() );
	return( l_exit_point );
}


const entry_point* compound_transition_step::get_entry_point() const
{
	const entry_point* const l_entry_point = dynamic_cast< const entry_point* >( &get_unique_source() );
	return( l_entry_point );
}


const raw_const_vertices compound_transition_step::get_target_vertices()
{
	raw_const_vertices target_vertices;
	target_vertices.reserve( transitions_.size() );

	SX_FOR( const transition* const transition, transitions_ )
	{
		const vertex& target_vertex = transition->get_source();
		target_vertices.push_back( &target_vertex );
	}

	return( target_vertices );
}


void compound_transition_step::execute_transition_behaviors( const event& _event, event_collector& _event_collector ) const
{
	SX_FOR( const transition* const transition, transitions_ )
	{
		transition->on_transition_behavior( _event, _event_collector );
	}
}


}
