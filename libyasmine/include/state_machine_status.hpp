//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATUS_A02F2056_A314_4093_B3AB_75FEBFB43A57
#define STATUS_A02F2056_A314_4093_B3AB_75FEBFB43A57


namespace sxy
{


#ifndef SX_CPP03_BOOST		
	enum class state_machine_status
	{
		NEW, STARTED, STOP_REQUESTED, TERMINATED, STOPPED
	};
#else
	struct state_machine_status
	{
		enum inner
		{
			NEW, STARTED, STOP_REQUESTED, TERMINATED, STOPPED
		};


		state_machine_status() : value_( NEW )
		{
			// Nothing to do...
		}


		// cppcheck-suppress noExplicitConstructor
		state_machine_status( const inner _value ) : value_( _value )
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


	bool operator==( const state_machine_status& _lhs, const state_machine_status::inner _rhs );
	bool operator==( const state_machine_status::inner _lhs, const state_machine_status& _rhs );


#endif


}

#endif
