#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include "Texture.hpp"
#include "EntityManager.hpp"

namespace soap {

namespace Manager {
    extern EntityManager<std::string, Texture> texture;
}


}

#endif
