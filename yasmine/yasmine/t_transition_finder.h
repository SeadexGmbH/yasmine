//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TRANSITION_FINDER_FDB88C02_ECF9_4BB5_B99C_3F45813BF357
#define T_TRANSITION_FINDER_FDB88C02_ECF9_4BB5_B99C_3F45813BF357


#include "i_choice_fwd.h"
#include "t_compound_transition_fwd.h"


namespace sxy
{


class i_state;
class i_composite_state;
class i_transition;
class i_event_processing_callback;
class i_event;


class t_transition_finder final
{
public:
	t_transition_finder
	(
	);


	~t_transition_finder
	(
	);


	t_transition_finder
	(
		const t_transition_finder&
	) = delete;


	t_transition_finder& operator=
	(
		const t_transition_finder&
	) = delete;


	void 
	search_for_enabled_transitions_in_all_regions
	(
		const i_state& p_current_state,
		const i_event& p_event,
		t_compound_transitions& p_enabled_compound_transitions,
		bool& p_event_is_deferred
	) const;


	void 
	search_for_enabled_completion_transitions_in_all_regions
	(
		const i_state& p_current_state,
		t_compound_transitions& p_enabled_compound_transitions,
		bool& p_event_is_deferred
	) const;


	static
	void
	search_initial_transitions
	(
		const i_composite_state& p_state,
		t_compound_transitions& p_compound_transitions
	);


	static
	void
	search_choice_transitions
	(
		const t_raw_const_choices& p_choices,
		t_compound_transitions& p_compound_transitions,
		const i_event& p_event
	);


private:
	static
	i_transition*
	search_completion_transition
	(
		const i_state& p_state
	);


	bool
	search_for_transition
	(
		const i_state& p_current_state,
		t_compound_transitions& p_enabled_compound_transitions,
		const i_event& p_event,
		bool& p_event_is_deferred
	) const;


};


}


#endif
