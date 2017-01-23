#pragma once

#include <string>
#include <iostream>
#include <GL/glew.h>
#include "SOIL/SOIL.h"



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
