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
#include "MyScene2.hpp"

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


    int width, height;

    glfwGetFramebufferSize(window, &width, &height);

    MyScene scene(width, height);
    //MyScene2 scene(width, height);





    GLfloat lastFrame = 0.0f;
    while (!glfwWindowShouldClose(window))
    {
        GLfloat currentFrame = (GLfloat)glfwGetTime();
        soap::EventsHandler::deltaTimeFrame = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();



        scene.draw();



        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}
