//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "event_model.hpp"


namespace sxy
{


namespace model
{


	event_model::event_model()
		: name(),
			id(),
			priority()
	{
		// Nothing to do...
	}


	event_model::event_model( const std::string _name, const event_id _id, const event_priority _priority )
		: name( _name ),
			id( _id ),
			priority( _priority )
	{
		// Nothing to do...
	}


	event_model::~event_model() SX_NOEXCEPT
	{
		// Nothing to do...
	}


}


}
