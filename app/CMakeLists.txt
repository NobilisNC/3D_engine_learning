CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(Apptest)

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


include_directories(include/ ../gl/include/ ../core/include)
add_executable(${PROJECT_NAME} ${includeFiles} ${sourceFiles})
target_link_libraries(${PROJECT_NAME} soap-gl soap-core -lglfw -lGL -lSOIL)
