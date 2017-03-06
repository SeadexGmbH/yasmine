//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPATIBILITY_63A35CFD_26BC_42BE_9F09_D559349FFE63
#define COMPATIBILITY_63A35CFD_26BC_42BE_9F09_D559349FFE63


#ifdef Y_CPP03_BOOST
#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4456 )
#pragma warning( disable : 4996 )
#endif


#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/move/unique_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/cstdint.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/type_traits.hpp>
#include <boost/random/random_device.hpp>

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#else
#include <memory>
#include <functional>
#include <cstdint>
#include <type_traits>
#include <random>
#endif
				

namespace sxy
{


#ifdef Y_CPP03_BOOST // C++03 compatibility

	#define Y_OVERRIDE
	#define Y_FINAL
	#define Y_DELETE
	#define Y_NULLPTR NULL

	#define Y_FOR(_variable, _container)  BOOST_FOREACH( _variable, _container )

	#define Y_CONSTEXPR const

	#define Y_NOEXCEPT throw()


	using boost::shared_ptr;
	#define Y_UNIQUE_PTR shared_ptr

	#define Y_MAKE_SHARED boost::make_shared
	#define Y_MAKE_UNIQUE boost::make_shared

	template<typename _type>
	_type& move(_type& _t)
	{
		return( _t );
	}

	using boost::int8_t;
	using boost::int16_t;
	using boost::uint8_t;
	using boost::uint16_t;
	using boost::uint32_t;
	using boost::int64_t;

	using boost::bind;
	using boost::ref;
	using boost::cref;
	using boost::placeholders::_1;
	using boost::placeholders::_2;

	using boost::function;

	using boost::remove_reference;
	using boost::remove_const;

	using boost::random_device;	


#else // C++11 compatibility

	#ifdef Y_NO_STD_MAKE_UNIQUE

		template< typename t, typename ... args >
		std::unique_ptr< t > make_unique(args&& ... _args) {
			return( std::unique_ptr< t >(new t(std::forward< args >(_args)...)) );
		}

	#else

		using std::make_unique;

	#endif

	#define Y_OVERRIDE override
	#define Y_FINAL final
	#define Y_DELETE  = delete
	#define Y_NULLPTR nullptr

	#define Y_FOR(_variable, _container) for( _variable : _container )

	#ifdef _MSC_VER
		#if _MSC_VER <= 1800
			#define Y_CONSTEXPR const
		#endif
	#endif

	#ifndef Y_CONSTEXPR
		#define Y_CONSTEXPR constexpr
	#endif

#ifdef _MSC_VER
	#if _MSC_VER <= 1800
		#define Y_NOEXCEPT throw()
	#else
		#define Y_NOEXCEPT noexcept
	#endif
#else
	#define Y_NOEXCEPT noexcept
#endif

	using std::shared_ptr;
	template<typename _pointee>
	using Y_UNIQUE_PTR = std::unique_ptr<_pointee>;	

	#define Y_MAKE_SHARED std::make_shared
	#define Y_MAKE_UNIQUE sxy::make_unique

	using std::move;


	using std::int8_t;
	using std::int16_t;
	using std::uint8_t;
	using std::uint16_t;
	using std::uint32_t;
	using std::int64_t;

	using std::bind;
	using std::ref;
	using std::cref;
	using std::placeholders::_1;
	using std::placeholders::_2;

	using std::function;

	using std::remove_reference;
	using std::remove_const;

	using std::random_device;	
	

#endif


}


#endif
