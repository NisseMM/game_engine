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

ShaderProgram::ShaderProgram(std::initializer_list<ShaderStage> stages)
    : program_id_{glCreateProgram()}
{
    for (auto const& stage : stages)
    {
        unsigned int shader = glCreateShader(SHADER_MAPPING.at(stage.type));
        compileShader(shader, stage.path);
        glAttachShader(program_id_, shader);
        glDeleteShader(shader);
    }

    linkProgram();
}

ShaderProgram::ShaderProgram(ShaderProgram && other) noexcept
    : program_id_{0}
{
    *this = std::move(other);
}

ShaderProgram& ShaderProgram::operator=(ShaderProgram && other) noexcept
{
    std::swap(program_id_, other.program_id_);
    return *this;
}

void ShaderProgram::bind() const
{
    glUseProgram(program_id_);
}

std::string readFile(std::string const& path)
{
    std::ifstream ifs{path};

    if (not ifs)
        throw std::runtime_error("Could not open file: " + path);

    std::ostringstream buffer{};
    buffer << ifs.rdbuf();
    return buffer.str();
}

void ShaderProgram::compileShader(unsigned int shader, std::string const& path) const
{
    std::string shader_src{readFile(path)};
    char const* shader_src_c{shader_src.c_str()};
    glShaderSource(shader, 1, &shader_src_c, NULL);
    glCompileShader(shader);

    if (not compilationSuccess(shader))
    {
        throw std::runtime_error(shaderLogs(shader));
    }
}

bool ShaderProgram::compilationSuccess(unsigned int shader) const
{
    int compile_good{0};
    glGetShaderiv(shader,  GL_COMPILE_STATUS, &compile_good);
    return compile_good != 0;
}

std::string readLog(unsigned int id, auto getiv, auto getlog)
{
    int length{};
    getiv(id,  GL_INFO_LOG_LENGTH, &length);
    
    if (length == 0)
        return "Log missing";

    std::string log(length, '\0');
    int log_size{};
    getlog(id, length, &log_size, log.data());
    log.resize(log_size);
    return log;
}

std::string ShaderProgram::shaderLogs(unsigned int shader) const
{
    return readLog(shader, glGetShaderiv, glGetShaderInfoLog);
}

void ShaderProgram::linkProgram() const
{
    glLinkProgram(program_id_);

    if (not linkSuccess())
    {
        throw std::runtime_error(programLogs());
    }
}

bool ShaderProgram::linkSuccess() const
{
    int link_good{0};
    glGetProgramiv(program_id_,  GL_LINK_STATUS, &link_good);
    return link_good != 0;
}

std::string ShaderProgram::programLogs() const
{
    return readLog(program_id_, glGetProgramiv, glGetProgramInfoLog);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(program_id_);
}