#pragma once
#include "GLtypes.hpp"


namespace GLP
{
    class IVertexArrayLayout
    {
        private:
        GLsizei m_size;
        public:
        IVertexArrayLayout(std::size_t size);
        virtual void setVertexInfo() const = 0;
        virtual GLsizei getIndexCount() const;
    };
    
} // namespace GLP
