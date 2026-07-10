#include <math/layout_traits.h>

namespace
{
    template <typename T>
    VertexAttrib make_attrib(int index, size_t offset = 0, bool normalize = false)
    {
        return {index, LayoutTraits<T>::count(), normalize, LayoutTraits<T>::type(), offset};
    }
}

template <typename T>
void VertexLayout::addAttrib(int index, bool normalize)
{
    size_t offset{stride_};
    stride_ += LayoutTraits<T>::size();
    attributes_.push_back(make_attrib(index, offset, normalize));
}

template <typename T>
void VertexLayout::addAttrib(bool normalize)
{
    addAttrib(attributes_.size(), normalize);
}