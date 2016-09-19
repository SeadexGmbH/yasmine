//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "simple_transition_step.hpp"

#include "transition.hpp"
#include "entry_point.hpp"
#include "exit_point.hpp"


namespace sxy
{


simple_transition_step::simple_transition_step( transition& _transition )
	: transition_step(),
		transition_( _transition ),
		transition_step_()
{
	transition_step_.push_back( &transition_ );
}


const raw_transitions& simple_transition_step::get_transitions() const
{
	return( transition_step_ );
}


const vertex& simple_transition_step::get_unique_source() const
{
	const auto& source_vertex = transition_.get_source();
	return( source_vertex );
}


const vertex& simple_transition_step::get_unique_target() const
{
	const auto& target_vertex = transition_.get_target();
	return( target_vertex );
}


const exit_point* simple_transition_step::get_exit_point() const
{
	const auto l_exit_point = dynamic_cast< const exit_point* >( &get_unique_target() );
	return( l_exit_point );
}


const entry_point* simple_transition_step::get_entry_point() const
{
	const auto vertex = dynamic_cast< const entry_point* >( &get_transitions().front()->get_source() );
	return( vertex );
}


const raw_const_vertices simple_transition_step::get_target_vertices()
{
	raw_const_vertices target_vertices;
	const auto& target_vertex = transition_.get_target();
	target_vertices.push_back( &target_vertex );
	return( target_vertices );
}


void simple_transition_step::execute_transition_behaviors( const event& _event ) const
{
	for( const auto & transition : transition_step_ )
	{
		transition->on_transition_behavior( _event );
	}
}


}
