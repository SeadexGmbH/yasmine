//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_state_machine_element.h"


namespace sxy
{


t_state_machine_element::t_state_machine_element
(
	const std::string& p_name
): m_name( p_name )
{
	// Nothing to do...
}


t_state_machine_element::~t_state_machine_element
(
) = default;


const std::string&
t_state_machine_element::get_name
(
) const
{
	return( m_name );
}	


const i_state_machine_element*
t_state_machine_element::get_parent
(
) const 
{
	return ( nullptr );
}


}
