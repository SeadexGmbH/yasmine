//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_terminate_pseudostate.h"

#include "base.h"
#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_pseudostate_visitor.h"


namespace sxy
{


t_terminate_pseudostate::t_terminate_pseudostate( const std::string& p_name )
	: t_region_pseudostate( p_name )
{
	// Nothing to do...
}


t_terminate_pseudostate::~t_terminate_pseudostate() = default;


bool t_terminate_pseudostate::check( t_state_machine_defects& p_defects ) const
{
	Y_UNUSED_PARAMETER( p_defects );
	auto l_check_ok = true;
	return( l_check_ok );
}


void t_terminate_pseudostate::accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_terminate_pseudostate::accept_vertex_visitor( i_vertex_visitor& p_visitor )
{
	p_visitor.visit( *this );
}


void t_terminate_pseudostate::accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_terminate_pseudostate::add_outgoing_transition( i_transition& p_outgoing_transition )
{
	Y_UNUSED_PARAMETER( p_outgoing_transition );
	Y_ASSERT( t_vertex::get_outgoing_transitions().empty(), "Terminate pseudostate cannot have outgoing transitions!" );
}


}
