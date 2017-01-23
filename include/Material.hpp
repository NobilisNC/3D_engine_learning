#ifndef MATERIAL_H
#define MATERIAL_H

#include "glm/glm.hpp"
#include "Color.hpp"

struct Material
{
    RGBColor ambient;
    RGBColor diffuse;
    RGBColor specular;
};

#endif // MATERIAL_H
