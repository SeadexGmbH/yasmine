//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BACKWARD_COMPATIBILITY_51D0150C_395A_4339_9F99_DFFD7274916D
#define BACKWARD_COMPATIBILITY_51D0150C_395A_4339_9F99_DFFD7274916D


#include "essentials/compatibility/compatibility.hpp"


#ifdef Y_NO_LOGGING
#define SX_NO_LOGGING
#endif


#ifdef Y_NO_STD_MAKE_UNIQUE
#define SX_NO_STD_MAKE_UNIQUE
#endif


#ifdef Y_CPP03_BOOST
#define SX_CPP03_BOOST
#endif


#ifdef Y_NO_WINDOWS_H
#define SX_NO_WINDOWS_H
#endif


#define Y_CONSTEXPR SX_CONSTEXPR
#define Y_FINAL SX_FINAL
#define Y_NOEXCEPT SX_NOEXCEPT
#define Y_OVERRIDE SX_OVERRIDE
#define Y_NO_COPY SX_NO_COPY
#define Y_NO_COPY_OPERATOR_EQUAL SX_NO_ASSIGNMENT_OPERATOR
#define Y_UNIQUE_PTR SX_UNIQUE_PTR
#define Y_MAKE_UNIQUE SX_MAKE_UNIQUE
#define Y_MAKE_SHARED SX_MAKE_SHARED
#define Y_UNUSED_PARAMETER SX_UNUSED_PARAMETER
#define Y_NO_LOGGING SX_NO_LOGGING
#define Y_LOG SX_LOG
#define Y_LOG_HEX SX_LOG_HEX
#define Y_ASSERT SX_ASSERT
#define Y_NULLPTR SX_NULLPTR
#define Y_FOR SX_FOR
#define Y_CPP03_BOOST SX_CPP03_BOOST
#define Y_NO_STD_MAKE_UNIQUE SX_NO_STD_MAKE_UNIQUE
#define Y_NO_WINDOWS_H SX_NO_WINDOWS_H


namespace sxy
{
	using sxe::shared_ptr;
}


#endif
