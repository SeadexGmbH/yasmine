//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
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
	virtual ~pseudostate_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(pseudostate_impl)
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
};


}


#endif
