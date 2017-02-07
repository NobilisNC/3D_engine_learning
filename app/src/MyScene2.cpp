#include "MyScene2.hpp"


const std::string DATA_PATH = "/home/nobilis/coding/perso/c++/openGL/";

MyScene2::MyScene2(int h, int w) :
    soap::Scene(h,w) ,
    lightShader(DATA_PATH +"data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/source_light.shader"),
    objectShader(DATA_PATH + "data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/light.shader"),
    lightMat(soap::Color::white, soap::Color::white,soap::Color::white, 16),
    plight0(glm::vec3(1,-0.5,0), &lightMat, 1, 0.9f, 0.032),
    nanosuit(DATA_PATH + "data/Obj/nanosuit/nanosuit.obj"),
    cam(glm::vec3(0.0f, 0.0f, 5.0f))
{

    this->init();
}

void MyScene2::init()
{
    setProjection(glm::perspective(45.0f, GLfloat(width()) / height(), 0.1f, 100.0f));
    addLight(&plight0);

}


void MyScene2::render()
{


    objectShader.use();
    setView(cam.getView());
    objectShader.uniform("viewPos", cam.position());

    nanosuit.draw(objectShader);






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
    //cubeLight.draw(lightShader);
}


