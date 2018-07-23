//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "initial_pseudostate_model_impl.hpp"

#include "model_vertex_visitor.hpp"
#include "delete_visitor.hpp"


namespace sxy
{


namespace model
{


initial_pseudostate_model_impl::initial_pseudostate_model_impl( const std::string& _name )
	: pseudostate_model_impl( _name, model_element_type::TYE_INITIAL_PSEUDOSTATE )
{
	// Nothing to do...
}


initial_pseudostate_model_impl::~initial_pseudostate_model_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


void initial_pseudostate_model_impl::accept( model_vertex_visitor& _constructor_visitor ) const
{
	_constructor_visitor.visit( *this );
}


void initial_pseudostate_model_impl::accept_delete_visitor( delete_visitor& _delete_visitor )
{
	_delete_visitor.visit( *this );
}


}


}
