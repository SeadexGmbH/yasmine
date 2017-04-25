//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CHOICE_MODEL_IMPL_62F688E5_4520_44BA_A749_E428975B0111
#define CHOICE_MODEL_IMPL_62F688E5_4520_44BA_A749_E428975B0111


#include "choice_model.hpp"
#include "pseudostate_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class chice_model_impl
//!\brief A choice pseudostate in the model.
class choice_model_impl SX_FINAL: 
	public virtual choice_model, public pseudostate_model_impl
{
public:
	//!\brief Constructor.
	//!\param _name Name of the choice.
	explicit choice_model_impl( const std::string& _name );
	virtual ~choice_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( choice_model_impl )
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
};


}


}


#endif
