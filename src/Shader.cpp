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

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        throw std::runtime_error(std::string("[ERROR] - VERTEX SHADER :") + std::string((const char*)infoLog));
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        throw std::runtime_error(std::string("[ERROR] - FRAGMENT SHADER :") + std::string((const char*)infoLog));
    }

    _program = glCreateProgram();
    glAttachShader(_program, vertex);
    glAttachShader(_program, fragment);
    glLinkProgram(_program);

    glGetProgramiv(_program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(_program, 512, NULL, infoLog);
        throw std::runtime_error(std::string("[ERROR] - LINK SHADERS :") + std::string((const char*)infoLog));
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() {
    glUseProgram(_program);
}
