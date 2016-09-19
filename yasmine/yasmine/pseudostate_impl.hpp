//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef PSEUDOSTATE_IMPL_5DF69044_2EB3_4226_92B4_A04674AB02CF
#define PSEUDOSTATE_IMPL_5DF69044_2EB3_4226_92B4_A04674AB02CF


#include "pseudostate.hpp"
#include "vertex_impl.hpp"


namespace sxy
{


class pseudostate_impl:
	public virtual pseudostate, public vertex_impl
{
public:
	explicit pseudostate_impl( const std::string& _name );
	virtual ~pseudostate_impl() noexcept override = default;
	pseudostate_impl( const pseudostate_impl& ) = delete;
	pseudostate_impl& operator=( const pseudostate_impl& ) = delete;
	virtual bool check( state_machine_defects& _defects ) const override;
};


}


#endif
