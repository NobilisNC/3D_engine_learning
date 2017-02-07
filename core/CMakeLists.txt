CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(soap-core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


file(
	GLOB_RECURSE
	sourceFiles
	./src/*.cpp
	)

file(
	GLOB_RECURSE
	includeFiles
	./include/*.hpp
	)

include_directories(include/)

add_library(soap-core ${includeFiles} ${sourceFiles})
target_link_libraries(soap-core)



