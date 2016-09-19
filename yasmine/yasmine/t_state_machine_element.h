//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_STATE_MACHINE_ELEMENT
#define T_STATE_MACHINE_ELEMENT


#include <string>

#include "i_state_machine_element.h"


namespace sxy
{


class t_state_machine_element : public virtual i_state_machine_element
{
public:
	explicit t_state_machine_element
	(
		const std::string& p_name
	);


	virtual 
	~t_state_machine_element
	(
	) override;


	t_state_machine_element
	(
		const t_state_machine_element&
	) = delete;


	t_state_machine_element& operator=
	(
		const t_state_machine_element&
	) = delete;


	virtual const std::string&
	get_name
	(
	) const override;



	virtual const i_state_machine_element*
	get_parent
	(
	) const override;


private:
	const std::string m_name;	

};


}


#endif
