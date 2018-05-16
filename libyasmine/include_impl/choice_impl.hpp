//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CHOICE_IMPL_E8DE2646_E657_4A8B_96EE_B0699FB5652D
#define CHOICE_IMPL_E8DE2646_E657_4A8B_96EE_B0699FB5652D


#include "choice.hpp"
#include "region_pseudostate_impl.hpp"


namespace sxy
{


class choice_impl SX_FINAL:
	public choice, public region_pseudostate_impl
{
public:
	explicit choice_impl( const std::string& _name );
	virtual ~choice_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(choice_impl)
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const SX_OVERRIDE;
};


}


#endif
