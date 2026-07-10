#ifndef LAYOUT_TRAITS_H
#define LAYOUT_TRAITS_H

#include <string>

#include <glad/gl.h>
#include <math/math.h>

template <typename T>
struct LayoutTraits
{
    static_assert(false, "Unsupported datatype for layout");
};

template <>
struct LayoutTraits<float>
{
    static int type()
    {
        return GL_FLOAT;
    }

    static int count()
    {
        return 1;
    }

    static size_t size()
    {
        return sizeof(float);
    }
};

template <>
struct LayoutTraits<int>
{
    static int type()
    {
        return GL_INT;
    }

    static int count()
    {
        return 1;
    }

    static size_t size()
    {
        return sizeof(int);
    }
};

template <>
struct LayoutTraits<unsigned int>
{
    static int type()
    {
        return GL_UNSIGNED_INT;
    }

    static int count()
    {
        return 1;
    }

    static size_t size()
    {
        return sizeof(unsigned int);
    }
};

template <>
struct LayoutTraits<bool>
{
    static int type()
    {
        return GL_INT;
    }

    static int count()
    {
        return 1;
    }

    static size_t size()
    {
        return sizeof(bool);
    }
};

template <>
struct LayoutTraits<glm::vec2>
{
    static int type()
    {
        return GL_FLOAT;
    }

    static int count()
    {
        return 2;
    }

    static size_t size()
    {
        return sizeof(glm::vec2);
    }
};

template <>
struct LayoutTraits<glm::vec3>
{
    static int type()
    {
        return GL_FLOAT;
    }

    static int count()
    {
        return 3;
    }

    static size_t size()
    {
        return sizeof(glm::vec3);
    }
};

template <>
struct LayoutTraits<glm::vec4>
{
    static int type()
    {
        return GL_FLOAT;
    }

    static int count()
    {
        return 4;
    }

    static size_t size()
    {
        return sizeof(glm::vec4);
    }
};

#endif // LAYOUT_TRAITS_H