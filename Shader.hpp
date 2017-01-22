#pragma once

#include <string>
#include <fstream>
#include <stdexcept>

#include <GL/glew.h>

class Shader {
    private :
        GLuint _program;

    public :
        Shader(std::string vertexPath, std::string fragmentPath);
        void use();

        inline GLuint getProgram() const {return _program;}
};
