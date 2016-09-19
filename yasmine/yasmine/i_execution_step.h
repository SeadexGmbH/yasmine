//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_EXECUTION_STEP_H_94397D2C_C792_4163_B87A_1CB896808779
#define I_EXECUTION_STEP_H_94397D2C_C792_4163_B87A_1CB896808779


#include "i_execution_step_fwd.h"


namespace sxy
{


class i_execution_step_visitor;
class i_event_processing_callback;
class i_event;


class i_execution_step
{
public:
	i_execution_step
	(
	) = default;


	virtual
	~i_execution_step
	(
	) = default;


	i_execution_step
	(
		const i_execution_step&
	) = delete;


	i_execution_step&
	operator=
	(
		const i_execution_step&
	) = delete;


	virtual bool
	execute_behavior
	(
		i_event_processing_callback* const p_event_processing_callback,
		const i_event& p_event
	) const = 0;


	virtual void
	accept
	(
		i_execution_step_visitor& p_visitor
	) const = 0;


};


}


#endif
