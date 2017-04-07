//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "terminate_pseudostate_impl.hpp"

#include "essentials/base.hpp"

#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "pseudostate_visitor.hpp"
#include "transition.hpp"


namespace sxy
{


terminate_pseudostate_impl::terminate_pseudostate_impl( const std::string& _name )
	: region_pseudostate_impl( _name )
{
	// Nothing to do...
}


terminate_pseudostate_impl::~terminate_pseudostate_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


bool terminate_pseudostate_impl::check( state_machine_defects& _defects ) const
{
	SX_UNUSED_PARAMETER( _defects );
	const bool check_ok = true;
	return( check_ok );
}


void terminate_pseudostate_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void terminate_pseudostate_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void terminate_pseudostate_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void terminate_pseudostate_impl::add_outgoing_transition( transition& _outgoing_transition )
{
	SX_UNUSED_PARAMETER( _outgoing_transition );
	SX_ASSERT( vertex_impl::get_outgoing_transitions().empty(), "Terminate pseudostate cannot have outgoing transitions!" );
}


}
