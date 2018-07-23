//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATES_NESTING_COMPARER_ASCENDING_D08136C5_FE07_48F1_8D77_5C460EC2EFF4
#define STATES_NESTING_COMPARER_ASCENDING_D08136C5_FE07_48F1_8D77_5C460EC2EFF4


#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class state;


struct states_nesting_comparer_ascending SX_FINAL
{
public:
	states_nesting_comparer_ascending();
	~states_nesting_comparer_ascending() SX_NOEXCEPT;
	bool operator()( const state& _lhs, const state& _rhs ) const;
	bool operator()( const state* const _lhs, const state* const _rhs ) const;
};

}


#endif
