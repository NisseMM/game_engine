#ifndef VERTEX_LAYOUT_H
#define VERTEX_LAYOUT_H

#include <vector>
#include <cstddef>

struct VertexAttrib
{
    int index;
    int count;
    bool normalize;
    int type;
    size_t offset;
};

class VertexLayout
{
public:
    VertexLayout() = default;

    template <typename T>
    void addAttrib(int index, bool normalize = false);
    template <typename T>
    void addAttrib(bool normalize = false);

    std::vector<VertexAttrib> const &attributes() const;
    size_t stride() const;

private:
    std::vector<VertexAttrib> attributes_;
    size_t stride_;
};

#include <rendering/vertex_layout.tcc>

#endif // VERTEX_LAYOUT_H