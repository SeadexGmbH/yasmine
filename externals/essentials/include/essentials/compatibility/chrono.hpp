//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CHRONO_2625645C_6611_46F7_AA2F_6F3B256839F3
#define CHRONO_2625645C_6611_46F7_AA2F_6F3B256839F3


#ifdef SX_CPP03_BOOST

#include <boost/chrono.hpp>

#else

#include <chrono>

#endif


namespace sxe
{


#ifdef SX_CPP03_BOOST // C++03 compatibility

	using boost::chrono::time_point;
	using boost::chrono::system_clock;
	using boost::chrono::steady_clock;
	using boost::chrono::seconds;
	using boost::chrono::milliseconds;
	using boost::chrono::duration_cast;
	using boost::chrono::time_point;


#else // C++11 compatibility


	using std::chrono::time_point;
	using std::chrono::system_clock;
	using std::chrono::steady_clock;
	using std::chrono::milliseconds;
	using std::chrono::seconds;
	using std::chrono::duration_cast;
	using std::chrono::time_point;


#endif


}


#endif
