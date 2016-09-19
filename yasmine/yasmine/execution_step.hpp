//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXECUTION_STEP_H_94397D2C_C792_4163_B87A_1CB896808779
#define EXECUTION_STEP_H_94397D2C_C792_4163_B87A_1CB896808779


#include "execution_step_fwd.hpp"
#include "behavior_exception_fwd.hpp"
#include "event_fwd.hpp"


namespace sxy
{


class execution_step_visitor;
class event_processing_callback;
class async_event_handler;


class execution_step
{
public:
	execution_step() = default;
	virtual ~execution_step() noexcept = default;
	execution_step( const execution_step& ) = delete;
	execution_step& operator=( const execution_step& ) = delete;
	virtual bool execute_behavior( event_processing_callback* const _event_processing_callback, 
		const event& _event, events& _exception_events,
		async_event_handler* const _async_event_handler ) const = 0;
	virtual void accept( execution_step_visitor& _visitor ) const = 0;
};


}


#endif
