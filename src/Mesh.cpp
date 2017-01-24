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
    unsigned nb_textured = 0;
    for(GLint i = 0; i < _materials.size(); i++) {
        if (_materials[i]->isTextured()) {
            std::string name = "texMaterials[" + std::to_string(i) + "]";
            shader.uniform(name, *_materials[i], true, nb_textured );
            nb_textured += 2;
        } else {
            std::string name = "materials[" + std::to_string(i) + "]";
            shader.uniform(name, *_materials[i] );
        }
    }
    GLint nb_textured_materials = nb_textured / 2;
    GLint nb_materials = _materials.size() - nb_textured_materials  ;

    shader.uniform("dynamic_nb_materials", nb_materials);
    shader.uniform("dynamic_nb_textured_materials", nb_textured_materials);



    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
    glBindVertexArray(0);


}
