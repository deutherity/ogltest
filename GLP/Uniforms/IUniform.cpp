#include "IUniform.hpp"
#include <GL/glew.h>
#include <stdexcept>


namespace GLP
{
    IUniform::IUniform(const Program& t_prog, const char* t_name):
    m_UID(glGetUniformLocation(t_prog.getUID(), t_name))
    {
        if (m_UID == static_cast<GLuint>(-1))
        {
            throw std::runtime_error("Wrong uniform name or program");
        }
    }

    IUniform::~IUniform()
    {}

    GLuint IUniform::getUID() const
    {
        return m_UID;
    }
    
    void IUniform::setName(const GLP::Program& program, const char* name)
    {
        m_UID = glGetUniformLocation(program.getUID(), name);
        if (m_UID == static_cast<GLuint>(-1))
        {
            throw std::runtime_error("Wrong uniform name or program");
        }
    }
} // namespace GLP
