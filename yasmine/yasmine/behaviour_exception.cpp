//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "behaviour_exception.hpp"


namespace sxy
{


behaviour_exception::behaviour_exception( const event_sptr& _event )
	: exception("Error handle exception."),
		error_event_( _event )
{	
	// Nothing to do...
}


behaviour_exception::~behaviour_exception() Y_NOEXCEPT
{
	// Nothing to do...
}

	
const event_sptr behaviour_exception::get_error_event() const
{
	return( error_event_ );
}


}
