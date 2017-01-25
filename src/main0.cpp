#include <iostream>

#include "gl_core_3_3.hpp"

// GLFW
#include <GLFW/glfw3.h>

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

const std::string DATA_PATH = "/home/nobilis/coding/perso/c++/openGL/";


Camera cam1(glm::vec3(0.0f, 0.0f, 5.0f));



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


    EventsHandler::init();
    glfwSetKeyCallback(window, EventsHandler::key_callback);
    glfwSetCursorPosCallback(window, EventsHandler::mouse_callback);


    if(!gl::sys::LoadFunctions())
        throw 'a';

    checkError();

    gl::Enable(gl::DEPTH_TEST);

    checkError();


    int width, height;

    glfwGetFramebufferSize(window, &width, &height);
    gl::Viewport(0, 0, width, height);


    //Shader lightingShader(DATA_PATH + "data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/light.shader");
    Shader lightingShader(DATA_PATH + "data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/bug.shader");
    Shader lightSourceShader(DATA_PATH +"data/shaders/vertex/2.shader", DATA_PATH +"data/shaders/fragment/source_light.shader");

    Texture cubeTexture(DATA_PATH +"data/textures/container2.png");
    Texture cubeTexture_spec(DATA_PATH +"data/textures/container2_specular.png", Texture::SPECULAR);

    Material lightMaterial({100, 100, 100}, Color::yellow, Color::white);
    Material cubeMaterial({100,100,100}, Color::white, Color::white);
    Material cubeMaterial2({200,100,100}, Color::blue, Color::blue);
    cubeMaterial2.setTextured(&cubeTexture, &cubeTexture_spec);


    glm::mat4 projection;
    projection = glm::perspective(45.0f, GLfloat(WIDTH) / HEIGHT, 0.1f, 100.0f);


    VertexArray verticesCube ={
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


    Mesh cubeMesh(verticesCube);
    cubeMesh.addMaterial(&cubeMaterial);
    cubeMesh.addMaterial(&cubeMaterial2);
    //cubeMesh.addMaterial(&cubeMaterial2);
    //cubeMesh.addTexture(&cubeTexture);
    //cubeMesh.addTexture(&cubeTexture_spec);

    Mesh lightMesh(verticesCube);
    lightMesh.addMaterial(&lightMaterial);


    GLuint cubeVBO;
    GLuint cubeVAO, lightVAO;
    gl::GenBuffers(1, &cubeVBO);
    gl::GenVertexArrays(1, &cubeVAO);
    gl::GenVertexArrays(1, &lightVAO);



    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);



    checkError();


    GLfloat lastFrame = 0.0f;
    while (!glfwWindowShouldClose(window))
    {
        GLfloat currentFrame = (GLfloat)glfwGetTime();
        EventsHandler::deltaTimeFrame = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        lightingShader.use();

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

        lightMesh.draw(lightSourceShader);



        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}
