//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
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
	virtual ~state_machine_element_impl() noexcept override = default;
	state_machine_element_impl( const state_machine_element_impl& ) = delete;
	state_machine_element_impl& operator=( const state_machine_element_impl& ) = delete;
	virtual const std::string& get_name() const override;


private:
	const std::string name_;
};


}


#endif
