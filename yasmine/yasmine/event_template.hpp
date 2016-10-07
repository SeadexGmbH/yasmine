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


#include "specialized_event.hpp"


//!\brief Macro for creating an event class that inherits the specialized_event. The event will have an ID and a priority.
//!\param _class_name Name of the event class.
//!\param _event_id Event's ID.
//!\param _event_priority Event's priority.
#define Y_EVENT_WITH_ID_PRIORITY( _class_name, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority > { \
public: \
	explicit _class_name() \
	: sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority >( #_class_name ) \
	{ \
	} \
\
\
	virtual ~_class_name() noexcept override \
	{ \
	} \
\
\
	_class_name( const _class_name& ) = delete; \
	_class_name& operator=( const _class_name& ) = delete; \
\
\
	static std::shared_ptr< _class_name > create() { \
		return( std::make_shared< _class_name >() ); \
	} \
\
\
	static sxy::event_id get_event_id() \
	{ \
		return( event_id_ ); \
	} \
\
\
private: \
	const static sxy::event_id event_id_ = _event_id; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event priority will be the default priority.
//!\param _class_name Name of the event class.
//!\param _event_id Event's id.
#define Y_EVENT_WITH_ID( _class_name, _event_id ) Y_EVENT_WITH_ID_PRIORITY( _class_name, _event_id, sxy::DEFAULT_EVENT_PRIORITY )
							

//!\brief Macro for creating an event class that inherits the specialized_event. The event will have an ID, a priority and a given type parameter.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the parameter.
//!\param _getter_name1 Name of the method that returns the value of the parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_1PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority > { \
public: \
	explicit _class_name( const _parameter_type1& _p1 ) \
	: sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ) \
	{ \
	} \
\
\
	virtual ~_class_name() noexcept override \
	{ \
	} \
\
\
	_class_name( const _class_name& ) = delete; \
	_class_name& operator=( const _class_name& ) = delete; \
\
\
	const _parameter_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	static std::shared_ptr< _class_name > create( const _parameter_type1& _p1 ) \
	{ \
		return( std::make_shared< _class_name >( _p1 ) ); \
	} \
\
\
	static sxy::event_id get_event_id() \
	{ \
		return( event_id_ ); \
	} \
\
\
private: \
	const _parameter_type1 p1_; \
	const static sxy::event_id event_id_ = _event_id; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event will have one parameter. The event priority will be the default priority.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the parameter.
//!\param _getter_name1 Name of the method that returns the value of the parameter.
//!\param _event_id Event's id.
#define Y_EVENT_1PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _event_id ) Y_EVENT_1PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _event_id, sxy::DEFAULT_EVENT_PRIORITY )
		

//!\brief Macro for creating an event class that inherits the specialized_event. The event will have an ID, a priority and two given type parameter.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_2PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority > { \
public: \
	explicit _class_name( const _parameter_type1& _p1, const _parameter_type2& _p2 ) \
	: sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ) \
	{ \
	} \
\
\
	virtual ~_class_name() noexcept override \
	{ \
	} \
\
\
	_class_name( const _class_name& ) = delete; \
	_class_name& operator=( const _class_name& ) = delete; \
\
\
	const _parameter_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _parameter_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	static std::shared_ptr< _class_name > create( const _parameter_type1& _p1, const _parameter_type2& _p2 ) \
	{ \
		return( std::make_shared< _class_name >( _p1, _p2 ) ); \
	} \
\
\
	static sxy::event_id get_event_id() \
	{ \
		return( event_id_ ); \
	} \
\
\
private: \
	const _parameter_type1 p1_; \
	const _parameter_type2 p2_; \
	const static sxy::event_id event_id_ = _event_id; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event will have two parameters. The event priority will be the default priority.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _event_id Event's id.
#define Y_EVENT_2PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _event_id ) Y_EVENT_2PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _event_id, sxy::DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event will have an ID, a priority and three given type parameters.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _parameter_type3 Type of the third parameter.
//!\param _getter_name3 Name of the method that returns the value of the third parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_3PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority > { \
public: \
	explicit _class_name( const _parameter_type1& _p1, const _parameter_type2& _p2, const _parameter_type3& _p3 ) \
	: sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ) \
	{ \
	} \
\
\
	virtual ~_class_name() noexcept override \
	{ \
	} \
\
\
	_class_name( const _class_name& ) = delete; \
	_class_name& operator=( const _class_name& ) = delete; \
\
\
	const _parameter_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _parameter_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _parameter_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	static std::shared_ptr< _class_name > create( const _parameter_type1& _p1, const _parameter_type2& _p2, const _parameter_type3& _p3 ) \
	{ \
		return( std::make_shared< _class_name >( _p1, _p2, _p3 ) ); \
	} \
\
\
	static sxy::event_id get_event_id() \
	{ \
		return( event_id_ ); \
	} \
\
\
private: \
	const _parameter_type1 p1_; \
	const _parameter_type2 p2_; \
	const _parameter_type3 p3_; \
	const static sxy::event_id event_id_ = _event_id; \
};
							

//!\brief Macro for creating an event class that inherits the specialized_event. The event will have three parameters. The event priority will be the default priority.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _parameter_type3 Type of the third parameter.
//!\param _getter_name3 Name of the method that returns the value of the third parameter.
//!\param _event_id Event's id.
#define Y_EVENT_3PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _event_id ) Y_EVENT_3PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _event_id, sxy::DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event will have an ID, a priority and four given type parameters.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _parameter_type3 Type of the third parameter.
//!\param _getter_name3 Name of the method that returns the value of the third parameter.
//!\param _parameter_type4 Type of the fourth parameter.
//!\param _getter_name4 Name of the method that returns the value of the fourth parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_4PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority > { \
public: \
	explicit _class_name( const _parameter_type1& _p1, const _parameter_type2& _p2, const _parameter_type3& _p3, const _parameter_type4& _p4 ) \
	: sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ), \
		p4_( _p4 ) \
	{ \
	} \
\
\
	virtual ~_class_name() noexcept override \
	{ \
	} \
\
\
	_class_name( const _class_name& ) = delete; \
	_class_name& operator=( const _class_name& ) = delete; \
\
\
	const _parameter_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _parameter_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _parameter_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	const _parameter_type4& _getter_name4() const \
	{ \
		return( p4_ ); \
	} \
\
\
	static std::shared_ptr< _class_name > create( const _parameter_type1& _p1, const _parameter_type2& _p2, const _parameter_type3& _p3, const _parameter_type4& _p4 ) \
	{ \
		return( std::make_shared< _class_name >( _p1, _p2, _p3, _p4 ) ); \
	} \
\
\
	static sxy::event_id get_event_id() \
	{ \
		return( event_id_ ); \
	} \
\
\
private: \
	const _parameter_type1 p1_; \
	const _parameter_type2 p2_; \
	const _parameter_type3 p3_; \
	const _parameter_type4 p4_; \
	const static sxy::event_id event_id_ = _event_id; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event will have four parameters. The event priority will be the default priority.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _parameter_type3 Type of the third parameter.
//!\param _getter_name3 Name of the method that returns the value of the third parameter.
//!\param _parameter_type4 Type of the forth parameter.
//!\param _getter_name4 Name of the method that returns the value of the forth parameter.
//!\param _event_id Event's id.
#define Y_EVENT_4PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _event_id ) Y_EVENT_4PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _event_id, sxy::DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event will have an ID, a priority and five given type parameters.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _parameter_type3 Type of the third parameter.
//!\param _getter_name3 Name of the method that returns the value of the third parameter.
//!\param _parameter_type4 Type of the forth parameter.
//!\param _getter_name4 Name of the method that returns the value of the forth parameter.
//!\param _parameter_type5 Type of the fifth parameter.
//!\param _getter_name5 Name of the method that returns the value of the fifth parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_5PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority > { \
public: \
	explicit _class_name( const _parameter_type1& _p1, const _parameter_type2& _p2, const _parameter_type3& _p3, const _parameter_type4& _p4, const _parameter_type5& _p5 ) \
	: sxy::specialized_event< struct _class_name##_tag, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ), \
		p4_( _p4 ), \
		p5_( _p5 ) \
	{ \
	} \
\
\
	virtual ~_class_name() noexcept override \
	{ \
	} \
\
\
	_class_name( const _class_name& ) = delete; \
	_class_name& operator=( const _class_name& ) = delete; \
\
\
	const _parameter_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _parameter_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _parameter_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	const _parameter_type4& _getter_name4() const \
	{ \
		return( p4_ ); \
	} \
\
\
	const _parameter_type5& _getter_name5() const \
	{ \
		return( p5_ ); \
	} \
\
\
	static std::shared_ptr< _class_name > create( const _parameter_type1& _p1, const _parameter_type2& _p2, const _parameter_type3& _p3, const _parameter_type4& _p4, const _parameter_type5& _p5 ) \
	{ \
		return( std::make_shared< _class_name >( _p1, _p2, _p3, _p4, _p5 ) ); \
	} \
\
\
	static sxy::event_id get_event_id() \
	{ \
		return( event_id_ ); \
	} \
\
\
private: \
	const _parameter_type1 p1_; \
	const _parameter_type2 p2_; \
	const _parameter_type3 p3_; \
	const _parameter_type4 p4_; \
	const _parameter_type5 p5_; \
	const static sxy::event_id event_id_ = _event_id; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event will have five parameters. The event priority will be the default priority.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _parameter_type3 Type of the third parameter.
//!\param _getter_name3 Name of the method that returns the value of the third parameter.
//!\param _parameter_type4 Type of the forth parameter.
//!\param _getter_name4 Name of the method that returns the value of the forth parameter.
//!\param _parameter_type5 Type of the fifth parameter.
//!\param _getter_name5 Name of the method that returns the value of the fifth parameter.
//!\param _event_id Event's id.
#define Y_EVENT_5PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _event_id ) Y_EVENT_5PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _event_id, sxy::DEFAULT_EVENT_PRIORITY )


#endif
