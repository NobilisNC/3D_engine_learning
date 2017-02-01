#include "Light.hpp"

using namespace soap;


Light::Light(glm::vec3 position, SimpleMaterial *material, LightType type)
 : _position(position), _material(material), _type(type)
{

}

Light::~Light()
{

}

void Light::bind(Shader &shader)
{
    _material->lightBind(shader);
    shader.uniform("light.pos", _position);
}
