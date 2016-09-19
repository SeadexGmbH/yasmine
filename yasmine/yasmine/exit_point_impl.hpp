//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXIT_POINT_IMPL_3F9A1319_C306_4E7D_A153_D725292B4763
#define EXIT_POINT_IMPL_3F9A1319_C306_4E7D_A153_D725292B4763


#include "exit_point.hpp"
#include "state_pseudostate_impl.hpp"


namespace sxy
{


class exit_point_impl final:
	public virtual exit_point, public state_pseudostate_impl
{
public:
	explicit exit_point_impl( const std::string& _name );
	virtual ~exit_point_impl() noexcept override = default;
	exit_point_impl( const exit_point_impl& ) = delete;
	exit_point_impl& operator=( const exit_point_impl& ) = delete;
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual void accept_vertex_visitor( const_vertex_visitor& _visitor ) const override;
	virtual void accept_vertex_visitor( vertex_visitor& _visitor ) override;
	virtual void accept_pseudostate_visitor( pseudostate_visitor& _visitor ) const override;
};


}


#endif
