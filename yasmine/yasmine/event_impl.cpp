//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "event_impl.h"

#include <memory>


namespace sxy
{


event_impl::event_impl( const event_id _event_id )
	: event(),
		event_id_( _event_id )
{
	// Nothing to do...
}


event_impl::~event_impl() = default;


event_id event_impl::get_id() const
{
	return( event_id_ );
}


// cppcheck-suppress unusedFunction
event_sptr event_impl::create_event( const event_id _event_id )
{
	return( std::make_shared< sxy::event_impl >( _event_id ) );
}


}
