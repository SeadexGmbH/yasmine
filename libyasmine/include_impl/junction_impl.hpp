//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef JUNCTION_IMPL_9BB5CE53_8B97_444D_8548_FDF175AB929C
#define JUNCTION_IMPL_9BB5CE53_8B97_444D_8548_FDF175AB929C


#include "junction.hpp"
#include "region_pseudostate_impl.hpp"


namespace sxy
{


class junction_impl SX_FINAL:
	public junction, public region_pseudostate_impl
{
public:
	explicit junction_impl( const std::string& _name );
	virtual ~junction_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(junction_impl)
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const SX_OVERRIDE;
};


}


#endif
