#include <glad/gl.h>

template <typename T>
VertexBuffer::VertexBuffer(std::vector<T> list)
    : VertexBuffer{}
{
    bind();
    upload(list);
}

template <typename T>
void VertexBuffer::upload(std::vector<T> const &list)
{
    glBufferData(GL_ARRAY_BUFFER, list.size() * sizeof(T), list.data(), GL_STATIC_DRAW);
}