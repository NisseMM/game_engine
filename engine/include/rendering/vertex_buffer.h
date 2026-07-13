#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <vector>

class VertexBuffer
{
public:
    VertexBuffer();
    VertexBuffer(std::initializer_list<float> list);

    template <typename T>
    VertexBuffer(std::vector<T> list);

    ~VertexBuffer();

    VertexBuffer(VertexBuffer const &) = delete;
    VertexBuffer &operator=(VertexBuffer const &) = delete;

    VertexBuffer(VertexBuffer &&other) noexcept;
    VertexBuffer &operator=(VertexBuffer &&other) noexcept;

    void bind() const;

    void upload(std::initializer_list<float> list);
    template <typename T>
    void upload(std::vector<T> const &list);

private:
    unsigned int buffer_object_;
};

#include <rendering/vertex_buffer.tcc>

#endif // VERTEX_BUFFER_H