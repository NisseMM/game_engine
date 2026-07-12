#ifndef MESH_H
#define MESH_H

#include <rendering/vertex_array.h>
#include <rendering/vertex_buffer.h>
#include <rendering/index_buffer.h>

class Mesh
{
public:
    Mesh(VertexBuffer && vbo, 
        VertexLayout const& layout, 
        IndexBuffer && ebo);

    Mesh(Mesh&&) noexcept = default;
    Mesh& operator=(Mesh&&) noexcept = default;

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    void draw() const;

    void bind() const;

private:
        VertexArray vao_;
        VertexBuffer vbo_;
        IndexBuffer ebo_;
};




#endif //MESH_H