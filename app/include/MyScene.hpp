#ifndef MYSCENE_HPP
#define MYSCENE_HPP

#include <chrono>
#include <cmath>

#include "Scene.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"
#include "SimpleMaterial.hpp"
#include "TexturedMaterial.hpp"
#include "DirectionalLight.hpp"
#include "Texture.hpp"
#include "Global.hpp"

class MyScene : public soap::Scene
{
private :
    soap::Shader lightShader;
    soap::Shader objectShader;

    soap::Camera cam;

    soap::DirectionalLight light0;
    soap::PointLight plight0;
    soap::SpotLight splight0;

    soap::Model nanosuit;
    soap::Model hitler;



public:
    MyScene(int h, int w);

    virtual void render();
    virtual void init();

};

#endif // MYSCENE_HPP
