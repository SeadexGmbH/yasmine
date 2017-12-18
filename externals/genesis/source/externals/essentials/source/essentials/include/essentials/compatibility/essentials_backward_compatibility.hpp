//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ESSENTIALS_BACKWARD_COMPATIBILITY_EBFE3698_30C0_456A_A146_1F081011CB49
#define ESSENTIALS_BACKWARD_COMPATIBILITY_EBFE3698_30C0_456A_A146_1F081011CB49


#ifdef Y_NO_STD_MAKE_UNIQUE
#define SX_NO_STD_MAKE_UNIQUE
#endif


#ifdef Y_CPP03_BOOST
#define SX_CPP03_BOOST
#endif


#define Y_UNIQUE_PTR SX_UNIQUE_PTR
#define Y_MAKE_UNIQUE SX_MAKE_UNIQUE
#define Y_MAKE_SHARED SX_MAKE_SHARED
#define Y_UNUSED_PARAMETER SX_UNUSED_PARAMETER


#endif
