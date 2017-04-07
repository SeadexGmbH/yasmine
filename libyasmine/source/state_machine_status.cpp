//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_machine_status.hpp"


namespace sxy
{


#ifdef SX_CPP03_BOOST


	// cppcheck-suppress unusedFunction
	bool operator==( const state_machine_status& _lhs, const state_machine_status::inner _rhs )
	{
		return( _lhs.value_ == _rhs );
	}


	bool operator==( const state_machine_status::inner _lhs, const state_machine_status& _rhs )
	{
		return( _lhs == _rhs.value_ );
	}


#endif


}
	