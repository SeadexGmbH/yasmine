//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXECUTION_STATE_DO_STEP_E8739F61_00B1_43BD_9E32_2DCD7B890E2C
#define EXECUTION_STATE_DO_STEP_E8739F61_00B1_43BD_9E32_2DCD7B890E2C


#include "essentials/non_copyable.hpp"

#include "execution_step.hpp"
#include "event_fwd.hpp"


namespace sxy
{


class state;


class execution_state_do_step SX_FINAL :
	public execution_step
{
public:
	explicit execution_state_do_step(const state& _state);
	virtual ~execution_state_do_step() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(execution_state_do_step)	
	virtual bool execute_behavior( event_processing_callback* const _event_processing_callback, 
		const event& _event, events& _exception_events,	async_event_handler* const _async_event_handler,
		event_collector& _event_collector ) const SX_OVERRIDE;
	virtual void accept( execution_step_visitor& _visitor ) const SX_OVERRIDE;
	const state& get_state() const;


private:
	const state& state_;
};


}


#endif
