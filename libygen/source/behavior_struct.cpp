//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "behavior_struct.hpp"


namespace sxy
{


behavior_struct::behavior_struct():
	behavior_class_name(),
	behavior_method_name(),
	call_operator()
{
	// Nothing to do...
}


behavior_struct::~behavior_struct() SX_NOEXCEPT
{
	// Nothing to do...
}


}
