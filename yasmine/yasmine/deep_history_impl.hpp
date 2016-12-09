//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef DEEP_HISTORY_IMPL_F0E414BF_2D3A_406F_9BCF_9E6A87E7329D
#define DEEP_HISTORY_IMPL_F0E414BF_2D3A_406F_9BCF_9E6A87E7329D


#include "deep_history.hpp"
#include "history_impl.hpp"


namespace sxy
{


class deep_history_impl Y_FINAL:
	public virtual deep_history, public history_impl
{
public:
	explicit deep_history_impl( const std::string& _name );
	virtual ~deep_history_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(deep_history_impl)
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const Y_OVERRIDE;
};


}


#endif
