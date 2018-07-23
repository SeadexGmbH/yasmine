//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_TEMPLATE_D5281A8F_E064_45B5_B1E6_0C5B91DCD932
#define EVENT_TEMPLATE_D5281A8F_E064_45B5_B1E6_0C5B91DCD932


#include "essentials/compatibility/compatibility.hpp"

#include "specialized_event.hpp"


#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )
	#define Y_AUX_DEFAULT_EVENT_PRIORITY DEFAULT_EVENT_PRIORITY
#else
	#define Y_AUX_DEFAULT_EVENT_PRIORITY sxy::DEFAULT_EVENT_PRIORITY
#endif


#ifndef SX_NO_VARIADIC_MACRO

#define Y_EVENT_EXPAND( x ) x

#define Y_EVENT_CAT( A, B ) A ## B
#define Y_EVENT_SELECT( NAME, NUM ) Y_EVENT_CAT( NAME ## _, NUM )

#define Y_EVENT_GET_COUNT( _ONE, _TWO, _THREE, _FOUR, _FIVE, _SIX, _SEVEN, _EIGHT, _NINE, _TEN, _ELEVEN, _TWELVE, _THIRTEEN, _FOURTEEN, _FIFTEEN, _SIXTEEN, _EIGHTEEN, _NINETEEN, _TWENTY, _TWENTY_ONE, _TWENTY_TWO, COUNT, ... ) COUNT
#define Y_EVENT_VA_SIZE( ... ) Y_EVENT_EXPAND( Y_EVENT_GET_COUNT( __VA_ARGS__, 10, 10, 9, 9, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 0, 0, -1, -1, -2, -2 ) )

#define Y_VA_SELECT( NAME, _level, ... ) Y_EVENT_EXPAND( Y_EVENT_SELECT( NAME, Y_EVENT_VA_SIZE(__VA_ARGS__) )( _level, __VA_ARGS__) )
#define Y_VA_SELECT_PRIORITY( NAME, _level, _level_2, ... ) Y_EVENT_EXPAND( Y_EVENT_SELECT( NAME, Y_EVENT_VA_SIZE(__VA_ARGS__) )( _level, _level_2, __VA_ARGS__) )

//!\brief Macro for creating event class. It supports up to 10 event parameters. For each parameter, the type and the
//!\getter name must be specified.
#define Y_EVENT_CREATE( _class_name, ... ) Y_EVENT_EXPAND( Y_VA_SELECT( Y_EVENT_PARAM, _class_name, __VA_ARGS__ ) )

#define Y_EVENT_PARAM_0( _class_name, _event_id ) Y_EVENT_WITH_ID( _class_name, _event_id )
#define Y_EVENT_PARAM_1( _class_name, _event_id, _parameter_type1, _getter_name1 ) Y_EVENT_1PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _event_id )
#define Y_EVENT_PARAM_2( _class_name, _event_id, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2 ) Y_EVENT_2PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _event_id )
#define Y_EVENT_PARAM_3( _class_name, _event_id, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3 ) Y_EVENT_3PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _event_id )
#define Y_EVENT_PARAM_4( _class_name, _event_id, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4 ) Y_EVENT_4PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _event_id )
#define Y_EVENT_PARAM_5( _class_name, _event_id, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5 ) Y_EVENT_5PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _event_id )
#define Y_EVENT_PARAM_6( _class_name, _event_id, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6 ) Y_EVENT_6PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _event_id )
#define Y_EVENT_PARAM_7( _class_name, _event_id, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7 ) Y_EVENT_7PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _event_id )
#define Y_EVENT_PARAM_8( _class_name, _event_id, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8 ) Y_EVENT_8PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _event_id )
#define Y_EVENT_PARAM_9( _class_name, _event_id, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9 ) Y_EVENT_9PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _event_id )
#define Y_EVENT_PARAM_10( _class_name, _event_id, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _parameter_type10, _getter_name10 ) Y_EVENT_10PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _parameter_type10, _getter_name10, _event_id )


//!\brief Macro for creating event class with event priority. It supports up to 10 event parameters. For each 
//!\parameter, the type and the getter name must be specified.
#define Y_EVENT_WITH_PRIORITY_CREATE( _class_name, _event_id, ... ) Y_EVENT_EXPAND( Y_VA_SELECT_PRIORITY( Y_EVENT_PARAM_PRIORITY, _class_name, _event_id, __VA_ARGS__ ) )

#define Y_EVENT_PARAM_PRIORITY_0( _class_name, _event_id, _event_priority ) Y_EVENT_WITH_ID_PRIORITY( _class_name, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_1( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1 ) Y_EVENT_1PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_2( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2 ) Y_EVENT_2PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_3( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3 ) Y_EVENT_3PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_4( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4 ) Y_EVENT_4PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_5( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5 ) Y_EVENT_5PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_6( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6 ) Y_EVENT_6PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_7( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7 ) Y_EVENT_7PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_8( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8 ) Y_EVENT_8PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_9( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9 ) Y_EVENT_9PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _event_id, _event_priority )
#define Y_EVENT_PARAM_PRIORITY_10( _class_name, _event_id, _event_priority, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _parameter_type10, _getter_name10 ) Y_EVENT_10PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _parameter_type10, _getter_name10, _event_id, _event_priority )

#endif




//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID and a priority.
//!\param _class_name Name of the event class.
//!\param _event_id Event's ID.
//!\param _event_priority Event's priority.
#define Y_EVENT_WITH_ID_PRIORITY( _class_name, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	explicit _class_name() \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY( _class_name )\
\
\
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event priority is the default priority.
//!\param _class_name Name of the event class.
//!\param _event_id Event's id.
#define Y_EVENT_WITH_ID( _class_name, _event_id ) Y_EVENT_WITH_ID_PRIORITY( _class_name, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and a given type parameter.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the parameter.
//!\param _getter_name1 Name of the method that returns the value of the parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_1PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	explicit _class_name( const _param_type1& _p1 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event has one parameter. The event priority is the default priority.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the parameter.
//!\param _getter_name1 Name of the method that returns the value of the parameter.
//!\param _event_id Event's id.
#define Y_EVENT_1PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _event_id ) Y_EVENT_1PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )
				

//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and two given type parameter.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_2PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type2>::type>::type _param_type2;\
	explicit _class_name( const _param_type1& _p1, const _param_type2& _p2 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _param_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
	const _param_type2 p2_; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event has two parameters. The event priority is the default priority.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _event_id Event's id.
#define Y_EVENT_2PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _event_id ) Y_EVENT_2PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and three given type parameters.
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
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type2>::type>::type _param_type2;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type3>::type>::type _param_type3;\
	explicit _class_name( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _param_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _param_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
	const _param_type2 p2_; \
	const _param_type3 p3_; \
};
							

//!\brief Macro for creating an event class that inherits the specialized_event. The event has three parameters. The event priority is the default priority.
//!\param _class_name Name of the event class.
//!\param _parameter_type1 Type of the first parameter.
//!\param _getter_name1 Name of the method that returns the value of the first parameter.
//!\param _parameter_type2 Type of the second parameter.
//!\param _getter_name2 Name of the method that returns the value of the second parameter.
//!\param _parameter_type3 Type of the third parameter.
//!\param _getter_name3 Name of the method that returns the value of the third parameter.
//!\param _event_id Event's id.
#define Y_EVENT_3PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _event_id ) Y_EVENT_3PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and four given type parameters.
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
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type2>::type>::type _param_type2;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type3>::type>::type _param_type3;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type4>::type>::type _param_type4;\
	explicit _class_name( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3, const _param_type4& _p4 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ), \
		p4_( _p4 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _param_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _param_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	const _param_type4& _getter_name4() const \
	{ \
		return( p4_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
	const _param_type2 p2_; \
	const _param_type3 p3_; \
	const _param_type4 p4_; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event has four parameters. The event priority is the default priority.
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
#define Y_EVENT_4PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _event_id ) Y_EVENT_4PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and five given type parameters.
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
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type2>::type>::type _param_type2;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type3>::type>::type _param_type3;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type4>::type>::type _param_type4;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type5>::type>::type _param_type5;\
	explicit _class_name( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3, const _param_type4& _p4, const _param_type5& _p5 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ), \
		p4_( _p4 ), \
		p5_( _p5 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _param_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _param_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	const _param_type4& _getter_name4() const \
	{ \
		return( p4_ ); \
	} \
\
\
	const _param_type5& _getter_name5() const \
	{ \
		return( p5_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
	const _param_type2 p2_; \
	const _param_type3 p3_; \
	const _param_type4 p4_; \
	const _param_type5 p5_; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event has five parameters. The event priority is the default priority.
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
#define Y_EVENT_5PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _event_id ) Y_EVENT_5PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and six given type parameters.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_6PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type2>::type>::type _param_type2;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type3>::type>::type _param_type3;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type4>::type>::type _param_type4;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type5>::type>::type _param_type5;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type6>::type>::type _param_type6;\
	explicit _class_name( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3, const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ), \
		p4_( _p4 ), \
		p5_( _p5 ), \
		p6_( _p6 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _param_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _param_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	const _param_type4& _getter_name4() const \
	{ \
		return( p4_ ); \
	} \
\
\
	const _param_type5& _getter_name5() const \
	{ \
		return( p5_ ); \
	} \
\
\
	const _parameter_type6& _getter_name6() const \
	{ \
		return( p6_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
	const _param_type2 p2_; \
	const _param_type3 p3_; \
	const _param_type4 p4_; \
	const _param_type5 p5_; \
	const _param_type6 p6_; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event has six parameters. The event priority is the default priority.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _event_id Event's id.
#define Y_EVENT_6PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _event_id ) Y_EVENT_6PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and seven given type parameters.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _parameter_type7 Type of the seventh parameter.
//!\param _getter_name7 Name of the method that returns the value of the seventh parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_7PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type2>::type>::type _param_type2;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type3>::type>::type _param_type3;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type4>::type>::type _param_type4;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type5>::type>::type _param_type5;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type6>::type>::type _param_type6;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type7>::type>::type _param_type7;\
	explicit _class_name( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3, const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6, const _param_type7& _p7 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ), \
		p4_( _p4 ), \
		p5_( _p5 ), \
		p6_( _p6 ), \
		p7_( _p7 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _param_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _param_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	const _param_type4& _getter_name4() const \
	{ \
		return( p4_ ); \
	} \
\
\
	const _param_type5& _getter_name5() const \
	{ \
		return( p5_ ); \
	} \
\
\
	const _param_type6& _getter_name6() const \
	{ \
		return( p6_ ); \
	} \
\
\
	const _param_type7& _getter_name7() const \
	{ \
		return( p7_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
	const _param_type2 p2_; \
	const _param_type3 p3_; \
	const _param_type4 p4_; \
	const _param_type5 p5_; \
	const _param_type6 p6_; \
	const _param_type7 p7_; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event has seven parameters. The event priority is the default priority.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _parameter_type7 Type of the seventh parameter.
//!\param _getter_name7 Name of the method that returns the value of the seventh parameter.
//!\param _event_id Event's id.
#define Y_EVENT_7PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _event_id ) Y_EVENT_7PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )


//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and eight given type parameters.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _parameter_type7 Type of the seventh parameter.
//!\param _getter_name7 Name of the method that returns the value of the seventh parameter.
//!\param _parameter_type8 Type of the eighth parameter.
//!\param _getter_name8 Name of the method that returns the value of the eighth parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_8PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type2>::type>::type _param_type2;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type3>::type>::type _param_type3;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type4>::type>::type _param_type4;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type5>::type>::type _param_type5;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type6>::type>::type _param_type6;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type7>::type>::type _param_type7;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type8>::type>::type _param_type8;\
	explicit _class_name( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3, const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6, const _param_type7& _p7, const _param_type8& _p8 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ), \
		p4_( _p4 ), \
		p5_( _p5 ), \
		p6_( _p6 ), \
		p7_( _p7 ), \
		p8_( _p8 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _param_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _param_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	const _param_type4& _getter_name4() const \
	{ \
		return( p4_ ); \
	} \
\
\
	const _param_type5& _getter_name5() const \
	{ \
		return( p5_ ); \
	} \
\
\
	const _param_type6& _getter_name6() const \
	{ \
		return( p6_ ); \
	} \
\
\
	const _param_type7& _getter_name7() const \
	{ \
		return( p7_ ); \
	} \
\
\
	const _param_type8& _getter_name8() const \
	{ \
		return( p8_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
	const _param_type2 p2_; \
	const _param_type3 p3_; \
	const _param_type4 p4_; \
	const _param_type5 p5_; \
	const _param_type6 p6_; \
	const _param_type7 p7_; \
	const _param_type8 p8_; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event has seven parameters. The event priority is the default priority.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _parameter_type7 Type of the seventh parameter.
//!\param _getter_name7 Name of the method that returns the value of the seventh parameter.
//!\param _parameter_type8 Type of the eighth parameter.
//!\param _getter_name8 Name of the method that returns the value of the eighth parameter.
//!\param _event_id Event's id.
#define Y_EVENT_8PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _event_id ) Y_EVENT_8PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )



//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and nine given type parameters.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _parameter_type7 Type of the seventh parameter.
//!\param _getter_name7 Name of the method that returns the value of the seventh parameter.
//!\param _parameter_type8 Type of the eighth parameter.
//!\param _getter_name8 Name of the method that returns the value of the eighth parameter.
//!\param _parameter_type9 Type of the ninth parameter.
//!\param _getter_name9 Name of the method that returns the value of the ninth parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_9PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type2>::type>::type _param_type2;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type3>::type>::type _param_type3;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type4>::type>::type _param_type4;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type5>::type>::type _param_type5;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type6>::type>::type _param_type6;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type7>::type>::type _param_type7;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type8>::type>::type _param_type8;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type9>::type>::type _param_type9;\
	explicit _class_name( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3, const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6, const _param_type7& _p7, const _param_type8& _p8, const _param_type9& _p9 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ), \
		p4_( _p4 ), \
		p5_( _p5 ), \
		p6_( _p6 ), \
		p7_( _p7 ), \
		p8_( _p8 ), \
		p9_( _p9 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _param_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _param_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	const _param_type4& _getter_name4() const \
	{ \
		return( p4_ ); \
	} \
\
\
	const _param_type5& _getter_name5() const \
	{ \
		return( p5_ ); \
	} \
\
\
	const _param_type6& _getter_name6() const \
	{ \
		return( p6_ ); \
	} \
\
\
	const _param_type7& _getter_name7() const \
	{ \
		return( p7_ ); \
	} \
\
\
const _param_type8& _getter_name8() const \
	{ \
		return( p8_ ); \
	} \
\
\
	const _param_type9& _getter_name9() const \
	{ \
		return( p9_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
	const _param_type2 p2_; \
	const _param_type3 p3_; \
	const _param_type4 p4_; \
	const _param_type5 p5_; \
	const _param_type6 p6_; \
	const _param_type7 p7_; \
	const _param_type8 p8_; \
	const _param_type9 p9_; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event has seven parameters. The event priority is the default priority.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _parameter_type7 Type of the seventh parameter.
//!\param _getter_name7 Name of the method that returns the value of the seventh parameter.
//!\param _parameter_type8 Type of the eighth parameter.
//!\param _getter_name8 Name of the method that returns the value of the eighth parameter.
//!\param _parameter_type9 Type of the ninth parameter.
//!\param _getter_name9 Name of the method that returns the value of the ninth parameter.
//!\param _event_id Event's id.
#define Y_EVENT_9PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _event_id ) Y_EVENT_9PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )



//!\brief Macro for creating an event class that inherits the specialized_event. The event has an ID, a priority and ten given type parameters.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _parameter_type7 Type of the seventh parameter.
//!\param _getter_name7 Name of the method that returns the value of the seventh parameter.
//!\param _parameter_type8 Type of the eighth parameter.
//!\param _getter_name8 Name of the method that returns the value of the eighth parameter.
//!\param _parameter_type9 Type of the ninth parameter.
//!\param _getter_name9 Name of the method that returns the value of the ninth parameter.
//!\param _parameter_type10 Type of the tenth parameter.
//!\param _getter_name10 Name of the method that returns the value of the tenth parameter.
//!\param _event_id Event's id.
//!\param _event_priority Event's priority.
#define Y_EVENT_10PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _parameter_type10, _getter_name10, _event_id, _event_priority ) \
class _class_name: public sxy::specialized_event< _class_name, _event_id, _event_priority > { \
public: \
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type1>::type>::type _param_type1;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type2>::type>::type _param_type2;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type3>::type>::type _param_type3;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type4>::type>::type _param_type4;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type5>::type>::type _param_type5;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type6>::type>::type _param_type6;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type7>::type>::type _param_type7;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type8>::type>::type _param_type8;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type9>::type>::type _param_type9;\
	typedef sxe::remove_reference<sxe::remove_const<_parameter_type10>::type>::type _param_type10;\
	explicit _class_name( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3, const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6, const _param_type7& _p7, const _param_type8& _p8, const _param_type9& _p9, const _param_type10& _p10 ) \
	: sxy::specialized_event< _class_name, _event_id, _event_priority >( #_class_name ), \
	  p1_( _p1 ), \
		p2_( _p2 ), \
		p3_( _p3 ), \
		p4_( _p4 ), \
		p5_( _p5 ), \
		p6_( _p6 ), \
		p7_( _p7 ), \
		p8_( _p8 ), \
		p9_( _p9 ), \
		p10_( _p10 ) \
	{ \
	} \
\
\
	virtual ~_class_name() SX_NOEXCEPT SX_OVERRIDE \
	{ \
	} \
\
\
	SX_NO_COPY(_class_name)\
\
\
	const _param_type1& _getter_name1() const \
	{ \
		return( p1_ ); \
	} \
\
\
	const _param_type2& _getter_name2() const \
	{ \
		return( p2_ ); \
	} \
\
\
	const _param_type3& _getter_name3() const \
	{ \
		return( p3_ ); \
	} \
\
\
	const _param_type4& _getter_name4() const \
	{ \
		return( p4_ ); \
	} \
\
\
	const _param_type5& _getter_name5() const \
	{ \
		return( p5_ ); \
	} \
\
\
	const _param_type6& _getter_name6() const \
	{ \
		return( p6_ ); \
	} \
\
\
	const _param_type7& _getter_name7() const \
	{ \
		return( p7_ ); \
	} \
\
\
	const _param_type8& _getter_name8() const \
	{ \
		return( p8_ ); \
	} \
\
\
	const _param_type9& _getter_name9() const \
	{ \
		return( p9_ ); \
	} \
\
\
	const _param_type10& _getter_name10() const \
	{ \
		return( p10_ ); \
	} \
\
\
private: \
	const _param_type1 p1_; \
	const _param_type2 p2_; \
	const _param_type3 p3_; \
	const _param_type4 p4_; \
	const _param_type5 p5_; \
	const _param_type6 p6_; \
	const _param_type7 p7_; \
	const _param_type8 p8_; \
	const _param_type9 p9_; \
	const _param_type10 p10_; \
};


//!\brief Macro for creating an event class that inherits the specialized_event. The event has seven parameters. The event priority is the default priority.
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
//!\param _parameter_type6 Type of the sixth parameter.
//!\param _getter_name6 Name of the method that returns the value of the sixth parameter.
//!\param _parameter_type7 Type of the seventh parameter.
//!\param _getter_name7 Name of the method that returns the value of the seventh parameter.
//!\param _parameter_type8 Type of the eighth parameter.
//!\param _getter_name8 Name of the method that returns the value of the eighth parameter.
//!\param _parameter_type9 Type of the ninth parameter.
//!\param _getter_name9 Name of the method that returns the value of the ninth parameter.
//!\param _parameter_type10 Type of the tenth parameter.
//!\param _getter_name10 Name of the method that returns the value of the tenth parameter.
//!\param _event_id Event's id.
#define Y_EVENT_10PARAM_WITH_ID( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _parameter_type10, _getter_name10, _event_id ) Y_EVENT_10PARAM_WITH_ID_PRIORITY( _class_name, _parameter_type1, _getter_name1, _parameter_type2, _getter_name2, _parameter_type3, _getter_name3, _parameter_type4, _getter_name4, _parameter_type5, _getter_name5, _parameter_type6, _getter_name6, _parameter_type7, _getter_name7, _parameter_type8, _getter_name8, _parameter_type9, _getter_name9, _parameter_type10, _getter_name10, _event_id, Y_AUX_DEFAULT_EVENT_PRIORITY )


#endif
