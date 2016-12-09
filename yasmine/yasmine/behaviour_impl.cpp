//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "behaviour_impl.hpp"
#include "event_impl.hpp"


namespace sxy
{


behaviour_impl::behaviour_impl( const behaviour_function& _function )
	: function_( _function )
{
	// Nothing to do.
}


behaviour_impl::~behaviour_impl() Y_NOEXCEPT
{
	// Nothing to do.
}


void behaviour_impl::operator()( const event& _event ) const
{
	if( function_ )
	{
		function_( _event );
	}
}


behaviour_uptr behaviour_impl::create_behaviour( const behaviour_function& _function )
{
	return( Y_MAKE_UNIQUE< sxy::behaviour_impl >( _function ) );
}


}
