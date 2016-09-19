//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_constraint.h"


namespace sxy
{


t_constraint::t_constraint
(
	const t_constraint_function& p_function
): 
	i_constraint(),
	m_function( p_function )
{
	// Nothing to do...
}


t_constraint::~t_constraint
(
) = default;


bool
t_constraint::operator()
(
	const i_event& p_event
) const
{
	return( m_function( p_event ) );
}


i_constraint_uptr
t_constraint::create_constraint
(
	const t_constraint_function& p_function
)
{
	auto l_constraint = std::make_unique<sxy::t_constraint>( p_function );
	return( std::move( l_constraint ) );
}


}
