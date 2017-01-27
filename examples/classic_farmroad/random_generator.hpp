//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef RANDOM_GENERATOR_63744576_1DBE_44C8_B2EE_3A3A1EE0B66F
#define RANDOM_GENERATOR_63744576_1DBE_44C8_B2EE_3A3A1EE0B66F


#include "non_copyable.hpp"


namespace examples
{


class random_generator Y_FINAL
{
public:
	random_generator();
	~random_generator();
	Y_NO_COPY( random_generator )

		const unsigned int generate(const unsigned int _lower_extremity, const unsigned int _upper_extremity);

private:
	sxy::random_device random_device_;	


};


}


#endif
