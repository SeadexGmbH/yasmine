//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex generator(http://generator.seadex.de).                           //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://generator.seadex.de/License.html.          //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GENESIS_IMPL_D878BF81_EC04_4B08_B920_240704E648CC
#define GENESIS_IMPL_D878BF81_EC04_4B08_B920_240704E648CC


#include "essentials/non_copyable.hpp"


namespace examples
{


class logic
{
public:
	logic();
	~logic();
	SX_NO_COPY( logic )
	static void behavior_enter_state_3();
	static void behavior_transition();
	void behavior_exit_state_3() const;
	void behavior_enter_state_1() const;
	void behavior_exit_state_1() const;
	void behavior_do_state_4a() const;
	void behavior_enter_state_4a() const;
	void behavior_do_state_4b() const;
	void behavior_enter_state_5() const;
	void behavior_exit_state_5() const;
	void behavior_enter_state_8() const;
	void behavior_exit_state_8() const;
	void behavior_do_state_11() const;
	void behavior_do_state_12() const;
	void behavior_do_state_13() const;
	static void behavior_enter_state_7();
	static void behavior_exit_state_7();
};


void behavior_do_state_3();
void behavior_do_state_9();
void behavior_function_transition();


}


#endif
