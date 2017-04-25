//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_MACHINE_TYPE_DF8B2D7E_F25F_43B0_9B98_3A974487574C
#define STATE_MACHINE_TYPE_DF8B2D7E_F25F_43B0_9B98_3A974487574C

#include <string>


namespace sxy
{


#ifndef SX_CPP03_BOOST


	//!\enum state_machine_type
	//!\brief Enumeration for state machine types.
	enum class state_machine_type
	{
		SMT_SYNC = 0, SMT_ASYNC = 1
	};


#else


	//!\struct state_machine_type
	//!\brief Structure representing state machine types (enum wrapper for C++11 enum class like behavior).
	struct state_machine_type
	{
		//!\enum state_machine_type
		//!\brief Enumeration for state machine types.
		enum inner
		{
			SMT_SYNC = 0, SMT_ASYNC = 1
		};


		//!\brief Constructor. Default value is white.
		state_machine_type() : value_( SMT_SYNC )
		{
			// Nothing to do...
		}


		//!\brief Constructor
		//!\param _value Given state machine type value that is represented by the structure.		
		state_machine_type( const inner _value ) : value_( _value )
		{
			// Nothing to do...
		}


		//!\brief Constructor
		//!\param _state_machine_type Given state machine type structure containing the 
		//!\state machine type that is represented by the structure.		
		state_machine_type( const state_machine_type& _state_machine_type ) : value_( _state_machine_type.value_ )
		{
			// Nothing to do...
		}


		//!\brief Get the state machine type value represented by the structure.		
		operator inner() const
		{
			return ( value_ );
		}


		//!\brief State machine type represented by the structure.
		inner value_;

	};

#endif
	
	state_machine_type sm_type_from_string( const std::string& _type );
	const std::string sm_type_to_string( const state_machine_type& _type );
	const std::string get_state_machine_class_as_string( const state_machine_type& _type );
	std::istream& operator >> ( std::istream& _in_stream, sxy::state_machine_type& _sm_type );


}


#endif
