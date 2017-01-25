#pragma once

#include <string>
#include <fstream>
#include <stdexcept>

#include "gl_core_3_3.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Material.hpp"
#include "Debug.hpp"

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
        inline void uniform(std::string name,const  glm::mat4& m){gl::UniformMatrix4fv(gl::GetUniformLocation(_program, name.c_str()), 1, false, glm::value_ptr(m));}

        inline void uniform(std::string name, const Material& mat, bool textured = false, GLint nb = 0) {
            uniform(name + ".ambient",   mat.ambient.toVec3());
            uniform(name + ".shininess",  mat.shininess);
            if(!textured) {
                uniform(name + ".diffuse",   mat.diffuse.toVec3());
                uniform(name + ".specular",  mat.specular.toVec3());
            } else {
                std::cerr << name << ".diffuse " << nb << std::endl;
                mat.text_diff->bind(nb);
                uniform(name + ".diffuse", nb);
                nb++;
                std::cerr << name << ".specular " << nb << std::endl;
                mat.text_spec->bind(nb);
                uniform(name + ".specular", nb);
            }

        }


        inline GLuint getProgram() const {return _program;}
};
