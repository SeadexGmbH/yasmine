//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "constraint_impl.hpp"


namespace sxy
{


constraint_impl::constraint_impl( const constraint_function& _function )
	: constraint(),
		function_( _function )
{
	// Nothing to do.
}


constraint_impl::~constraint_impl() SX_NOEXCEPT
{
	// Nothing to do.
}


bool constraint_impl::operator()( const event& _event, event_collector& _event_collector ) const
{
	return( function_( _event, _event_collector ) );
}


constraint_uptr constraint_impl::create( const constraint_function& _function )
{		
	return( SX_MAKE_UNIQUE< sxy::constraint_impl >( _function ) );
}


}
