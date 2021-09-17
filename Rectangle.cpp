#include "Rectangle.hpp"
#include "GLP/Uniforms/Uniform4f.hpp"
#include "GLP/IVertexArrayLayout.hpp"

#include <GL/glew.h>
#include <array>

#include <cmath>

static constexpr float pi = 3.1415926f;

typedef unsigned int uint;


static constexpr float x = 0.9f;

static constexpr std::array positions {
    -x, -x,
     x, -x,
     x,  x,
    -x,  x
    
};

static constexpr std::array<uint, 2 * 3> indices = {
    0,1,2,
    0,2,3
};

class PositLayout: public GLP::IVertexArrayLayout
{
public:
    PositLayout(std::size_t t_size):
    IVertexArrayLayout(t_size)
    {}
    void setVertexInfo() const override
    {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*) 0 );
        glEnableVertexAttribArray(0);
    }
};

static PositLayout info(sizeof(indices) / sizeof(uint));



Rectangle::Rectangle():
m_vertexBuffer(GLP::Buffer::Type::Array, positions),
m_indexBuffer(GLP::Buffer::Type::ElementArray, indices),
m_vao(&m_vertexBuffer, &info, &m_indexBuffer)
{
    GLP::Shader frag(GLP::Shader::Type::Fragment, std::string("./src/shaders/Rectangle/frag.fs"));
    frag.doEverything();
    GLP::Shader vert(GLP::Shader::Type::Vertex, std::string("./src/shaders/Rectangle/vert.vs"));
    vert.doEverything();


    m_program.AttachShader(&frag);
    m_program.AttachShader(&vert);

    m_program.Link();

    m_colorUniform.setName(m_program, "u_Color");
}


void Rectangle::frame()
{
    m_program.Use();

    if (m_time >= pi && m_incr > 0)
        m_incr = -time_step;
    if (m_time <= 0 && m_incr < 0)
        m_incr = time_step;
        
    m_time += m_incr;
    
    m_colorUniform.setValue(std::sin(m_time), std::sin(m_time + pi * 2 / 3), std::sin(m_time + pi * 4 / 3), 1.0f);
}

void Rectangle::Draw(GLP::Renderer& renderer)
{
    renderer.Draw(m_vao);
}

Rectangle::~Rectangle()
{
}