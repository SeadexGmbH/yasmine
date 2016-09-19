//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TERMINATE_PSEUDOSTATE_IMPL_8A849A3E_D15E_4C67_9BA0_77470C0F6683
#define TERMINATE_PSEUDOSTATE_IMPL_8A849A3E_D15E_4C67_9BA0_77470C0F6683


#include "terminate_pseudostate.h"
#include "region_pseudostate_impl.h"


namespace sxy
{


class terminate_pseudostate_impl final:
	public virtual terminate_pseudostate, public region_pseudostate_impl
{
public:
	explicit terminate_pseudostate_impl( const std::string& _name );
	virtual ~terminate_pseudostate_impl() override;
	terminate_pseudostate_impl( const terminate_pseudostate_impl& ) = delete;
	terminate_pseudostate_impl& operator=( const terminate_pseudostate_impl& ) = delete;
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const override;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) override;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const override;
	virtual void add_outgoing_transition( transition& _outgoing_transition ) override;
};


}


#endif
