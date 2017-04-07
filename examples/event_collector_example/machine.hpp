//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef MACHINE_B41DB262_B103_4A14_9F5E_C75B945CB276
#define MACHINE_B41DB262_B103_4A14_9F5E_C75B945CB276


#include "essentials/non_copyable.hpp"

#include "action.hpp"
		 		 

namespace sxy
{


class sync_state_machine;	


}


namespace examples
{	


typedef sxe::SX_UNIQUE_PTR< sxy::sync_state_machine > state_machine_uptr;


class machine SX_FINAL
{	
	
public:		
	machine();
	~machine() SX_NOEXCEPT;
	SX_NO_COPY( machine )
private:
	int run_machine();
	state_machine_uptr setup_state_machine( const std::string& _name );
	bool check_state_machine_for_defects( const sxy::sync_state_machine& _state_machine );

	state_machine_uptr state_machine_;
	action action_;
};


}


#endif
