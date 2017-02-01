#include "Scene.hpp"

using namespace soap;

Scene::Scene(int width, int height) :
    _width(width),
    _height(height)
{
    if(!gl::sys::LoadFunctions())
        throw std::runtime_error("[OPENGL] - Error loading OpenGL");

    gl::Enable(gl::DEPTH_TEST);
    gl::Viewport(0, 0, width, height);

    _init();
}

Scene::~Scene()
{

}

void Scene::draw()
{
    _render();
}

void Scene::initialize()
{
    _init();
}

void Scene::sendMatrix(Shader& shader)
{
    shader.uniform("view", _view);
    shader.uniform("model", _model);
    shader.uniform("projection", _projection);
}

void Scene::_init()
{
    gl::ClearColor(0.f, 0.f, 0.f, 1.0f);
}

void Scene::_render()
{

    gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);
    render();
}

void Scene::init()
{

}

void Scene::render()
{

}




