#ifndef SIMPLEMATERIAL_HPP
#define SIMPLEMATERIAL_HPP

#include "Material.hpp"

namespace soap {

class SimpleMaterial : public Material
{
protected :
    RGBColor _diffuse;
    RGBColor _specular;

public :
    const type TYPE = SIMPLE;

    SimpleMaterial(RGBColor ambient = Color::white, RGBColor diffuse = Color::white, RGBColor specular= Color::white, float shininess = DEFAULT_SHININESS);
    virtual ~SimpleMaterial();

    virtual void bind(Shader &shader);
    virtual Material* clone();

    void lightBind(Shader& shader);


    inline const RGBColor& diffuse() const {return _diffuse;}
    inline       RGBColor& diffuse()       {return _diffuse;}

    inline const RGBColor& specular() const {return _specular;}
    inline       RGBColor& specular()       {return _specular;}

};

}
#endif
