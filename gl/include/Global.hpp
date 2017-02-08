#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include "Texture.hpp"
#include "EntityManager.hpp"
#include "Material.hpp"

namespace soap {

namespace Manager {
    extern EntityManager<std::string, Texture> texture;
    extern EntityManager<std::string, Material> material;
}


}

#endif
