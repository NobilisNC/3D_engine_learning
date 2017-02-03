#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP

#include "Light.hpp"

namespace soap {

class PointLight : public Light
{
protected :
    static unsigned NB_LIGHT;

    float _constant;
    float _linear;
    float _quadratic;

public:
    PointLight(glm::vec3 position, SimpleMaterial *material, float constant, float linear, float quadratic);
    ~PointLight();

    virtual void bind(Shader &shader);

    static void reset();
    static unsigned numberBinded();

    inline const float& constant() const {return _constant;}
    inline       float& constant()       {return _constant;}

    inline const float& linear() const {return _linear;}
    inline       float& linear()       {return _linear;}

    inline const float& quadratic() const {return _quadratic;}
    inline       float& quadratic()       {return _quadratic;}
};


}
#endif // POINTLIGHT_HPP
