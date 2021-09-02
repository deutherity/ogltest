#pragma once
#include "VertexArray.hpp"
#include "Program.hpp"


namespace GLP
{
    
    class Renderer
    {

    public:

        void Draw(const VertexArray& vao) const;
        void SetShader(const Program &prog);
    };
    
} // namespace GLP
