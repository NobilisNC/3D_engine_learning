CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(OpenGL CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT bin/${CMAKE_BUILD_TYPE})

file(
        GLOB_RECURSE
        includeFiles
        ./include/*.hpp
        )

file(
	GLOB_RECURSE
	sourceFiles 
	./src/*.cpp
	)



include_directories(include/)

add_executable(${PROJECT_NAME} ${includeFiles} ${sourceFiles}   )
target_link_libraries(${PROJECT_NAME} -lGL -lGLU -lglfw  -lGLEW -lSOIL)
