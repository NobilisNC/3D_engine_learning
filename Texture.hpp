#pragma once

#include <string>
#include <iostream>
#include <GL/glew.h>
#include "SOIL/SOIL.h"



class Texture {
    private :
        GLuint id;

    public :
        Texture(std::string path);
        void bind(GLuint unit = 0);
        void unbind();

};
