#include "Mesh.hpp"

using namespace soap;

void Mesh::construct()
{

    destroy();
    gl::GenVertexArrays(1, &_VAO);
    gl::BindVertexArray(_VAO);
        gl::GenBuffers(1, &_VBO);
        gl::BindBuffer(gl::ARRAY_BUFFER, _VBO);
        gl::BufferData(gl::ARRAY_BUFFER, sizeof(_vertices[0])* _vertices.size(), _vertices.data(), gl::STATIC_DRAW);

        gl::VertexAttribPointer(0, 3, gl::FLOAT, false, 8 * sizeof(GLfloat), (GLvoid*)0 );
        gl::EnableVertexAttribArray(0);

        gl::VertexAttribPointer(1, 3, gl::FLOAT, false, 8 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)) );
        gl::EnableVertexAttribArray(1);


        gl::VertexAttribPointer(2, 2, gl::FLOAT, false, 8 * sizeof(GLfloat), (GLvoid*)(6*sizeof(GLfloat)) );
        gl::EnableVertexAttribArray(2);

        gl::BindVertexArray(0);
}

void Mesh::destroy()
{
    gl::DeleteBuffers(1, &_VBO);
    gl::DeleteVertexArrays(1, &_VAO);
}

Mesh::Mesh()
{

}

Mesh::Mesh(const VertexArray& vertices)
    : _vertices(vertices)
{
    construct();
}

Mesh::~Mesh()
{
    destroy();
}

void Mesh::draw(Shader &shader)
{
    shader.use();

    _material->bind(shader);

    gl::BindVertexArray(_VAO);
        gl::DrawArrays(gl::TRIANGLES, 0, _vertices.size());
    gl::BindVertexArray(0);
}
