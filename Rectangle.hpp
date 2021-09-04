#pragma once
#include "IEntity.hpp"
#include <memory>
#include "GLP/Uniforms/Uniform4f.hpp"
#include "GLP/Buffer.hpp"
#include "GLP/VertexArray.hpp"


class Rectangle: public IEntity
{
private:
    GLP::Uniform4f m_colorUniform;
    GLP::Buffer m_vertexBuffer;
    GLP::Buffer m_indexBuffer;
    GLP::VertexArray m_vao;
    float m_time = 0.0f;
    float m_incr = 0.01f;
public:
    Rectangle();
    ~Rectangle();
    void frame();
    void Draw(GLP::Renderer& renderer) override;
};
