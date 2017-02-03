#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <fstream>
#include <stdexcept>

#include "gl_core_3_3.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Debug.hpp"

namespace soap {


class Shader {
    private :
    GLuint _program;

public :
    Shader(std::string vertexPath, std::string fragmentPath);
    void use();

    inline void uniform(std::string name, float f)          {gl::Uniform1f(gl::GetUniformLocation(_program, name.c_str()), f);                          }
    inline void uniform(std::string name, glm::vec2 vec)    {gl::Uniform2f(gl::GetUniformLocation(_program, name.c_str()),  vec.x, vec.y);              }
    inline void uniform(std::string name, glm::vec3 vec)    {gl::Uniform3f(gl::GetUniformLocation(_program, name.c_str()),  vec.x, vec.y, vec.z);       }
    inline void uniform(std::string name, glm::vec4 vec)    {gl::Uniform4f(gl::GetUniformLocation(_program, name.c_str()),  vec.x, vec.y, vec.z, vec.w);}
    inline void uniform(std::string name, GLint i)          {gl::Uniform1i(gl::GetUniformLocation(_program, name.c_str()),  i);                         }
    inline void uniform(std::string name, unsigned i)       {gl::Uniform1ui(gl::GetUniformLocation(_program, name.c_str()),  i);                        }
    inline void uniform(std::string name,const  glm::mat4& m){gl::UniformMatrix4fv(gl::GetUniformLocation(_program, name.c_str()), 1, false, glm::value_ptr(m));}
    inline void uniform(std::string name, bool boolean) {gl::Uniform1f(gl::GetUniformLocation(_program, name.c_str()), boolean);                        }

    inline GLuint getProgram() const {return _program;}
};

}

#endif
