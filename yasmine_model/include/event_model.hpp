//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EVENT_3677D50A_2158_4FCD_BB50_308B5C537D87
#define EVENT_3677D50A_2158_4FCD_BB50_308B5C537D87


#include "essentials/non_copyable.hpp"

#include "event_model_id.hpp"
#include "event_model_priority.hpp"


namespace sxy
{


namespace model
{


//!\struct event_model
//!\brief An event in the model.
struct event_model
{
public:
	//!\brief Constructor.
	event_model();
	
	//!\brief Constructor.
	//!\param _name Name of the event.
	//!\param _id Id of the event.
	//!\param _priority Priority of the event.
	event_model( const std::string _name, const event_id _id, const event_priority _priority );
	~event_model() SX_NOEXCEPT;


	std::string name;
	event_id id;
	event_priority priority;
};


}


}


#endif
