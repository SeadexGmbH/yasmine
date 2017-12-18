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



event_model::event_model( const std::string _name, const event_id _id, const event_priority _priority )
	: name_( _name ),
		id_( _id ),
		priority_( _priority )
{
	// Nothing to do...
}


event_model::~event_model() SX_NOEXCEPT
{
	// Nothing to do...
}


const std::string& event_model::get_name() const
{
	return( name_ );
}


void event_model::set_name( const std::string& _name )
{
	name_ = _name;
}


const event_id event_model::get_id() const
{
	return( id_ );
}


void event_model::set_id( const event_id _id )
{
	id_ = _id;
}


const event_priority event_model::get_priority() const
{
	return( priority_ );
}


void event_model::set_priority( const event_priority _priority )
{
	priority_ = _priority;
}


}


}
