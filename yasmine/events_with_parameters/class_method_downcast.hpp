//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CLASS_METHOD_DOWNCAST_CCA48F47_4FDA_41C2_A6CE_EF8ED80002FA
#define CLASS_METHOD_DOWNCAST_CCA48F47_4FDA_41C2_A6CE_EF8ED80002FA


#include "events.hpp"


namespace sxy
{


typedef Y_UNIQUE_PTR< sxy::state_machine > state_machine_uptr;


class class_method_downcast Y_FINAL
{
public:
	class_method_downcast();
	~class_method_downcast() Y_NOEXCEPT;
	Y_NO_COPY( class_method_downcast )

private:
#ifndef Y_CPP03_BOOST
	void do_something_event_2_parameters( const event_2& _event );
	void do_something_event_1_parameter( const event_1& _event );
	void do_something_event_0_parameters( const completion_event& _event );
#else
	void do_something_event_2_parameters( const event& _event );
	void do_something_event_1_parameter( const event& _event );
	void do_something_event_0_parameters( const event& _event );
#endif		
	state_machine_uptr setup_state_machine( const std::string& _name );
};


void use_method_downcast();


}

#endif
