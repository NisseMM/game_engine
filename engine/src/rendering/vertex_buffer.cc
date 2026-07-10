#include <rendering/vertex_buffer.h>

#include <glad/gl.h>

VertexBuffer::VertexBuffer()
    : buffer_object_{0}
{
    glGenBuffers(1, &buffer_object_);
}

VertexBuffer::VertexBuffer(std::initializer_list<float> list)
    : VertexBuffer{}
{
    bind();
    upload(list);
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, buffer_object_);
}

void VertexBuffer::upload(std::initializer_list<float> list)
{
    glBufferData(GL_ARRAY_BUFFER, list.size() * sizeof(float), list.begin(), GL_STATIC_DRAW);
}

void VertexBuffer::upload(std::vector<float> const &list)
{
    glBufferData(GL_ARRAY_BUFFER, list.size() * sizeof(float), list.data(), GL_STATIC_DRAW);
}