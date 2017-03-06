//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CALLER_8B0F592E_A1FC_4089_9145_BB3BF453FE5F
#define CALLER_8B0F592E_A1FC_4089_9145_BB3BF453FE5F


#include "event.hpp"
#include "base.hpp"
#include "caller_adapter.hpp"
#include "caller_helper.hpp"
#include "event_adjuster.hpp"
#include "event_collector.hpp"
#include "exception.hpp"


namespace sxy
{	


void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<void()> _method );


void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<void( event_collector& )> _method );


template< typename _event_type >
void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<void( const _event_type& )> _method )
{
	Y_UNUSED_PARAMETER( _event_collector );

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );
	if( specialized_event )
	{		
			_method( specialized_event );		
	}
	else
	{
		throw sxy::exception( "Invalid event type!" );
	}


#else


	auto& specialized_event = sxy::adjust_event_type< _event_type >( _event );
	_method( specialized_event );


#endif
}


template< typename _event_type >
void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<void( const _event_type&, sxy::event_collector& _event_collector )> _method )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );
	if( specialized_event )
	{		
		_method( specialized_event, _event_collector );		
	}
	else
	{
		throw sxy::exception( "Invalid event type!" );
	}


#else
	

	auto& specialized_event = sxy::adjust_event_type< _event_type >( _event );	
	_method( specialized_event, _event_collector );	
	

#endif
}


template< typename _event_type1, typename _event_type2 >
void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<void( const _event_type1&, sxy::event_collector& )> _method1,
	sxy::function<void( const _event_type2&, sxy::event_collector& )> _method2 )
{

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_method2( specialized_event2, _event_collector );
		}
		else
		{
			throw sxy::exception( "Invalid event type!" );
		}
	}


#else


	static_assert( has_get_event_id<_event_type1>::value,
		"Event type 1 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type2>::value,
		"Event type 2 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );

	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );		
		_method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		const auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );		
		_method2( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3 >
void behavior_caller(	const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<void( const _event_type1&, sxy::event_collector& )> _method1,
	sxy::function<void( const _event_type2&, sxy::event_collector& )> _method2,
	sxy::function<void( const _event_type3&, sxy::event_collector& )> _method3 )
{	
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_method3( specialized_event3, _event_collector );
			}
			else
			{
				throw sxy::exception( "Invalid event type!" );
			}
		}
	}


#else


	static_assert( has_get_event_id<_event_type1>::value,
		"Event type 1 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type2>::value,
		"Event type 2 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type3>::value,
		"Event type 3 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );

	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		_method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_method3( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4 >
void behavior_caller(	const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<void( const _event_type1&, sxy::event_collector& )> _method1,
	sxy::function<void( const _event_type2&, sxy::event_collector& )> _method2,
	sxy::function<void( const _event_type3&, sxy::event_collector& )> _method3,
	sxy::function<void( const _event_type4&, sxy::event_collector& )> _method4 )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_method4( specialized_event4, _event_collector );
				}
				else
				{
					throw sxy::exception( "Invalid event type!" );
				}
			}
		}
	}


#else


	static_assert( has_get_event_id<_event_type1>::value,
		"Event type 1 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type2>::value,
		"Event type 2 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type3>::value,
		"Event type 3 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type4>::value,
		"Event type 4 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );

	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		_method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_method4( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
					typename _event_type5 >
void behavior_caller(	const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<void( const _event_type1&, sxy::event_collector& )> _method1,
	sxy::function<void( const _event_type2&, sxy::event_collector& )> _method2,
	sxy::function<void( const _event_type3&, sxy::event_collector& )> _method3,
	sxy::function<void( const _event_type4&, sxy::event_collector& )> _method4,
	sxy::function<void( const _event_type5&, sxy::event_collector& )> _method5 )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_method5( specialized_event5, _event_collector );
					}
					else
					{
						throw sxy::exception( "Invalid event type!" );
					}
				}
			}
		}
	}


#else


	static_assert( has_get_event_id<_event_type1>::value,
		"Event type 1 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type2>::value,
		"Event type 2 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type3>::value,
		"Event type 3 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type4>::value,
		"Event type 4 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type5>::value,
		"Event type 5 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );

	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		_method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_method5( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<void( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<void( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<void( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<void( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<void( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<void( const _event_type6&, sxy::event_collector& )> _method6 )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_method6( specialized_event6, _event_collector );
						}
						else
						{
							throw sxy::exception( "Invalid event type!" );
						}
					}
				}
			}
		}
	}


#else


	static_assert( has_get_event_id<_event_type1>::value,
		"Event type 1 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type2>::value,
		"Event type 2 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type3>::value,
		"Event type 3 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type4>::value,
		"Event type 4 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type5>::value,
		"Event type 5 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type6>::value,
		"Event type 6 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );

	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		_method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_method6( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<void( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<void( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<void( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<void( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<void( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<void( const _event_type6&, sxy::event_collector& )> _method6,
		sxy::function<void( const _event_type7&, sxy::event_collector& )> _method7 )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_method6( specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								_method7( specialized_event7, _event_collector );
							}
							else
							{
								throw sxy::exception( "Invalid event type!" );
							}
						}
					}
				}
			}
		}
	}


#else


	static_assert( has_get_event_id<_event_type1>::value,
		"Event type 1 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type2>::value,
		"Event type 2 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type3>::value,
		"Event type 3 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type4>::value,
		"Event type 4 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type5>::value,
		"Event type 5 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type6>::value,
		"Event type 6 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type7>::value,
		"Event type 7 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );

	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		_method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_method6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		_method7( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<void( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<void( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<void( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<void( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<void( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<void( const _event_type6&, sxy::event_collector& )> _method6,
		sxy::function<void( const _event_type7&, sxy::event_collector& )> _method7,
		sxy::function<void( const _event_type8&, sxy::event_collector& )> _method8 )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_method6( specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								_method7( specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									_method8( specialized_event8, _event_collector );
								}
								else
								{
									throw sxy::exception( "Invalid event type!" );
								}
							}
						}
					}
				}
			}
		}
	}


#else


	static_assert( has_get_event_id<_event_type1>::value,
		"Event type 1 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type2>::value,
		"Event type 2 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type3>::value,
		"Event type 3 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type4>::value,
		"Event type 4 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type5>::value,
		"Event type 5 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type6>::value,
		"Event type 6 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type7>::value,
		"Event type 7 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type8>::value,
		"Event type 8 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );

	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		_method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_method6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		_method7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		_method8( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<void( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<void( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<void( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<void( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<void( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<void( const _event_type6&, sxy::event_collector& )> _method6,
		sxy::function<void( const _event_type7&, sxy::event_collector& )> _method7,
		sxy::function<void( const _event_type8&, sxy::event_collector& )> _method8,
		sxy::function<void( const _event_type9&, sxy::event_collector& )> _method9 )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_method6( specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								_method7( specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									_method8( specialized_event8, _event_collector );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										_method9( specialized_event9, _event_collector );
									}
									else
									{
										throw sxy::exception( "Invalid event type!" );
									}
								}
							}
						}
					}
				}
			}
		}
	}


#else


	static_assert( has_get_event_id<_event_type1>::value,
		"Event type 1 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type2>::value,
		"Event type 2 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type3>::value,
		"Event type 3 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type4>::value,
		"Event type 4 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type5>::value,
		"Event type 5 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type6>::value,
		"Event type 6 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type7>::value,
		"Event type 7 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type8>::value,
		"Event type 8 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
	static_assert( has_get_event_id<_event_type9>::value,
		"Event type 9 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );

	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		_method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_method6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		_method7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		_method8( specialized_event, _event_collector );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		_method9( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9, 
	typename _event_type10 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<void( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<void( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<void( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<void( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<void( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<void( const _event_type6&, sxy::event_collector& )> _method6,
		sxy::function<void( const _event_type7&, sxy::event_collector& )> _method7,
		sxy::function<void( const _event_type8&, sxy::event_collector& )> _method8,
		sxy::function<void( const _event_type9&, sxy::event_collector& )> _method9,
		sxy::function<void( const _event_type10&, sxy::event_collector& )> _method10 )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_method6( specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								_method7( specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									_method8( specialized_event8, _event_collector );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										_method9( specialized_event9, _event_collector );
									}
									else
									{
										const _event_type10* specialized_event10 = dynamic_cast< const _event_type10* >( &_event );
										if( specialized_event10 )
										{
											_method10( specialized_event10, _event_collector );
										}
										else
										{
											throw sxy::exception( "Invalid event type!" );
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}


#else


static_assert( has_get_event_id<_event_type1>::value,
	"Event type 1 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
static_assert( has_get_event_id<_event_type2>::value,
	"Event type 2 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
static_assert( has_get_event_id<_event_type3>::value,
	"Event type 3 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
static_assert( has_get_event_id<_event_type4>::value,
	"Event type 4 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
static_assert( has_get_event_id<_event_type5>::value,
	"Event type 5 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
static_assert( has_get_event_id<_event_type6>::value,
	"Event type 6 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
static_assert( has_get_event_id<_event_type7>::value,
	"Event type 7 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
static_assert( has_get_event_id<_event_type8>::value,
	"Event type 8 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
static_assert( has_get_event_id<_event_type9>::value,
	"Event type 9 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );
static_assert( has_get_event_id<_event_type10>::value,
	"Event type 10 does not have the method 'get_event_id'. This is mandatory for using the behavior_caller!" );


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		_method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_method6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		_method7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		_method8( specialized_event, _event_collector );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		_method9( specialized_event, _event_collector );
		break;
	}

	case _event_type10::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type10 >( _event );
		_method10( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


}

#endif
