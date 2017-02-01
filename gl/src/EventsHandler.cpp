#include "EventsHandler.hpp"
using namespace soap;

bool* EventsHandler::_keys = nullptr;
std::vector<KeyboardListener*> EventsHandler::_keyboardListener = std::vector<KeyboardListener*> ();
std::vector<MouseListener*> EventsHandler::_mouseListener = std::vector<MouseListener*> ();
 GLfloat EventsHandler::deltaTimeFrame = 0.0f;

void EventsHandler::init() {
    _keys = new bool[1024];
    for (size_t i = 0; i < 1024; i++)
        _keys[i] = false;

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
        glfwSetWindowShouldClose(window, true);

    if(action == GLFW_PRESS)
        _keys[key] = true;
    else if(action == GLFW_RELEASE)
        _keys[key] = false;

    broadcastKeyboardEvent();
}

void EventsHandler::addMouseListener(MouseListener* obj) {
    _mouseListener.push_back(obj);
}

void EventsHandler::broadcastMouseEvent(double xpos, double ypos) {
    for(auto& obj : _mouseListener )
        obj->mouseMoved(xpos, ypos);

}

void EventsHandler::mouse_callback(GLFWwindow* window, double xpos, double ypos) {

    broadcastMouseEvent(xpos, ypos);
}
