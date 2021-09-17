#include "Penguin.hpp"
#include "GLP/IVertexArrayLayout.hpp"
#include <GL/glew.h>

#include <array>


static constexpr std::array positions {
    -0.5f, -0.5f, 0.0f, 0.0f,
     0.5f, -0.5f, 1.0f, 0.0f,
     0.5f, 0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, 0.0f, 1.0f
    
};

static constexpr std::array<uint, 2 * 3> indices = {
    0,1,2,
    0,2,3
};


class TextureLayout: public GLP::IVertexArrayLayout
{
public:
    TextureLayout(std::size_t size):
    IVertexArrayLayout(size)
    {}
    void setVertexInfo() const override
    {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*) 0 );
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*) 8 );
        glEnableVertexAttribArray(1);
    }
};

static TextureLayout info(sizeof(indices) / sizeof(uint));



Penguin::Penguin():
m_vertexBuffer(GLP::Buffer::Type::Array, positions),
m_indexBuffer(GLP::Buffer::Type::ElementArray, indices),
m_vao(&m_vertexBuffer, &info, &m_indexBuffer)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    GLP::Shader frag(GLP::Shader::Type::Fragment, std::string("./src/shaders/Texture/frag.fs"));
    frag.doEverything();
    GLP::Shader vert(GLP::Shader::Type::Vertex, std::string("./src/shaders/Texture/vert.vs"));
    vert.doEverything();


    m_program.AttachShader(&frag);
    m_program.AttachShader(&vert);

    m_program.Link();

    m_texture = std::make_unique<GLP::Texture>("u_Texture", "./res/icon.png", m_program);
}

void Penguin::frame()
{
}

void Penguin::Draw(GLP::Renderer& renderer)
{
    m_texture->Bind(0);
    renderer.Draw(m_vao);
}

Penguin::~Penguin()
{
}