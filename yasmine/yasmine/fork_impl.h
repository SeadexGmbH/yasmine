//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FORK_IMPL_DCB9F2CB_E7C4_4E00_BD05_B2C179DEFCB0
#define FORK_IMPL_DCB9F2CB_E7C4_4E00_BD05_B2C179DEFCB0


#include "fork.h"
#include "region_pseudostate_impl.h"


namespace sxy
{


class fork_impl final:
	public virtual fork, public region_pseudostate_impl
{
public:
	explicit fork_impl( const std::string& _name );
	virtual ~fork_impl() override;
	fork_impl( const fork_impl& ) = delete;
	fork_impl& operator=( const fork_impl& ) = delete;
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const override;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) override;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const override;
	virtual void add_incoming_transition( transition& _incoming_transition ) override;
};


}


#endif
