#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "EventsHandler.hpp"

class Camera : public KeyboardListener {
    private :
        glm::vec3 _pos;
        glm::vec3 _front;
        glm::vec3 _up;

    public :
        Camera(glm::vec3 pos);
        glm::mat4 getView();

        inline void setPos(const glm::vec3& pos) {_pos=pos;}
        inline glm::vec3 getPos() const {return _pos;}

        inline void forward(GLfloat speed)      { _pos += speed * _front; }
        inline void backward(GLfloat speed)     { _pos -= speed * _front; }
        inline void left(GLfloat speed)         { _pos -= glm::normalize(glm::cross(_front, _up)) * speed; }
        inline void right(GLfloat speed)         { _pos += glm::normalize(glm::cross(_front, _up)) * speed; }

        //Events
        virtual void keyPressed(bool* keys);



};
