//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_STD_TIMESTAMP_POLICY_A0D64C16_D7D3_4E06_B647_F949D14BBBAB
#define T_STD_TIMESTAMP_POLICY_A0D64C16_D7D3_4E06_B647_F949D14BBBAB


#include <string>


namespace sxy
{


class t_std_timestamp_policy final
{
public:

	t_std_timestamp_policy
	(
	) = delete;


	~t_std_timestamp_policy
	(
	) = delete;


	static std::string
	get_timestamp
	(
	);


};


}


#endif
