//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SHALLOW_HISTORY_IMPL_42D1E208_B814_4D2E_9963_375AFE37F3A4
#define SHALLOW_HISTORY_IMPL_42D1E208_B814_4D2E_9963_375AFE37F3A4


#include "shallow_history.hpp"
#include "history_impl.hpp"


namespace sxy
{


class shallow_history_impl:
	public shallow_history, public history_impl
{
public:
	explicit shallow_history_impl( const std::string& _name );
	virtual ~shallow_history_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(shallow_history_impl)
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const SX_OVERRIDE;
};


}


#endif
