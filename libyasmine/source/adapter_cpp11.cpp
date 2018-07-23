//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "adapter_cpp11.hpp"

#ifndef SX_CPP03_BOOST
#include "essentials/base.hpp"
#endif


namespace sxy
{

#ifndef SX_CPP03_BOOST

	sxe::function<void()> adapt_function( void( *_function )( ) )
	{
		return( [_function]()
		{
			( *_function )( );
		}
		);
	}


	sxe::function<void( sxy::event_collector& )> adapt_function( void( *_function )( sxy::event_collector& ) )
	{
		return( [_function]( sxy::event_collector& _event_collector )
		{
			( *_function )( _event_collector );
		}
		);
	}


	sxe::function<bool()> adapt_function( bool( *_function )( ) )
	{
		return( [_function]()
		{
			return( ( *_function )( ) );
		}
		);
	}


	sxe::function<bool( sxy::event_collector& )> adapt_function( bool( *_function )( sxy::event_collector& ) )
	{
		return( [_function]( sxy::event_collector& _event_collector )
		{
			return( ( *_function )( _event_collector ) );
		}
		);
	}


#else


	// cppcheck-suppress unusedFunction
	void dummy_to_silence_linker_warning_in_adapter_cpp11()
	{
		// Nothing to do...
	}


#endif


}
