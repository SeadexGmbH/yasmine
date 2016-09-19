//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TRANSITION_EXECUTOR_H_2521E4B8_B89E_4CCE_9751_F5B6BD515AD5
#define T_TRANSITION_EXECUTOR_H_2521E4B8_B89E_4CCE_9751_F5B6BD515AD5


#include "i_choice_fwd.h"
#include "t_compound_transition_fwd.h"


namespace sxy
{


namespace impl
{
																 
class t_transition_executor_impl;

}


class i_composite_state;
class i_event_processing_callback;
class i_event;


class t_transition_executor final
{
public:
	t_transition_executor();
	~t_transition_executor();
	t_transition_executor( const t_transition_executor& ) = delete;
	t_transition_executor& operator=( const t_transition_executor& ) = delete;
	bool check_sort_and_execute_transitions( const t_compound_transitions& p_compound_transitions, 
		t_raw_const_choices& p_verices,	i_event_processing_callback* const p_event_processing_callback,	
		const i_event& p_event );


private:
	impl::t_transition_executor_impl* m_transition_executor_impl;
};


}


#endif
