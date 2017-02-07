#ifndef MYSCENE_HPP
#define MYSCENE_HPP

#include <chrono>

#include "Scene.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"
#include "SimpleMaterial.hpp"
#include "TexturedMaterial.hpp"
#include "DirectionalLight.hpp"

class MyScene : public soap::Scene
{
private :
    soap::Shader lightShader;
    soap::Shader objectShader;

    soap::Mesh cube;
    soap::Mesh cubeLight;
    soap::Mesh floor;

    soap::Texture textCube;
    soap::Texture textCube_spec;
    soap::Texture grass;
    soap::Texture default_spec;

    soap::TexturedMaterial cubeMaterial;
    soap::SimpleMaterial lightMaterial;
    soap::TexturedMaterial floorMaterial;

    soap::Camera cam;

    soap::DirectionalLight light0;
    soap::PointLight plight0;
    soap::SpotLight splight0;

    soap::Model nanosuit;


public:
    MyScene(int h, int w);

    virtual void render();
    virtual void init();

};

#endif // MYSCENE_HPP
