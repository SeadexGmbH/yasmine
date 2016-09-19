//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXECUTION_STEP_VISITOR_7AEFC8D8_8C36_4529_AC9E_F3A2B20622B4
#define EXECUTION_STEP_VISITOR_7AEFC8D8_8C36_4529_AC9E_F3A2B20622B4


namespace sxy
{


class execution_state_enter_step;
class execution_state_do_step;
class execution_state_exit_step;
class execution_transition_step;


class execution_step_visitor
{
public:
	execution_step_visitor() = default;
	virtual ~execution_step_visitor() = default;
	execution_step_visitor( const execution_step_visitor& ) = delete;
	execution_step_visitor& operator=( const execution_step_visitor& ) = delete;
	virtual void visit( const execution_state_enter_step& _execution_state_enter_step ) = 0;
	virtual void visit( const execution_state_do_step& _execution_state_do_step ) = 0;
	virtual void visit( const execution_state_exit_step& _execution_state_exit_step ) = 0;
	virtual void visit( const execution_transition_step& _execution_transition_step ) = 0;
};


}


#endif
