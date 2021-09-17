#pragma once
#include "GLtypes.hpp"
#include <string>
#include "Renderer.hpp"
#include "Uniforms/Uniform1i.hpp"
#include "Program.hpp"


namespace GLP
{
    class Texture
    {
    private:
        GLuint m_UID;
        std::string m_filePath;
        uchar* m_localBuffer;
        int m_width, m_height, m_BPP;
        GLP::Uniform1i m_slotUniform;
    public:
        Texture() = default;
        Texture(std::string_view name, std::string_view t_path, const GLP::Program& program);
        Texture(Texture&& other);
        ~Texture();
        void Bind(GLuint slot);
        void Unbind() const;
    };
    
} // namespace GLP
