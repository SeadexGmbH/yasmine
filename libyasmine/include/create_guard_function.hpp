//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CREATE_GUARD_FUNCTION_ACA9A120_8AEC_43B3_8745_DDC573C43D63
#define CREATE_GUARD_FUNCTION_ACA9A120_8AEC_43B3_8745_DDC573C43D63


#include "constraint_fwd.hpp"
#include "guard_caller.hpp"


#ifndef SX_CPP03_BOOST // C++11

#ifdef SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG


namespace sxy
{


template< typename function1 >
sxy::constraint_function create_guard_function( const function1& _function1 )
{
	return ( sxy::constraint_function( [_function1]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1 ) ); } ) );
}


template< typename function1, typename function2 >
sxy::constraint_function create_guard_function( const function1& _function1, const function2& _function2 )
{
	return ( sxy::constraint_function( [_function1, _function2]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1, _function2 ) ); } ) );
}


template< typename function1, typename function2, typename function3 >
sxy::constraint_function create_guard_function( const function1& _function1, const function2& _function2, const function3& _function3 )
{
	return ( sxy::constraint_function( [_function1, _function2, _function3]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1, _function2, _function3 ) ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4 >
sxy::constraint_function create_guard_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4 )
{
	return ( sxy::constraint_function( [_function1, _function2, _function3, _function4]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1, _function2, _function3, _function4 ) ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5 >
sxy::constraint_function create_guard_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5 )
{
	return ( sxy::constraint_function( [_function1, _function2, _function3, _function4, _function5]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5 ) ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6 >
sxy::constraint_function create_guard_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6 )
{
	return ( sxy::constraint_function( [_function1, _function2, _function3, _function4, _function5, _function6]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6 ) ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6, typename function7 >
sxy::constraint_function create_guard_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6, const function7& _function7 )
{
	return ( sxy::constraint_function( [_function1, _function2, _function3, _function4, _function5, _function6, _function7]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6, _function7 ) ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6, typename function7, typename function8 >
sxy::constraint_function create_guard_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6, const function7& _function7, const function8& _function8 )
{
	return ( sxy::constraint_function( [_function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ) ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6, typename function7, typename function8, typename function9 >
sxy::constraint_function create_guard_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6, const function7& _function7, const function8& _function8, const function9& _function9 )
{
	return ( sxy::constraint_function( [_function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ) ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6, typename function7, typename function8, typename function9, typename function10 >
sxy::constraint_function create_guard_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6, const function7& _function7, const function8& _function8, const function9& _function9, function10 _function10 )
{
	return ( sxy::constraint_function( [_function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ) ); } ) );
}

}


#else // !SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG

namespace sxy
{


template< typename ... Args >
sxy::constraint_function create_guard_function( Args...args )
{
	return ( sxy::constraint_function( [args...]( const sxy::event& _event, sxy::event_collector& _event_collector ) { return( guard_caller( _event, _event_collector, args... ) ); } ) );
}


}


#endif // SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG


#else // C++03 with Boost


namespace sxy
{


sxy::constraint_function create_guard_function( const sxe::function<bool()>& _function );


sxy::constraint_function create_guard_function( const sxe::function<bool( sxy::event_collector& )>& _function );


template< typename _event_type >
sxy::constraint_function create_guard_function( const sxe::function<bool( const _event_type& )>& _function1 )
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&, const sxe::function<bool( const _event_type& )>& );
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1 ) ) );
}


template< typename _event_type1 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1 ) ) );
}


template< typename _event_type1, typename _event_type2 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1, _function2 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6, typename _event_type7 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6,
	const sxe::function<bool( const _event_type7&, sxy::event_collector& )>& _function7
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type7&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6, _function7 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6,
	const sxe::function<bool( const _event_type7&, sxy::event_collector& )>& _function7,
	const sxe::function<bool( const _event_type8&, sxy::event_collector& )>& _function8
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type7&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type8&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6,
	const sxe::function<bool( const _event_type7&, sxy::event_collector& )>& _function7,
	const sxe::function<bool( const _event_type8&, sxy::event_collector& )>& _function8,
	const sxe::function<bool( const _event_type9&, sxy::event_collector& )>& _function9
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type7&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type8&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type9&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9, typename _event_type10 >
sxy::constraint_function create_guard_function(
	const sxe::function<bool( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<bool( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<bool( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<bool( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<bool( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<bool( const _event_type6&, sxy::event_collector& )>& _function6,
	const sxe::function<bool( const _event_type7&, sxy::event_collector& )>& _function7,
	const sxe::function<bool( const _event_type8&, sxy::event_collector& )>& _function8,
	const sxe::function<bool( const _event_type9&, sxy::event_collector& )>& _function9,
	const sxe::function<bool( const _event_type10&, sxy::event_collector& )>& _function10
)
{
	typedef bool( *guard_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<bool( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type6&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type7&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type8&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type9&, sxy::event_collector& )>&,
		const sxe::function<bool( const _event_type10&, sxy::event_collector& )>&
		);
	return( sxy::constraint_function( sxe::bind( static_cast< guard_caller_selector >( guard_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ) ) );
}

}

#endif // !SX_CPP03_BOOST


#endif
