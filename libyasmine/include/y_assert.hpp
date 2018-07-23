//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef Y_ASSERT_99E5ACCD_95C4_419D_A257_7294D6692569
#define Y_ASSERT_99E5ACCD_95C4_419D_A257_7294D6692569


#define Y_ASSERT( _condition, _message ) \
	do \
	{ \
		if( !( _condition ) ) \
		{ \
			SX_LOG_AND_WAIT( hermes::log_level::LL_ASSERT, "Assert failed! Message: '%', Condition '%'", _message, #_condition ); \
			assert( ( _condition ) && _message ); \
		} \
	} \
	while( 0 )

#include "hermes/log.hpp"


#endif
