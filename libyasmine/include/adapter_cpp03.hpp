//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ADAPTER_CPP03_F4E4A216_157F_4271_9E7D_476521F6101E
#define ADAPTER_CPP03_F4E4A216_157F_4271_9E7D_476521F6101E


#ifndef SX_CPP03_BOOST


// Nothing to do... adapter_cpp11 is used.


#else


#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class event_collector;


template<typename T>
sxe::function<void()> adapt( T* _object, void ( T::*_method )( ) )
{
	return( sxe::bind( _method, _object ) );
}


template<typename T>
sxe::function<void()> adapt( T* _object, void ( T::*_method )( ) const )
{
	return( sxe::bind( _method, _object ) );
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type& )> adapt( T* _object, void ( T::*_method )( const _event_type& ) )
{
	return( sxe::bind( _method, _object, sxe::_1 ) );
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type& )> adapt( T* _object, void ( T::*_method )( const _event_type& ) const )
{
	return( sxe::bind( _method, _object, sxe::_1 ) );
}


template<typename T>
sxe::function<void( sxy::event_collector& )> adapt( T* _object, void ( T::*_method )( sxy::event_collector& ) )
{
	return( sxe::bind( _method, _object, sxe::_1 ) );
}


template<typename T>
sxe::function<void( sxy::event_collector& )> adapt( T* _object, void ( T::*_method )( sxy::event_collector& ) const )
{
	return( sxe::bind( _method, _object, sxe::_1 ) );
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type&, sxy::event_collector& )> adapt( T* _object,
	void ( T::*_method )( const _event_type&, sxy::event_collector& ) )
{
	return( sxe::bind( _method, _object, sxe::_1, sxe::_2 ) );
}


template<typename T, typename _event_type>
sxe::function<void( const _event_type&, sxy::event_collector& )> adapt( T* _object,
	void ( T::*_method )( const _event_type&, sxy::event_collector& ) const )
{
	return( sxe::bind( _method, _object, sxe::_1, sxe::_2 ) );
}


sxe::function<void()> adapt_function( void( *_function )( ) );


sxe::function<void( sxy::event_collector& )> adapt_function( void( *_function )( sxy::event_collector& ) );


template< typename _event_type >
sxe::function<void( const _event_type& )> adapt_function( void( *_function )( const _event_type& ) )
{
	return( sxe::bind( _function, sxe::_1 ) );
}


template< typename _event_type >
sxe::function<void( const _event_type&, sxy::event_collector& )> adapt_function(
	void( *_function )( const _event_type&, sxy::event_collector& ) )
{
	return( sxe::bind( _function, sxe::_1, sxe::_2 ) );
}



template<typename T>
sxe::function<bool()> adapt( T* _object, bool ( T::*_method )( ) )
{
	return( sxe::bind( _method, _object ) );
}


template<typename T>
sxe::function<bool()> adapt( T* _object, bool ( T::*_method )( ) const )
{
	return( sxe::bind( _method, _object ) );
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type& )> adapt( T* _object, bool ( T::*_method )( const _event_type& ) )
{
	return( sxe::bind( _method, _object, sxe::_1 ) );
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type& )> adapt( T* _object, bool ( T::*_method )( const _event_type& ) const )
{
	return( sxe::bind( _method, _object, sxe::_1 ) );
}


template<typename T>
sxe::function<bool( sxy::event_collector& )> adapt( T* _object,
	bool ( T::*_method )( sxy::event_collector& ) )
{
	return( sxe::bind( _method, _object, sxe::_1 ) );
}


template<typename T>
sxe::function<bool( sxy::event_collector& )> adapt( T* _object,
	bool ( T::*_method )( sxy::event_collector& ) const )
{
	return( sxe::bind( _method, _object, sxe::_1 ) );
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type&, sxy::event_collector& )> adapt( T* _object,
	bool ( T::*_method )( const _event_type&, sxy::event_collector& ) )
{
	return( sxe::bind( _method, _object, sxe::_1, sxe::_2 ) );
}


template<typename T, typename _event_type>
sxe::function<bool( const _event_type&, sxy::event_collector& )> adapt( T* _object,
	bool ( T::*_method )( const _event_type&, sxy::event_collector& ) const )
{
	return( sxe::bind( _method, _object, sxe::_1, sxe::_2 ) );
}


sxe::function<bool()> adapt_function( bool( *_function )( ) );


sxe::function<bool( sxy::event_collector& )> adapt_function( bool( *_function )( sxy::event_collector& ) );


template< typename _event_type >
sxe::function<bool( const _event_type& )> adapt_function( bool( *_function )( const _event_type& ) )
{
	return( sxe::bind( _function, sxe::_1 ) );
}


template< typename _event_type >
sxe::function<bool( const _event_type&, sxy::event_collector& )> adapt_function(
	bool( *_function )( const _event_type&, sxy::event_collector& ) )
{
	return( sxe::bind( _function, sxe::_1, sxe::_2 ) );
}


}


#endif


#endif
