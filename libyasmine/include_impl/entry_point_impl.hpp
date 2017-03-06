//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ENTRY_POINT_IMPL_78A17172_D649_4870_988D_50A995692441
#define ENTRY_POINT_IMPL_78A17172_D649_4870_988D_50A995692441


#include "entry_point.hpp"
#include "state_pseudostate_impl.hpp"


namespace sxy
{


class entry_point_impl Y_FINAL:
	public virtual entry_point, public state_pseudostate_impl
{
public:
	explicit entry_point_impl( const std::string& _name );
	virtual ~entry_point_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(entry_point_impl)
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const Y_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) Y_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const Y_OVERRIDE;
};


}


#endif
