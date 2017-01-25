#ifndef MESH_H
#define MESH_H

#include "gl_core_3_3.hpp"
#include "Vertex.hpp"
#include "Texture.hpp"
#include "Material.hpp"
#include "Shader.hpp"

class Mesh
{
private :
    GLuint _VAO, _VBO;
    VertexArray _vertices;
    std::vector<Texture*> _textures;
    std::vector<Material*> _materials;

public:
    Mesh(const VertexArray& vertices);
    ~Mesh();

    inline void addTexture(Texture* texture)   noexcept {_textures.push_back(texture);  }
    inline void addMaterial(Material* material) noexcept {_materials.push_back(material);}

    void draw(Shader& shader);


};

#endif // MESH_H
