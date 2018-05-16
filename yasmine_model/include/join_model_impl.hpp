//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef JOIN_MODEL_IMPL_B7AE319E_F291_4AE5_81C3_D18CE80F0D09
#define JOIN_MODEL_IMPL_B7AE319E_F291_4AE5_81C3_D18CE80F0D09


#include "pseudostate_model_impl.hpp"
#include "join_model.hpp"


namespace sxy
{


namespace model
{


//!\class join_model_impl
//!\brief A join pseudostate in the model.
class join_model_impl SX_FINAL: 
	public join_model, public pseudostate_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name Name of the join.
	explicit join_model_impl( const std::string& _name );
	virtual ~join_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( join_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;
};




}


}


#endif
