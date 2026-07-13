#include <asset/model_loader.h>
#include <rendering/index_buffer.h>
#include <rendering/vertex_layout.h>
#include <rendering/vertex_buffer.h>

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <format>

std::istream& operator>>(std::istream & in, Coord & v)
{
    in >> v.x >> v.y >> v.z;
    return in;
}

std::istream& operator>>(std::istream & in, TextureCoord & t)
{
    in >> t.x >> t.y;
    return in;
}

std::istream& operator>>(std::istream & in, PartialFace & f)
{
    char trash;
    in >> f.v >> trash >> f.t >> trash >> f.n;
    return in;
}

void ModelLoader::load(std::string const &file_name)
{
    std::ifstream ifs{file_name};
    if (not ifs)
        throw std::runtime_error("Could not open file: " + file_name);

    std::string line{};
    while (std::getline(ifs, line))
    {
        std::istringstream iss{line};
        std::string type{};

        iss >> type;
        if (type == "v")
        {
            vertices_.emplace_back();
            iss >> vertices_.back();
            continue;
        }

        if (type == "vn")
        {
            normals_.emplace_back();
            iss >> normals_.back();
            continue;
        }

        if (type == "vt")
        {
            texture_coords_.emplace_back();
            iss >> texture_coords_.back();
            continue;
        }

        if (type == "f")
        {
            PartialFace f{};
            while(iss >> f)
            {
                faces_.push_back(f);
            }
            continue;
        }
    }
}

struct VertexData
{
    Coord position;
    Coord normal;
    TextureCoord uv;
};

Mesh ModelLoader::createMesh() const
{
    VertexLayout layout{};
    layout.addAttrib<glm::vec3>();
    layout.addAttrib<glm::vec3>();
    layout.addAttrib<glm::vec2>();

    std::unordered_map<std::string, size_t> index_map{};
    std::vector<VertexData> vbo;
    std::vector<unsigned int> ebo;

    VertexData vertex;
    for (auto const& face : faces_)
    {
        std::ostringstream key{};
        key << face.v << face.n << face.t;

        if (index_map.find(key.str()) != index_map.end())
        {
            ebo.push_back(index_map[key.str()]);
            continue;
        }

        vertex.position = vertices_[face.v - 1];
        vertex.normal   = normals_[face.n - 1];
        vertex.uv       = texture_coords_[face.t - 1];

        ebo.push_back(vbo.size());
        vbo.push_back(vertex);

        index_map[key.str()] = ebo.back();
    }

    return Mesh{VertexBuffer{vbo}, layout, IndexBuffer{ebo}};
}