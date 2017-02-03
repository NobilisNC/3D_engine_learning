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


struct DirLight {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
   
};

struct PointLight {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};


out vec4 color;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

uniform vec3 viewPos;
uniform bool isTextured = false;

#define NR_DIR_LIGHTS 5
#define NR_POINT_LIGHTS 20
#define NR_SPOT_LIGHTS 10

uniform DirLight directional_lights[NR_DIR_LIGHTS];
uniform PointLight point_lights[NR_POINT_LIGHTS];
uniform SpotLight spot_lights[NR_SPOT_LIGHTS];

uniform uint nr_directional_lights = 0u;
uniform uint nr_point_lights = 0u;
uniform uint nr_spot_lights = 0u;



vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir, Material current_material);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, Material current_material);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, Material current_material);

void main()
{
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);    

    Material current_mat;

    current_mat.ambient = material.ambient;
    current_mat.diffuse = material.diffuse;
    current_mat.specular = material.specular;
    current_mat.shininess = material.shininess;

    if(isTextured) {

      current_mat.diffuse = vec3(texture(texMaterial.diffuse, TexCoord));
      current_mat.specular = vec3(texture(texMaterial.specular, TexCoord));
      current_mat.shininess = texMaterial.shininess;
      current_mat.ambient = texMaterial.ambient * current_mat.diffuse;
    }

      vec3 result = vec3(0.0f);   
    
      for(uint i = 0u; i < nr_directional_lights; i++)
        result += CalcDirLight(directional_lights[i], norm, viewDir, current_mat);

      for(uint i = 0u; i < nr_point_lights; i++)
        result += CalcPointLight(point_lights[i], norm, FragPos, viewDir, current_mat); 
     
      for(uint i = 0u; i < nr_spot_lights; i++)
        result += CalcSpotLight(spot_lights[i], norm, FragPos, viewDir, current_mat); 

      color = vec4(result, 1.0f);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewPos, Material current_material) {
    // Ambient
    vec3 ambient = light.ambient * current_material.ambient;

    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * current_material.diffuse;

    //Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), current_material.shininess);
    vec3 specular = light.specular * spec * current_material.specular;

    return (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewPos, Material current_material)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewPos, reflectDir), 0.0), current_material.shininess);

    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    
    // Combine results
    vec3 ambient = light.ambient * current_material.ambient;
    vec3 diffuse = light.diffuse * diff * current_material.diffuse;
    vec3 specular = light.specular * spec * current_material.specular;

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, Material current_material)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // Spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    // Combine results
    vec3 ambient = light.ambient * current_material.ambient;
    vec3 diffuse = light.diffuse * diff * current_material.diffuse;
    vec3 specular = light.specular * spec * current_material.specular;
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}


