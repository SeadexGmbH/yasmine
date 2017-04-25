//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef SX_CPP03_BOOST


#include "event_model_id.hpp"

namespace sxy
{


namespace model
{

	const event_id Y_MODEL_COMPLETION_EVENT_ID = std::numeric_limits<sxy::model::event_id>::max();

}


}

#else


#include "event_model_id.hpp"

namespace sxy
{


	namespace model
	{

		const event_id Y_MODEL_COMPLETION_EVENT_ID = std::numeric_limits<sxy::model::event_id>::max();

	}


}


#endif
