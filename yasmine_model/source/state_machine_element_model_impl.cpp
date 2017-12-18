//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "state_machine_element_model_impl.hpp"

#include "model_element_type.hpp"


namespace sxy
{


namespace model
{


state_machine_element_model_impl::state_machine_element_model_impl(
	const std::string& _name,
	const model_element_type& _type )
	: name_( _name ),
		parent_(),
		type_( _type )
{
	// Nothing to do...
}


state_machine_element_model_impl::~state_machine_element_model_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


const std::string& state_machine_element_model_impl::get_name() const
{
	return( name_ );
}


void state_machine_element_model_impl::set_name( const std::string& _name )
{
	name_ = _name;
}


const state_machine_element_model* state_machine_element_model_impl::get_parent() const
{
	return( parent_ );
}


state_machine_element_model* state_machine_element_model_impl::get_parent()
{
	return( parent_ );
}


void state_machine_element_model_impl::set_parent( state_machine_element_model* _parent )
{
	parent_ = _parent;
}


const sxe::uri state_machine_element_model_impl::get_uri() const
{
	sxe::uri element_uri( get_name() );
	add_ancestor_uri( element_uri );
	return( element_uri );
}


model_element_type state_machine_element_model_impl::get_type() const
{
	return( type_ );
}


void state_machine_element_model_impl::add_ancestor_uri( sxe::uri& _uri ) const
{
	const state_machine_element_model* parent = get_parent();
	while( parent )
	{
		_uri.push_front( parent->get_name() );
		parent = parent->get_parent();
	}
}


}


}
