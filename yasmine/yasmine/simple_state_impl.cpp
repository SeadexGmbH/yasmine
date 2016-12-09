//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "simple_state_impl.hpp"

#include "log.hpp"
#include "behaviour.hpp"


namespace sxy
{		 


simple_state_impl::simple_state_impl( const std::string& _name, behaviour_uptr _do_action, behaviour_uptr _entry_action,
	behaviour_uptr _exit_action, const event_ids& _deferred_events, event_sptr _error_event )
	: simple_state_base( _name, sxy::move( _entry_action ), sxy::move( _exit_action ), _deferred_events, 
			_error_event ),
		do_( sxy::move( _do_action ) )		
{
	// Nothing to do...
}


simple_state_impl::~simple_state_impl() Y_NOEXCEPT
{
	// Nothing to do...
}


void simple_state_impl::execute_do_behaviour( const event& _event, async_event_handler* const _async_event_handler ) const
{
	Y_UNUSED_PARAMETER( _async_event_handler );
	const behaviour* const behaviour = get_do();
	if( behaviour )
	{
		Y_LOG( sxy::log_level::LL_TRACE, "Executing state's '%' do behaviour.", get_name() );
		( *behaviour )( _event );		
	}
}


const behaviour* simple_state_impl::get_do() const
{
	return( do_.get() );
}




}
