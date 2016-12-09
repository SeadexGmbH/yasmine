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

#include "yprintf.hpp"
#include "log.hpp"
#include "compatibility.hpp"

#include "state_machine_defect_fwd.hpp"


namespace sxy
{


class state_machine_element;


class state_machine_defect Y_FINAL
{	

public:


#ifndef Y_CPP03_BOOST


	template< typename ... args >
	state_machine_defect( const state_machine_element &_element, const std::string & _message, args ... _args ):
		element_( &_element ), message_( yprintf( _message.c_str(), _args ... ) )
	{
		// Nothing to do.
	}


#else

	state_machine_defect( const state_machine_element&_element, const std::string & _message );
	state_machine_defect( const state_machine_element&_element, const std::string & _message, const log_value &_value );
	state_machine_defect( const state_machine_element&_element, const std::string & _message, const log_value &_value1,
		const log_value &_value2 );
	state_machine_defect( const state_machine_element&_element, const std::string & _message, const log_value &_value1,
		const log_value &_value2, const log_value&_value3 );
	state_machine_defect( const state_machine_element&_element, const std::string & _message, const log_value &_value1,
		const log_value &_value2, const log_value &_value3, const log_value &_value4 );
	state_machine_defect( const state_machine_element&_element, const std::string & _message, const log_value &_value1,
		const log_value &_value2, const log_value &_value3, const log_value &_value4,
		const log_value &_value5 );	

#endif


	~state_machine_defect() Y_NOEXCEPT;


	const state_machine_element& get_element() const;
	const std::string& get_message() const;


private:
	const state_machine_element* element_;
	std::string message_;
};


void write_defects_to_log( const state_machine_defects& _defects );
}


#endif
