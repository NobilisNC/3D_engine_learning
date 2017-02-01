#include <iostream>

#include "gl_core_3_3.hpp"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Shader.hpp"
#include "Texture.hpp"
#include "Camera.hpp"
#include "EventsHandler.hpp"
#include "Debug.hpp"
#include "Material.hpp"
#include "Mesh.hpp"
#include "MyScene.hpp"

const std::string DATA_PATH = "/home/nobilis/coding/perso/c++/openGL/";


soap::Camera cam1(glm::vec3(0.0f, 0.0f, 5.0f));



const GLuint WIDTH = 800, HEIGHT = 600;


int main()
{

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, false);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Test", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    soap::EventsHandler::init();
    glfwSetKeyCallback(window, soap::EventsHandler::key_callback);
    glfwSetCursorPosCallback(window, soap::EventsHandler::mouse_callback);




    /*if(!gl::sys::LoadFunctions())
        throw 'a';

    gl::Enable(gl::DEPTH_TEST);*/


    int width, height;

    glfwGetFramebufferSize(window, &width, &height);
    //gl::Viewport(0, 0, width, height);
    MyScene scene(width, height);


   /* soap::Shader lightingShader(DATA_PATH + "data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/light.shader");
    //Shader lightingShader(DATA_PATH + "data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/bug.shader");
    soap::Shader lightSourceShader(DATA_PATH +"data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/source_light.shader");

    soap::Texture cubeTexture(DATA_PATH +"data/textures/container2.png");
    soap::Texture cubeTexture_spec(DATA_PATH +"data/textures/container2_specular.png", soap::Texture::SPECULAR);

    soap::Material lightMaterial({100, 100, 100}, {200,200,200}, soap::Color::white);
    soap::Material cubeMaterial({100,100,100}, soap::Color::blue, soap::Color::cyan);
    soap::Material cubeMaterial2({200,100,100}, soap::Color::blue, soap::Color::blue);
    cubeMaterial2.setTextured(&cubeTexture, &cubeTexture_spec);


    glm::mat4 projection;
    projection = glm::perspective(45.0f, GLfloat(WIDTH) / HEIGHT, 0.1f, 100.0f);


    soap::VertexArray verticesCube ={
        // Positions           // Normals           // Texture Coords
        {{-0.5f, -0.5f, -0.5f}, {0.0f,  0.0f, -1.0f},  {0.0f, 0.0f}},
        {{0.5f, -0.5f, -0.5f},  {0.0f,  0.0f, -1.0f},  {1.0f, 0.0f}},
        {{0.5f,  0.5f, -0.5f},  {0.0f,  0.0f, -1.0f},  {1.0f, 1.0f}},
        {{0.5f,  0.5f, -0.5f},  {0.0f,  0.0f, -1.0f},  {1.0f, 1.0f}},
        {{-0.5f,  0.5f, -0.5f}, {0.0f,  0.0f, -1.0f},  {0.0f, 1.0f}},
        {{-0.5f, -0.5f, -0.5f}, {0.0f,  0.0f, -1.0f},  {0.0f, 0.0f}},

        {{-0.5f, -0.5f,  0.5f},  {0.0f,  0.0f, 1.0f},  {0.0f, 0.0f}},
        {{0.5f, -0.5f,  0.5f},   {0.0f,  0.0f, 1.0f},  {1.0f, 0.0f}},
        {{0.5f,  0.5f,  0.5f},   {0.0f,  0.0f, 1.0f},  {1.0f, 1.0f}},
        {{0.5f,  0.5f,  0.5f},   {0.0f,  0.0f, 1.0f},  {1.0f, 1.0f}},
        {{-0.5f,  0.5f,  0.5f},  {0.0f,  0.0f, 1.0f},  {0.0f, 1.0f}},
        {{-0.5f, -0.5f,  0.5f},  {0.0f,  0.0f, 1.0f},  {0.0f, 0.0f}},

        {{-0.5f,  0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f}, {1.0f, 0.0f}},
        {{-0.5f,  0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f}, {1.0f, 1.0f}},
        {{-0.5f, -0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f}, {0.0f, 1.0f}},
        {{-0.5f, -0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f}, {0.0f, 1.0f}},
        {{-0.5f, -0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f}, {0.0f, 0.0f}},
        {{-0.5f,  0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f}, {1.0f, 0.0f}},

        {{0.5f,  0.5f,  0.5f},  {1.0f,  0.0f,  0.0f},  {1.0f, 0.0f}},
        {{0.5f,  0.5f, -0.5f},  {1.0f,  0.0f,  0.0f},  {1.0f, 1.0f}},
        {{0.5f, -0.5f, -0.5f},  {1.0f,  0.0f,  0.0f},  {0.0f, 1.0f}},
        {{0.5f, -0.5f, -0.5f},  {1.0f,  0.0f,  0.0f},  {0.0f, 1.0f}},
        {{0.5f, -0.5f,  0.5f},  {1.0f,  0.0f,  0.0f},  {0.0f, 0.0f}},
        {{0.5f,  0.5f,  0.5f},  {1.0f,  0.0f,  0.0f},  {1.0f, 0.0f}},

        {{-0.5f, -0.5f, -0.5f}, {0.0f, -1.0f,  0.0f},  {0.0f, 1.0f}},
        {{0.5f, -0.5f, -0.5f},  {0.0f, -1.0f,  0.0f},  {1.0f, 1.0f}},
        {{0.5f, -0.5f,  0.5f},  {0.0f, -1.0f,  0.0f},  {1.0f, 0.0f}},
        {{0.5f, -0.5f,  0.5f},  {0.0f, -1.0f,  0.0f},  {1.0f, 0.0f}},
        {{-0.5f, -0.5f,  0.5f}, {0.0f, -1.0f,  0.0f},  {0.0f, 0.0f}},
        {{-0.5f, -0.5f, -0.5f}, {0.0f, -1.0f,  0.0f},  {0.0f, 1.0f}},

        {{-0.5f,  0.5f, -0.5f}, {0.0f,  1.0f,  0.0f},  {0.0f, 1.0f}},
        {{0.5f,  0.5f, -0.5f},  {0.0f,  1.0f,  0.0f},  {1.0f, 1.0f}},
        {{0.5f,  0.5f,  0.5f},  {0.0f,  1.0f,  0.0f},  {1.0f, 0.0f}},
        {{0.5f,  0.5f,  0.5f},  {0.0f,  1.0f,  0.0f},  {1.0f, 0.0f}},
        {{-0.5f,  0.5f,  0.5f}, {0.0f,  1.0f,  0.0f},  {0.0f, 0.0f}},
        {{-0.5f,  0.5f, -0.5f}, {0.0f,  1.0f,  0.0f},  {0.0f, 1.0f}}
    };


    soap::Mesh cubeMesh(verticesCube);
    //cubeMesh.setMaterial(&cubeMaterial);
    cubeMesh.setMaterial(&cubeMaterial2);


    soap::Mesh lightMesh(verticesCube);
    lightMesh.setMaterial(&lightMaterial);






    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);



    checkError();*/


    GLfloat lastFrame = 0.0f;
    while (!glfwWindowShouldClose(window))
    {
        GLfloat currentFrame = (GLfloat)glfwGetTime();
        soap::EventsHandler::deltaTimeFrame = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        /*lightingShader.use();

        gl::ClearColor(0.f, 0.f, 0.f, 1.0f);

        gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);

        glm::mat4 view = cam1.getView();



        glm::mat4 model;
        model = glm::translate(model, glm::vec3(0.0f));

        lightingShader.uniform("view", view);
        lightingShader.uniform("model", model);
        lightingShader.uniform("projection", projection);


        lightingShader.uniform("light", lightMaterial);
        lightingShader.uniform("light.pos", lightPos);
        lightingShader.uniform("viewPos", cam1.position());

        cubeMesh.draw(lightingShader);


        // --- lighting SOURCE --- //
        lightSourceShader.use();

        GLfloat radius = 1.f;
        lightPos.x = sin(glfwGetTime()) * radius;
        lightPos.y = sin(glfwGetTime()) * radius;
        lightPos.z = cos(glfwGetTime()) * radius;

        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f));

        lightSourceShader.uniform("view", view);
        lightSourceShader.uniform("model", model);
        lightSourceShader.uniform("projection", projection);
        lightSourceShader.uniform("lightColor", lightMaterial.diffuse.toVec3());

        lightMesh.draw(lightSourceShader);*/

        scene.draw();



        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}
