#ifndef UNIFORM_TRAITS_H
#define UNIFORM_TRAITS_H

#include <string>

#include <glad/gl.h>
#include <math/math.h>

template <typename T>
struct UniformTraits
{
    static void upload(int location, T const &value)
    {
        static_assert(false, "Unsupported datatype for uniform upload");
    }
};

template <>
struct UniformTraits<float>
{
    static void upload(int location, float value)
    {
        glUniform1f(location, value);
    }
};

template <>
struct UniformTraits<int>
{
    static void upload(int location, int value)
    {
        glUniform1i(location, value);
    }
};

template <>
struct UniformTraits<unsigned int>
{
    static void upload(int location, unsigned int value)
    {
        glUniform1ui(location, value);
    }
};

template <>
struct UniformTraits<bool>
{
    static void upload(int location, bool value)
    {
        glUniform1i(location, value);
    }
};

template <>
struct UniformTraits<glm::vec2>
{
    static void upload(int location, glm::vec2 const &value)
    {
        glUniform2fv(location, 1, glm::value_ptr(value));
    }
};

template <>
struct UniformTraits<glm::vec3>
{
    static void upload(int location, glm::vec3 const &value)
    {
        glUniform3fv(location, 1, glm::value_ptr(value));
    }
};

template <>
struct UniformTraits<glm::vec4>
{
    static void upload(int location, glm::vec4 const &value)
    {
        glUniform4fv(location, 1, glm::value_ptr(value));
    }
};

template <>
struct UniformTraits<glm::mat3>
{
    static void upload(int location, glm::mat3 const &value, bool transpose = false)
    {
        glUniformMatrix3fv(location, 1, transpose, glm::value_ptr(value));
    }
};

template <>
struct UniformTraits<glm::mat4>
{
    static void upload(int location, glm::mat4 const &value, bool transpose = false)
    {
        glUniformMatrix4fv(location, 1, transpose, glm::value_ptr(value));
    }
};

#endif // UNIFORM_TRAITS_H