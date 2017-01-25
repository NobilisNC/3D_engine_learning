#version 330 core

#define NB_MATERIALS 15
#define NB_TEXTURED_MATERIALS 5

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct TexturedMaterial {
    vec3 ambient;
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct LightData {
    vec3 pos;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


out vec4 color;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

uniform vec3 viewPos;

uniform Material materials[NB_MATERIALS];
uniform TexturedMaterial texMaterials[NB_TEXTURED_MATERIALS];

uniform int nb_materials_dyn = NB_MATERIALS;
uniform int nb_textured_materials_dyn = NB_TEXTURED_MATERIALS;

uniform LightData light;



void main()
{
	//Mix Materials
        vec3 mixed_ambient = vec3(0.0f);
        vec3 mixed_diffuse = vec3(0.0f);
        vec3 mixed_specular = vec3(0.0f);
        float mixed_shininess = 16.0f;
	int begin_mat = 0;
	int begin_text = 0;
	vec3 debug = vec3(1.0f, 1.0f, 1.0f);
        vec3 _debug;

	if (nb_materials_dyn > 0) {
            mixed_ambient = materials[0].ambient;
            mixed_diffuse = materials[0].diffuse;
            mixed_specular = materials[0].specular;
            mixed_shininess = materials[0].shininess;
            begin_mat = 1;
	} else if (nb_textured_materials_dyn > 0) {		
            mixed_ambient = texMaterials[0].ambient;
            mixed_diffuse = vec3(texture(texMaterials[0].diffuse, TexCoord));
            mixed_specular = vec3(texture(texMaterials[0].specular, TexCoord));
            mixed_shininess = texMaterials[0].shininess;
            begin_text = 1;
	}

    for(int i = begin_mat; i < nb_materials_dyn; i++) {

        mixed_ambient = mixed_ambient * materials[i].ambient;
        mixed_diffuse = mix(mixed_diffuse, materials[i].diffuse, 0.5f);
        mixed_specular = min(mixed_specular,materials[i].specular);
        mixed_shininess = min(mixed_shininess, materials[i].shininess);
        debug = vec3(1.0f, 1.0f, 1.0f);
    }



    for(int i = begin_text; i < nb_textured_materials_dyn; i++) {

            debug = vec3(texture(texMaterials[i].diffuse, TexCoord));
            //mixed_ambient = mixed_ambient * texMaterials[i].ambient;
            //mixed_diffuse = vec3(mix(vec4(mixed_diffuse,1.0f), texture(texMaterials[i].diffuse, TexCoord), 0.5f));
            //mixed_specular = min(mixed_specular, vec3(texture(texMaterials[i].specular, TexCoord)));
            //mixed_shininess = min(mixed_shininess, texMaterials[i].shininess);
      }

    // Ambient
    vec3 ambient = light.ambient * mixed_ambient * mixed_diffuse;

    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.pos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * mixed_diffuse;

    //Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), mixed_shininess);
    vec3 specular = light.specular * spec * mixed_specular;


	
	//vec3 result = normalize(ambient + diffuse + specular);
    //debug = mixed_specular;
    vec3 result = debug;
    color = vec4(result, 1.0f);
}
