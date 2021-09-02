#pragma once
#include "Program.hpp"
#include "GLtypes.hpp"


namespace GLP
{
    class Uniform4f
    {
    private:
        GLuint m_UID;
    public:
        Uniform4f(const Program& program, const char* name);
        void setValue(float v0, float v1, float v2, float v3);
    };
    
} // namespace GLP
