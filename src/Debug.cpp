#include "Debug.hpp"

#include <string>
#include <iostream>



void glCheckError(const char* file, int line)
{
	GLenum errorCode;
    while ((errorCode = gl::GetError()) != gl::NO_ERROR_)
	{
		std::string error;
		switch (errorCode)
		{
            case gl::INVALID_ENUM:					error = "INVALID_ENUM"; break;
            case gl::INVALID_VALUE:					error = "INVALID_VALUE"; break;
            case gl::INVALID_OPERATION:				error = "INVALID_OPERATION"; break;
            case gl::STACK_OVERFLOW:					error = "STACK_OVERFLOW"; break;
            case gl::STACK_UNDERFLOW:				error = "STACK_UNDERFLOW"; break;
            case gl::OUT_OF_MEMORY:					error = "OUT_OF_MEMORY"; break;
            case gl::INVALID_FRAMEBUFFER_OPERATION:	error = "OUT_OF_MEMORY"; break;
		}
		std::cerr << error << " | " << file << " (" << line << ")\n";
	}
}
