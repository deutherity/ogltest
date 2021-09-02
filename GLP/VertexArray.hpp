#pragma once
#include "GLtypes.hpp"
#include "Buffer.hpp"
#include "IVertexArrayLayout.hpp"

namespace GLP
{
    typedef GLuint VArrId_t;

    
    
    class VertexArray
    {
    private:
        VArrId_t m_UID;
        bool m_hasIndBuf;
        IVertexArrayLayout *m_info;
        Buffer *m_buffer;
        Buffer *m_indBuf;

    public:
        VertexArray(Buffer *buffer, IVertexArrayLayout *info, Buffer *indBuf);
        ~VertexArray();

        void Bind() const;
        void Unbind() const;
        void Draw() const;
        void pollInfo();
    };
    
} // namespace GLP
