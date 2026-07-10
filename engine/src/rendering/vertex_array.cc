#include <rendering/vertex_array.h>
#include <rendering/vertex_layout.h>
#include <rendering/vertex_buffer.h>

#include <glad/gl.h>

VertexArray::VertexArray()
    : array_object_{}
{
    glGenVertexArrays(1, &array_object_);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &array_object_);
}

VertexArray::VertexArray(VertexArray&& other) noexcept
    : array_object_{}
{
    *this = std::move(other);
}

VertexArray& VertexArray::operator=(VertexArray&& other) noexcept
{
    std::swap(array_object_, other.array_object_);
    return *this;
}

void VertexArray::addBuffer(VertexBuffer const &buffer, VertexLayout const &layout)
{
    bind();
    buffer.bind();

    for (auto const& attrib: layout.attributes())
    {
        glEnableVertexAttribArray(attrib.index);

        glVertexAttribPointer(
            attrib.index,
            attrib.count,
            attrib.type,
            attrib.normalize,
            layout.stride(),
            reinterpret_cast<void*>(attrib.offset)
        );
    }
}

void VertexArray::bind() const
{
    glBindVertexArray(array_object_);
}