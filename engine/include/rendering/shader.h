#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>

#include <math/math.h>
#include <math/uniform_traits.h>

enum class ShaderType
{
    VERT,
    FRAG,
    GEOM,
    TESC,
    TESE,
    COMP
};

struct ShaderStage
{
    std::string path;
    ShaderType type;
};

class ShaderProgram
{
public:
    ShaderProgram(std::initializer_list<ShaderStage> stages);

    ~ShaderProgram();

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;

    ShaderProgram(ShaderProgram&& other) noexcept;
    ShaderProgram& operator=(ShaderProgram&& other) noexcept;

    void bind() const;

    template<typename T>
    void set(std::string const& name, T const& value)
    {
        int location{glGetUniformLocation(program_id_, name.c_str())};
        if (location == -1)
            throw std::runtime_error("Cannot find location for '" + name + "'");
        UniformTraits<T>::upload(location, value);
    }


private:
    unsigned int program_id_;

    void compileShader(unsigned int shader, std::string const& path) const;
    bool compilationSuccess(unsigned int shader) const;
    std::string shaderLogs(unsigned int shader) const;
    

    void linkProgram() const;
    bool linkSuccess() const;
    std::string programLogs() const;
};

#endif //SHADER_H