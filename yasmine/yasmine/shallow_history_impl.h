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


#include "shallow_history.h"
#include "history_impl.h"


namespace sxy
{


class shallow_history_impl:
	public virtual shallow_history, public history_impl
{
public:
	explicit shallow_history_impl( const std::string& _name );
	virtual ~shallow_history_impl() override;
	shallow_history_impl( const shallow_history_impl& ) = delete;
	shallow_history_impl& operator=( const shallow_history_impl& ) = delete;
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const override;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) override;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const override;
};


}


#endif
