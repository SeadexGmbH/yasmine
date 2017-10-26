//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATES_NESTING_COMPARER_B8C0C256_3761_47DC_A60A_DB2BF706EEB0
#define STATES_NESTING_COMPARER_B8C0C256_3761_47DC_A60A_DB2BF706EEB0


#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class state;


struct states_nesting_comparer SX_FINAL
{
public:
	states_nesting_comparer();
	~states_nesting_comparer() SX_NOEXCEPT;
	bool operator()( const state& _lhs, const state& _rhs ) const;
	bool operator()( const state* const _lhs, const state* const _rhs ) const;
};

}


#endif
