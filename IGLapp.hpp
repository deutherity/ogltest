#pragma once
#include "IEntity.hpp"
#include "GLP/Renderer.hpp"
#include <vector>
#include <memory>


class IGLapp
{
protected:
    std::vector<std::unique_ptr<IEntity>> m_entities_for_destructing;
    std::vector<IEntity*> m_entities_all;

    GLP::Renderer m_renderer;
public:
    IGLapp();
    
    IGLapp(const IGLapp& other) = delete;
    IGLapp& operator= (const IGLapp& other) = delete;

    // renders frames
    void frame();
    virtual void updateState() = 0;
    void draw();

    void addEntity(std::unique_ptr<IEntity>&& entity); // IGLapp would call destructors for those
    void addEntity(IEntity* entity); // wouldn't

    virtual void resizeEvent(const short width, const short height) const;

    virtual ~IGLapp() = default;
};




