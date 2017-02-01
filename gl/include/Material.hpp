#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "glm/glm.hpp"
#include "Color.hpp"
#include "Shader.hpp"


namespace soap {


class Material
{
public :
    enum type {
        SIMPLE, TEXTURED
    };

protected :
    RGBColor    _ambient;
    float       _shininess;

public :
    Material(RGBColor ambient, float shininess);
    virtual ~Material() = 0;

    virtual void bind(Shader& shader) = 0;


    inline const RGBColor& ambient() const {return _ambient;}
    inline       RGBColor& ambient()       {return _ambient;}

    inline const float& shininess() const {return _shininess;}
    inline       float& shininess()       {return _shininess;}

};

}

#endif // MATERIAL_H
