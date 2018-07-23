//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXECUTION_STEP_VISITOR_7AEFC8D8_8C36_4529_AC9E_F3A2B20622B4
#define EXECUTION_STEP_VISITOR_7AEFC8D8_8C36_4529_AC9E_F3A2B20622B4


#include "essentials/non_copyable.hpp"


namespace sxy
{


class execution_state_enter_step;
class execution_state_do_step;
class execution_state_exit_step;
class execution_transition_step;


class execution_step_visitor
{
public:
	execution_step_visitor() 
	{
		// Nothing to do...
	}


	virtual ~execution_step_visitor() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY(execution_step_visitor)	
	virtual void visit( const execution_state_enter_step& _execution_state_enter_step ) = 0;
	virtual void visit( const execution_state_do_step& _execution_state_do_step ) = 0;
	virtual void visit( const execution_state_exit_step& _execution_state_exit_step ) = 0;
	virtual void visit( const execution_transition_step& _execution_transition_step ) = 0;
};


}


#endif
