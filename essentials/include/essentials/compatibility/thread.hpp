//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef THREAD_A43220E4_F5F8_42D5_9B31_749D813922CF
#define THREAD_A43220E4_F5F8_42D5_9B31_749D813922CF


#ifdef SX_CPP03_BOOST

#include <boost/thread.hpp>
#include <boost/atomic.hpp>

#else

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

#endif



namespace sxe
{

	
#ifdef SX_CPP03_BOOST // C++03 compatibility

	using boost::thread;
	using boost::unique_lock;
	using boost::mutex;
	using boost::lock_guard;
	using boost::condition_variable;
	using boost::this_thread::sleep_for;
	using boost::atomic;


#else // C++11 compatibility


	using std::thread;
	using std::unique_lock;
	using std::mutex;
	using std::lock_guard;
	using std::condition_variable;
	using std::this_thread::sleep_for;
	using std::atomic;


#endif


}


#endif
