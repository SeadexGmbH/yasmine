//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_STATE_MACHINE_ELEMENT_122BB9E6_0CA4_4EEC_A341_EAD756AC89E9
#define I_STATE_MACHINE_ELEMENT_122BB9E6_0CA4_4EEC_A341_EAD756AC89E9


#include "t_state_machine_defects_fwd.h"
#include "t_uri.h"


namespace sxy
{


class i_state_machine_element
{
public:
	i_state_machine_element() = default;
	virtual ~i_state_machine_element() = default;
	i_state_machine_element( const i_state_machine_element& ) = delete;
	i_state_machine_element& operator=( const i_state_machine_element& ) = delete;
	virtual const std::string& get_name() const = 0;
	virtual t_uri get_uri() const = 0;
	virtual void add_ancestor_uri( t_uri& p_uri ) const = 0;
	virtual bool check( t_state_machine_defects& p_defects ) const = 0;
	virtual const i_state_machine_element * get_parent() const = 0;
};


}


#endif
