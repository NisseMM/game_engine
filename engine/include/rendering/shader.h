#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <vector>
#include <initializer_list>

#include <math/math.h>
#include <glad/gl.h>

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

private:
    size_t progam_id_;
};

#endif //SHADER_H