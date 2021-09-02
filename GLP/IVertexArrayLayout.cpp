#include "IVertexArrayLayout.hpp"

namespace GLP
{
    IVertexArrayLayout::IVertexArrayLayout(std::size_t t_size):
    m_size(static_cast<GLsizei>(t_size))
    {}

    GLsizei IVertexArrayLayout::getIndexCount() const
    {
        return m_size;
    }
} // namespace GLP
