//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "downcast_event.hpp"
#include "function_downcast.hpp"
#include "class_method_downcast.hpp"


int main()
{
	std::cout << "#1 Downcast event scenario:" << std::endl;
	examples::downcast_event();

	std::cout << "#2 Use function downcast scenario:" << std::endl;
	examples::use_function_downcast();

	std::cout << "#3 Use class method downcast scenario:" << std::endl;
	examples::use_method_downcast();

}
