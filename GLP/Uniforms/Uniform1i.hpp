#pragma once
#include "IUniform.hpp"


namespace GLP
{
    class Uniform1i: public IUniform
    {
    public:
        Uniform1i() = default;
        Uniform1i(const GLP::Uniform1i& other) = default;
        Uniform1i(GLP::Uniform1i&& other) = default;
        Uniform1i(const Program& t_prog, const char* t_name);
        void setValue(int v0);
    };
    
    
} // namespace GLP
