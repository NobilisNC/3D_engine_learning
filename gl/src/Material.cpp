#include "Material.hpp"

using namespace soap;

Material::Material(RGBColor _ambient, RGBColor _diffuse, RGBColor _specular, GLfloat _shininess, Texture *_text_diff, Texture *_text_spec)
    : ambient(_ambient), diffuse(_diffuse), specular(_specular), shininess(_shininess), text_diff(_text_diff),  text_spec(_text_spec)
{

}
