#include "Model.hpp"

using namespace soap;

Model::Model(std::string path)
    :_path(path.substr(0, path.find_last_of('/')+1))
{
    loadModel(path);
}

void Model::loadModel(std::string &path)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        throw std::runtime_error("[Assimp] ==  Error loading Model : " + path + " -- Infos : " + importer.GetErrorString());

    processNode(*(scene->mRootNode), *scene);
}

void Model::processNode(aiNode& node, const aiScene &scene) {

    for(int i = 0; i < node.mNumMeshes; i++ )
    {
        aiMesh& mesh = *(scene.mMeshes[node.mMeshes[i]]);
        processMesh(mesh, scene);
    }

    for(uint i = 0; i < node.mNumChildren; i++)
        processNode(*(node.mChildren[i]), scene);
}

void Model::processMesh(aiMesh &mesh, const aiScene &scene) {

    VertexArray vertices;


    for(uint i = 0; i < mesh.mNumVertices; i++) {
        Vertex v;
        v.position = { mesh.mVertices[i].x, mesh.mVertices[i].y, mesh.mVertices[i].z };
        v.normal   = { mesh.mNormals[i].x , mesh.mNormals[i].y , mesh.mNormals[i].z  };
        if (mesh.mTextureCoords[0])
            v.texture = { mesh.mTextureCoords[0][i].x, mesh.mTextureCoords[0][i].y};
        vertices.push_back(v);
    }

    Mesh* new_mesh = new Mesh(vertices);

    if (mesh.mMaterialIndex >= 0) {
        aiMaterial& material = *(scene.mMaterials[mesh.mMaterialIndex]);
        processMaterial(*new_mesh, material);
        processMaterial(*new_mesh, material);
     }

    _meshes.push_back(new_mesh);
}

void Model::processMaterial(Mesh &mesh, aiMaterial &material) {

    aiString path;
    material.GetTexture(aiTextureType_DIFFUSE, 0, &path);
    TextureKey text_diff = Manager::texture(_path + path.C_Str()).insert(Texture(_path + path.C_Str(), Texture::DIFFUSE));

    material.GetTexture(aiTextureType_SPECULAR, 0, &path);
    TextureKey text_spec = Manager::texture(_path + path.C_Str()).insert(Texture(_path + path.C_Str(), Texture::SPECULAR));

    mesh.setMaterial(
                Manager::material(std::to_string(text_diff.hash) + std::to_string(text_spec.hash))
                     (TexturedMaterial({100,100,100}, text_diff, text_spec, 16.f))
                );

}

void Model::draw(Shader &shader) {

  for(auto& mesh : _meshes )
      mesh->draw(shader);
}
