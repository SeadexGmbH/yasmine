//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TERMINATE_PSEUDOSTATE_IMPL_8A849A3E_D15E_4C67_9BA0_77470C0F6683
#define TERMINATE_PSEUDOSTATE_IMPL_8A849A3E_D15E_4C67_9BA0_77470C0F6683


#include "terminate_pseudostate.hpp"
#include "region_pseudostate_impl.hpp"


namespace sxy
{


class terminate_pseudostate_impl Y_FINAL:
	public virtual terminate_pseudostate, public region_pseudostate_impl
{
public:
	explicit terminate_pseudostate_impl( const std::string& _name );
	virtual ~terminate_pseudostate_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(terminate_pseudostate_impl)
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const Y_OVERRIDE;
	virtual void add_outgoing_transition( transition& _outgoing_transition ) Y_OVERRIDE;
};


}


#endif
