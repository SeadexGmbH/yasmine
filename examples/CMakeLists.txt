cmake_minimum_required(VERSION 3.5)

add_subdirectory(hello_yasmine)
add_subdirectory(classic_farmroad)
add_subdirectory(forty_two)
add_subdirectory(events_with_parameters)
add_subdirectory(substatemachines_and_variables)				 
add_subdirectory(event_collector_example)
add_subdirectory(unhandled_event_handler_example)

if(NOT "${CPP_VERSION}" STREQUAL "03")
	add_subdirectory(generator_example)
endif()