//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "adapter_cpp03.hpp"

#ifndef SX_CPP03_BOOST
	// Nothing to do...
#else
#include "essentials/base.hpp"
#endif


namespace sxy
{

#ifndef SX_CPP03_BOOST


	// cppcheck-suppress unusedFunction
	void dummy_to_silence_linker_warning_in_adapter_cpp03()
	{
		// Nothing to do...
	}


#else


	sxe::function<void()> adapt_function( void( *_function )( ) )
	{
		return( sxe::bind( _function ) );
	}


	// cppcheck-suppress unusedFunction
	sxe::function<void( sxy::event_collector& )> adapt_function( void( *_function )( sxy::event_collector& ) )
	{
		return( sxe::bind( _function, sxe::_1 ) );
	}


	sxe::function<bool()> adapt_function( bool( *_function )( ) )
	{
		return( sxe::bind( _function ) );
	}


	sxe::function<bool( sxy::event_collector& )> adapt_function( bool( *_function )( sxy::event_collector& ) )
	{
		return( sxe::bind( _function, sxe::_1 ) );
	}


#endif


}
