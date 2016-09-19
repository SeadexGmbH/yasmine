//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_COMPLEX_STATE_7A94F6AB_7A00_438C_9841_1C0F5981E82F
#define T_COMPLEX_STATE_7A94F6AB_7A00_438C_9841_1C0F5981E82F


#include "i_complex_state.h"
#include "t_state.h"

#include "i_behavior_fwd.h"


namespace sxy
{


class t_complex_state: public virtual i_complex_state, public t_state
{
public:
	explicit t_complex_state
	(			
		const std::string& p_name,
		i_behavior_uptr	p_entry_behavior,
		i_behavior_uptr p_exit_behavior,
		const t_event_ids& p_deferred_events = {}
	);


	virtual 
	~t_complex_state
	(
	) override;


	t_complex_state
	(
		const t_complex_state&
	) = delete;


	t_complex_state&
	operator=
	(
		const t_complex_state&
	) = delete;


	virtual i_behavior*
	get_entry_behavior
	(
	) const override;


	virtual i_behavior*
	get_exit_behavior
	(
	) const override;


	virtual bool
	is_event_deferred
	(
		const t_event_id& p_event_id
	) const override;


protected:
	bool
	check_if_one_of_the_deferred_events_triggers_a_transition
	(
	) const;


private:
	i_behavior_uptr m_entry;
	i_behavior_uptr m_exit;
	t_event_ids m_deferred_events;
};


}


#endif
