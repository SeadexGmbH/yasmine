//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXECUTION_STATE_ENTER_STEP_455BAA75_9584_4CCF_87C2_AFA0FB76F9AB
#define EXECUTION_STATE_ENTER_STEP_455BAA75_9584_4CCF_87C2_AFA0FB76F9AB


#include "execution_step.hpp"


namespace sxy
{


class state;


class execution_state_enter_step final:
	public execution_step
{
public:
	explicit execution_state_enter_step( state& _state );
	virtual ~execution_state_enter_step() noexcept override = default;
	execution_state_enter_step( const execution_state_enter_step& ) = delete;
	execution_state_enter_step& operator=( const execution_state_enter_step& ) = delete;
	virtual bool execute_behavior( event_processing_callback* const _event_processing_callback,
		const event& _event, events& _exception_events,	async_event_handler* const _async_event_handler ) const override;
	virtual void accept( execution_step_visitor& _visitor ) const override;
	const state& get_state() const;


private:
	state& state_;
};


}


#endif
