//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef JUNCTION_IMPL_9BB5CE53_8B97_444D_8548_FDF175AB929C
#define JUNCTION_IMPL_9BB5CE53_8B97_444D_8548_FDF175AB929C


#include "junction.hpp"
#include "region_pseudostate_impl.hpp"


namespace sxy
{


class junction_impl Y_FINAL:
	public virtual junction, public region_pseudostate_impl
{
public:
	explicit junction_impl( const std::string& _name );
	virtual ~junction_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(junction_impl)
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const Y_OVERRIDE;
};


}


#endif
