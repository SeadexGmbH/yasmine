//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_EXECUTION_STATE_ENTER_STEP_455BAA75_9584_4CCF_87C2_AFA0FB76F9AB
#define T_EXECUTION_STATE_ENTER_STEP_455BAA75_9584_4CCF_87C2_AFA0FB76F9AB


#include "i_execution_step.h"


namespace sxy
{


class i_state;


class t_execution_state_enter_step final:
	public i_execution_step
{
public:
	explicit t_execution_state_enter_step( i_state& p_state );
	virtual ~t_execution_state_enter_step() override;
	t_execution_state_enter_step( const t_execution_state_enter_step& ) = delete;
	t_execution_state_enter_step& operator=( const t_execution_state_enter_step& ) = delete;
	virtual bool execute_behavior( i_event_processing_callback* const p_event_processing_callback,
		const i_event& p_event ) const override;
	virtual void accept( i_execution_step_visitor& p_visitor ) const override;
	const i_state& get_state() const;


private:
	i_state& m_state;
};


}


#endif
