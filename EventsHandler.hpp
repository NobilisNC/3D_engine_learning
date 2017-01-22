#pragma once

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class KeyboardListener {
    public :
        virtual void keyPressed(bool* keys) = 0;
};

class EventsHandler {
    private :
        static std::vector<KeyboardListener*> _keyboardListener;
        static bool* _keys;
        static void broadcastKeyboardEvent();

    public :
        static GLfloat deltaTimeFrame;

        static void init();
        static void addKeyboardListener(KeyboardListener* obj);
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);



};
