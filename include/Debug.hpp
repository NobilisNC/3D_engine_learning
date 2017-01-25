#pragma once

#include "gl_core_3_3.hpp"

void glCheckError(const char* file, int ligneline);

#define checkError() glCheckError(__FILE__, __LINE__)
