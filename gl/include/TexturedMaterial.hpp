#ifndef TEXTUREDMATERIAL_HPP
#define TEXTUREDMATERIAL_HPP

#include "Material.hpp"
#include "Texture.hpp"

namespace soap {

class TexturedMaterial : public Material
{
protected :
    Texture* _diffuse;
    Texture* _specular;

public :
        const type TYPE = TEXTURED;
        TexturedMaterial(RGBColor ambient, Texture* diffuse, Texture* specular, float shininess);
        virtual ~TexturedMaterial();

        virtual void bind(Shader &shader);

        inline Texture*  diffuse() const {return _diffuse;}
        inline Texture*& diffuse()       {return _diffuse;}

        inline Texture* specular()  const {return _specular;}
        inline Texture*& specular()       {return _specular;}
};


}

#endif // TEXTUREDMATERIAL_HPP
