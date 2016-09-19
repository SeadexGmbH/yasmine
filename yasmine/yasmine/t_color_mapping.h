//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_COLOR_MAPPING_H
#define T_COLOR_MAPPING_H


#include <map>

#include "t_color.h"
#include "t_log_level.h"


namespace sxy
{


class t_color_mapping final
{
public:	
	t_color_mapping
	(
	); 


	~t_color_mapping
	(
	) = default;


	t_color_mapping
	(
		const t_color_mapping&
	) = delete;


	t_color_mapping&
	operator=
	(
		const t_color_mapping&
	) = delete;


	t_color
	get_color
	(
		const t_log_level p_log_level
	);


private:
	std::map<t_log_level, t_color> m_color_map;
};


}


#endif
