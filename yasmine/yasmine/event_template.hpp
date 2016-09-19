//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_TEMPLATE_D5281A8F_E064_45B5_B1E6_0C5B91DCD932
#define EVENT_TEMPLATE_D5281A8F_E064_45B5_B1E6_0C5B91DCD932


#include "event_impl.hpp"
												 

#define EVENT_WITH_ID( _name, _event_id ) \
class _name : public sxy::event_impl \
{ \
public: \
	_name() \
	: event_impl(_event_id) \
{ \
} \
\
virtual ~_name() noexcept override = default;\
\
_name( const _name& ) = delete;\
_name& operator=( const _name& ) = delete;\
\
static sxy::event_sptr create() \
{ \
	return( std::make_shared< _name >() ); \
} \
\
};


#define EVENT_WITH_ID_PRIORITY( _name, _event_id, _event_priority ) \
class _name : public sxy::event_impl \
{ \
public: \
	_name() \
	: event_impl(_event_id, _event_priority) \
{ \
} \
\
virtual ~_name() noexcept override = default;\
\
_name( const _name& ) = delete;\
_name& operator=( const _name& ) = delete;\
\
static sxy::event_sptr create() \
{ \
	return( std::make_shared< _name >() ); \
} \
\
};

#endif
