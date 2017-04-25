//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "final_state_model_impl.hpp"

#include "essentials/base.hpp"

#include "model_vertex_visitor.hpp"
#include "model_element_type.hpp"


namespace sxy
{


namespace model
{

final_state_model_impl::final_state_model_impl( const std::string& _name )
	: state_model_impl( _name, model_element_type::TYE_FINAL_STATE ),
		no_behavior_("")
{
	// Nothing to do...
}


final_state_model_impl::~final_state_model_impl()SX_NOEXCEPT
{
	// Nothing to do...
}


const raw_const_region_models final_state_model_impl::get_regions() const
{
	raw_const_region_models regions;
	return( regions );
}


const std::string& final_state_model_impl::get_enter_behavior() const
{
	return( no_behavior_ );
}


void final_state_model_impl::set_enter_behavior( const std::string& _enter_behavior )
{
	SX_UNUSED_PARAMETER( _enter_behavior );
}


const std::string& final_state_model_impl::get_do_behavior() const
{
	return( no_behavior_ );
}


void final_state_model_impl::set_do_behavior( const std::string& _do_behavior )
{
	SX_UNUSED_PARAMETER( _do_behavior );
}


const std::string& final_state_model_impl::get_exit_behavior() const
{
	return( no_behavior_ );
}


void final_state_model_impl::set_exit_behavior( const std::string& _exit_behavior )
{
	SX_UNUSED_PARAMETER( _exit_behavior );
}


void final_state_model_impl::accept( model_vertex_visitor& _constructor_visitor ) const
{
	_constructor_visitor.visit( *this );
}


}


}
