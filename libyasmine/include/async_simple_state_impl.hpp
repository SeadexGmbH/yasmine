//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_SIMPLE_STATE_905AB129_358B_4868_8215_40BD3D95F9FD
#define ASYNC_SIMPLE_STATE_905AB129_358B_4868_8215_40BD3D95F9FD


#include "simple_state_base.hpp"
#include "async_behavior_fwd.hpp"


namespace sxy
{


class async_simple_state_impl SX_FINAL:
	public simple_state_base
{
public:
	explicit async_simple_state_impl( const std::string& _name, async_behavior_uptr _do_action,
		behavior_uptr _entry_action = behavior_uptr(), behavior_uptr _exit_action = behavior_uptr(),
		const event_ids& _deferred_events = event_ids(), event_sptr _error_event = event_sptr());
	virtual ~async_simple_state_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(async_simple_state_impl)
	void execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler,
		event_collector& _event_collector ) const SX_OVERRIDE;
	void execute_exit_behavior( const event& _event, event_collector& _event_collector ) const SX_OVERRIDE;
	void stop_do_behavior() const;


private:
	async_behavior_uptr do_;
};


}


#endif
