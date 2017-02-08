#ifndef TEXTUREDMATERIAL_HPP
#define TEXTUREDMATERIAL_HPP

#include "Material.hpp"
#include "Texture.hpp"
#include "Global.hpp"

namespace soap {

class TexturedMaterial : public Material
{
protected :
    TextureKey _diffuse;
    TextureKey _specular;

public :
        const type TYPE = TEXTURED;
        TexturedMaterial(RGBColor ambient, TextureKey diffuse, TextureKey specular, float shininess);
        virtual ~TexturedMaterial();

        virtual void bind(Shader &shader);

        inline const TextureKey&  diffuse() const {return _diffuse;}
        inline       TextureKey& diffuse()        {return _diffuse;}

        inline const TextureKey& specular()  const {return _specular;}
        inline       TextureKey& specular()        {return _specular;}
};


}

#endif // TEXTUREDMATERIAL_HPP
