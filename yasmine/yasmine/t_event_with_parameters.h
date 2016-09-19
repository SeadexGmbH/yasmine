//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_EVENT_WITH_PARAMETERS_93594F58_8D69_4290_AC6E_4FFB49E9B87E
#define T_EVENT_WITH_PARAMETERS_93594F58_8D69_4290_AC6E_4FFB49E9B87E


#include <utility>

#include "t_event.h"


namespace sxy
{


template<typename ... tt_args>
class t_event_with_parameters : public t_event
{


public:
	using t_parameters = std::tuple< tt_args ... >;
		
	t_event_with_parameters
	(
		const t_event_id p_event_id,
		tt_args ... p_args
	):
		t_event(p_event_id),
		m_parameters(std::forward<tt_args>(p_args) ...)
	{

	}
	
	
	virtual
	~t_event_with_parameters
	(
	) override
	{
	};
	
	
	t_event_with_parameters
	(
		const t_event_with_parameters&
	) = delete;


	t_event_with_parameters&
	operator=
	(
		const t_event_with_parameters&
	) = delete;


	const t_parameters&
	get_parameters
	(
	) const
	{
		return ( m_parameters );
	}


	static t_event_sptr
	create_event
	(
		const t_event_id p_event_id,
		tt_args ... p_args
	)	
	{
		auto l_event = std::make_shared< sxy::t_event_with_parameters< tt_args ... > >( p_event_id, p_args ... );
		return( l_event );
	}

	
private:
	t_parameters m_parameters;

};


}


#endif
