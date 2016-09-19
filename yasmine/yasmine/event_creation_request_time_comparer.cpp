//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "event_creation_request_time_comparer.hpp"


namespace sxy
{


bool event_creation_request_time_comparer::operator()( const std::unique_ptr< event_creation_request >& _lhs,
	const std::unique_ptr< event_creation_request >& _rhs ) const
{
	return( _lhs->get_time() < _rhs->get_time() );
}


}
