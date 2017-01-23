#version 330 core

#define NB_MATERIALS 5

struct Material {
    vec3 global;
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
uniform LightData light;



void main()
{
	//Mix Materials
	vec3 mixed_ambient = materials[0].ambient;
	vec3 mixed_diffuse = vec3(texture(materials[0].diffuse,  TexCoord));
	vec3 mixed_specular = vec3(texture(materials[0].specular, TexCoord));
	for(int i = 1; i < NB_MATERIALS-1; i++) {
			if (materials[i].ambient == vec3(0.f))
					break;

				mixed_ambient = mixed_ambient * materials[0].ambient;
				mixed_diffuse = vec3(mix(vec4(mixed_diffuse,1.0f), texture(materials[i].diffuse, TexCoord), 0.5f));	
				mixed_specular = min(mixed_specular, vec3(texture(materials[i].specular, TexCoord))); 
	}

    // Ambient
    vec3 ambient = light.ambient * mixed_ambient * mixed_diffuse ;

    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.pos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * mixed_diffuse;

    //Specular
    float specularStrength = 0.4f;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), materials[0].shininess);
    vec3 specular = light.specular * spec * mixed_specular;


	vec3 result = (specular + diffuse + ambient);
	//vec3 result = diffuse;
    color = vec4(result, 1.0f);

}


