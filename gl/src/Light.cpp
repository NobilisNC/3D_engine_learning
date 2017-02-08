#include "Light.hpp"

using namespace soap;


Light::Light(glm::vec3 position, SimpleMaterial&& material)
 : _position(position), _material(material)
{

}

Light::~Light()
{

}




