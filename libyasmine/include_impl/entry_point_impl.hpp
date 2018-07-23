//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ENTRY_POINT_IMPL_78A17172_D649_4870_988D_50A995692441
#define ENTRY_POINT_IMPL_78A17172_D649_4870_988D_50A995692441


#include "entry_point.hpp"
#include "state_pseudostate_impl.hpp"


namespace sxy
{


class entry_point_impl SX_FINAL:
	public entry_point, public state_pseudostate_impl
{
public:
	explicit entry_point_impl( const std::string& _name );
	virtual ~entry_point_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(entry_point_impl)
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const SX_OVERRIDE;
};


}


#endif
