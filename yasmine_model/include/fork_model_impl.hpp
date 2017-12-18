//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef FORK_MODEL_IMPL_46FE8620_288B_48A2_B020_D9E0E8962E2F
#define FORK_MODEL_IMPL_46FE8620_288B_48A2_B020_D9E0E8962E2F


#include "fork_model.hpp"
#include "pseudostate_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class fork_model_impl
//!\brief A fork pseudostate in the model.
class fork_model_impl SX_FINAL: 
	public virtual fork_model, public pseudostate_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name Name of the fork.
	explicit fork_model_impl( const std::string& _name );
	virtual ~fork_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( fork_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;
};


}


}


#endif
