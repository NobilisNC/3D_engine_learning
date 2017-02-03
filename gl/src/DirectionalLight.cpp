#include "DirectionalLight.hpp"

using namespace soap;

unsigned DirectionalLight::NB_LIGHT = 0;

soap::DirectionalLight::DirectionalLight(glm::vec3 position, soap::SimpleMaterial *material)
    : Light(position, material)
{

}

DirectionalLight::~DirectionalLight()
{

}

void DirectionalLight::bind(Shader &shader)
{
    std::string i = std::to_string(NB_LIGHT);
    shader.uniform("directional_lights[" + i + "].position", _position);
    shader.uniform("directional_lights[" + i + "].ambient", _material->ambient().toVec3() );
    shader.uniform("directional_lights[" + i + "].diffuse", _material->diffuse().toVec3());
    shader.uniform("directional_lights[" + i + "].specular", _material->specular().toVec3());
    shader.uniform("directional_lights[" + i + "].shininess", _material->shininess());

    NB_LIGHT++;
}

void DirectionalLight::reset()
{
    NB_LIGHT = 0;
}

unsigned DirectionalLight::numberBinded()
{
    return NB_LIGHT;
}
