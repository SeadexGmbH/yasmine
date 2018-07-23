//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_MACHINE_ELEMENT_MODEL_34418F5F_B45F_4C66_BC45_41DF4FE3A0D0
#define STATE_MACHINE_ELEMENT_MODEL_34418F5F_B45F_4C66_BC45_41DF4FE3A0D0


#include "essentials/non_copyable.hpp"

#include "model_element_type.hpp"


namespace sxe
{
	class uri;
}


namespace sxy
{


namespace model
{


class delete_visitor;


//!\interface state_machine_element_model
//!\brief Interface for an element in the state machine model.
class state_machine_element_model
{
public:
	state_machine_element_model()
	{
		// Nothing to do...
	}


	virtual ~state_machine_element_model() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY( state_machine_element_model ) 
	virtual const std::string & get_name() const = 0;
	virtual void set_name( const std::string& _name ) = 0;
	virtual const sxe::uri get_uri() const = 0;
	virtual model::model_element_type get_type() const = 0;
	virtual const state_machine_element_model* get_parent() const = 0;
	virtual state_machine_element_model* get_parent() = 0;
	virtual void set_parent( state_machine_element_model* _parent ) = 0;

	//!\brief Get the child element with the given uri.
	//!\param _uri Uri of the requested element.
	//!\return Pointer to the requested element.
	//!\exception Throws sxy::model::exception if the element does not exists.
	virtual state_machine_element_model* get_child( const sxe::uri& _uri ) = 0;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) = 0;
};


}


}


#endif
