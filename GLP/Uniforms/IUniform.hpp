#pragma once
#include "../Program.hpp"
#include "../GLtypes.hpp"

namespace GLP
{
    class IUniform
    {
    protected:
        GLuint m_UID = -1;
    public:
        IUniform() = default;
        IUniform(const Program& t_prog, const char* t_name);
        virtual ~IUniform();
        GLuint getUID() const;

        void setName(const Program& t_program, const char* t_name);

    };
    
} // namespace GLP
