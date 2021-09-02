#pragma once
#include "GLtypes.hpp"


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
        constexpr static GLenum makeUsageHint(FreqHint h1, AccessHint h2);
        constexpr inline static GLenum makeBindType(Type t_type);

    public:
        Buffer(Type t_type, const uint dataSize, const void* data,
               const FreqHint h1 = FreqHint::Static,
               const AccessHint h2 = AccessHint::Draw);
        ~Buffer();

        Buffer(const Buffer& other) = delete;
        Buffer(Buffer&& other) = delete;
        Buffer& operator=(const Buffer& other) = delete;
        Buffer& operator=(Buffer&& other) = delete;
        
        Type getType() const;
        bufferId_t getId() const;
        GLsizei getSize() const;

        void Bind() const;
        void Unbind() const;

    };

} // namespace GLP
