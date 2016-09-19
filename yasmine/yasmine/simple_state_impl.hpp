//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SIMPLE_STATE_IMPL_F53AD7D0_4393_4F4A_9FB4_4D865E93C724
#define SIMPLE_STATE_IMPL_F53AD7D0_4393_4F4A_9FB4_4D865E93C724


#include "simple_state_base.hpp"


namespace sxy
{


class simple_state_impl final:
	public simple_state_base
{
public:
	explicit simple_state_impl( const std::string& _name,	behavior_uptr do_action = nullptr, 
		behavior_uptr _entry_action = nullptr,	behavior_uptr _exit_action = nullptr,
		const event_ids& _deferred_events = {}, event_sptr _error_event = nullptr );
	virtual ~simple_state_impl() noexcept override = default;
	simple_state_impl( const simple_state_impl& ) = delete;
	simple_state_impl& operator=( const simple_state_impl& ) = delete;	
	void execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler ) const override;

private:
	const behavior * get_do() const;

	behavior_uptr do_;	
};


}


#endif
