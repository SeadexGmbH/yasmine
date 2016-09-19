//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_state_machine_defects.h"
#include "t_state_machine_defects_fwd.h"


namespace sxy
{


t_state_machine_defect::~t_state_machine_defect
(
) = default;


const i_state_machine_element&
// cppcheck-suppress unusedFunction
t_state_machine_defect::get_element
(
) const
{
	return( *m_element );
}


const std::string&
t_state_machine_defect::get_message
(
) const
{
	return( m_message );
}	 



void
// cppcheck-suppress unusedFunction
write_defects_to_log
(
	const t_state_machine_defects& p_defects
)
{
	for( const auto& l_defect : p_defects )
	{
		Y_LOG( sxy::t_log_level::LL_ERROR, l_defect->get_message() );
	}
}


}
