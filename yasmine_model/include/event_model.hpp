//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EVENT_MODEL_1280B0B7_E85B_4EFF_BF3D_D5548D88D0D8
#define EVENT_MODEL_1280B0B7_E85B_4EFF_BF3D_D5548D88D0D8


#include "essentials/non_copyable.hpp"

#include "event_model_id.hpp"
#include "event_model_priority.hpp"


namespace sxy
{


namespace model
{


//!\class event_model
//!\brief An event in the model.
class event_model
{
public:
	//!\brief Constructor.
	//!\param _name Name of the event.
	//!\param _id ID of the event.
	//!\param _priority Priority of the event.
	explicit event_model( const std::string _name, const event_id _id, const event_priority _priority = 0 );
	~event_model() SX_NOEXCEPT;
	const std::string& get_name() const;
	void set_name( const std::string& _name );
	const event_id get_id() const;
	void set_id( const event_id _id );
	const event_priority get_priority() const;
	void set_priority( const event_priority _priority);


private:
	std::string name_;
	event_id id_;
	event_priority priority_;
};


}


}


#endif
