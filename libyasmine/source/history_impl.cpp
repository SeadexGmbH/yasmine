//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "history_impl.hpp"

#include "base.hpp"
#include "composite_state.hpp"


namespace sxy
{


history_impl::history_impl( const std::string& _name )
	: state_pseudostate_impl( _name )
{
	// Nothing to do...
}


history_impl::~history_impl() Y_NOEXCEPT
{
	// Nothing to do...
}


raw_transitions history_impl::get_default_transitions() const
{
	return( vertex_impl::get_outgoing_transitions() );
}


void history_impl::add_default_transition( transition& _default_transition )
{
	vertex_impl::add_outgoing_transition( _default_transition );
}


bool history_impl::check_if_state_was_active_before() const
{
	const composite_state& parent_state = get_parent_state();
	const bool state_was_active = parent_state.was_active();
	return( state_was_active );
}


}
