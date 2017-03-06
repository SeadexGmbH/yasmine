//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef NON_COPYABLE_D2C5BF6C_4B43_42AF_9E42_1AAE2B5C49C8
#define NON_COPYABLE_D2C5BF6C_4B43_42AF_9E42_1AAE2B5C49C8


#include "compatibility.hpp"


namespace sxy
{


#ifdef Y_CPP03_BOOST

#define	Y_NO_COPY(_class_name)\
private:\
	_class_name(const _class_name&) Y_DELETE;\
	_class_name& operator=(const _class_name&) Y_DELETE;\
public:\
\


#define Y_NO_COPY_OPERATOR_EQUAL(_class_name)\
private:\
	_class_name& operator=( const _class_name& ) Y_DELETE;\
public:\
\


#else

#define	Y_NO_COPY(_class_name)\
	_class_name(const _class_name&) Y_DELETE;\
	_class_name& operator=(const _class_name&) Y_DELETE;\
\


#define Y_NO_COPY_OPERATOR_EQUAL(_class_name)\
	_class_name& operator=( const _class_name& ) Y_DELETE;\
\


#endif


}


#endif
