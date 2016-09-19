//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "event_impl.hpp"

#include <memory>


namespace sxy
{


event_impl::event_impl( const event_id _event_id, const event_priority _event_priority )
	: event(),
		event_id_( _event_id ),
		event_priority_( _event_priority)
{
	// Nothing to do...
}


event_id event_impl::get_id() const
{
	return( event_id_ );
}


std::string event_impl::get_name() const
{
	return ( std::to_string( event_id_ ) );
}


event_priority event_impl::get_priority() const
{
	return( event_priority_);
}


event_sptr event_impl::create( const event_id _event_id, const event_priority _event_priority )
{
	return( std::make_shared< sxy::event_impl >( _event_id, _event_priority ) );
}


}
