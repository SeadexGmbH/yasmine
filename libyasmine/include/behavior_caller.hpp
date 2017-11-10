//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef BEHAVIOR_CALLER_B33A4070_B042_4171_8DC5_9E5AE0B2DDD5
#define BEHAVIOR_CALLER_B33A4070_B042_4171_8DC5_9E5AE0B2DDD5


#include "essentials/base.hpp"
#include "essentials/exception.hpp"

#include "event.hpp"
#include "adapter.hpp"
#include "caller_helper.hpp"
#include "event_adjuster.hpp"
#include "event_collector.hpp"


namespace sxy
{


void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void()>& _function );


void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void( event_collector& )>& _function );


template< typename _event_type >
void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void( const _event_type& )>& _function )
{
	SX_UNUSED_PARAMETER( _event_collector );

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );
	if( specialized_event )
	{
		_function( *specialized_event );
	}
	else
	{
		throw sxe::exception( "Invalid event type!" );
	}


#else


	auto& specialized_event = sxy::adjust_event_type< _event_type >( _event );
	_function( specialized_event );


#endif
}


template< typename _event_type >
void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void( const _event_type&, sxy::event_collector& _event_collector )>& _function )
{
#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );
	if( specialized_event )
	{
		_function( *specialized_event, _event_collector );
	}
	else
	{
		throw sxe::exception( "Invalid event type!" );
	}


#else


	auto& specialized_event = sxy::adjust_event_type< _event_type >( _event );	
	_function( specialized_event, _event_collector );


#endif
}


template< typename _event_type1, typename _event_type2 >
void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2 )
{

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_function2( *specialized_event2, _event_collector );
		}
		else
		{
			throw sxe::exception( "Invalid event type!" );
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
		_function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		const auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );		
		_function2( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3 >
void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3 )
{
#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_function3( *specialized_event3, _event_collector );
			}
			else
			{
				throw sxe::exception( "Invalid event type!" );
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
		_function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_function3( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4 >
void behavior_caller(	const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4 )
{
#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_function4( *specialized_event4, _event_collector );
				}
				else
				{
					throw sxe::exception( "Invalid event type!" );
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
		_function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_function4( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
					typename _event_type5 >
void behavior_caller(	const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5 )
{
#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_function5( *specialized_event5, _event_collector );
					}
					else
					{
						throw sxe::exception( "Invalid event type!" );
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
		_function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_function5( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6 )
{
#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_function6( *specialized_event6, _event_collector );
						}
						else
						{
							throw sxe::exception( "Invalid event type!" );
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
		_function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_function6( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6,
		const sxe::function<void( const _event_type7&, sxy::event_collector& )>& _function7 )
{
#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_function6( *specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								_function7( *specialized_event7, _event_collector );
							}
							else
							{
								throw sxe::exception( "Invalid event type!" );
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
		_function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_function6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		_function7( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6,
		const sxe::function<void( const _event_type7&, sxy::event_collector& )>& _function7,
		const sxe::function<void( const _event_type8&, sxy::event_collector& )>& _function8 )
{
#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_function6( *specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								_function7( *specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									_function8( *specialized_event8, _event_collector );
								}
								else
								{
									throw sxe::exception( "Invalid event type!" );
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
		_function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_function6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		_function7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		_function8( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6,
		const sxe::function<void( const _event_type7&, sxy::event_collector& )>& _function7,
		const sxe::function<void( const _event_type8&, sxy::event_collector& )>& _function8,
		const sxe::function<void( const _event_type9&, sxy::event_collector& )>& _function9 )
{
#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_function6( *specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								_function7( *specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									_function8( *specialized_event8, _event_collector );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										_function9( *specialized_event9, _event_collector );
									}
									else
									{
										throw sxe::exception( "Invalid event type!" );
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
		_function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_function6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		_function7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		_function8( specialized_event, _event_collector );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		_function9( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9, 
	typename _event_type10 >
	void behavior_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6,
		const sxe::function<void( const _event_type7&, sxy::event_collector& )>& _function7,
		const sxe::function<void( const _event_type8&, sxy::event_collector& )>& _function8,
		const sxe::function<void( const _event_type9&, sxy::event_collector& )>& _function9,
		const sxe::function<void( const _event_type10&, sxy::event_collector& )>& _function10 )
{
#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		_function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			_function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				_function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					_function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						_function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							_function6( *specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								_function7( *specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									_function8( *specialized_event8, _event_collector );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										_function9( *specialized_event9, _event_collector );
									}
									else
									{
										const _event_type10* specialized_event10 = dynamic_cast< const _event_type10* >( &_event );
										if( specialized_event10 )
										{
											_function10( *specialized_event10, _event_collector );
										}
										else
										{
											throw sxe::exception( "Invalid event type!" );
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
		_function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		_function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		_function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		_function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		_function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		_function6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		_function7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		_function8( specialized_event, _event_collector );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		_function9( specialized_event, _event_collector );
		break;
	}

	case _event_type10::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type10 >( _event );
		_function10( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif
}


}

#endif
