//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
					
#ifndef Y_NO_LOGGING

#ifndef COLOR_63B5B1DB_D383_404D_93EF_AB2BC3A0D286
#define COLOR_63B5B1DB_D383_404D_93EF_AB2BC3A0D286


namespace sxy
{


#ifndef Y_CPP03_BOOST


	enum class color
	{
		C_BLACK = 0, C_WHITE = 15, C_DARK_WHITE = 7, C_BLUE = 9, C_DARK_BLUE = 1, C_GREEN = 10, C_DARK_GREEN = 2, C_RED = 12,
		C_DARK_RED = 4, C_YELLOW = 14, C_DARK_YELLOW = 6, C_AQUA = 3, C_GRAY = 8, C_MAGENTA = 13, C_CYAN = 11
	};


#else

	struct color
	{
		enum inner
		{
			C_BLACK = 0, C_WHITE = 15, C_DARK_WHITE = 7, C_BLUE = 9, C_DARK_BLUE = 1, C_GREEN = 10, C_DARK_GREEN = 2, C_RED = 12,
			C_DARK_RED = 4, C_YELLOW = 14, C_DARK_YELLOW = 6, C_AQUA = 3, C_GRAY = 8, C_MAGENTA = 13, C_CYAN = 11
		};
		
		
		color() : value_(C_WHITE) {
			// Nothing to do...
		}


		// cppcheck-suppress noExplicitConstructor
		color( const inner _value ) : value_( _value )
		{
			// Nothing to do...
		}


		// cppcheck-suppress noExplicitConstructor
		color( const color& _color ) : value_( _color.value_ )
		{
			// Nothing to do...
		}


		// cppcheck-suppress functionConst
		operator inner()
		{
			return ( value_ );
		}


		inner value_;

	};

#endif


}


#endif

#endif