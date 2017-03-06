//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef MACRO_HELPERS_D52C3077_E0EF_4C4E_B451_1472DEE602E8
#define MACRO_HELPERS_D52C3077_E0EF_4C4E_B451_1472DEE602E8


#ifndef Y_NO_VARIADIC_MACRO

#define EXPAND( x ) x

#define CAT( A, B ) A ## B
#define SELECT( NAME, NUM ) CAT( NAME ## _, NUM )

#define GET_COUNT( _ONE, _TWO, _THREE, _FOUR, _FIVE, _SIX, _SEVEN, _EIGHT, _NINE, _TEN, COUNT, ... ) COUNT
#define VA_SIZE( ... ) EXPAND( GET_COUNT( __VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1 ) )

#define VA_SELECT( NAME, ... ) EXPAND( SELECT( NAME, VA_SIZE(__VA_ARGS__) )(__VA_ARGS__) )

#endif


#endif
