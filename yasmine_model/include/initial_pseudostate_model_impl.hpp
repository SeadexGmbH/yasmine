//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef INITIAL_PSEUDOSTATE_MODEL_IMPL_BF7EC689_C277_476C_AE7B_DD17EA0CCAC9
#define INITIAL_PSEUDOSTATE_MODEL_IMPL_BF7EC689_C277_476C_AE7B_DD17EA0CCAC9


#include "initial_pseudostate_model.hpp"
#include "pseudostate_model_impl.hpp"


namespace sxy
{


namespace model
{


class model_vertex_visitor;


//!\class initial_pseudostate_model_impl
//!\brief An initial pseudostate in the model.
class initial_pseudostate_model_impl SX_FINAL: 
	public virtual initial_pseudostate_model, public pseudostate_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name Name of the initial pseudostate.
	explicit initial_pseudostate_model_impl( const std::string& _name );
	virtual ~initial_pseudostate_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( initial_pseudostate_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
};


}


}


#endif
