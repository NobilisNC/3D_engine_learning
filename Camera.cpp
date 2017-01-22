#include "Camera.hpp"


Camera::Camera(glm::vec3 pos) : _pos(pos), _front(0.0f, 0.0f, -1.0f), _up(0.0f, 1.0f, 0.0f)
{

}

glm::mat4 Camera::getView() {
    return glm::lookAt(_pos, _pos + _front, _up);
}

#include <iostream>

void Camera::keyPressed(bool* keys) {

    GLfloat speed = 5.0f * EventsHandler::deltaTimeFrame;

    if(keys[GLFW_KEY_W])
        forward(speed);
    if(keys[GLFW_KEY_S])
        backward(speed);
    if(keys[GLFW_KEY_A])
        left(speed);
    if(keys[GLFW_KEY_D])
        right(speed);
}
