#ifndef MYSCENE2_HPP
#define MYSCENE2_HPP

#include <chrono>

#include "Scene.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"
#include "SimpleMaterial.hpp"
#include "TexturedMaterial.hpp"
#include "DirectionalLight.hpp"
#include "Model.hpp"

class MyScene2 : public soap::Scene
{
private :
    soap::Shader lightShader;
    soap::Shader objectShader;
    soap::SimpleMaterial lightMat;
    soap::PointLight plight0;
    soap::Model  nanosuit;

    soap::Camera cam;



public:
    MyScene2(int h, int w);

    virtual void render();
    virtual void init();

};

#endif // MYSCENE_HPP
