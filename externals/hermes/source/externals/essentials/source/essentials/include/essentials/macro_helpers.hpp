//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef MACRO_HELPERS_D52C3077_E0EF_4C4E_B451_1472DEE602E8
#define MACRO_HELPERS_D52C3077_E0EF_4C4E_B451_1472DEE602E8


#ifndef SX_NO_VARIADIC_MACRO


//!\def EXPAND( x )
//!\brief Helper to work around some Visual C++ compiler quirk dealing with variadic macros.
#define EXPAND( x ) x

//!\def CAT( A, B )
//!\brief Concatenate two tokens.
#define CAT( A, B ) A ## B

//!\def SELECT( NAME, NUM )
//!\brief Creating a name from a base name and a number with underscore between them.
#define SELECT( NAME, NUM ) CAT( NAME ## _, NUM )

//!\def GET_COUNT( _ONE, _TWO, _THREE, _FOUR, _FIVE, _SIX, _SEVEN, _EIGHT, _NINE, _TEN, _ELEVEN, _TWELVE, _THIRTEEN, _FOURTEEN, _FIFTEEN, COUNT, ... )
//!\brief Helper for counting the number of parameters of a macro.
#define GET_COUNT( _ONE, _TWO, _THREE, _FOUR, _FIVE, _SIX, _SEVEN, _EIGHT, _NINE, _TEN, _ELEVEN, _TWELVE, _THIRTEEN, _FOURTEEN, _FIFTEEN, COUNT, ... ) COUNT

//!\def VA_SIZE( ... )
//!\brief Count the number of parameters of a macro.
#define VA_SIZE( ... ) EXPAND( GET_COUNT( __VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1 ) )

//!\def VA_SELECT( NAME, ... )
//!\brief Selects the correct overloaded macro based on the number of parameters.
#define VA_SELECT( NAME, ... ) EXPAND( SELECT( NAME, VA_SIZE(__VA_ARGS__) )(__VA_ARGS__) )


#endif


#endif
