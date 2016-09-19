//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_HISTORY_8019EFCB_44B8_4B81_A578_46C97A9B4E81
#define T_HISTORY_8019EFCB_44B8_4B81_A578_46C97A9B4E81


#include "i_history.h"
#include "t_state_pseudostate.h"


namespace sxy
{


class t_history: public virtual i_history, public t_state_pseudostate
{
public:
	explicit t_history
	(
		const std::string& p_name
	);


	virtual
	~t_history
	(
	) override;


	t_history
	(
		const t_history&
	) = delete;


	t_history&
	operator=
	(
		const t_history&
	) = delete;


	virtual t_raw_transitions
	get_default_transitions
	(
	) const override;


	virtual void
	add_default_transition
	(			
		i_transition& p_default_transition
	) override;


	virtual bool
	check_if_state_was_active_before
	(
	) const override;


private:	

};


}


#endif
