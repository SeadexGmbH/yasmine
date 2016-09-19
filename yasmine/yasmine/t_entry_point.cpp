//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_entry_point.h"

#include "base.h"
#include "i_const_vertex_visitor.h"
#include "i_vertex_visitor.h"
#include "i_pseudostate_visitor.h"


namespace sxy
{


t_entry_point::t_entry_point( const std::string& p_name )
	: t_state_pseudostate( p_name )
{
	// Nothing to do...
}


t_entry_point::~t_entry_point() = default;


bool t_entry_point::check( t_state_machine_defects& p_defects ) const
{
	auto l_check_ok = true;

	// transitions exiting pseudostates cannot have a trigger
	if( !t_pseudostate::check( p_defects ) )
	{
		l_check_ok = false;
	}

	return( l_check_ok );
}


void t_entry_point::accept_vertex_visitor( i_const_vertex_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


void t_entry_point::accept_vertex_visitor( i_vertex_visitor& p_visitor )
{
	p_visitor.visit( *this );
}


void t_entry_point::accept_pseudostate_visitor( i_pseudostate_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


}
