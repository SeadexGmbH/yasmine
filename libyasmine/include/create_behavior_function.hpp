//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CREATE_BEHAVIOR_FUNCTION_AE991E8C_8970_4642_AAAF_983076825DAB
#define CREATE_BEHAVIOR_FUNCTION_AE991E8C_8970_4642_AAAF_983076825DAB


#include "behavior_fwd.hpp"
#include "behavior_caller.hpp"


#ifndef SX_CPP03_BOOST // C++11

#ifdef SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG


namespace sxy
{


template< typename function1 >
sxy::behavior_function create_behavior_function( const function1& _function1 )
{
	return ( sxy::behavior_function( [_function1]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1 ); } ) );
}


template< typename function1, typename function2 >
sxy::behavior_function create_behavior_function( const function1& _function1, const function2& _function2 )
{
	return ( sxy::behavior_function( [_function1, _function2]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1, _function2 ); } ) );
}


template< typename function1, typename function2, typename function3 >
sxy::behavior_function create_behavior_function( const function1& _function1, const function2& _function2, const function3& _function3 )
{
	return ( sxy::behavior_function( [_function1, _function2, _function3]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1, _function2, _function3 ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4 >
sxy::behavior_function create_behavior_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4 )
{
	return ( sxy::behavior_function( [_function1, _function2, _function3, _function4]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1, _function2, _function3, _function4 ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5 >
sxy::behavior_function create_behavior_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5 )
{
	return ( sxy::behavior_function( [_function1, _function2, _function3, _function4, _function5]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5 ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6 >
sxy::behavior_function create_behavior_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6 )
{
	return ( sxy::behavior_function( [_function1, _function2, _function3, _function4, _function5, _function6]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6 ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6, typename function7 >
sxy::behavior_function create_behavior_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6, const function7& _function7 )
{
	return ( sxy::behavior_function( [_function1, _function2, _function3, _function4, _function5, _function6, _function7]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6, _function7 ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6, typename function7, typename function8 >
sxy::behavior_function create_behavior_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6, const function7& _function7, const function8& _function8 )
{
	return ( sxy::behavior_function( [_function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6, typename function7, typename function8, typename function9 >
sxy::behavior_function create_behavior_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6, const function7& _function7, const function8& _function8, const function9& _function9 )
{
	return ( sxy::behavior_function( [_function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ); } ) );
}


template< typename function1, typename function2, typename function3, typename function4, typename function5, typename function6, typename function7, typename function8, typename function9, typename function10 >
sxy::behavior_function create_behavior_function( const function1& _function1, const function2& _function2, const function3& _function3, const function4& _function4, const function5& _function5, const function6& _function6, const function7& _function7, const function8& _function8, const function9& _function9, const function10& _function10 )
{
	return ( sxy::behavior_function( [_function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ); } ) );
}

}
#else // !SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG 

namespace sxy
{


template< typename ... Args >
sxy::behavior_function create_behavior_function( Args...args )
{
	return ( sxy::behavior_function( [args...]( const sxy::event& _event, sxy::event_collector& _event_collector ) { behavior_caller( _event, _event_collector, args... ); } ) );
}


}


#endif // SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG


#else // C++03 with Boost


namespace sxy
{


sxy::behavior_function create_behavior_function( const sxe::function<void()>& _function );


sxy::behavior_function create_behavior_function( const sxe::function<void( sxy::event_collector& )>& _function );


template< typename _event_type >
sxy::behavior_function create_behavior_function( const sxe::function<void( const _event_type& )>& _function1 )
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&, const sxe::function<void( const _event_type& )>& );
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1 ) ) );
}


template< typename _event_type >
sxy::behavior_function create_behavior_function( 
	const sxe::function<void( const _event_type&, sxy::event_collector& )>& _function1 
	)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&, const sxe::function<void( const _event_type&, sxy::event_collector& )>& );
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1 ) ) );
}


template< typename _event_type1, typename _event_type2 >
sxy::behavior_function create_behavior_function(
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2
	)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>&
		);
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1, _function2 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3 >
sxy::behavior_function create_behavior_function(
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3
)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>&
		);
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4 >
sxy::behavior_function create_behavior_function(
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4
)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>&
		);
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5 >
sxy::behavior_function create_behavior_function(
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5
)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>&
		);
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6 >
sxy::behavior_function create_behavior_function(
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6
)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>&
		);
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6, typename _event_type7 >
sxy::behavior_function create_behavior_function(
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6,
	const sxe::function<void( const _event_type7&, sxy::event_collector& )>& _function7
)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type7&, sxy::event_collector& )>&
		);
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6, _function7 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8 >
sxy::behavior_function create_behavior_function(
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6,
	const sxe::function<void( const _event_type7&, sxy::event_collector& )>& _function7,
	const sxe::function<void( const _event_type8&, sxy::event_collector& )>& _function8
)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type7&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type8&, sxy::event_collector& )>&
		);
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9 >
sxy::behavior_function create_behavior_function(
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6,
	const sxe::function<void( const _event_type7&, sxy::event_collector& )>& _function7,
	const sxe::function<void( const _event_type8&, sxy::event_collector& )>& _function8,
	const sxe::function<void( const _event_type9&, sxy::event_collector& )>& _function9
)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type7&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type8&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type9&, sxy::event_collector& )>&
		);
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9 ) ) );
}


template< typename _event_type1, typename _event_type2, typename _event_type3, typename _event_type4, typename _event_type5, typename _event_type6, typename _event_type7, typename _event_type8, typename _event_type9, typename _event_type10 >
sxy::behavior_function create_behavior_function(
	const sxe::function<void( const _event_type1&, sxy::event_collector& )>& _function1,
	const sxe::function<void( const _event_type2&, sxy::event_collector& )>& _function2,
	const sxe::function<void( const _event_type3&, sxy::event_collector& )>& _function3,
	const sxe::function<void( const _event_type4&, sxy::event_collector& )>& _function4,
	const sxe::function<void( const _event_type5&, sxy::event_collector& )>& _function5,
	const sxe::function<void( const _event_type6&, sxy::event_collector& )>& _function6,
	const sxe::function<void( const _event_type7&, sxy::event_collector& )>& _function7,
	const sxe::function<void( const _event_type8&, sxy::event_collector& )>& _function8,
	const sxe::function<void( const _event_type9&, sxy::event_collector& )>& _function9,
	const sxe::function<void( const _event_type10&, sxy::event_collector& )>& _function10
)
{
	typedef void( *behavior_caller_selector )( const sxy::event&, sxy::event_collector&,
		const sxe::function<void( const _event_type1&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type2&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type3&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type4&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type5&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type6&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type7&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type8&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type9&, sxy::event_collector& )>&,
		const sxe::function<void( const _event_type10&, sxy::event_collector& )>&
		);
	return( sxy::behavior_function( sxe::bind( static_cast< behavior_caller_selector >( behavior_caller ), sxe::_1, sxe::_2, _function1, _function2, _function3, _function4, _function5, _function6, _function7, _function8, _function9, _function10 ) ) );
}


}

#endif // !SX_CPP03_BOOST



#endif
