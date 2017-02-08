#include "MyScene.hpp"


const std::string DATA_PATH = "/home/nobilis/coding/perso/c++/soap/";

MyScene::MyScene(int h, int w) :
    soap::Scene(h,w) ,
    lightShader(DATA_PATH +"data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/source_light.shader"),
    objectShader(DATA_PATH + "data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/light.shader"),
    cam(glm::vec3(0.0f, 0.0f, 5.0f)),
    light0(glm::vec3(1,0,0), soap::SimpleMaterial(soap::Color::white, soap::Color::white, soap::Color::white, 16)),
    plight0(glm::vec3(1,-0.5,0), soap::SimpleMaterial(), 1, 0.9f, 0.032),
    splight0(glm::vec3(0,3,0), soap::SimpleMaterial(), 1, 0.9f, 0.032, {0,-1,0}, 15.f, 17.f),
    nanosuit(DATA_PATH + "data/Obj/Psyduck/Psyduck.obj"),
    hitler(DATA_PATH + "data/Obj/hitler/hitler.obj")
{


  this->init();
}

void MyScene::init()
{
    setProjection(glm::perspective(45.0f, GLfloat(width()) / height(), 0.1f, 100.0f));



    addLight(&light0);
    addLight(&plight0);
    //addLight(&splight0);

    //gl::ClearColor(soap::Color::gray.r,soap::Color::gray.g,soap::Color::gray.b, 1.0f);
}


void MyScene::render()
{


    objectShader.use();
    setView(cam.getView());

    bindLights(objectShader);

    objectShader.uniform("viewPos", cam.position());

    static float i = 0;

    setModel(glm::mat4());
    setModel( glm::translate(model(), glm::vec3(.0f, -0.f, 0.0f)));
    setModel(glm::scale(model(), glm::vec3(0.2f, 0.2f, 0.2f)));
    setModel(glm::rotate(model(), glm::radians(180.f), glm::vec3(0,0,1) ));
    setModel(glm::rotate(model(), i, glm::vec3(0,1,0) ));

    sendMatrix(objectShader);
    nanosuit.draw(objectShader);
    i+=0.1f;

    float taille = 0.04f * abs(sin(i));
    setModel(glm::mat4());
    //setModel( glm::translate(model(), glm::vec3(.0f, -0.f, 1.0f)));
    setModel(glm::scale(model(), glm::vec3(0.02f, taille, 0.02f)));
    sendMatrix(objectShader);
    hitler.draw(objectShader);












    // --- lighting SOURCE --- //

    lightShader.use();
    GLfloat radius = 1.f;

    plight0.position().x = sin(glfwGetTime()) * radius;
    plight0.position().y = sin(glfwGetTime()) * radius;
    plight0.position().z = cos(glfwGetTime()) * radius;
    setModel(glm::mat4());

    setModel( glm::translate(model(), plight0.position()));
    setModel(glm::scale(model(), glm::vec3(0.2f)));

    sendMatrix(lightShader);

}


