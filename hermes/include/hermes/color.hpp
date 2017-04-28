//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
					
#ifndef SX_NO_LOGGING


#ifndef COLOR_63B5B1DB_D383_404D_93EF_AB2BC3A0D286
#define COLOR_63B5B1DB_D383_404D_93EF_AB2BC3A0D286


namespace hermes
{


#ifndef SX_CPP03_BOOST


	//!\enum color
	//!\brief Enumeration for predefined colors.
	enum class color
	{
		C_BLACK = 0, C_WHITE = 15, C_DARK_WHITE = 7, C_BLUE = 9, C_DARK_BLUE = 1, C_GREEN = 10, C_DARK_GREEN = 2, C_RED = 12,
		C_DARK_RED = 4, C_YELLOW = 14, C_DARK_YELLOW = 6, C_AQUA = 3, C_GRAY = 8, C_MAGENTA = 13, C_CYAN = 11
	};


#else

	
	//!\struct color
	//!\brief Structure representing a predefined color (enum wrapper for C++11 enum class like behavior).
	struct color
	{
		//!\enum color
		//!\brief Enumeration for predefined colors.
		enum inner
		{
			C_BLACK = 0, C_WHITE = 15, C_DARK_WHITE = 7, C_BLUE = 9, C_DARK_BLUE = 1, C_GREEN = 10, C_DARK_GREEN = 2, C_RED = 12,
			C_DARK_RED = 4, C_YELLOW = 14, C_DARK_YELLOW = 6, C_AQUA = 3, C_GRAY = 8, C_MAGENTA = 13, C_CYAN = 11
		};
		
		
		//!\brief Constructor. Default value is white.
		color() : value_( C_WHITE )
		{
			// Nothing to do...
		}


		//!\brief Constructor
		//!\param _value Given color value that is represented by the structure.		
		color( const inner _value ) : value_( _value )
		{
			// Nothing to do...
		}


		//!\brief Constructor
		//!\param _color Given color structure containing the color that is represented by the structure.		
		color( const color& _color ) : value_( _color.value_ )
		{
			// Nothing to do...
		}


		//!\brief Get the color value represented by the structure.		
		operator inner() const
		{
			return ( value_ );
		}


		//!\brief Color represented by the structure.
		inner value_;

	};


#endif


}


#endif


#endif
