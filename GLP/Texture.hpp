#pragma once
#include "GLtypes.hpp"
#include <string>
#include "Renderer.hpp"


namespace GLP
{
    class Texture
    {
    private:
        GLuint m_UID;
        std::string m_filePath;
        uchar* m_localBuffer;
        int m_width, m_height, m_BPP;
    public:
        Texture(const std::string& t_path);
        ~Texture();
        void Bind(GLuint slot) const;
        void Unbind() const;
    };
    
} // namespace GLP
