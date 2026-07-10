#include <rendering/shader.h>

#include <map>
#include <fstream>
#include <sstream>

#include <glad/gl.h>

const std::map<ShaderType, int> SHADER_MAPPING{
    {ShaderType::VERT, GL_VERTEX_SHADER},
    {ShaderType::FRAG, GL_FRAGMENT_SHADER},
    {ShaderType::GEOM, GL_GEOMETRY_SHADER}
};

std::string read_file(std::string const& path)
{
    std::ifstream ifs{path};
    std::ostringstream buffer{};
    buffer << ifs.rdbuf();
    return buffer.str();
}

ShaderProgram::ShaderProgram(std::initializer_list<ShaderStage> stages)
    : program_id_{glCreateProgram()}
{
    for (auto const& stage : stages)
    {
        unsigned int shader = glCreateShader(SHADER_MAPPING.at(stage.type));
        std::string shader_src{read_file(stage.path).c_str()};
        char const* shader_src_c{shader_src.c_str()};
        glShaderSource(shader, 1, &shader_src_c, NULL);
        glCompileShader(shader);
        glAttachShader(program_id_, shader);
        glDeleteShader(shader);
    }

    glLinkProgram(program_id_);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(program_id_);
}