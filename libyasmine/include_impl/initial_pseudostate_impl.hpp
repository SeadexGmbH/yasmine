//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef INITIAL_PSEUDOSTATE_IMPL_39ED4963_725A_495E_ADAE_09739A333E71
#define INITIAL_PSEUDOSTATE_IMPL_39ED4963_725A_495E_ADAE_09739A333E71


#include "initial_pseudostate.hpp"
#include "region_pseudostate_impl.hpp"


namespace sxy
{


class initial_pseudostate_impl Y_FINAL:
	public virtual initial_pseudostate, public region_pseudostate_impl
{
public:
	explicit initial_pseudostate_impl( const std::string& _name );
	virtual ~initial_pseudostate_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(initial_pseudostate_impl)
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const Y_OVERRIDE;
	virtual transition * get_transition() const Y_OVERRIDE;
	virtual void add_incoming_transition( transition& _incoming_transition ) Y_OVERRIDE;
};


}


#endif
