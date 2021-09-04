#pragma once
#include "../Program.hpp"
#include "../GLtypes.hpp"
#include "IUniform.hpp"


namespace GLP
{
    class Uniform4f: public IUniform
    {
    public:
        Uniform4f() = default;
        Uniform4f(const Program& program, const char* name);
        void setValue(float v0, float v1, float v2, float v3);
    };
    
} // namespace GLP
