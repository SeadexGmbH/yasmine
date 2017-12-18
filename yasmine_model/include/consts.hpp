//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CONSTS_ACE2AE01_CFDD_4BD0_AB05_9B3190BFE90D
#define CONSTS_ACE2AE01_CFDD_4BD0_AB05_9B3190BFE90D


#include <string>


namespace sxy
{


namespace model
{


extern const char* const JSON_STATE_MACHINE_NODE;
extern const char* const JSON_ROOT_NODE;
extern const char* const JSON_TRANSITIONS_NODE;
extern const char* const JSON_NAME_NODE;
extern const char* const JSON_TYPE_NODE;
extern const char* const JSON_ENTER_BEHAVIOR_NODE;
extern const char* const JSON_DO_BEHAVIOR_NODE;
extern const char* const JSON_EXIT_BEHAVIOR_NODE;
extern const char* const JSON_REGIONS_NODE;
extern const char* const JSON_VERTICES_NODE;
extern const char* const JSON_STATE_PSEUDOSTATES_NODE;
extern const char* const JSON_PSEUDOSTATES_NODE;
extern const char* const JSON_TRANSITION_KIND_NODE;
extern const char* const JSON_TRANSITION_SOURCE_NODE;
extern const char* const JSON_TRANSITION_TARGET_NODE;
extern const char* const JSON_TRANSITION_GUARD_NODE;
extern const char* const JSON_TRANSITION_BEHAVIOR_NODE;
extern const char* const JSON_TRANSITION_EVENTS_NODE;
extern const char* const JSON_DEFERRED_EVENTS;
extern const char* const JSON_ERROR_EVENT;
extern const char* const JSON_EVENT_ID;
extern const char* const JSON_EVENT_NAME;
extern const char* const JSON_EVENT_LIST_NODE;
extern const char* const JSON_EVENT_PRIORITY;
extern const char* const JSON_VERSION;
extern const char* const JSON_CURRENT_VERSION_VALUE;
extern const char* const JSON_VERSION_1;
extern const char* const JSON_EXTERNALS;


extern const std::string TYPE_TRANSITION;
extern const std::string TYPE_SIMPLE_STATE;
extern const std::string TYPE_ASYNC_SIMPLE_STATE;
extern const std::string TYPE_COMPOSITE_STATE;
extern const std::string TYPE_FINAL_STATE;
extern const std::string TYPE_INITIAL_PSEUDOSTATE;
extern const std::string TYPE_TERMINATE_PSEUDOSTATE;
extern const std::string TYPE_ENTRY_POINT;
extern const std::string TYPE_EXIT_POINT;
extern const std::string TYPE_DEEP_HISTORY;
extern const std::string TYPE_SHALLOW_HISTORY;
extern const std::string TYPE_JOIN;
extern const std::string TYPE_JUNCTION;
extern const std::string TYPE_FORK;
extern const std::string TYPE_CHOICE;
extern const std::string TYPE_REGION;
extern const std::string TYPE_UNKNOWN;


extern const std::string CONFIG_FILE_IS_CORRUPTED;
extern const std::string CHOOSE_FILE_TEXT;
extern const std::string FILE_CANNOT_BE_OPENED;
extern const std::string PATH_CONFIG_JSON_FILE;
extern const std::string CHOOSE_FILE_TYPE;
extern const std::string CHOOSE_FILE_TEXT_SAVE;
extern const std::string CHOOSE_FILE_DEFAULT_SAVING_NAME;
extern const std::string CHOOSE_FILE_TYPE_SAVE;

extern const char* const TRANSITION_MUST_BE_IN_JSON_ARRAY;


}


}


#endif
