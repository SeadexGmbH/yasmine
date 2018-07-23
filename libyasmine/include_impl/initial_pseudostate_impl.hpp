//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef INITIAL_PSEUDOSTATE_IMPL_39ED4963_725A_495E_ADAE_09739A333E71
#define INITIAL_PSEUDOSTATE_IMPL_39ED4963_725A_495E_ADAE_09739A333E71


#include "initial_pseudostate.hpp"
#include "region_pseudostate_impl.hpp"


namespace sxy
{


class initial_pseudostate_impl SX_FINAL:
	public initial_pseudostate, public region_pseudostate_impl
{
public:
	explicit initial_pseudostate_impl( const std::string& _name );
	virtual ~initial_pseudostate_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(initial_pseudostate_impl)
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const SX_OVERRIDE;
	virtual transition * get_transition() const SX_OVERRIDE;
	virtual void add_incoming_transition( transition& _incoming_transition ) SX_OVERRIDE;
};


}


#endif
