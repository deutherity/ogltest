#include "Uniform4f.hpp"
#include <GL/glew.h>


namespace GLP
{
    Uniform4f::Uniform4f(const Program& t_prog, const char* t_name):
    IUniform(t_prog, t_name)
    {}

    void Uniform4f::setValue(float v0, float v1, float v2, float v3)
    {
        glUniform4f(this->getUID(), v0, v1, v2, v3);
    }
} // namespace GLP
