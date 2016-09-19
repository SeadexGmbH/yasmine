//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_MACHINE_ELEMENT_122BB9E6_0CA4_4EEC_A341_EAD756AC89E9
#define STATE_MACHINE_ELEMENT_122BB9E6_0CA4_4EEC_A341_EAD756AC89E9


#include "state_machine_defect_fwd.hpp"
#include "uri.hpp"


namespace sxy
{


class state_machine_element
{
public:
	state_machine_element() = default;
	virtual ~state_machine_element() noexcept = default;
	state_machine_element( const state_machine_element& ) = delete;
	state_machine_element& operator=( const state_machine_element& ) = delete;
	virtual const std::string& get_name() const = 0;
	virtual uri get_uri() const = 0;
	virtual void add_ancestor_uri( uri& _uri ) const = 0;
	virtual bool check( state_machine_defects& _defects ) const = 0;
	virtual const state_machine_element * get_parent() const = 0;
};


}


#endif
