//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_INTERSECTION_AF842AAC_E608_4AE1_A245_2AC8A4602CDE
#define T_INTERSECTION_AF842AAC_E608_4AE1_A245_2AC8A4602CDE


#include "i_detector_callback.h"
#include "t_timed_event_creator.h"
#include "t_traffic_light.h"
#include "t_detector.h"
#include "t_async_state_machine.h"


namespace sxy
{


class t_intersection final : private i_detector_callback
{
	

public:
	t_intersection
	(
	);
	
	
	~t_intersection
	(
	);
	
	
	t_intersection
	(
		const t_intersection&
	) = delete;


	t_intersection&
	operator=
	(
		const t_intersection&
	) = delete;

	
	bool
	start
	(
	);


	void
	stop
	(
	);

	
private:
	virtual void
	detector_on
	(
	) override;


	virtual void
	detector_off
	(
	) override;


	int
	fire_timed_event
	(
		const std::chrono::milliseconds p_milliseconds,
		const t_event_id p_event_id
	);


	void
	highway_open_entry
	(
	);


	static void
	highway_open_exit
	(
	);


	void
	switching_to_farmroad_phase_1
	(
	);


	void
	switching_to_farmroad_phase_2
	(
	);


	void
	farmroad_open_entry
	(
	);


	static void
	farmroad_open_exit
	(
	);


	static void
	minimum_time_not_elapsed
	(
	);


	static void
	minimum_time_elapsed
	(
	);


	static void
	minimum_time_not_elapsed_farmroad_waiting
	(
	);


	void
	switching_to_highway_phase_1
	(
	);


	void
	switching_to_highway_phase_2
	(
	);


	void
	build_intersection_state_machine
	(
	);


	bool
	check_detector_is_on
	(
	);


	bool
	check_detector_is_off
	(
	);


	void
	cancel_timer_event_on_detector_off
	(
		const sxy::i_event& p_event
	);


	t_async_state_machine m_intersection_state_machine;
	t_traffic_light m_highway_traffic_light;
	t_traffic_light m_farmroad_traffic_light;	
	
	t_timed_event_creator m_timed_event_creator;
	t_detector m_detector;

	unsigned int m_farmroad_maximum_time_event_handle;


};


}


#endif
