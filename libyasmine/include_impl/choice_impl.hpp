//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CHOICE_IMPL_E8DE2646_E657_4A8B_96EE_B0699FB5652D
#define CHOICE_IMPL_E8DE2646_E657_4A8B_96EE_B0699FB5652D


#include "choice.hpp"
#include "region_pseudostate_impl.hpp"


namespace sxy
{


class choice_impl Y_FINAL:
	public virtual choice, public region_pseudostate_impl
{
public:
	explicit choice_impl( const std::string& _name );
	virtual ~choice_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(choice_impl)
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const Y_OVERRIDE;
};


}


#endif
