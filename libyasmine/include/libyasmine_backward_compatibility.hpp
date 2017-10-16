//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LIBYASMINE_BACKWARD_COMPATIBILITY_25EFEF99_3357_4F3D_843D_AEB2C56E19DD
#define LIBYASMINE_BACKWARD_COMPATIBILITY_25EFEF99_3357_4F3D_843D_AEB2C56E19DD


#include "essentials/compatibility/compatibility.hpp"


#ifdef Y_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG
#define SX_GCC_EXPAND_TEMPLATE_PARAM_PACK_BUG
#endif


namespace sxy
{
	using sxe::shared_ptr;
}


#endif
