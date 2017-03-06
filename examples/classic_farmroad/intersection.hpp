//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef INTERSECTION_AF842AAC_E608_4AE1_A245_2AC8A4602CDE
#define INTERSECTION_AF842AAC_E608_4AE1_A245_2AC8A4602CDE


#include "detector_callback.hpp"
#include "timed_event_creator.hpp"
#include "traffic_light.hpp"
#include "detector.hpp"
#include "async_state_machine.hpp"


namespace examples
{


class intersection Y_FINAL:	private detector_callback
{
public:
	intersection();
	~intersection() Y_NOEXCEPT;
	Y_NO_COPY( intersection )
	bool start();
	void stop();


private:
	virtual void detector_on() Y_OVERRIDE;
	virtual void detector_off() Y_OVERRIDE;
	int fire_timed_event(	const sxy::milliseconds _milliseconds, const sxy::event_sptr _event );
	void highway_open_entry();
	void highway_open_exit() const;
	void switching_to_farmroad_phase_1();
	void switching_to_farmroad_phase_2();
	void farmroad_open_entry();
	void farmroad_open_exit() const;
	void minimum_time_not_elapsed() const;
	void minimum_time_elapsed() const;
	void minimum_time_not_elapsed_farmroad_waiting() const;
	void switching_to_highway_phase_1();
	void switching_to_highway_phase_2();
	void build_intersection_state_machine();
	bool check_detector_is_on();
	bool check_detector_is_off();
	void cancel_timer_event_on_detector_off( const sxy::event& _event );


	sxy::async_state_machine intersection_state_machine_;
	traffic_light highway_traffic_light_;
	traffic_light farmroad_traffic_light_;
	sxy::timed_event_creator timed_event_creator_;
	detector detector_;
	unsigned int farmroad_maximum_time_event_handle_;
};


}


#endif
