//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex generator (http://generator.seadex.de).                          //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://generator.seadex.de/License.html.          //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "logic.hpp"

#include <iostream>


namespace examples
{

logic::logic()
{
	// Nothing to do...
}


logic::~logic()
{
	// Nothing to do...
}
		

void logic::behavior_enter_state_3()
{
	std::cout << "Enter State3. Static class method as behavior." << std::endl;
}


void logic::behavior_transition()
{
	std::cout << "Static class method as behavior for transition." << std::endl;
}


void logic::behavior_exit_state_3() const
{
	std::cout << "Exit State3. Class method as behavior." << std::endl;
}


void logic::behavior_enter_state_1() const
{
	std::cout << "Enter State1. Class method as behavior." << std::endl;
}


void logic::behavior_exit_state_1() const
{
	std::cout << "Exit State1. Class method as behavior." << std::endl;
}


void logic::behavior_do_state_4a() const
{
	std::cout << "Do behavior State4a. Class method as behavior." << std::endl;
}


void logic::behavior_enter_state_4a() const
{
	std::cout << "Enter behavior State4a. Class method as behavior." << std::endl;
}


void logic::behavior_do_state_4b() const
{
	std::cout << "Do behavior State4b. Class method as behavior." << std::endl;
}


void logic::behavior_enter_state_5() const
{
	std::cout << "Enter State5. Class method as behavior." << std::endl;
}


void logic::behavior_exit_state_5() const
{
	std::cout << "Exit State5. Class method as behavior." << std::endl;
}

void logic::behavior_enter_state_8() const
{
	std::cout << "Enter State8. Class method as behavior." << std::endl;
}


void logic::behavior_exit_state_8() const
{
	std::cout << "Exit State8. Class method as behavior." << std::endl;
}


void logic::behavior_do_state_11() const
{
	std::cout << "Do behavior State11. Class method as behavior." << std::endl;
}


void logic::behavior_do_state_12() const
{
	std::cout << "Do behavior State12. Class method as behavior." << std::endl;
}


void logic::behavior_do_state_13() const
{
	std::cout << "Do behavior State13. Class method as behavior." << std::endl;
}


void logic::behavior_enter_state_7()
{
	std::cout << "Enter behavior State7. Static class method as behavior." << std::endl;
}


void logic::behavior_exit_state_7()
{
	std::cout << "Exit behavior State7. Static class method as behavior." << std::endl;
}


void behavior_do_state_3()
{
	std::cout << "Behavior do State3: Free function as behavior." << std::endl;
}


void behavior_do_state_9()
{
	std::cout << "Behavior do State9: Free function as behavior." << std::endl;
}


void behavior_function_transition()
{
	std::cout << "Behavior of transition: Free function as behavior." << std::endl;
}

}

