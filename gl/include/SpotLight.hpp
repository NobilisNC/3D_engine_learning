#ifndef SPOTLIGHT_HPP
#define SPOTLIGHT_HPP

#include "PointLight.hpp"

namespace soap {


class SpotLight : public PointLight
{
protected :
    static unsigned NB_LIGHT;

    glm::vec3 _direction;

    float _cutOff;
    float _outerCutOff;


public:
    SpotLight(glm::vec3 position, SimpleMaterial&& material, float constant, float linear, float quadratic, glm::vec3 direction, float cutOff, float outerCutOff);
    ~SpotLight();

    virtual void bind(Shader &shader);

    static void reset();
    static unsigned numberBinded();

    inline const float& cutOff() const {return _cutOff;}
    inline       float& cutOff()       {return _cutOff;}

    inline const float& outerCutOff() const {return _outerCutOff;}
    inline       float& outerCutOff()       {return _outerCutOff;}
};


}
#endif // SPOTLIGHT_HPP
