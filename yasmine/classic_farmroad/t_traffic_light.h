//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TRAFFIC_LIGHT_3B22DEE5_C976_43FF_B528_127733D61CD8
#define T_TRAFFIC_LIGHT_3B22DEE5_C976_43FF_B528_127733D61CD8


#include <string>

#include "t_async_state_machine.h"


namespace sxy
{


class t_traffic_light final
{
public:
	t_traffic_light
	(
		const std::string& p_name,
		const std::string& p_ascii_prefix
	);


	~t_traffic_light
	(
	);


	t_traffic_light
	(
		const t_traffic_light&
	) = delete;


	t_traffic_light&
	operator=
	(
		const t_traffic_light&
	) = delete;


	void
	start
	(
	);


	void
	stop
	(
	);


	void
	switch_to_red_yellow
	(
	);


	void
	switch_to_green
	(
	);


	void
	switch_to_yellow
	(
	);


	void
	switch_to_red
	(
	);


private:
	void 
	on_traffic_light_red
	(
	) const;


	void
	on_traffic_light_red_yellow
	(
	) const;


	void
	on_traffic_light_green
	(
	) const;


	void
	on_traffic_light_yellow
	(
	) const;


	void
	build_traffic_light_state_machine
	(
	);


	std::string
	display_road_name_with_ascii_prefix
	( 		
	) const;
							

	t_async_state_machine m_traffic_light_state_machine;	
	const std::string m_name;
	const std::string m_ascii_prefix;


};


}


#endif
