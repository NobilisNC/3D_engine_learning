#version 330 core

const int NB_TEXTURED_MATERIALS = 1;
const int NB_MATERIALS = 15;


struct TexturedMaterial {
    vec3 ambient;
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

out vec4 color;

in vec2 TexCoord;

uniform TexturedMaterial texMaterials[NB_TEXTURED_MATERIALS];

uniform int nb_materials_dyn = NB_MATERIALS;
uniform int nb_textured_materials_dyn = NB_TEXTURED_MATERIALS;

void main()
{
	vec3 pix_color = vec3(0.f, 0.f, 0.f);

	for(int i = 0; i < nb_textured_materials_dyn; i++)
		pix_color = vec3(texture(texMaterials[i].diffuse, TexCoord));

	color = vec4(pix_color, 1.f);
}
