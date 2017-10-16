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



// TODO add to log as removed?
//#define Y_ASSERT SX_ASSERT
//#define Y_NULLPTR SX_NULLPTR
//#define Y_FOR SX_FOR
//#define Y_CONSTEXPR SX_CONSTEXPR
//#define Y_FINAL SX_FINAL
//#define Y_NOEXCEPT SX_NOEXCEPT
//#define Y_OVERRIDE SX_OVERRIDE
//#define Y_NO_COPY SX_NO_COPY
//#define Y_NO_COPY_OPERATOR_EQUAL SX_NO_ASSIGNMENT_OPERATOR



namespace sxy
{
	using sxe::shared_ptr;
}


#endif
