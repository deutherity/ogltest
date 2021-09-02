#include "Renderer.hpp"
#include <GL/glew.h>


namespace GLP
{
    void Renderer::Draw(const VertexArray& vao) const
    {
        vao.Draw();
    }

    void Renderer::SetShader(const Program& renderer)
    {
        renderer.Use();
    }
} // namespace GLP
