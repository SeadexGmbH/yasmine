//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TERMINATE_PSEUDOSTATE_MODEL_IMPL_F473E031_5035_4D29_ACBD_2F292A9BC6F8
#define TERMINATE_PSEUDOSTATE_MODEL_IMPL_F473E031_5035_4D29_ACBD_2F292A9BC6F8


#include "terminate_pseudostate_model.hpp"
#include "pseudostate_model_impl.hpp"


namespace sxy
{


namespace model
{


class model_vertex_visitor;


//!\class terminate_pseudostate_model_impl
//!\brief A terminate pseudostate in the model.
class terminate_pseudostate_model_impl SX_FINAL: 
	public terminate_pseudostate_model, public pseudostate_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name Name of the terminate pseudostate.
	explicit terminate_pseudostate_model_impl( const std::string& _name );
	virtual ~terminate_pseudostate_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( terminate_pseudostate_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;
};



}


}


#endif
