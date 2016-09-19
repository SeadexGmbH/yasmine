//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_SIMPLE_STATE_905AB129_358B_4868_8215_40BD3D95F9FD
#define ASYNC_SIMPLE_STATE_905AB129_358B_4868_8215_40BD3D95F9FD


#include "simple_state_base.hpp"
#include "async_behavior.hpp"


namespace sxy
{


class async_simple_state_impl final:
	public simple_state_base
{
public:
	explicit async_simple_state_impl( const std::string& _name, async_behavior_uptr _do_action,
		behavior_uptr _entry_action = nullptr, behavior_uptr _exit_action = nullptr,
		const event_ids& _deferred_events = {}, event_sptr _error_event = nullptr );
	virtual ~async_simple_state_impl() noexcept override = default;
	async_simple_state_impl( const async_simple_state_impl& ) = delete;
	async_simple_state_impl& operator=( const async_simple_state_impl& ) = delete;	
	void execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler ) const override;
	void execute_exit_behavior( const event& _event ) const override;
	void stop_do_behavior() const;


private:
	async_behavior_uptr do_;
};


}


#endif
