#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/glm.hpp>
#include "SimpleMaterial.hpp"

namespace soap {

enum class LightType {
    DEFAULT, TEST
};

class Light
{
public :


protected :
    SimpleMaterial* _material;
    glm::vec3 _position;
    LightType _type;

public :
    Light(glm::vec3 position, SimpleMaterial *material, LightType type = LightType::DEFAULT);
    ~Light();

    virtual void bind(Shader &shader);

    inline const glm::vec3& position() const {return _position;}
    inline       glm::vec3& position()       {return _position;}

    inline SimpleMaterial*  material() const {return _material;}
    inline SimpleMaterial*& material()       {return _material;}

    inline const LightType& type() const {return _type;}
    inline       LightType& type()       {return _type;}

};

}
#endif // LIGHT_HPP
