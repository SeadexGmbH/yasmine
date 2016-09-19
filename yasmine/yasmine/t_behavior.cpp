//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_behavior.h"
#include "t_event.h"


namespace sxy
{


t_behavior::t_behavior
(
	const t_behavior_function& p_function
): 
	 m_function( p_function )
{
	// Nothing to do
}


t_behavior::~t_behavior
(
) = default;


void
t_behavior::operator()
(
	const i_event& p_event
) const
{
	if( m_function )
	{
		m_function( p_event );
	}
}


i_behavior_uptr
t_behavior::create_behavior
(
	const t_behavior_function& p_function
)
{	
	return( std::make_unique<sxy::t_behavior>( p_function ) );
}


}
