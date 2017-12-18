//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SHALLOW_HISTORY_MODEL_IMPL_CDCC97A1_5256_4665_81DB_94D4A3006DE5
#define SHALLOW_HISTORY_MODEL_IMPL_CDCC97A1_5256_4665_81DB_94D4A3006DE5


#include "shallow_history_model.hpp"
#include "pseudostate_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class shallow_history_model_impl
//!\brief A shallow history pseudostate in the model.
class shallow_history_model_impl SX_FINAL: 
	public virtual shallow_history_model, public pseudostate_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name Name of the shallow history.
	explicit shallow_history_model_impl( const std::string& _name );
	virtual ~shallow_history_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( shallow_history_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;
};


}


}


#endif
