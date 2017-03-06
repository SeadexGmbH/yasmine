//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_MACHINE_ELEMENT_IMPL_EC5B279B_E7A2_40CF_8D97_F0581F89B36C
#define STATE_MACHINE_ELEMENT_IMPL_EC5B279B_E7A2_40CF_8D97_F0581F89B36C


#include <string>

#include "state_machine_element.hpp"


namespace sxy
{


class state_machine_element_impl:
	public virtual state_machine_element
{
public:
	explicit state_machine_element_impl( const std::string& _name );
	virtual ~state_machine_element_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(state_machine_element_impl)	
	virtual const std::string& get_name() const Y_OVERRIDE;


private:
	const std::string name_;
};


}


#endif
