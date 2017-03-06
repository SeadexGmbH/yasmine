//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "action.hpp"

#include <iostream>

#include "events.hpp"


namespace examples
{


	action::action()
	{
		// Nothing to do...
	}


	action::~action() Y_NOEXCEPT
	{
		// Nothing to do...
	}


#ifndef Y_CPP03_BOOST

	void action::fire_event_E3( sxy::event_collector& _event_collector )
	{			
		_event_collector.push( examples::E3::create() );
	}


	void action::fire_event_E4( sxy::event_collector& _event_collector )
	{			
		_event_collector.push( examples::E4::create( "The transition from simple state 'S3' to the final state has been executed!" ) );																									    
	}

	void action::print_message_from_event( const E4& _event )
	{
		std::cout << _event.get_message() << std::endl;
	}

#else

	void action::fire_event_E3( const sxy::event& _event, sxy::event_collector& _event_collector )
	{
		Y_UNUSED_PARAMETER( _event );
		_event_collector.push( examples::E3::create() );
	}


	void action::fire_event_E4( const sxy::event& _event, sxy::event_collector& _event_collector )
	{
		Y_UNUSED_PARAMETER( _event );
		_event_collector.push( examples::E4::create( "The transition from simple state 'S3' to the final state has been executed!" ) );
	}


	void action::print_message_from_event( const sxy::event& _event )
	{
		const E4* specialized_event = dynamic_cast< const E4* >( &_event );
		if( specialized_event )
		{
			std::cout << specialized_event->get_message() << std::endl;			
		}
		else
		{
			throw sxy::exception( "Invalid event type!" );
		}
	}

#endif




}
