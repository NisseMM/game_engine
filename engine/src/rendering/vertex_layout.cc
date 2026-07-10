#include <rendering/vertex_layout.h>

std::vector<VertexAttrib> const &VertexLayout::attributes() const
{
    return attributes_;
}

size_t VertexLayout::stride() const
{
    return stride_;
}