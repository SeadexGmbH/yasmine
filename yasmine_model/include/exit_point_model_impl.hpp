//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EXIT_POINT_MODEL_IMPL_737E881A_9FD7_4F2B_95BC_6A5CAB7BADF9
#define EXIT_POINT_MODEL_IMPL_737E881A_9FD7_4F2B_95BC_6A5CAB7BADF9


#include "exit_point_model.hpp"
#include "pseudostate_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class exit_point_model_impl
//!\brief An exit point pseudostate in the model.
class exit_point_model_impl SX_FINAL : 
	public exit_point_model, public pseudostate_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name Name of the exit point.
	explicit exit_point_model_impl( const std::string& _name );
	virtual ~exit_point_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( exit_point_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;
};


}


}


#endif
