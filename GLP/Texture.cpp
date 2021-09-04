#include "Texture.hpp"
#include <GL/glew.h>
#include "lib/stb_image.h"


namespace GLP
{
    Texture::Texture(const std::string& t_path):
    m_filePath(t_path)
    {
        stbi_set_flip_vertically_on_load(1);
        m_localBuffer = stbi_load(t_path.c_str(), &m_width, &m_height, &m_BPP, 4);

        glGenTextures(1, &m_UID);
        glBindTexture(GL_TEXTURE_2D, m_UID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);
        
        glBindTexture(GL_TEXTURE_2D, 0);
        if (m_localBuffer)
        {
            stbi_image_free(m_localBuffer);
        }
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &m_UID);
    }

    void Texture::Bind(GLuint slot) const
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_UID);
    }

    void Texture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    
} // namespace GLP
