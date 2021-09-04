#include "GL/glew.h"
#include "IGLapp.hpp"
#include <stdexcept>


IGLapp::IGLapp()
{
    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("GL init error");
    }
}

void IGLapp::resizeEvent(const short width, const short height) const
{
    glViewport(0,0, width, height);
}

void IGLapp::addEntity(std::unique_ptr<IEntity>&& entity)
{
    m_entities_all.push_back(entity.get());
    m_entities_for_destructing.push_back(std::move(entity));
}

void IGLapp::addEntity(IEntity* entity)
{
    m_entities_all.push_back(entity);
}

void IGLapp::frame()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (const auto& entity: m_entities_all)
    {
        entity->frame();
    }
    
}

void IGLapp::draw()
{
    for (const auto& entity: m_entities_all)
    {
        entity->DrawSetup(m_renderer);
        entity->Draw(m_renderer);
    }
}
