//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_SIMPLE_TRANSITION_STEP_12297D2C_C792_4163_B87A_1CB896808779
#define T_SIMPLE_TRANSITION_STEP_12297D2C_C792_4163_B87A_1CB896808779


#include "i_transition_step.h"


namespace sxy
{


class i_transition;
class i_state;


class t_simple_transition_step final:
	public i_transition_step
{
public:
	explicit t_simple_transition_step( i_transition& p_transition );
	virtual ~t_simple_transition_step() override;
	t_simple_transition_step( const t_simple_transition_step& ) = delete;
	t_simple_transition_step& operator=( const t_simple_transition_step& ) = delete;
	virtual const t_raw_transitions& get_transitions() const override;
	virtual const i_vertex& get_unique_source() const override;
	virtual const i_vertex& get_unique_target() const override;
	virtual const i_exit_point * get_exit_point() const override;
	virtual const i_entry_point * get_entry_point() const override;
	virtual const t_raw_const_vertices get_target_vertices() override;
	void execute_transition_behaviors( const i_event& p_event ) const override;


private:
	i_transition& m_transition;
	t_raw_transitions m_transition_step;
};


}


#endif
