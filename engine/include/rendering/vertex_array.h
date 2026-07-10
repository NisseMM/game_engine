#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <vector>

class VertexLayout;

class VertexBuffer;

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    VertexArray(VertexArray const&) = delete;
    VertexArray& operator=(VertexArray const&) = delete;

    VertexArray(VertexArray&& other) noexcept;
    VertexArray& operator=(VertexArray&& other) noexcept;

    void addBuffer(VertexBuffer const &buffer, VertexLayout const &layout);

    void bind() const;

private:
    unsigned int array_object_;
};

#endif // VERTEX_ARRAY_H