//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_EXECUTION_TRANSITION_STEP_H_94397D2C_C792_4163_B87A_1CB4931208779
#define T_EXECUTION_TRANSITION_STEP_H_94397D2C_C792_4163_B87A_1CB4931208779


#include "i_execution_step.h"


namespace sxy
{


class i_transition_step;


class t_execution_transition_step final:
	public i_execution_step
{
public:
	explicit t_execution_transition_step( i_transition_step& p_transition_step );
	virtual ~t_execution_transition_step() override;
	t_execution_transition_step( const t_execution_transition_step& ) = delete;
	t_execution_transition_step& operator=( const t_execution_transition_step& ) = delete;
	virtual bool execute_behavior( i_event_processing_callback* const p_event_processing_callback, 
		const i_event& p_event ) const override;
	virtual void accept( i_execution_step_visitor& p_visitor ) const override;
	const i_transition_step& get_transition_step() const;


private:
	i_transition_step& m_transition_step;
};


}


#endif
