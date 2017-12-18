//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef NON_COPYABLE_D2C5BF6C_4B43_42AF_9E42_1AAE2B5C49C8
#define NON_COPYABLE_D2C5BF6C_4B43_42AF_9E42_1AAE2B5C49C8


#include "essentials/compatibility/compatibility.hpp"


namespace sxe
{


#ifdef SX_CPP03_BOOST


//!\def SX_NO_COPY(_class_name)
//!\brief Delete the copy constructor and assignment operator of the given class.
#define	SX_NO_COPY(_class_name)\
private:\
	_class_name(const _class_name&) SX_DELETE;\
	_class_name& operator=(const _class_name&) SX_DELETE;\
public:\
\


//!\def SX_NO_ASSIGNMENT_OPERATOR(_class_name)
//!\brief Delete the assignment operator of the given class.
#define SX_NO_ASSIGNMENT_OPERATOR(_class_name)\
private:\
	_class_name& operator=( const _class_name& ) SX_DELETE;\
public:\
\


#else


//!\def SX_NO_COPY(_class_name)
//!\brief Delete the copy constructor and assignment operator of the given class.
#define	SX_NO_COPY(_class_name)\
	_class_name(const _class_name&) SX_DELETE;\
	_class_name& operator=(const _class_name&) SX_DELETE;\
\


//!\def SX_NO_ASSIGNMENT_OPERATOR(_class_name)
//!\brief Delete the assignment operator of the given class.
#define SX_NO_ASSIGNMENT_OPERATOR(_class_name)\
	_class_name& operator=( const _class_name& ) SX_DELETE;\
\


#endif


}


#endif
