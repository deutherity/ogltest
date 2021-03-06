#pragma once
#include "IEntity.hpp"
#include "GLP/Uniforms/Uniform4f.hpp"
#include "GLP/Buffer.hpp"
#include "GLP/VertexArray.hpp"


class Rectangle: public IEntity
{
private:
    static constexpr float time_step = 0.01f;
    GLP::Uniform4f m_colorUniform;
    GLP::Buffer m_vertexBuffer;
    GLP::Buffer m_indexBuffer;
    GLP::VertexArray m_vao;
    float m_time = 0.0f;
    float m_incr = time_step;
public:
    Rectangle();
    ~Rectangle();
    void frame();
    void Draw(GLP::Renderer& renderer) override;
};
