//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FORK_IMPL_DCB9F2CB_E7C4_4E00_BD05_B2C179DEFCB0
#define FORK_IMPL_DCB9F2CB_E7C4_4E00_BD05_B2C179DEFCB0


#include "fork.hpp"
#include "region_pseudostate_impl.hpp"


namespace sxy
{


class fork_impl SX_FINAL:
	public virtual fork, public region_pseudostate_impl
{
public:
	explicit fork_impl( const std::string& _name );
	virtual ~fork_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(fork_impl)
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const SX_OVERRIDE;
	virtual void add_incoming_transition( transition& _incoming_transition ) SX_OVERRIDE;
};


}


#endif
