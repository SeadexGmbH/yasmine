//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SHALLOW_HISTORY_IMPL_42D1E208_B814_4D2E_9963_375AFE37F3A4
#define SHALLOW_HISTORY_IMPL_42D1E208_B814_4D2E_9963_375AFE37F3A4


#include "shallow_history.hpp"
#include "history_impl.hpp"


namespace sxy
{


class shallow_history_impl:
	public virtual shallow_history, public history_impl
{
public:
	explicit shallow_history_impl( const std::string& _name );
	virtual ~shallow_history_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(shallow_history_impl)
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const Y_OVERRIDE;
};


}


#endif
