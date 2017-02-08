#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "glm/glm.hpp"
#include "Color.hpp"
#include "Shader.hpp"
#include "EntityManager.hpp"
#include "Interface.hpp"


namespace soap {


constexpr float DEFAULT_SHININESS = 32.0f;

class Material : public virtual Cloneable<Material>
{
public :
    enum type {
        SIMPLE, TEXTURED
    };

protected :
    RGBColor    _ambient;
    float       _shininess;


public :
    Material(RGBColor ambient, float shininess = DEFAULT_SHININESS);
    virtual ~Material() = 0;

    virtual void bind(Shader& shader) = 0;
    virtual Material* clone() = 0;


    inline const RGBColor& ambient() const noexcept {return _ambient;}
    inline       RGBColor& ambient()       noexcept {return _ambient;}

    inline const float& shininess() const  noexcept {return _shininess;}
    inline       float& shininess()        noexcept {return _shininess;}

};
    using MaterialKey = EntityManager<std::string, Material>::Key;

}

#endif // MATERIAL_H
