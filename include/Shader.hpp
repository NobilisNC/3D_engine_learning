#pragma once

#include <string>
#include <fstream>
#include <stdexcept>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
    private :
        GLuint _program;

    public :
        Shader(std::string vertexPath, std::string fragmentPath);
        void use();

        inline void uniform(std::string name, GLfloat f)        {glUniform1f(glGetUniformLocation(_program, name.c_str()), f);                          }
        inline void uniform(std::string name, glm::vec2 vec)    {glUniform2f(glGetUniformLocation(_program, name.c_str()),  vec.x, vec.y);              }
        inline void uniform(std::string name, glm::vec3 vec)    {glUniform3f(glGetUniformLocation(_program, name.c_str()),  vec.x, vec.y, vec.z);       }
        inline void uniform(std::string name, glm::vec4 vec)    {glUniform4f(glGetUniformLocation(_program, name.c_str()),  vec.x, vec.y, vec.z, vec.w);}
        inline void uniform(std::string name, GLint i)          {glUniform1i(glGetUniformLocation(_program, name.c_str()),  i);                         }
        inline void uniform(std::string name,const  glm::mat4& m)      {glUniformMatrix4fv(glGetUniformLocation(_program, name.c_str()), 1, GL_FALSE, glm::value_ptr(m));}


        inline GLuint getProgram() const {return _program;}
};
