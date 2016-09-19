//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_machine_defect.h"
#include "state_machine_defect_fwd.h"


namespace sxy
{


state_machine_defect::~state_machine_defect() = default;


// cppcheck-suppress unusedFunction
const state_machine_element& state_machine_defect::get_element() const
{
	return( *element_ );
}


const std::string& state_machine_defect::get_message() const
{
	return( message_ );
}


// cppcheck-suppress unusedFunction
void write_defects_to_log( const state_machine_defects& _defects )
{
	for( const auto & defect : _defects )
	{
		Y_LOG( sxy::log_level::LL_ERROR, defect->get_message() );
	}
}


}
