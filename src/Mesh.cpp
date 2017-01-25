#include "Mesh.hpp"

Mesh::Mesh(const VertexArray& vertices)
    : _vertices(vertices)
{
    gl::GenVertexArrays(1, &_VAO);
    gl::BindVertexArray(_VAO);
        gl::GenBuffers(1, &_VBO);
        gl::BindBuffer(gl::ARRAY_BUFFER, _VBO);
        gl::BufferData(gl::ARRAY_BUFFER, sizeof(vertices[0])* _vertices.size(), _vertices.data(), gl::STATIC_DRAW);

        gl::VertexAttribPointer(0, 3, gl::FLOAT, false, 8 * sizeof(GLfloat), (GLvoid*)0 );
        gl::EnableVertexAttribArray(0);

        gl::VertexAttribPointer(1, 3, gl::FLOAT, false, 8 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)) );
        gl::EnableVertexAttribArray(1);


        gl::VertexAttribPointer(2, 2, gl::FLOAT, false, 8 * sizeof(GLfloat), (GLvoid*)(6*sizeof(GLfloat)) );
        gl::EnableVertexAttribArray(2);

    gl::BindVertexArray(0);

}

Mesh::~Mesh()
{
    gl::DeleteBuffers(1, &_VBO);
    gl::DeleteVertexArrays(1, &_VAO);
}

void Mesh::draw(Shader &shader)
{

    shader.use();
    unsigned nb_textured = 0;
    for(GLint i = 0; i < _materials.size(); i++) {
        if (_materials[i]->isTextured()) {

            std::string name = "texMaterials[" + std::to_string(nb_textured) + "]";
            shader.uniform(name, *_materials[i], true, nb_textured );
            nb_textured += 2;
        } else {
            std::string name = "materials[" + std::to_string(i) + "]";
            shader.uniform(name, *_materials[i] );
        }
    }
    GLint nb_textured_materials = nb_textured / 2 ;
    std::cerr << nb_textured_materials << std::endl;

    GLint nb_materials = _materials.size() - nb_textured_materials  ;

    shader.uniform("nb_materials_dyn", nb_materials);
    shader.uniform("nb_textured_materials_dyn", nb_textured_materials);



    gl::BindVertexArray(_VAO);
    gl::DrawArrays(gl::TRIANGLES, 0, _vertices.size());
    gl::BindVertexArray(0);


}
