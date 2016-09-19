//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
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


class junction_impl final:
	public virtual junction, public region_pseudostate_impl
{
public:
	explicit junction_impl( const std::string& _name );
	virtual ~junction_impl() noexcept override = default;
	junction_impl( const junction_impl& ) = delete;
	junction_impl& operator=( const junction_impl& ) = delete;
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const override;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) override;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const override;
};


}


#endif
