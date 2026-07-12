#include <rendering/index_buffer.h>

#include <glad/gl.h>



IndexBuffer::IndexBuffer()
    : buffer_object_{0}, count_{0}
{
    glGenBuffers(1, &buffer_object_);
}

IndexBuffer::IndexBuffer(std::initializer_list<unsigned int> list)
    : IndexBuffer{}
{
    bind();
    upload(list);
    count_ = list.size();
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &buffer_object_);
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_object_);
}

void IndexBuffer::upload(std::initializer_list<unsigned int> list)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, list.size() * sizeof(unsigned int), list.begin(), GL_STATIC_DRAW);
}

void IndexBuffer::upload(std::vector<unsigned int> const &list)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, list.size() * sizeof(unsigned int), list.data(), GL_STATIC_DRAW);
}

size_t IndexBuffer::count() const
{
    return count_;
}