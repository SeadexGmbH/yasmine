//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ADAPTER_CPP11_630F2EA5_B25B_4585_B496_7C142FF90420
#define ADAPTER_CPP11_630F2EA5_B25B_4585_B496_7C142FF90420


#ifndef SX_CPP03_BOOST


#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class event_collector;


template<typename T>
sxe::function<void()> adapt( T* _object, void ( T::*_method )() )
{
	return( [_object, _method]()
	{
		( _object->*_method )();
	}
	);
}


template<typename T>
sxe::function<void()> adapt( T* _object, void ( T::*_method )( ) const )
{
	return( [_object, _method]()
	{
		( _object->*_method )( );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type& )> adapt( T* _object,
	void ( T::*_method )( const _event_type& ) )
{
	return( [_object, _method]( const _event_type& _event)
	{
		( _object->*_method )( _event );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type&)> adapt( T* _object,
	void ( T::*_method )( const _event_type& ) const )
{
	return( [_object, _method]( const _event_type& _event )
	{
		( _object->*_method )( _event );
	}
	);
}


template<typename T>
sxe::function<void( sxy::event_collector& )> adapt( T* _object,
	void ( T::*_method )( sxy::event_collector& ) )
{
	return( [_object, _method]( sxy::event_collector& _event_collector )
	{
		( _object->*_method )( _event_collector );
	}
	);
}


template<typename T>
sxe::function<void( sxy::event_collector& )> adapt( T* _object,
	void ( T::*_method )( sxy::event_collector& ) const )
{
	return( [_object, _method]( sxy::event_collector& _event_collector )
	{
		( _object->*_method )( _event_collector );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type&, sxy::event_collector& )> adapt( T* _object, 
	void ( T::*_method )( const _event_type&, sxy::event_collector& ) )
{
	return( [_object, _method]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		( _object->*_method )( _event, _event_collector );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type&, sxy::event_collector& )> adapt( T* _object,
	void ( T::*_method )( const _event_type&, sxy::event_collector& ) const )
{
	return( [_object, _method]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		( _object->*_method )( _event, _event_collector );
	}
	);
}


sxe::function<void()> adapt_function( void( *_function )() );


sxe::function<void( sxy::event_collector& )> adapt_function( void( *_function )( sxy::event_collector& ) );


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
sxe::function<bool()> adapt( T* _object, bool ( T::*_method )() )
{
	return( [_object, _method]()
	{
		return( ( _object->*_method )( ) );
	}
	);
}


template<typename T>
sxe::function<bool()> adapt( T* _object, bool ( T::*_method )() const )
{
	return( [_object, _method]()
	{
		return( ( _object->*_method )( ) );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type& )> adapt( T* _object, bool ( T::*_method )( const _event_type& ) )
{
	return( [_object, _method]( const _event_type& _event )
	{
		return( ( _object->*_method )( _event ) );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type& )> adapt( T* _object, bool ( T::*_method )( const _event_type& ) const )
{
	return( [_object, _method]( const _event_type& _event )
	{
		return( ( _object->*_method )( _event ) );
	}
	);
}


template<typename T>
sxe::function<bool( sxy::event_collector& )> adapt( T* _object,
	bool ( T::*_method )( sxy::event_collector& ) )
{
	return( [_object, _method]( sxy::event_collector& _event_collector )
	{
		return ( ( _object->*_method )( _event_collector ) );
	}
	);
}


template<typename T>
sxe::function<bool( sxy::event_collector& )> adapt( T* _object,
	bool ( T::*_method )( sxy::event_collector& ) const )
{
	return( [_object, _method]( sxy::event_collector& _event_collector )
	{
		return( ( _object->*_method )( _event_collector ) );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type&, sxy::event_collector& )> adapt( T* _object,
	bool ( T::*_method )( const _event_type&, sxy::event_collector& ) )
{
	return( [_object, _method]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		return( ( _object->*_method )( _event, _event_collector ) );
	}
	);
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type&, sxy::event_collector& )> adapt( T* _object,
	bool ( T::*_method )( const _event_type&, sxy::event_collector& ) const )
{
	return( [_object, _method]( const _event_type& _event, sxy::event_collector& _event_collector )
	{
		return( ( _object->*_method )( _event, _event_collector ) );
	}
	);
}


sxe::function<bool()> adapt_function( bool( *_function )() );


sxe::function<bool( sxy::event_collector& )> adapt_function( bool( *_function )( sxy::event_collector& ) );


template< typename _event_type >
sxe::function<bool( const _event_type& )> adapt_function( bool( *_function )( const _event_type& ) )
{
	return( [_function]( const _event_type& _event )
	{
		return( ( *_function )( _event ) );
	}
	);
}


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


}


#endif


#endif
