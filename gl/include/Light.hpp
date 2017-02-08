#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/glm.hpp>
#include "SimpleMaterial.hpp"

namespace soap {

class Light
{
public :


protected :
    SimpleMaterial _material;
    glm::vec3 _position;


public :
    Light(glm::vec3 position, SimpleMaterial&& material);
    ~Light();

    virtual void bind(Shader &shader) = 0;

    inline const glm::vec3& position() const {return _position;}
    inline       glm::vec3& position()       {return _position;}

    inline SimpleMaterial  material() const {return _material;}
    inline SimpleMaterial material()        {return _material;}


};

}
#endif // LIGHT_HPP
