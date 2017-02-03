#ifndef DIRECTIONALLIGHT_HPP
#define DIRECTIONALLIGHT_HPP

#include "Light.hpp"
namespace soap {



class DirectionalLight : public Light
{
protected :
    static unsigned NB_LIGHT;

public:
    DirectionalLight(glm::vec3 position, SimpleMaterial *material);
    ~DirectionalLight();

    virtual void bind(Shader &shader);

    static void reset();
    static unsigned numberBinded();
};

}
#endif // DIRECTIONALLIGHT_HPP
