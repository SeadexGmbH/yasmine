//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "compound_transition_step.h"

#include "transition.h"
#include "entry_point.h"
#include "exit_point.h"


namespace sxy
{


compound_transition_step::compound_transition_step( const raw_transitions& _transitions )
	: transition_step(),
		transitions_( _transitions )
{
	// Nothing to do...
}


compound_transition_step::~compound_transition_step() = default;


const raw_transitions& compound_transition_step::get_transitions() const
{
	return( transitions_ );
}


const vertex& compound_transition_step::get_unique_source() const
{
	const auto unique_transition = transitions_.front();
	const auto& source_vertex = unique_transition->get_source();
	return( source_vertex );
}


const vertex& compound_transition_step::get_unique_target() const
{
	const auto unique_transition = transitions_.front();
	const auto& target_vertex = unique_transition->get_target();
	return( target_vertex );
}


const exit_point* compound_transition_step::get_exit_point() const
{
	const auto l_exit_point = dynamic_cast< const exit_point* >( &get_unique_target() );
	return( l_exit_point );
}


const entry_point* compound_transition_step::get_entry_point() const
{
	const auto l_entry_point = dynamic_cast< const entry_point* >( &get_unique_source() );
	return( l_entry_point );
}


// cppcheck-suppress unusedFunction
const raw_const_vertices compound_transition_step::get_target_vertices()
{
	raw_const_vertices target_vertices;

	for( const auto & transition : transitions_ )
	{
		const auto& target_vertex = transition->get_source();
		target_vertices.push_back( &target_vertex );
	}

	return( target_vertices );
}


// cppcheck-suppress unusedFunction
void compound_transition_step::execute_transition_behaviors( const event& _event ) const
{
	for( const auto transition : transitions_ )
	{
		transition->on_transition_behavior( _event );
	}
}


}
