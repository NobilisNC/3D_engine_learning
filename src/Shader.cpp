#include "Shader.hpp"

Shader::Shader(std::string vertexPath, std::string fragmentPath) : _program(0) {


    //Load Source Code from File
    std::ifstream vertexFile(vertexPath);
    std::ifstream fragmentFile(fragmentPath);

    if(!fragmentFile.is_open() || !vertexFile.is_open())
        throw std::runtime_error("[ERROR] - SHADERS FILES");

    std::string vertexCodeStr((std::istreambuf_iterator<char>(vertexFile)), std::istreambuf_iterator<char>());
    std::string fragmentCodeStr((std::istreambuf_iterator<char>(fragmentFile)), std::istreambuf_iterator<char>());

    const GLchar * vertexCode = vertexCodeStr.c_str();
    const GLchar * fragmentCode = fragmentCodeStr.c_str();

    //Create OpenGL Shaders
    GLuint vertex, fragment;
    GLint success;
    GLchar infoLog[512];

    vertex = gl::CreateShader(gl::VERTEX_SHADER);
    gl::ShaderSource(vertex, 1, &vertexCode, NULL);
    gl::CompileShader(vertex);

    gl::GetShaderiv(vertex, gl::COMPILE_STATUS, &success);
    if(!success) {
        gl::GetShaderInfoLog(vertex, 512, NULL, infoLog);
        throw std::runtime_error(std::string("[ERROR] - VERTEX SHADER :") + std::string((const char*)infoLog));
    }

    fragment = gl::CreateShader(gl::FRAGMENT_SHADER);
    gl::ShaderSource(fragment, 1, &fragmentCode, NULL);
    gl::CompileShader(fragment);

    gl::GetShaderiv(fragment, gl::COMPILE_STATUS, &success);
    if(!success) {
        gl::GetShaderInfoLog(fragment, 512, NULL, infoLog);
        throw std::runtime_error(std::string("[ERROR] - FRAGMENT SHADER :") + std::string((const char*)infoLog));
    }

    _program = gl::CreateProgram();
    gl::AttachShader(_program, vertex);
    gl::AttachShader(_program, fragment);
    gl::LinkProgram(_program);

    gl::GetProgramiv(_program, gl::LINK_STATUS, &success);
    if(!success) {
        gl::GetProgramInfoLog(_program, 512, NULL, infoLog);
        throw std::runtime_error(std::string("[ERROR] - LINK SHADERS :") + std::string((const char*)infoLog));
    }

    gl::DeleteShader(vertex);
    gl::DeleteShader(fragment);
}

void Shader::use() {
    gl::UseProgram(_program);
}
