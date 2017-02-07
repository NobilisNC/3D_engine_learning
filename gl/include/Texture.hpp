#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "gl_core_3_3.hpp"
#include <string>
#include <iostream>
#include <algorithm>


namespace soap {



class Texture {
public :
    enum Type {
        SPECULAR, DIFFUSE
    };

    private :
        GLuint _id;
        Type _type;

    public :
        Texture(std::string path, Type type = DIFFUSE);
        void bind(GLuint unit = 0);
        void unbind();

        inline Type getType() const {return _type;}
};


}

#endif
