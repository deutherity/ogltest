#include "Texture.hpp"
#include <GL/glew.h>
#include "lib/stb_image.h"


namespace GLP
{
    Texture::Texture(std::string_view name, std::string_view t_path, const GLP::Program& program):
    m_filePath(t_path), m_slotUniform(program, name.data())
    {
        stbi_set_flip_vertically_on_load(1);
        m_localBuffer = stbi_load(t_path.data(), &m_width, &m_height, &m_BPP, 4);

        glGenTextures(1, &m_UID);
        glBindTexture(GL_TEXTURE_2D, m_UID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);
        
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(m_localBuffer);
    }

    Texture::Texture(GLP::Texture&& other):
    m_UID(other.m_UID),
    m_filePath(std::move(other.m_filePath)),
    m_localBuffer(other.m_localBuffer),
    m_width(other.m_width), m_height(other.m_height), m_BPP(other.m_BPP),
    m_slotUniform(std::move(other.m_slotUniform))
    {
        other.m_UID = 0;
    }

    Texture::~Texture()
    {
        if (m_UID)
        {
            glDeleteTextures(1, &m_UID);
        }
    }

    void Texture::Bind(GLuint slot)
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_UID);
        m_slotUniform.setValue(slot);
    }

    void Texture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    
} // namespace GLP
