//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_MACHINE_DEFECT_B3B7FA9A_C6E8_496E_8A31_E00451C9B7AC
#define STATE_MACHINE_DEFECT_B3B7FA9A_C6E8_496E_8A31_E00451C9B7AC


#include <string>
#include <vector>

#include "yprintf.h"
#include "log.h"

#include "state_machine_defect_fwd.h"


namespace sxy
{


class state_machine_element;


class state_machine_defect final
{
public:
	template< typename ... args > 
	state_machine_defect( const state_machine_element& _element, const std::string& _message,	args ... _args )
		: element_( &_element ),
			message_( yprintf( _message.c_str(), _args ... ) )
	{
		// Nothing to do.
	}


	virtual ~state_machine_defect();
	state_machine_defect( const state_machine_defect& ) = delete;
	state_machine_defect& operator=( const state_machine_defect& ) = delete;
	const state_machine_element& get_element() const;
	const std::string& get_message() const;


private:
	const state_machine_element* element_;
	const std::string message_;
};


void write_defects_to_log( const state_machine_defects& _defects );


}


#endif
