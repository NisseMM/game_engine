#include <rendering/mesh.h>
#include <rendering/vertex_layout.h>

Mesh::Mesh(VertexBuffer &&vbo,
           VertexLayout const&layout,
           IndexBuffer &&ebo)
    : vao_{}, vbo_{std::move(vbo)}, ebo_{std::move(ebo)}
{
    vao_.addBuffer(vbo_, layout);
    vao_.setIndexBuffer(ebo_);
}

void Mesh::draw() const
{
    vao_.bind();
    glDrawElements(GL_TRIANGLES, ebo_.count(), GL_UNSIGNED_INT, nullptr);
}

void Mesh::bind() const
{
    vao_.bind();
}
