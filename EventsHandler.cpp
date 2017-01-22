#include "EventsHandler.hpp"

bool* EventsHandler::_keys = nullptr;
std::vector<KeyboardListener*> EventsHandler::_keyboardListener = std::vector<KeyboardListener*> ();
 GLfloat EventsHandler::deltaTimeFrame = 0.0f;

void EventsHandler::init() {
    _keys = new bool[1024];

}

void EventsHandler::broadcastKeyboardEvent() {
    for(auto& obj : _keyboardListener )
        obj->keyPressed(_keys);
}

void EventsHandler::addKeyboardListener(KeyboardListener* obj) {
    _keyboardListener.push_back(obj);
}

void EventsHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if(action == GLFW_PRESS)
        _keys[key] = true;
    else if(action == GLFW_RELEASE)
        _keys[key] = false;

    broadcastKeyboardEvent();
}
