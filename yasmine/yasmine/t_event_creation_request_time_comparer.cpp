//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_event_creation_request_time_comparer.h"


namespace sxy
{	


bool t_event_creation_request_time_comparer::operator() ( const std::unique_ptr<t_event_creation_request>& p_lhs, const std::unique_ptr<t_event_creation_request>& p_rhs ) const
{
	return( p_lhs->get_time() < p_rhs->get_time() );
}


}
