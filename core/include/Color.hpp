#ifndef COLOR_HPP
#define COLOR_HPP

#include <stdint.h>
#include <glm/glm.hpp>

namespace soap {

struct RGBColor
{
    uint8_t r;
    uint8_t g;
    uint8_t b;

    inline glm::vec3 toVec3() const {return glm::vec3( (float) (r) /256, (float) (g) /256, (float) (b) /256);}



};

namespace Color {
    constexpr RGBColor black    =   RGBColor{0,    0,    0};
    constexpr RGBColor white    =   RGBColor{255, 255, 255};
    constexpr RGBColor red      =   RGBColor{255,   0,   0};
    constexpr RGBColor green    =   RGBColor{  0, 255,   0};
    constexpr RGBColor blue     =   RGBColor{  0,   0, 255};
    constexpr RGBColor yellow   =   RGBColor{255, 255,   0};
    constexpr RGBColor cyan     =   RGBColor{  0, 255, 255};
    constexpr RGBColor magenta  =   RGBColor{255,   0, 255};
    constexpr RGBColor gray     =   RGBColor{100, 100, 100};

}

}

#endif // COLOR_H
