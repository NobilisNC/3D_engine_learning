#include "Texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace soap;

Texture::Texture(std::string path, Type type) : _type(type){

    std::replace(path.begin(), path.end(), '\\', '/');

    int width, height, comp;

    unsigned char* image = stbi_load(path.c_str(), &width, &height, &comp, 4);


    if(image == nullptr)
        std::cerr << "[TEXTURE] - Error loading : " << path << std::endl;

    gl::GenTextures(1, &_id);
    gl::BindTexture(gl::TEXTURE_2D, _id);

    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, gl::REPEAT);
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, gl::REPEAT);


    gl::TexImage2D(gl::TEXTURE_2D, 0, gl::RGBA, width, height, 0,gl::RGBA, gl::UNSIGNED_BYTE, image);

    gl::GenerateMipmap(gl::TEXTURE_2D);
    stbi_image_free(image);
    gl::BindTexture(gl::TEXTURE_2D, 0);
}

void Texture::bind(GLuint unit) {
    gl::ActiveTexture(gl::TEXTURE0 + unit);
    gl::BindTexture(gl::TEXTURE_2D, _id);
}

void Texture::unbind() {
    gl::BindTexture(gl::TEXTURE_2D, 0);

}
