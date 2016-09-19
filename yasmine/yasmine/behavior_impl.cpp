//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "make_unique.hpp"
#include "behavior_impl.hpp"
#include "event_impl.hpp"


namespace sxy
{


behavior_impl::behavior_impl( const behavior_function& _function )
	: function_( _function )
{
	// Nothing to do
}
																				 

void behavior_impl::operator()( const event& _event ) const
{
	if( function_ )
	{
		function_( _event );
	}
}


behavior_uptr behavior_impl::create_behavior( const behavior_function& _function )
{
	return( sxy::make_unique< sxy::behavior_impl >( _function ) );
}


}
