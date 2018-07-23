//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_MACHINE_EXTERNAL_ELEMENT_AEC00D27_A69B_41EB_A235_C68063B7F121
#define STATE_MACHINE_EXTERNAL_ELEMENT_AEC00D27_A69B_41EB_A235_C68063B7F121

#include "essentials/non_copyable.hpp"

#include "externals_fwd.hpp"
#include "model_element_type.hpp"


namespace sxy
{


namespace model
{


class state_machine_external_element SX_FINAL
{
public:
	explicit state_machine_external_element( const std::string& _name, const model_element_type& _type );
	~state_machine_external_element() SX_NOEXCEPT;
	SX_NO_COPY( state_machine_external_element )
	const std::string& get_name() const;
	const std::string& get_name();
	void set_name( const std::string& _name );
	const model_element_type get_type() const;
	void set_type( const model_element_type& _type );


private:
	std::string name_;
	model_element_type type_;
};


}


}


#endif

