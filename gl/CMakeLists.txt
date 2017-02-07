CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(soap-gl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(EXECUTABLE_OUTPUT bin/${CMAKE_BUILD_TYPE})

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


include_directories(include/ ../core/include/)
add_library(soap-gl ${includeFiles} ${sourceFiles})
target_link_libraries(soap-gl soap-core -lSOIL -lGL -lglfw -lassimp)



