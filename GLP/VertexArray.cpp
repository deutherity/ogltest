#include "VertexArray.hpp"
#include <iostream>
#include <GL/glew.h>
#include <cassert>


GLP::VertexArray::VertexArray(Buffer *buf, IVertexArrayLayout *layout, Buffer *indBuf):
m_info(layout), m_buffer(buf), m_indBuf(indBuf)
{
    glCreateVertexArrays(1, &m_UID);
    this->Bind();
    buf->Bind();
    layout->setVertexInfo();
    assert(indBuf->getType() == Buffer::Type::ElementArray);
    indBuf->Bind();
}

GLP::VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_UID);
}

void GLP::VertexArray::Bind() const
{
    glBindVertexArray(m_UID);
}

void GLP::VertexArray::Unbind() const
{
    glBindVertexArray(0);
}

void GLP::VertexArray::pollInfo()
{
    this->Bind();
    m_buffer->Bind();
    m_info->setVertexInfo();
}

void GLP::VertexArray::Draw() const
{
    this->Bind();
    auto foo = m_indBuf->getSize();
    std::cout << foo << '\n';
    glDrawElements(GL_TRIANGLES, foo, GL_UNSIGNED_INT, 0);
}

