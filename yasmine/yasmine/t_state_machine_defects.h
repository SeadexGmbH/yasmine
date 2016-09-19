//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_STATE_MACHINE_DEFECTS_64AC315E_0899_49D8_B5B6_E5BEA8C47374
#define T_STATE_MACHINE_DEFECTS_64AC315E_0899_49D8_B5B6_E5BEA8C47374


#include <string>
#include <vector>

#include "yprintf.h"
#include "log.h"

#include "t_state_machine_defects_fwd.h"


namespace sxy
{


class i_state_machine_element;


class t_state_machine_defect
{


public:
	template<typename ... tt_args>
	t_state_machine_defect
	(
		const i_state_machine_element& p_element,
		const std::string& p_message,
		tt_args ... p_args
	):
		m_element( &p_element ),
		m_message( yprintf( p_message.c_str(), p_args... ) )
	{
		// Nothing to do.
	}

	
	virtual ~t_state_machine_defect
	(
	);


	t_state_machine_defect
	( 
		const t_state_machine_defect&
	) = delete;


	t_state_machine_defect&
	operator=
	(
		const t_state_machine_defect&
	) = delete;
	

	const i_state_machine_element& 
	get_element
	(
	) const;


	const	std::string& 
	get_message
	(
	) const;


private:
	const i_state_machine_element* m_element;
	const std::string m_message;	


};


void
write_defects_to_log
(		
	const t_state_machine_defects& p_defects
);


}


#endif
