//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef GUARD_CALLER_739F1B72_B584_4F9E_AD3B_56149B96F7BE
#define GUARD_CALLER_739F1B72_B584_4F9E_AD3B_56149B96F7BE


#include "event.hpp"
#include "base.hpp"
#include "caller_adapter.hpp"
#include "event_adjuster.hpp"
#include "event_collector.hpp"
#include "exception.hpp"


namespace sxy
{

bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<bool()> _method );


bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<bool( sxy::event_collector& _event_collector )> _method );


template< typename _event_type >
bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<bool( const _event_type& )> _method )
{
	Y_UNUSED_PARAMETER( _event_collector );
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );
	if( specialized_event )
	{
		enabled = _method( specialized_event );
	}
	else
	{
		throw sxy::exception( "Invalid event type!" );
	}


#else


	auto& specialized_event = sxy::adjust_event_type< _event_type >( _event );
	enabled = _method( specialized_event );



#endif

	return( enabled );
}


template< typename _event_type >
bool guard_caller(	const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<bool( const _event_type&, sxy::event_collector& _event_collector )> _method )
{
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );	
	if( specialized_event )
	{			
		enabled = _method( specialized_event, _event_collector );		
	}
	else
	{
		throw sxy::exception( "Invalid event type!" );
	}


#else
	

	auto& specialized_event = sxy::adjust_event_type< _event_type >( _event );		
	enabled = _method( specialized_event, _event_collector );
	


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2 >
bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<bool( const _event_type1&, sxy::event_collector& )> _method1,
	sxy::function<bool( const _event_type2&, sxy::event_collector& )> _method2 )
{
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _method2( specialized_event2, _event_collector );
		}
		else
		{
			throw sxy::exception( "Invalid event type!" );
		}
	}


#else


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );		
		enabled = _method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		const auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );		
		enabled = _method2( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3 >
bool guard_caller(	const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<bool( const _event_type1&, sxy::event_collector& )> _method1,
	sxy::function<bool( const _event_type2&, sxy::event_collector& )> _method2,
	sxy::function<bool( const _event_type3&, sxy::event_collector& )> _method3 )
{	
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _method3( specialized_event3, _event_collector );
			}
			else
			{
				throw sxy::exception( "Invalid event type!" );
			}
		}
	}


#else


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _method3( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4 >
bool guard_caller(	const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<bool( const _event_type1&, sxy::event_collector& )> _method1,
	sxy::function<bool( const _event_type2&, sxy::event_collector& )> _method2,
	sxy::function<bool( const _event_type3&, sxy::event_collector& )> _method3,
	sxy::function<bool( const _event_type4&, sxy::event_collector& )> _method4 )
{
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _method4( specialized_event4, _event_collector );
				}
				else
				{
					throw sxy::exception( "Invalid event type!" );
				}
			}
		}
	}


#else


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _method4( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
					typename _event_type5 >
bool guard_caller(	const sxy::event& _event, sxy::event_collector& _event_collector,
	sxy::function<bool( const _event_type1&, sxy::event_collector& )> _method1,
	sxy::function<bool( const _event_type2&, sxy::event_collector& )> _method2,
	sxy::function<bool( const _event_type3&, sxy::event_collector& )> _method3,
	sxy::function<bool( const _event_type4&, sxy::event_collector& )> _method4,
	sxy::function<bool( const _event_type5&, sxy::event_collector& )> _method5 )
{
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _method5( specialized_event5, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _method5( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<bool( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<bool( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<bool( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<bool( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<bool( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<bool( const _event_type6&, sxy::event_collector& )> _method6 )
{
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _method6( specialized_event6, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _method6( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<bool( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<bool( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<bool( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<bool( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<bool( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<bool( const _event_type6&, sxy::event_collector& )> _method6,
		sxy::function<bool( const _event_type7&, sxy::event_collector& )> _method7 )
{
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _method6( specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								enabled = _method7( specialized_event7, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _method6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		enabled = _method7( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<bool( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<bool( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<bool( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<bool( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<bool( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<bool( const _event_type6&, sxy::event_collector& )> _method6,
		sxy::function<bool( const _event_type7&, sxy::event_collector& )> _method7,
		sxy::function<bool( const _event_type8&, sxy::event_collector& )> _method8 )
{
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _method6( specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								enabled = _method7( specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									enabled = _method8( specialized_event8, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _method6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		enabled = _method7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		enabled = _method8( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<bool( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<bool( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<bool( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<bool( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<bool( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<bool( const _event_type6&, sxy::event_collector& )> _method6,
		sxy::function<bool( const _event_type7&, sxy::event_collector& )> _method7,
		sxy::function<bool( const _event_type8&, sxy::event_collector& )> _method8,
		sxy::function<bool( const _event_type9&, sxy::event_collector& )> _method9 )
{
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _method6( specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								enabled = _method7( specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									enabled = _method8( specialized_event8, _event_collector );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										enabled = _method9( specialized_event9, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _method6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		enabled = _method7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		enabled = _method8( specialized_event, _event_collector );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		enabled = _method9( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9, 
	typename _event_type10 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		sxy::function<bool( const _event_type1&, sxy::event_collector& )> _method1,
		sxy::function<bool( const _event_type2&, sxy::event_collector& )> _method2,
		sxy::function<bool( const _event_type3&, sxy::event_collector& )> _method3,
		sxy::function<bool( const _event_type4&, sxy::event_collector& )> _method4,
		sxy::function<bool( const _event_type5&, sxy::event_collector& )> _method5,
		sxy::function<bool( const _event_type6&, sxy::event_collector& )> _method6,
		sxy::function<bool( const _event_type7&, sxy::event_collector& )> _method7,
		sxy::function<bool( const _event_type8&, sxy::event_collector& )> _method8,
		sxy::function<bool( const _event_type9&, sxy::event_collector& )> _method9,
		sxy::function<bool( const _event_type10&, sxy::event_collector& )> _method10 )
{
	bool enabled = false;

#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _method1( specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _method2( specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _method3( specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _method4( specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _method5( specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _method6( specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								enabled = _method7( specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									enabled = _method8( specialized_event8, _event_collector );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										enabled = _method9( specialized_event9, _event_collector );
									}
									else
									{
										const _event_type10* specialized_event10 = dynamic_cast< const _event_type10* >( &_event );
										if( specialized_event10 )
										{
											enabled = _method10( specialized_event10, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _method1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _method2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _method3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _method4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _method5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _method6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		enabled = _method7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		enabled = _method8( specialized_event, _event_collector );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		enabled = _method9( specialized_event, _event_collector );
		break;
	}

	case _event_type10::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type10 >( _event );
		enabled = _method10( specialized_event, _event_collector );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


}

#endif
