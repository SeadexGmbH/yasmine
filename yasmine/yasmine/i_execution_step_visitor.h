//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_EXECUTION_STEP_VISITOR_7AEFC8D8_8C36_4529_AC9E_F3A2B20622B4
#define I_EXECUTION_STEP_VISITOR_7AEFC8D8_8C36_4529_AC9E_F3A2B20622B4


namespace sxy
{


class t_execution_state_enter_step;
class t_execution_state_do_step;
class t_execution_state_exit_step;
class t_execution_transition_step;


class i_execution_step_visitor
{
public:
	i_execution_step_visitor
	(
	) = default;


	virtual
	~i_execution_step_visitor
	(
	) = default;


	i_execution_step_visitor
	(
		const i_execution_step_visitor&
	) = delete;


	i_execution_step_visitor&
	operator=
	(
		const i_execution_step_visitor&
	) = delete;


	virtual void
	visit
	(
		const t_execution_state_enter_step& p_execution_state_enter_step
	) = 0;


	virtual void
	visit
	(
		const t_execution_state_do_step& p_execution_state_do_step
	) = 0;


	virtual void
	visit
	(
		const t_execution_state_exit_step& p_execution_state_exit_step
	) = 0;


	virtual void
	visit
	(
		const t_execution_transition_step& p_execution_transition_step
	) = 0;


};


}


#endif
