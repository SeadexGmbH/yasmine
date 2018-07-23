//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_MACHINE_ELEMENT_122BB9E6_0CA4_4EEC_A341_EAD756AC89E9
#define STATE_MACHINE_ELEMENT_122BB9E6_0CA4_4EEC_A341_EAD756AC89E9


#include "essentials/non_copyable.hpp"
#include "essentials/uri.hpp"

#include "state_machine_defect_fwd.hpp"


namespace sxy
{


class state_machine_element
{
public:
	state_machine_element()
	{
		// Nothing to do...
	}


	virtual ~state_machine_element() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY(state_machine_element)
	virtual const std::string& get_name() const = 0;
	virtual sxe::uri get_uri() const = 0;
	virtual void add_ancestor_uri( sxe::uri& _uri ) const = 0;
	virtual bool check( state_machine_defects& _defects ) const = 0;
	virtual const state_machine_element * get_parent() const = 0;
};


}


#endif
