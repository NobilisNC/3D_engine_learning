#include "PointLight.hpp"

using namespace soap;

unsigned PointLight::NB_LIGHT = 0;

PointLight::PointLight(glm::vec3 position, SimpleMaterial *material, float constant, float linear, float quadratic)
 : Light(position, material), _constant(constant), _linear(linear), _quadratic(quadratic)
{

}

PointLight::~PointLight()
{

}

void PointLight::bind(Shader &shader)
{
    std::string i = std::to_string(NB_LIGHT);
    shader.uniform("point_lights[" + i + "].position", _position);
    shader.uniform("point_lights[" + i + "].ambient", _material->ambient().toVec3() );
    shader.uniform("point_lights[" + i + "].diffuse", _material->diffuse().toVec3());
    shader.uniform("point_lights[" + i + "].specular", _material->specular().toVec3());
    shader.uniform("point_lights[" + i + "].shininess", _material->shininess());

    shader.uniform("point_lights[" + i + "].constant", _constant);
    shader.uniform("point_lights[" + i + "].linear", _linear);
    shader.uniform("point_lights[" + i + "].quadratic", _quadratic);

    NB_LIGHT++;
}

void PointLight::reset()
{
    NB_LIGHT = 0;
}

unsigned PointLight::numberBinded()
{
    return NB_LIGHT;
}
