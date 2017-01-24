#ifndef MATERIAL_H
#define MATERIAL_H

#include "glm/glm.hpp"
#include "Color.hpp"
#include "Texture.hpp"

struct Material
{
    RGBColor ambient;
    RGBColor diffuse;
    RGBColor specular;
    GLfloat shininess;
    Texture* text_diff;
    Texture* text_spec;

    Material(RGBColor _ambient, RGBColor _diffuse, RGBColor _specular, GLfloat _shininess = 16.0f, Texture* _text_diff = nullptr, Texture* _text_spec = nullptr);

    inline bool isTextured() {return text_diff != nullptr && text_spec != nullptr;}
    inline void setTextured(Texture* _text_diff, Texture* _text_spec) {
        text_diff = _text_diff;
        text_spec = _text_spec;
    }
};

#endif // MATERIAL_H
