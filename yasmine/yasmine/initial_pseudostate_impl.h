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


#include "initial_pseudostate.h"
#include "region_pseudostate_impl.h"


namespace sxy
{


class initial_pseudostate_impl final:
	public virtual initial_pseudostate, public region_pseudostate_impl
{
public:
	explicit initial_pseudostate_impl( const std::string& _name );
	virtual ~initial_pseudostate_impl() override;
	initial_pseudostate_impl( const initial_pseudostate_impl& ) = delete;
	initial_pseudostate_impl& operator=( const initial_pseudostate_impl& ) = delete;
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const override;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) override;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const override;
	virtual transition * get_transition() const override;
	virtual void add_incoming_transition( transition& _incoming_transition ) override;
};


}


#endif
