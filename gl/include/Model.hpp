#ifndef MODEL_HPP
#define MODEL_HPP


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include <string>

#include "Mesh.hpp"
#include "TexturedMaterial.hpp"
#include "Global.hpp"


namespace soap {


class Model
{
private :
    std::vector<Mesh*> _meshes;
    std::string _path;

    void loadModel(std::string& path);
    void processNode(aiNode& node,  const aiScene& scene);
    void processMesh(aiMesh& mesh,  const aiScene& scene);
    void processMaterial(Mesh& mesh, aiMaterial& material);

public:
    Model(std::string path);



    void draw(Shader& shader);
};

}
#endif // MODEL_HPP
