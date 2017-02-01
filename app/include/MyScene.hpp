#ifndef MYSCENE_HPP
#define MYSCENE_HPP

#include <chrono>

#include "Scene.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"

class MyScene : public soap::Scene
{
private :
    soap::Shader lightShader;
    soap::Shader objectShader;

    soap::Mesh cube;
    soap::Mesh cubeLight;

    soap::Texture textCube;
    soap::Texture textCube_spec;

    soap::Material cubeMaterial;
    soap::Material lightMaterial;

    soap::Camera cam;


public:
    MyScene(int h, int w);

    virtual void render();
    virtual void init();

};

#endif // MYSCENE_HPP
