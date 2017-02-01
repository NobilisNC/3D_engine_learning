#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <stdexcept>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Mesh.hpp"
#include "Light.hpp"

namespace soap {

class Scene
{
private :
    int _width;
    int _height;
    std::vector<Mesh*> _meshes;
    std::vector<Light*> _lights;

    glm::mat4 _projection;
    glm::mat4 _model;
    glm::mat4 _view;

    void _init();
    void _render();


protected :
    virtual void init();
    virtual void render();


public :
    Scene(int width = 400, int height = 800);
    ~Scene();

    void draw();
    void initialize();
    void sendMatrix(Shader& shader);


    inline void setProjection(glm::mat4 projection) {_projection = projection;}
    inline glm::mat4 projection() const {return _projection;}
    inline void setView(glm::mat4 view) {_view = view;}
    inline glm::mat4 view() const {return _view;}
    inline void setModel(glm::mat4 model) {_model= model;}
    inline glm::mat4 model() const {return _model;}
    inline int width() const { return _width;}
    inline int height() const {return _height;}

    inline void addMesh(Mesh* mesh) { _meshes.push_back(mesh);}
     inline void addLight(Light* light) { _lights.push_back(light);}

};

}

#endif
