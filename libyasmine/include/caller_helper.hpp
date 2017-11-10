//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CALLER_HELPER_F7FFB6C9_339F_471F_B7A1_C77902353FBA
#define CALLER_HELPER_F7FFB6C9_339F_471F_B7A1_C77902353FBA


#include "event_id.hpp"


namespace sxy
{

#ifndef SX_CPP03_BOOST // C++11 only


	template<typename C>
	struct has_get_event_id
	{
	private:
		template<typename T>
		static constexpr auto check( T* ) -> typename
			std::is_same< decltype( T::get_event_id() ), sxy::event_id >::type;

		template<typename>
		static constexpr std::false_type check( ... );

		typedef decltype( check<C>( 0 ) ) type;

	public:
		static constexpr bool value = type::value;
	};


#endif

}


#endif
