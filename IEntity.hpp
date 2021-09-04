#pragma once
#include "GLP/Program.hpp"
#include "GLP/Renderer.hpp"


class IEntity
{
protected:
    GLP::Program m_program;
public:

    void DrawSetup(GLP::Renderer& renderer);
    virtual void frame() = 0;
    virtual void Draw(GLP::Renderer& renderer) = 0;
    

    virtual ~IEntity() = default;
};
