#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <vector>

class VertexBuffer
{
public:
    VertexBuffer();
    VertexBuffer(std::initializer_list<float> list);

    ~VertexBuffer();

    void bind() const;

    void upload(std::initializer_list<float> list);
    void upload(std::vector<float> const &list);

private:
    unsigned int buffer_object_;
};

#endif // VERTEX_BUFFER_H