#include "state_machine_creator.hpp"
#include "logic.hpp"

int main()
{
	examples::logic behaviors;
	examples::state_machine_uptr sm = create_state_machine( "Generated state machine", behaviors );
	sm->run();
	sm->fire_event( examples::E1::create() );
	sm->fire_event( examples::E2::create() );
	sm->fire_event( examples::E4::create() );
	sm->fire_event( examples::E6::create() );
	sm->fire_event( examples::E7::create() );
	sm->halt();
	return ( 0 );
}