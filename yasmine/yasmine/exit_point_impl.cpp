//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "exit_point_impl.h"

#include "base.h"
#include "const_vertex_visitor.h"
#include "vertex_visitor.h"
#include "pseudostate_visitor.h"


namespace sxy
{


exit_point_impl::exit_point_impl( const std::string& _name )
	: state_pseudostate_impl( _name )
{
	// Nothing to do...
}


exit_point_impl::~exit_point_impl() = default;


bool exit_point_impl::check( state_machine_defects& _defects ) const
{
	auto check_ok = true;

	// transitions exiting pseudostates cannot have a trigger
	if( !pseudostate_impl::check( _defects ) )
	{
		check_ok = false;
	}

	return( check_ok );
}


void exit_point_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void exit_point_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void exit_point_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


}