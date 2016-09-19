//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "simple_state_impl.h"

#include "log.h"
#include "behavior.h"


namespace sxy
{		 


simple_state_impl::simple_state_impl( const std::string& _name, behavior_uptr _do_action, behavior_uptr _entry_action,
	behavior_uptr _exit_action, const event_ids& _deferred_events, behavior_exception_uptr _error_event  )
	: simple_state_base( _name, std::move( _entry_action ), std::move( _exit_action ), _deferred_events, 
			std::move( _error_event ) ),
		do_( std::move( _do_action ) )		
{
	// Nothing to do...
}


simple_state_impl::~simple_state_impl() = default;


void simple_state_impl::execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler ) const
{
	Y_UNUSED_PARAMETER( _async_event_handler );
	const auto behavior = get_do();
	if( behavior )
	{
		Y_LOG( sxy::log_level::LL_DEBUG, "Executing state '%' behavior.", get_name() );
		( *behavior )( _event );		
	}
}


const behavior* simple_state_impl::get_do() const
{
	return( do_.get() );
}




}
