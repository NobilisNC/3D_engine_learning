#include "Mesh.hpp"

Mesh::Mesh(const VertexArray& vertices)
    : _vertices(vertices)
{
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);
        glGenBuffers(1, &_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0])* _vertices.size(), _vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0 );
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)) );
        glEnableVertexAttribArray(1);


        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6*sizeof(GLfloat)) );
        glEnableVertexAttribArray(2);

    glBindVertexArray(0);

}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &_VBO);
    glDeleteVertexArrays(1, &_VAO);
}

void Mesh::draw(Shader &shader)
{
    shader.use();

    for(GLint i = 0; i < _materials.size(); i++) {
        std::string name = "materials[" + std::to_string(i) + "]";
        shader.uniform(name, *_materials[i]);
    }


    for(GLint i = 0; i < _textures.size(); i++) {
        std::string name = "materials[" + std::to_string(i) + "]";
        shader.uniform(name, *_materials[i]);
        _textures[i]->bind(i);

        if(_textures[i]->getType() == Texture::DIFFUSE)
            shader.uniform(name + ".diffuse", i);
        else if (_textures[i]->getType() == Texture::SPECULAR)
            shader.uniform(name + ".specular", i);
    }

    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
    glBindVertexArray(0);


}
