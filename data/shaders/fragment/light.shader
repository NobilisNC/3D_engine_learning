#version 330 core

uniform struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
} material;

uniform struct TexturedMaterial {
    vec3 ambient;
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
} texMaterial;

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

uniform LightData light;

uniform bool isTextured;



void main()
{

    vec3 mat_ambient = material.ambient;
    vec3 mat_diffuse = material.diffuse;
    vec3 mat_specular = material.specular;
    float mat_shininess = material.shininess;

    if(isTextured) {

      mat_diffuse = vec3(texture(texMaterial.diffuse, TexCoord));
      mat_specular = vec3(texture(texMaterial.specular, TexCoord));
      mat_shininess = texMaterial.shininess;
      mat_ambient = texMaterial.ambient * mat_diffuse;
    }

    // Ambient
    vec3 ambient = light.ambient * mat_ambient;

    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.pos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * mat_diffuse;

    //Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), mat_shininess);
    vec3 specular = light.specular * spec * mat_specular;



	  vec3 result = ambient + diffuse + specular;
    color = vec4(result, 1.0f);
}
