//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "entry_point_impl.hpp"

#include "essentials/base.hpp"

#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "pseudostate_visitor.hpp"


namespace sxy
{


entry_point_impl::entry_point_impl( const std::string& _name )
	: state_pseudostate_impl( _name )
{
	// Nothing to do...
}


entry_point_impl::~entry_point_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


bool entry_point_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// transitions exiting pseudostates cannot have a trigger
	if( !pseudostate_impl::check( _defects ) )
	{
		check_ok = false;
	}

	return( check_ok );
}


void entry_point_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void entry_point_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void entry_point_impl::accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


}
