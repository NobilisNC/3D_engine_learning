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

    SimpleMaterial(RGBColor ambient, RGBColor diffuse, RGBColor specular, float shininess);
    virtual ~SimpleMaterial();

    virtual void bind(Shader &shader);


    inline const RGBColor& diffuse() const {return _diffuse;}
    inline       RGBColor& diffuse()       {return _diffuse;}

    inline const RGBColor& specular() const {return _specular;}
    inline       RGBColor& specular()       {return _specular;}

};

}
#endif
