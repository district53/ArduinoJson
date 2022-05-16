# ArduinoJson - https://arduinojson.org
# Copyright © 2014-2022, Benoit BLANCHON
# MIT License

cmake_minimum_required(VERSION 3.15)

if(ESP_PLATFORM)
   # Build ArduinoJson as an ESP-IDF component
   idf_component_register(INCLUDE_DIRS src)
   return()
endif()

project(ArduinoJson VERSION 6.19.4)

set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "") # disable -rdynamic - https://stackoverflow.com/q/35155835

#if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
#    include(CTest)
#endif()

add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
	include(extras/CompileOptions.cmake)
	#add_subdirectory(extras/tests)
	add_subdirectory(extras/fuzzing)
endif()
