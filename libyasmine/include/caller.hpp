//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CALLER_8B0F592E_A1FC_4089_9145_BB3BF453FE5F
#define CALLER_8B0F592E_A1FC_4089_9145_BB3BF453FE5F


#include "event.hpp"
#include "base.hpp"


namespace sxy
{


template<typename _event_type>
const _event_type& adjust_event_type(const event& _event)
{
#ifdef NDEBUG
	return( static_cast<const _event_type&>( _event ) );
#else
	const _event_type* const specialized_event = dynamic_cast< const _event_type* const >( &_event );
	const std::string message = "Event " + _event.get_name() + " is not of given type.";
	if (!specialized_event)
	{			
		Y_LOG( sxy::log_level::LL_ASSERT, message );
		Y_ASSERT_NO_LOG( false, "Invalid event type!" );
	}
	return( *specialized_event );
#endif
}


template< typename _class, typename _event_type >
void method_caller(	const sxy::event& _event,	_class* _this, void ( _class::* _method )( const _event_type& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );	
	if( specialized_event )
	{
		if( _event.get_id() == specialized_event->get_id() )
		{
			( _this->*_method )( *specialized_event );
		}
	}
	else
	{
		throw sxy::exception( "Invalid event type!" );
	}


#else


	switch( _event.get_id() )
	{
	case _event_type::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type >( _event );
		( _this->*_method )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _class, typename _event_type1, typename _event_type2 >
void method_caller( const sxy::event& _event, _class* _this,
	void ( _class::* _method1 )( const _event_type1& ),	void ( _class::* _method2 )( const _event_type2& ) )
{		
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( _this->*_method1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( _this->*_method2 )( *specialized_event2 );
		}
		else
		{
			throw sxy::exception("Invalid event type!");
		}
	}


#else
		

	switch( _event.get_id() )
	{
	case _event_type1::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >(_event);
		( _this->*_method1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >(_event);
		( _this->*_method2 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _class, typename _event_type1, typename _event_type2, typename _event_type3 >
void method_caller(	const sxy::event& _event,	_class* _this, void ( _class::* _method1 )( const _event_type1& ),
	void ( _class::* _method2 )( const _event_type2& ), void ( _class::* _method3 )( const _event_type3& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( _this->*_method1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( _this->*_method2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( _this->*_method3 )( *specialized_event3 );
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
		( _this->*_method1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( _this->*_method2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( _this->*_method3 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _class, typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4 >
void method_caller(	const sxy::event& _event,	_class* _this, void ( _class::* _method1 )( const _event_type1& ),
	void ( _class::* _method2 )( const _event_type2& ),	void ( _class::* _method3 )( const _event_type3& ),
	void ( _class::* _method4 )( const _event_type4& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( _this->*_method1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( _this->*_method2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( _this->*_method3 )( *specialized_event3 );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					( _this->*_method4 )( *specialized_event4 );
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
		( _this->*_method1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( _this->*_method2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( _this->*_method3 )( specialized_event );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		( _this->*_method4 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _class, typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
					typename _event_type5 >
void method_caller(	const sxy::event& _event,	_class* _this, void ( _class::* _method1 )( const _event_type1& ),
	void ( _class::* _method2 )( const _event_type2& ),	void ( _class::* _method3 )( const _event_type3& ),
	void ( _class::* _method4 )( const _event_type4& ),	void ( _class::* _method5 )( const _event_type5& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( _this->*_method1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( _this->*_method2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( _this->*_method3 )( *specialized_event3 );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					( _this->*_method4 )( *specialized_event4 );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						( _this->*_method5 )( *specialized_event5 );
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
		( _this->*_method1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( _this->*_method2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( _this->*_method3 )( specialized_event );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		( _this->*_method4 )( specialized_event );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		( _this->*_method5 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type >
void function_caller( const sxy::event& _event,	void ( *_function )( const _event_type& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type* specialized_event = dynamic_cast< const _event_type* >( &_event );
	if( specialized_event )
	{
		( *_function )( *specialized_event );
	}
	else
	{
		throw sxy::exception( "Invalid event type!" );
	}


#else


	switch( _event.get_id() )
	{
	case _event_type::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type >(_event);
		( *_function )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2 >
void function_caller(	const sxy::event& _event,	void ( *_function_1 )( const _event_type1& ),
	void ( *_function_2 )( const _event_type2& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( *_function_1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( *_function_2 )( *specialized_event2 );
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
		auto& specialized_event = sxy::adjust_event_type< _event_type1 >(_event);
		( *_function_1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >(_event);
		( *_function_2 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3 >
void function_caller(	const sxy::event& _event,	void ( *_function_1 )( const _event_type1& ),
	void ( * _function_2 )( const _event_type2& ), void ( *_function_3 )( const _event_type3& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( *_function_1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( *_function_2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( *_function_3 )( *specialized_event3 );
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
		( *_function_1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( *_function_2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( *_function_3 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4 >
void function_caller(	const sxy::event& _event,	void ( *_function_1 )( const _event_type1& ),
	void ( * _function_2 )( const _event_type2& ), void ( *_function_3 )( const _event_type3& ),
	void ( * _function_4 )( const _event_type4& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( *_function_1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( *_function_2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( *_function_3 )( *specialized_event3 );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					( *_function_4 )( *specialized_event4 );
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
		( *_function_1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( *_function_2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( *_function_3 )( specialized_event );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		( *_function_4 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
					typename _event_type5 >
void function_caller(	const sxy::event& _event,	void ( *_function_1 )( const _event_type1& ), 
	void ( *_function_2 )( const _event_type2& ), void ( *_function_3 )( const _event_type3& ), 
	void ( *_function_4 )( const _event_type4& ), void ( *_function_5 )( const _event_type5& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( *_function_1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( *_function_2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( *_function_3 )( *specialized_event3 );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					( *_function_4 )( *specialized_event4 );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						( *_function_5 )( *specialized_event5 );
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
		( *_function_1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( *_function_2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( *_function_3 )( specialized_event );
		break;
	}

	case _event_type4::get_event_id():
	{		
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		( *_function_4 )( specialized_event );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		( *_function_5 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6 >
	void function_caller( const sxy::event& _event, void( *_function_1 )( const _event_type1& ),
		void( *_function_2 )( const _event_type2& ), void( *_function_3 )( const _event_type3& ),
		void( *_function_4 )( const _event_type4& ), void( *_function_5 )( const _event_type5& ),
		void( *_function_6 )( const _event_type6& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( *_function_1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( *_function_2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( *_function_3 )( *specialized_event3 );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					( *_function_4 )( *specialized_event4 );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						( *_function_5 )( *specialized_event5 );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							( *_function_6 )( *specialized_event6 );
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
		( *_function_1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( *_function_2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( *_function_3 )( specialized_event );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		( *_function_4 )( specialized_event );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		( *_function_5 )( specialized_event );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		( *_function_6 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7 >
	void function_caller( const sxy::event& _event, void( *_function_1 )( const _event_type1& ),
		void( *_function_2 )( const _event_type2& ), void( *_function_3 )( const _event_type3& ),
		void( *_function_4 )( const _event_type4& ), void( *_function_5 )( const _event_type5& ),
		void( *_function_6 )( const _event_type6& ), void( *_function_7 )( const _event_type7& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( *_function_1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( *_function_2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( *_function_3 )( *specialized_event3 );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					( *_function_4 )( *specialized_event4 );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						( *_function_5 )( *specialized_event5 );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							( *_function_6 )( *specialized_event6 );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								( *_function_7 )( *specialized_event7 );
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
		( *_function_1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( *_function_2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( *_function_3 )( specialized_event );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		( *_function_4 )( specialized_event );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		( *_function_5 )( specialized_event );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		( *_function_6 )( specialized_event );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		( *_function_7 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8 >
	void function_caller( const sxy::event& _event, void( *_function_1 )( const _event_type1& ),
		void( *_function_2 )( const _event_type2& ), void( *_function_3 )( const _event_type3& ),
		void( *_function_4 )( const _event_type4& ), void( *_function_5 )( const _event_type5& ),
		void( *_function_6 )( const _event_type6& ), void( *_function_7 )( const _event_type7& ),
		void( *_function_8 )( const _event_type8& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( *_function_1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( *_function_2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( *_function_3 )( *specialized_event3 );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					( *_function_4 )( *specialized_event4 );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						( *_function_5 )( *specialized_event5 );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							( *_function_6 )( *specialized_event6 );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								( *_function_7 )( *specialized_event7 );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									( *_function_8 )( *specialized_event8 );
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
		( *_function_1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( *_function_2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( *_function_3 )( specialized_event );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		( *_function_4 )( specialized_event );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		( *_function_5 )( specialized_event );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		( *_function_6 )( specialized_event );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		( *_function_7 )( specialized_event );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		( *_function_8 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, 
	typename _event_type9 >
	void function_caller( const sxy::event& _event, void( *_function_1 )( const _event_type1& ),
		void( *_function_2 )( const _event_type2& ), void( *_function_3 )( const _event_type3& ),
		void( *_function_4 )( const _event_type4& ), void( *_function_5 )( const _event_type5& ),
		void( *_function_6 )( const _event_type6& ), void( *_function_7 )( const _event_type7& ),
		void( *_function_8 )( const _event_type8& ), void( *_function_9 )( const _event_type9& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( *_function_1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( *_function_2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( *_function_3 )( *specialized_event3 );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					( *_function_4 )( *specialized_event4 );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						( *_function_5 )( *specialized_event5 );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							( *_function_6 )( *specialized_event6 );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								( *_function_7 )( *specialized_event7 );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									( *_function_8 )( *specialized_event8 );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										( *_function_9 )( *specialized_event9 );
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
		( *_function_1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( *_function_2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( *_function_3 )( specialized_event );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		( *_function_4 )( specialized_event );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		( *_function_5 )( specialized_event );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		( *_function_6 )( specialized_event );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		( *_function_7 )( specialized_event );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		( *_function_8 )( specialized_event );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		( *_function_9 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}



template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4,
	typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8,
	typename _event_type9, typename _event_type10 >
	void function_caller( const sxy::event& _event, void( *_function_1 )( const _event_type1& ),
		void( *_function_2 )( const _event_type2& ), void( *_function_3 )( const _event_type3& ),
		void( *_function_4 )( const _event_type4& ), void( *_function_5 )( const _event_type5& ),
		void( *_function_6 )( const _event_type6& ), void( *_function_7 )( const _event_type7& ),
		void( *_function_8 )( const _event_type8& ), void( *_function_9 )( const _event_type9& ),
		void( *_function_10 )( const _event_type10& ) )
{
#if defined( Y_CPP03_BOOST ) || ( defined(_MSC_VER) && _MSC_VER <=1800 )


	const _event_type1* specialized_event = dynamic_cast< const _event_type1* >( &_event );
	if( specialized_event )
	{
		( *_function_1 )( *specialized_event );
	}
	else
	{
		const _event_type2* specialized_event2 = dynamic_cast< const _event_type2* >( &_event );
		if( specialized_event2 )
		{
			( *_function_2 )( *specialized_event2 );
		}
		else
		{
			const _event_type3* specialized_event3 = dynamic_cast< const _event_type3* >( &_event );
			if( specialized_event3 )
			{
				( *_function_3 )( *specialized_event3 );
			}
			else
			{
				const _event_type4* specialized_event4 = dynamic_cast< const _event_type4* >( &_event );
				if( specialized_event4 )
				{
					( *_function_4 )( *specialized_event4 );
				}
				else
				{
					const _event_type5* specialized_event5 = dynamic_cast< const _event_type5* >( &_event );
					if( specialized_event5 )
					{
						( *_function_5 )( *specialized_event5 );
					}
					else
					{
						const _event_type6* specialized_event6 = dynamic_cast< const _event_type6* >( &_event );
						if( specialized_event6 )
						{
							( *_function_6 )( *specialized_event6 );
						}
						else
						{
							const _event_type7* specialized_event7 = dynamic_cast< const _event_type7* >( &_event );
							if( specialized_event7 )
							{
								( *_function_7 )( *specialized_event7 );
							}
							else
							{
								const _event_type8* specialized_event8 = dynamic_cast< const _event_type8* >( &_event );
								if( specialized_event8 )
								{
									( *_function_8 )( *specialized_event8 );
								}
								else
								{
									const _event_type9* specialized_event9 = dynamic_cast< const _event_type9* >( &_event );
									if( specialized_event9 )
									{
										( *_function_9 )( *specialized_event9 );
									}
									else
									{
										const _event_type10* specialized_event10 = dynamic_cast< const _event_type10* >( &_event );
										if( specialized_event10 )
										{
											( *_function_10 )( *specialized_event10 );
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
		( *_function_1 )( specialized_event );
		break;
	}

	case _event_type2::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type2 >( _event );
		( *_function_2 )( specialized_event );
		break;
	}

	case _event_type3::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type3 >( _event );
		( *_function_3 )( specialized_event );
		break;
	}

	case _event_type4::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type4 >( _event );
		( *_function_4 )( specialized_event );
		break;
	}

	case _event_type5::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type5 >( _event );
		( *_function_5 )( specialized_event );
		break;
	}

	case _event_type6::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type6 >( _event );
		( *_function_6 )( specialized_event );
		break;
	}

	case _event_type7::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type7 >( _event );
		( *_function_7 )( specialized_event );
		break;
	}

	case _event_type8::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type8 >( _event );
		( *_function_8 )( specialized_event );
		break;
	}

	case _event_type9::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type9 >( _event );
		( *_function_9 )( specialized_event );
		break;
	}

	case _event_type10::get_event_id():
	{
		auto& specialized_event = sxy::adjust_event_type< _event_type10 >( _event );
		( *_function_10 )( specialized_event );
		break;
	}

	default:
		Y_ASSERT( false, "Invalid event type!" );
	}


#endif
}

					
}


#endif
