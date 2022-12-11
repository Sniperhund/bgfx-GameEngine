#pragma once
#include <bgfx/bgfx.h>

class Shaders
{
public:
    static bgfx::ShaderHandle LoadShader(const char* FILENAME);
};
