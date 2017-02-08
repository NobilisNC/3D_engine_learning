#include "SpotLight.hpp"

using namespace soap;

unsigned SpotLight::NB_LIGHT = 0;

SpotLight::SpotLight(glm::vec3 position, SimpleMaterial&& material, float constant, float linear, float quadratic,  glm::vec3 direction, float cutOff, float outerCutOff)
 : PointLight(position, std::move(material), constant, linear, quadratic), _direction(direction), _cutOff(cutOff), _outerCutOff(outerCutOff)
{

}

SpotLight::~SpotLight()
{

}

void SpotLight::bind(Shader &shader)
{
    std::string i = std::to_string(NB_LIGHT);
    shader.uniform("spot_lights[" + i + "].position", _position);
    shader.uniform("spot_lights[" + i + "].direction", _direction);
    shader.uniform("spot_lights[" + i + "].ambient", _material.ambient().toVec3() );
    shader.uniform("spot_lights[" + i + "].diffuse", _material.diffuse().toVec3());
    shader.uniform("spot_lights[" + i + "].specular", _material.specular().toVec3());
    shader.uniform("spot_lights[" + i + "].shininess", _material.shininess());

    shader.uniform("spot_lights[" + i + "].constant", _constant);
    shader.uniform("spot_lights[" + i + "].linear", _linear);
    shader.uniform("spot_lights[" + i + "].quadratic", _quadratic);

    shader.uniform("spot_lights[" + i + "].cutOff", glm::cos(glm::radians(_cutOff)));
    shader.uniform("spot_lights[" + i + "].outerCutOff", glm::cos(glm::radians(_outerCutOff)));

    NB_LIGHT++;
}

void SpotLight::reset()
{
    NB_LIGHT = 0;
}

unsigned SpotLight::numberBinded()
{
    return NB_LIGHT;
}

