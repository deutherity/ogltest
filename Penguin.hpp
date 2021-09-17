#pragma once
#include "IEntity.hpp"
#include "GLP/Buffer.hpp"
#include "GLP/VertexArray.hpp"
#include "GLP/Texture.hpp"
#include <memory>


class Penguin: public IEntity
{
private:
    GLP::Buffer m_vertexBuffer;
    GLP::Buffer m_indexBuffer;
    GLP::VertexArray m_vao;
    std::unique_ptr<GLP::Texture> m_texture;
public:
    Penguin();
    ~Penguin();
    void frame();
    void Draw(GLP::Renderer& renderer) override;
};