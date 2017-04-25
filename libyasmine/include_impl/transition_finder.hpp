//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_FINDER_FDB88C02_ECF9_4BB5_B99C_3F45813BF357
#define TRANSITION_FINDER_FDB88C02_ECF9_4BB5_B99C_3F45813BF357


#include "essentials/non_copyable.hpp"

#include "choice_fwd.hpp"
#include "compound_transition_fwd.hpp"


namespace sxy
{


class state;
class composite_state;
class transition;
class event_processing_callback;
class event;
class event_collector;


class transition_finder SX_FINAL
{
public:
	transition_finder();
	~transition_finder() SX_NOEXCEPT;
	SX_NO_COPY(transition_finder)
	void search_for_enabled_transitions_in_all_regions(	const state& _current_state, const event& _event,
		compound_transitions& _enabled_compound_transitions, bool& _event_is_deferred, 
		event_collector& _event_collector ) const;
	void search_for_enabled_completion_transitions_in_all_regions( const state& _current_state,
		compound_transitions& _enabled_compound_transitions, bool& _event_is_deferred, 
		event_collector& _event_collector ) const;
	static void search_initial_transitions(	const composite_state& _state,	
		compound_transitions& _compound_transitions, event_collector& _event_collector );
	static void search_choice_transitions( const raw_const_choices& _choices, 
		compound_transitions& _compound_transitions, const event& _event, event_collector& _event_collector );


private:
	static transition* search_completion_transition( const state& _state, event_collector& _event_collector );
	bool search_for_transition(	const state& _current_state, compound_transitions& _enabled_compound_transitions,
		const event& _event, bool& _event_is_deferred, event_collector& _event_collector ) const;
};


}


#endif
