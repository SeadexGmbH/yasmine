//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXIT_POINT_IMPL_3F9A1319_C306_4E7D_A153_D725292B4763
#define EXIT_POINT_IMPL_3F9A1319_C306_4E7D_A153_D725292B4763


#include "exit_point.hpp"
#include "state_pseudostate_impl.hpp"


namespace sxy
{


class exit_point_impl SX_FINAL:
	public exit_point, public state_pseudostate_impl
{
public:
	explicit exit_point_impl( const std::string& _name );
	virtual ~exit_point_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(exit_point_impl)
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const SX_OVERRIDE;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) SX_OVERRIDE;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const SX_OVERRIDE;
};


}


#endif
