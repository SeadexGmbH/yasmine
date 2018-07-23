//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_MACHINE_ELEMENT_MODEL_IMPL_07873CFE_DADC_4CDC_A2CE_28C029CD5696
#define STATE_MACHINE_ELEMENT_MODEL_IMPL_07873CFE_DADC_4CDC_A2CE_28C029CD5696


#include "essentials/uri.hpp"

#include "state_machine_element_model.hpp"


namespace sxy
{


namespace model
{


//!\class state_machine_element_model_impl
//!\brief An element of the state machine in the model.
class state_machine_element_model_impl:
	public virtual state_machine_element_model
{
public:
	//!\brief Constructor.
	//!\param _name Name of the element.
	//!\param _type Type of the element.
	state_machine_element_model_impl( const std::string& _name, const model_element_type& _type );
	virtual ~state_machine_element_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( state_machine_element_model_impl )

	//!\brief Get the name of the element.
	//!\return Name of the element.
	virtual const std::string & get_name() const SX_OVERRIDE;

	//!\brief Set the name of the element.
	//!\param _name Name of the element.
	void set_name( const std::string& _name ) SX_OVERRIDE;

	//!\brief Get the parent of the element.
	//!\return Pointer to the parent element.
	virtual const state_machine_element_model* get_parent() const SX_OVERRIDE;

	//!\brief Get the parent of the element (non const).
	//!\return Pointer to the parent element.
	virtual state_machine_element_model* get_parent() SX_OVERRIDE;

	//!\brief Set the parent of the element.
	//!\param _parent Parent of the element.
	virtual void set_parent( state_machine_element_model* _parent ) SX_OVERRIDE;

	//!\brief Get the uri of the element.
	//!\return Uri of the element.
	virtual const sxe::uri get_uri() const SX_OVERRIDE;

	//!\brief Get the type of the element.
	//!\return Element's type.
	virtual model_element_type get_type() const SX_OVERRIDE;


private:
	void add_ancestor_uri( sxe::uri& _uri ) const;

	std::string name_;
	state_machine_element_model* parent_;
	const model_element_type type_;
};



typedef sxe::SX_UNIQUE_PTR<state_machine_element_model_impl> state_machine_element_model_uptr;


}


}


#endif
