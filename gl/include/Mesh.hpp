#ifndef MESH_HPP
#define MESH_HPP

#include <iostream>

#include "gl_core_3_3.hpp"
#include "Vertex.hpp"
#include "Texture.hpp"
#include "Material.hpp"
#include "Shader.hpp"
#include "SimpleMaterial.hpp"
#include "Global.hpp"


namespace soap {


class Mesh
{
private :
    GLuint _VAO, _VBO;
    VertexArray _vertices;
    MaterialKey _material;

    void construct();
    void destroy();
public:
    Mesh();
    Mesh(const VertexArray& vertices);
    ~Mesh();

    inline void setMaterial(MaterialKey material) noexcept {_material = material;}
    inline void setVertices(const VertexArray& vertices) {_vertices = vertices; construct();}

    void draw(Shader& shader);
};

}

#endif // MESH_H
