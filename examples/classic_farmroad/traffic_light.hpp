//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRAFFIC_LIGHT_3B22DEE5_C976_43FF_B528_127733D61CD8
#define TRAFFIC_LIGHT_3B22DEE5_C976_43FF_B528_127733D61CD8


#include <string>

#include "async_state_machine.hpp"


namespace examples
{


class traffic_light SX_FINAL
{
public:
	traffic_light( const std::string& _name,	const std::string& _ascii_prefix );
	~traffic_light() SX_NOEXCEPT;
	SX_NO_COPY( traffic_light )
	void start();
	void stop();
	void switch_to_red_yellow();
	void switch_to_green();
	void switch_to_yellow();
	void switch_to_red();


private:
	void on_traffic_light_red() const;
	void on_traffic_light_red_yellow() const;
	void on_traffic_light_green() const;
	void on_traffic_light_yellow() const;
	void build_traffic_light_state_machine();
	std::string display_road_name_with_ascii_prefix() const;


	sxy::async_state_machine traffic_light_state_machine_;
	const std::string name_;
	const std::string ascii_prefix_;
};


}


#endif
