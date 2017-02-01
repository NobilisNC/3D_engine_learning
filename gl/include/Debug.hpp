#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "gl_core_3_3.hpp"

void glCheckError(const char* file, int ligneline);

#define checkError() glCheckError(__FILE__, __LINE__)

#endif
