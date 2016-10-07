//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_FINDER_FDB88C02_ECF9_4BB5_B99C_3F45813BF357
#define TRANSITION_FINDER_FDB88C02_ECF9_4BB5_B99C_3F45813BF357


#include "compatibility.hpp"
#include "choice_fwd.hpp"
#include "compound_transition_fwd.hpp"


namespace sxy
{


class state;
class composite_state;
class transition;
class event_processing_callback;
class event;


class transition_finder final
{
public:
	transition_finder();
	~transition_finder() noexcept = default;
	transition_finder( const transition_finder& ) = delete;
	transition_finder& operator=( const transition_finder& ) = delete;
	void search_for_enabled_transitions_in_all_regions(	const state& _current_state,	const event& _event,
		compound_transitions& _enabled_compound_transitions,	bool& _event_is_deferred ) const;
	void search_for_enabled_completion_transitions_in_all_regions( const state& _current_state,
		compound_transitions& _enabled_compound_transitions,	bool& _event_is_deferred ) const;
	static void search_initial_transitions(	const composite_state& _state,	
		compound_transitions& _compound_transitions );
	static void search_choice_transitions( const raw_const_choices& _choices, 
		compound_transitions& _compound_transitions, const event& _event );


private:
	static transition * search_completion_transition( const state& _state );
	bool search_for_transition(	const state& _current_state,	compound_transitions& _enabled_compound_transitions,
		const event& _event,	bool& _event_is_deferred ) const;
};


}


#endif
