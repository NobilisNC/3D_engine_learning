#include "TexturedMaterial.hpp"

using namespace soap;

TexturedMaterial::TexturedMaterial(soap::RGBColor ambient, soap::Texture *diffuse, soap::Texture *specular, float shininess)
    : Material(ambient, shininess), _diffuse(diffuse), _specular(specular)
{

}

TexturedMaterial::~TexturedMaterial()
{

}

void TexturedMaterial::bind(Shader &shader)
{
    constexpr int ID_TEXTURE_DIFFUSE = 1;
    constexpr int ID_TEXTURE_SPECULAR = 2;

    _diffuse->bind(ID_TEXTURE_DIFFUSE);
    _specular->bind(ID_TEXTURE_SPECULAR);

    shader.uniform("isTextured", true);
    shader.uniform("texMaterial.ambient", _ambient.toVec3());
    shader.uniform("texMaterial.diffuse", ID_TEXTURE_DIFFUSE);
    shader.uniform("texMaterial.specular", ID_TEXTURE_SPECULAR);
    shader.uniform("texMaterial.shininess", _shininess);

}
