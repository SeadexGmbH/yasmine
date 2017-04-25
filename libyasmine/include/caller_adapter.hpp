//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CALLER_ADAPTER_031DC27E_9A5F_4D54_A107_310F31977E26
#define CALLER_ADAPTER_031DC27E_9A5F_4D54_A107_310F31977E26

#ifndef SX_CPP03_BOOST

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class event_collector;


}


template<typename T>
sxe::function<void()> adapt( T* _class, void ( T::*method )() )
{
	return( [_class, method]()
	{				
		( _class->*method )();
	}
	);
}


template<typename T>
sxe::function<void()> adapt( T* _class, void ( T::*method )( ) const )
{
	return( [_class, method]()
	{
		( _class->*method )( );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type& )> adapt( T* _class,
	void ( T::*method )( const _event_type& ) )
{
	return( [_class, method]( const _event_type& _event)
	{		
		( _class->*method )( _event );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type&)> adapt( T* _class,
	void ( T::*method )( const _event_type& ) const )
{
	return( [_class, method]( const _event_type& _event )
	{		
		( _class->*method )( _event );
	}
	);
}


template<typename T>
sxe::function<void( sxy::event_collector& )> adapt( T* _class,
	void ( T::*method )( sxy::event_collector& ) )
{
	return( [_class, method]( sxy::event_collector& _event_collector )
	{		
		( _class->*method )( _event_collector );
	}
	);
}


template<typename T>
sxe::function<void( sxy::event_collector& )> adapt( T* _class,
	void ( T::*method )( sxy::event_collector& ) const )
{
	return( [_class, method]( sxy::event_collector& _event_collector )
	{		
		( _class->*method )( _event_collector );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type&, sxy::event_collector& )> adapt( T* _class, 
	void ( T::*method )( const _event_type&, sxy::event_collector& ) )
{
	return( [_class, method]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		( _class->*method )( _event, _event_collector );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type&, sxy::event_collector& )> adapt( T* _class,
	void ( T::*method )( const _event_type&, sxy::event_collector& ) const )
{
	return( [_class, method]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		( _class->*method )( _event, _event_collector );
	}
	);
}


sxe::function<void()> adapt_function( void( *_function )() );


template< typename _event_type >
sxe::function<void( const _event_type& )> adapt_function( 
	void ( *_function )( const _event_type& ) )
{
	return( [ _function ]( const _event_type& _event )
	{		
		( *_function )( _event );
	}
	);
}


sxe::function<void( sxy::event_collector& )> adapt_function( void( *_function )( sxy::event_collector& ) );


template< typename _event_type >
sxe::function<void( const _event_type&, sxy::event_collector& )> adapt_function( 
	void( *_function )( const _event_type&, sxy::event_collector& ) )
{
	return( [ _function ]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		( *_function )( _event, _event_collector );
	}
	);
}



template<typename T>
sxe::function<bool()> adapt( T* _class, bool ( T::*method )() )
{
	return( [_class, method]()
	{
		return( ( _class->*method )( ) );
	}
	);
}


template<typename T>
sxe::function<bool()> adapt( T* _class,	bool ( T::*method )() const )
{
	return( [_class, method]()
	{		
		return( ( _class->*method )( ) );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type& )> adapt( T* _class,	bool ( T::*method )( const _event_type& ) )
{
	return( [_class, method]( const _event_type& _event )
	{		
		return( ( _class->*method )( _event ) );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type& )> adapt( T* _class,	bool ( T::*method )( const _event_type& ) const )
{
	return( [_class, method]( const _event_type& _event )
	{		
		return( ( _class->*method )( _event ) );
	}
	);
}


template<typename T>
sxe::function<bool( sxy::event_collector& )> adapt( T* _class,
	bool ( T::*method )( sxy::event_collector& ) )
{
	return( [_class, method]( sxy::event_collector& _event_collector )
	{		
		return ( ( _class->*method )( _event_collector ) );
	}
	);
}


template<typename T>
sxe::function<bool( sxy::event_collector& )> adapt( T* _class,
	bool ( T::*method )( sxy::event_collector& ) const )
{
	return( [_class, method]( sxy::event_collector& _event_collector )
	{
		return( ( _class->*method )( _event_collector ) );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type&, sxy::event_collector& )> adapt( T* _class,
	bool ( T::*method )( const _event_type&, sxy::event_collector& ) )
{
	return( [_class, method]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		return( ( _class->*method )( _event, _event_collector ) );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type&, sxy::event_collector& )> adapt( T* _class,
	bool ( T::*method )( const _event_type&, sxy::event_collector& ) const )
{
	return( [_class, method]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		return( ( _class->*method )( _event, _event_collector ) );
	}
	);
}


sxe::function<bool()> adapt_function( bool( *_function )() );


template< typename _event_type >
sxe::function<bool( const _event_type& )> adapt_function( bool( *_function )( const _event_type& ) )
{
	return( [_function]( const _event_type& _event )
	{
		return( ( *_function )( _event ) );
	}
	);
}


sxe::function<bool( sxy::event_collector& )> adapt_function( bool( *_function )( sxy::event_collector& ) );


template< typename _event_type >
sxe::function<bool( const _event_type&, sxy::event_collector& )> adapt_function(
	bool( *_function )( const _event_type&, sxy::event_collector& ) )
{
	return( [_function]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		return( ( *_function )( _event, _event_collector ) );
	}
	);
}


#endif

#endif
