#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "gl_core_3_3.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include "EntityManager.hpp"
#include "Interface.hpp"


namespace soap {



class Texture : public virtual Cloneable<Texture> {
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

        virtual Texture* clone();


};
        using TextureKey = EntityManager<std::string, Texture>::Key;





}

#endif
