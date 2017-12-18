//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef COUNTRY_8520C99E_118A_4693_A3BB_D1268053EFEE
#define COUNTRY_8520C99E_118A_4693_A3BB_D1268053EFEE

#include <vector>

#include "city.hpp"


// DONE remove cpp
namespace examples
{


struct country
{
	std::string name_;
	std::vector<city> cities_;
	std::vector<city>::size_type capital_index_;
};



}


#endif
