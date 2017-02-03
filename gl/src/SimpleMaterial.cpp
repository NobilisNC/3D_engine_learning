#include "SimpleMaterial.hpp"

using namespace soap;

soap::SimpleMaterial::SimpleMaterial(soap::RGBColor ambient, soap::RGBColor diffuse, soap::RGBColor specular, float shininess)
    : Material(ambient, shininess), _diffuse(diffuse), _specular(specular)
{

}

SimpleMaterial::~SimpleMaterial()
{

}

void SimpleMaterial::bind(Shader &shader)
{
    shader.uniform("isTextured", false);
    shader.uniform("material.ambient", _ambient.toVec3());
    shader.uniform("material.diffuse", _diffuse.toVec3());
    shader.uniform("material.specular", _specular.toVec3());
    shader.uniform("material.shininess", _shininess);
}

void SimpleMaterial::lightBind(Shader &shader)
{
    shader.uniform("light.ambient", _ambient.toVec3() );
    shader.uniform("light.diffuse", _diffuse.toVec3());
    shader.uniform("light.specular", _specular.toVec3());
    shader.uniform("light.shininess", _shininess);

}
