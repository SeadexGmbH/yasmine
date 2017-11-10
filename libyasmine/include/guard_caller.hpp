//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef GUARD_CALLER_739F1B72_B584_4F9E_AD3B_56149B96F7BE
#define GUARD_CALLER_739F1B72_B584_4F9E_AD3B_56149B96F7BE


#include "essentials/base.hpp"
#include "essentials/exception.hpp"

#include "event.hpp"
#include "adapter.hpp"
#include "event_adjuster.hpp"
#include "event_collector.hpp"


namespace sxy
{

bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool()>& _function );


bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool( sxy::event_collector& _event_collector )>& _function );


template< typename _event_type >
bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool( const _event_type& )>& _function )
{
	SX_UNUSED_PARAMETER( _event_collector );
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );
	if( specialized_event )
	{
		enabled = _function( *specialized_event );
	}
	else
	{
		throw sxe::exception( "Invalid event type!" );
	}


#else


	auto& specialized_event = sxy::adjust_event_type< _event_type >( _event );
	enabled = _function( specialized_event );



#endif

	return( enabled );
}


template< typename _event_type >
bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool( const _event_type&, sxy::event_collector& _event_collector )>& _function )
{
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );	
	if( specialized_event )
	{
		enabled = _function( *specialized_event, _event_collector );
	}
	else
	{
		throw sxe::exception( "Invalid event type!" );
	}


#else
	

	auto& specialized_event = sxy::adjust_event_type< _event_type >( _event );		
	enabled = _function( specialized_event, _event_collector );
	


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2 >
bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2 )
{
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _function2( *specialized_event2, _event_collector );
		}
		else
		{
			throw sxe::exception( "Invalid event type!" );
		}
	}


#else


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );		
		enabled = _function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		const auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );		
		enabled = _function2( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3 >
bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3 )
{	
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _function3( *specialized_event3, _event_collector );
			}
			else
			{
				throw sxe::exception( "Invalid event type!" );
			}
		}
	}


#else


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _function3( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4 >
bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4 )
{
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _function4( *specialized_event4, _event_collector );
				}
				else
				{
					throw sxe::exception( "Invalid event type!" );
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
		enabled = _function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _function4( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5 >
bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5 )
{
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _function5( *specialized_event5, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _function5( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6 )
{
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _function6( *specialized_event6, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _function6( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6,
		const sxe::function<bool( const _event_type7&, sxy::event_collector& )>& _function7 )
{
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _function6( *specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								enabled = _function7( *specialized_event7, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _function6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		enabled = _function7( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6,
		const sxe::function<bool( const _event_type7&, sxy::event_collector& )>& _function7,
		const sxe::function<bool( const _event_type8&, sxy::event_collector& )>& _function8 )
{
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _function6( *specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								enabled = _function7( *specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									enabled = _function8( *specialized_event8, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _function6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		enabled = _function7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		enabled = _function8( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6,
		const sxe::function<bool( const _event_type7&, sxy::event_collector& )>& _function7,
		const sxe::function<bool( const _event_type8&, sxy::event_collector& )>& _function8,
		const sxe::function<bool( const _event_type9&, sxy::event_collector& )>& _function9 )
{
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _function6( *specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								enabled = _function7( *specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									enabled = _function8( *specialized_event8, _event_collector );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										enabled = _function9( *specialized_event9, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _function6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		enabled = _function7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		enabled = _function8( specialized_event, _event_collector );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		enabled = _function9( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9, 
	typename _event_type10 >
	bool guard_caller( const sxy::event& _event, sxy::event_collector& _event_collector,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6,
		const sxe::function<bool( const _event_type7&, sxy::event_collector& )>& _function7,
		const sxe::function<bool( const _event_type8&, sxy::event_collector& )>& _function8,
		const sxe::function<bool( const _event_type9&, sxy::event_collector& )>& _function9,
		const sxe::function<bool( const _event_type10&, sxy::event_collector& )>& _function10 )
{
	bool enabled = false;

#if defined( SX_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		enabled = _function1( *specialized_event, _event_collector );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			enabled = _function2( *specialized_event2, _event_collector );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				enabled = _function3( *specialized_event3, _event_collector );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					enabled = _function4( *specialized_event4, _event_collector );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						enabled = _function5( *specialized_event5, _event_collector );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							enabled = _function6( *specialized_event6, _event_collector );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								enabled = _function7( *specialized_event7, _event_collector );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									enabled = _function8( *specialized_event8, _event_collector );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										enabled = _function9( *specialized_event9, _event_collector );
									}
									else
									{
										const _event_type10* specialized_event10 = dynamic_cast< const _event_type10* >( &_event );
										if( specialized_event10 )
										{
											enabled = _function10( *specialized_event10, _event_collector );
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


	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >( _event );
		enabled = _function1( specialized_event, _event_collector );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		enabled = _function2( specialized_event, _event_collector );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		enabled = _function3( specialized_event, _event_collector );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		enabled = _function4( specialized_event, _event_collector );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		enabled = _function5( specialized_event, _event_collector );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		enabled = _function6( specialized_event, _event_collector );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		enabled = _function7( specialized_event, _event_collector );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		enabled = _function8( specialized_event, _event_collector );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		enabled = _function9( specialized_event, _event_collector );
		break;
	}

	case _event_type10::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type10 >( _event );
		enabled = _function10( specialized_event, _event_collector );
		break;
	}

	default:
		SX_ASSERT( false, "Invalid event type!" );
	}


#endif

	return( enabled );
}


}

#endif
