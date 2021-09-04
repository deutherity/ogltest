#pragma once
#include "GLtypes.hpp"
#include <array>


namespace GLP
{
    typedef GLuint bufferId_t;
    

    class Buffer
    {
    public:
        enum class FreqHint: uchar
        {
            Stream,
            Static,
            Dynamic
        };

        enum class AccessHint: uchar
        {
            Draw,
            Read,
            Copy
        };

        enum class Type: uchar
        // Only 2 because i dont know any of those. Also check Buffer::makeBindType before modifying
        {
            Array,
            //AtomicCounter,
            //CopyRead,
            //CopyWrite,
            //DispatchIndirect,
            //DrawIndirect,
            ElementArray,
            //PixelPack,
            //PixelUnpack,
            //Query,
            //ShaderStorage,
            //Texture,
            //TransformFeedback,
            //Uniform
        };

    private:
        bufferId_t m_UID;
        const Type m_type;
        GLsizei m_size = 0;
        GLsizei m_count = 0;
        const void * m_data;
        GLenum m_usageHint;
        constexpr inline static GLenum makeUsageHint(const FreqHint h1, const AccessHint h2);
        constexpr inline static GLenum makeBindType(Type t_type);

        void initGLbuffer();

    public:
        Buffer(Type t_type, const uint dataSize, const void* data,
               const FreqHint h1 = FreqHint::Static,
               const AccessHint h2 = AccessHint::Draw);
        ~Buffer();

        template <typename T, std::size_t size>
        Buffer(Buffer::Type t_type, const std::array<T, size>& data,
                        const FreqHint h1 = FreqHint::Static,
                        const AccessHint h2 = AccessHint::Draw):
            m_type(t_type),
            m_size(size * sizeof(T)),
            m_count(size),
            m_data(data.data()),
            m_usageHint(makeUsageHint(h1, h2))
        {
            if (t_type == Type::ElementArray)
            {
                m_count = size;
            }
            initGLbuffer();
        }

        Buffer(const Buffer& other) = delete;
        Buffer(Buffer&& other) = delete;
        Buffer& operator=(const Buffer& other) = delete;
        Buffer& operator=(Buffer&& other) = delete;
        
        Type getType() const;
        bufferId_t getId() const;
        GLsizei getCount() const;

        void Bind() const;
        void Unbind() const;

    };

} // namespace GLP
