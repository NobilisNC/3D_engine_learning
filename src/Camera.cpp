#include "Camera.hpp"


Camera::Camera(glm::vec3 pos) : _pos(pos), _front(0.0f, 0.0f, -1.0f), _up(0.0f, 1.0f, 0.0f), _yaw(-90.0f), _pitch(0.0f)
{
    EventsHandler::addKeyboardListener(this);
    EventsHandler::addMouseListener(this);
}

glm::mat4 Camera::getView() {
    return glm::lookAt(_pos, _pos + _front, _up);
}

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

void Camera::mouseMoved(double xpos, double ypos) {
    static GLfloat lastX = 0.0f, lastY = 0.0f;

    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    GLfloat sensitivity = 0.05;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    _yaw   += xoffset;
    _pitch += yoffset;

    if(_pitch > 89.0f)
        _pitch = 89.0f;
    if(_pitch < -89.0f)
        _pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
    front.y = sin(glm::radians(_pitch));
    front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
    _front = glm::normalize(front);

}
