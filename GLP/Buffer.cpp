#include "Buffer.hpp"
#include <stdexcept>
#include <GL/glew.h>


namespace GLP
{
    Buffer::Buffer(Buffer::Type t_type, uint size, const void* data,
                   const FreqHint h1, const AccessHint h2):
        m_type(t_type),
        m_size(size),
        m_data(data),
        m_usageHint(makeUsageHint(h1, h2))
    {
        if (t_type == Type::ElementArray)
        {
            m_count = size / sizeof(uint);
        }
        initGLbuffer();
    }

    void Buffer::initGLbuffer()
    {
        auto type = makeBindType(m_type);
        glGenBuffers(1, &m_UID);
        glBindBuffer(type, m_UID);
        glBufferData(type, m_size, m_data, m_usageHint);
    }

    constexpr inline GLenum Buffer::makeUsageHint(const FreqHint h1, const AccessHint h2)
    {
        switch (static_cast<uchar>(h1) * 3 + static_cast<uchar>(h2))
        {
        case 0:
            return GL_STREAM_DRAW;
        case 1:
            return GL_STREAM_READ;
        case 2:
            return GL_STREAM_COPY;
        case 3:
            return GL_STATIC_DRAW;
        case 4:
            return GL_STATIC_READ;
        case 5:
            return GL_STATIC_COPY;
        case 6:
            return GL_DYNAMIC_DRAW;
        case 7:
            return GL_DYNAMIC_READ;
        case 8:
            return GL_DYNAMIC_COPY;
        default:
            throw std::runtime_error("Error inside GLP library. Please report it.");
        }
    }

    constexpr inline GLenum Buffer::makeBindType(Type t_type)
    // Only 2 types for now
    {
        switch (t_type)
        {
        case Type::Array:
            return GL_ARRAY_BUFFER;
        case Type::ElementArray:
            return GL_ELEMENT_ARRAY_BUFFER;
        
        // TODO: Add more types
        
        default:
            throw std::runtime_error("Error inside GLP library. Please report it.");
        }
    }
    void Buffer::Bind() const
    {
        glBindBuffer(makeBindType(m_type), m_UID);
    }

    void Buffer::Unbind() const
    {
        glBindBuffer(makeBindType(m_type), 0);
    }

    Buffer::~Buffer()
    {
        glDeleteBuffers(1, &m_UID);
    }

    Buffer::Type Buffer::getType() const
    {
        return m_type;
    }

    bufferId_t Buffer::getId() const
    {
        return m_UID;
    }

    GLsizei Buffer::getCount() const
    {
        return m_count;
    }

} // namespace GLP
