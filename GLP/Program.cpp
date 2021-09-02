#include "Program.hpp"
#include <GL/glew.h>
#include <stdexcept>
#include <iostream>


namespace GLP
{
    Program::Program():
    m_UID(glCreateProgram())
    {}
    
    Program::~Program()
    {
        glDeleteProgram(m_UID);
    }
    
    inline void Program::throwIfInvalid() const
    {
        if (m_status == Status::Invalid)
        {
            throw std::logic_error("Tried to use invalid program");
        }
    }

    programId_t Program::getUID() const
    {
        return m_UID;
    }

    Program::Status Program::getStatus() const
    {
        return m_status;
    }

    void Program::AttachShader(const Shader* shader)
    {
        if (m_status != Status::Initialized)
        {
            throw std::logic_error("You tried to attach shader after linking");
        }
        m_shadersAttached[static_cast<unsigned char>(shader->getType())] = shader;
    }
    
    void Program::Link()
    {
        if (m_status != Status::Initialized)
        {
            throw std::logic_error("You tried to link already linked program");
        }
        for (unsigned char i = 0; i < 6; i++)
        {
            if (m_shadersAttached[i] != nullptr)
            {
                glAttachShader(m_UID, m_shadersAttached[i]->getUID());
            }
        }
        glLinkProgram(m_UID);
        m_status = Status::Linked;
    }

    bool Program::Valid(bool debug) const
    {
        if (m_status == Status::Invalid)
        {
            return false;
        }
        if (m_status == Status::Initialized)
        {
            throw std::logic_error("Prorgam is not linked");
        }
        glValidateProgram(m_UID);

        GLint res;
        glGetProgramiv(m_UID, GL_VALIDATE_STATUS, &res);
        if (res != GL_TRUE)
        {
            m_status = Status::Invalid;
            if (debug)
            {
                char buffer[1024];
                GLsizei length;
                glGetProgramInfoLog(m_UID, 1024, &length, buffer);
                std::cout.write(buffer, length); 
                std::cout << '\n';
            }
            return false;
        }
        return true;
    }

    void Program::Use() const
    {
        throwIfInvalid();
        if (m_status != Status::Linked)
        {
            throw std::logic_error("You tried to use unlinked program or program is already in use");
        }
        
        glUseProgram(m_UID);
        m_status = Status::Used;

    }

    void Program::doEverything()
    {
        this->Link();
        this->Use();
    }


} // namespace GLP
