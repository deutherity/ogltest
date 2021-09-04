#include "Uniform1i.hpp"
#include <GL/glew.h>


namespace GLP
{
    Uniform1i::Uniform1i(const Program& t_prog, const char *t_name):
    IUniform(t_prog, t_name)
    {}

    void Uniform1i::setValue(int v0)
    {
        glUniform1i(this->getUID(), v0);
    }
} // namespace GLP
