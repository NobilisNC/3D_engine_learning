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
        TexturedMaterial(RGBColor ambient, TextureKey diffuse, TextureKey specular, float shininess = DEFAULT_SHININESS);
        virtual ~TexturedMaterial();

        virtual void bind(Shader &shader);
        virtual Material* clone();

        inline const TextureKey& diffuse() const noexcept {return _diffuse;}
        inline       TextureKey& diffuse()       noexcept {return _diffuse;}

        inline const TextureKey& specular()  const noexcept {return _specular;}
        inline       TextureKey& specular()        noexcept {return _specular;}
};


}

#endif // TEXTUREDMATERIAL_HPP
