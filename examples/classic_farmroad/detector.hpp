//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef DETECTOR_5EBE86D2_647F_4029_94D8_B5521F641349
#define DETECTOR_5EBE86D2_647F_4029_94D8_B5521F641349


#include "essentials/compatibility/compatibility.hpp"
#include "essentials/compatibility/thread.hpp"
#include "essentials/non_copyable.hpp"


namespace examples
{


class detector_callback;


class detector SX_FINAL
{
public:
	explicit detector( detector_callback& _detector_callback );
	~detector();
	SX_NO_COPY( detector )
	void start();
	void stop();
	bool is_on();


private:
	void generate_detector_events();


	detector_callback& detector_callback_;
	bool is_on_;
	sxe::SX_UNIQUE_PTR< sxe::thread > generate_random_detector_events_;
	bool run_;
	sxe::mutex mutex_;
	sxe::condition_variable condition_variable_;
};


}


#endif
