#pragma once
#include "Shader.hpp"
#include "GLtypes.hpp"


namespace GLP
{
    typedef GLuint programId_t;

    class Program
    {
    public:
        enum class Status
        {
            Initialized,
            Linked,
            Used,
            Invalid
        };

    private:
        const programId_t m_UID;

        // GL_COMPUTE_SHADER, GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER, GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER, or GL_FRAGMENT_SHADER    
        mutable Status m_status = Status::Initialized;
        const GLP::Shader* m_shadersAttached[6] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
        inline void throwIfInvalid() const;
    public:
        Program();
        ~Program();

        void AttachShader(const Shader* shader);
        void Link();
        bool Valid(bool debug = false) const;
        void Use() const;
        void doEverything();

        programId_t getUID() const;
        Status getStatus() const;

    };
    
    
} // namespace GLP
