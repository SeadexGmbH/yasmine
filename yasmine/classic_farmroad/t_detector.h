//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_DETECTOR_5EBE86D2_647F_4029_94D8_B5521F641349
#define T_DETECTOR_5EBE86D2_647F_4029_94D8_B5521F641349


#include <memory>
#include <mutex>
#include <thread>
#include <condition_variable>


namespace sxy
{


class i_detector_callback;


class t_detector final
{
public:
	explicit t_detector( i_detector_callback& p_detector_callback );
	~t_detector();
	t_detector( const t_detector& ) = delete;
	t_detector& operator=( const t_detector& ) = delete;
	void start();
	void stop();
	bool is_on();


private:
	void generate_detector_events();


	i_detector_callback& m_detector_callback;
	bool m_is_on;
	std::unique_ptr< std::thread >  m_generate_random_detector_events;
	bool m_run;
	std::mutex m_mutex;
	std::condition_variable m_condition_variable;
};


}


#endif
