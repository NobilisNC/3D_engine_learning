#pragma once

#include <vector>
#include "gl_core_3_3.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
namespace soap {


class KeyboardListener {
    public :
        virtual void keyPressed(bool* keys) = 0;
};

class MouseListener {
    public :
        virtual void mouseMoved(double xpos, double ypos) = 0;
};

class EventsHandler {
    private :
        static std::vector<KeyboardListener*> _keyboardListener;
        static bool* _keys;

        static std::vector<MouseListener*> _mouseListener;

        static void broadcastKeyboardEvent();
        static void broadcastMouseEvent(double xpos, double ypos);

    public :
        static GLfloat deltaTimeFrame;

        static void init();
        static void addKeyboardListener(KeyboardListener* obj);
        static void addMouseListener(MouseListener* obj);

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
        static void mouse_callback(GLFWwindow* window, double xpos, double ypos);



};

}
