//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef DEEP_HISTORY_IMPL_F0E414BF_2D3A_406F_9BCF_9E6A87E7329D
#define DEEP_HISTORY_IMPL_F0E414BF_2D3A_406F_9BCF_9E6A87E7329D


#include "deep_history.hpp"
#include "history_impl.hpp"


namespace sxy
{


class deep_history_impl SX_FINAL:
	public deep_history, public history_impl
{
public:
	explicit deep_history_impl( const std::string& _name );
	virtual ~deep_history_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(deep_history_impl)
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const SX_OVERRIDE;
};


}


#endif
