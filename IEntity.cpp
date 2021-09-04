#include "IEntity.hpp"


void IEntity::DrawSetup(GLP::Renderer& renderer)
{
    renderer.SetShader(m_program);
}
