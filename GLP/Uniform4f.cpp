#include "Uniform4f.hpp"
#include <GL/glew.h>


namespace GLP
{
    Uniform4f::Uniform4f(const Program& t_prog, const char* t_name):
    m_UID(glGetUniformLocation(t_prog.getUID(), t_name))
    {}
    void Uniform4f::setValue(float v0, float v1, float v2, float v3)
    {
        glUniform4f(m_UID, v0, v1, v2, v3);
    }
} // namespace GLP
