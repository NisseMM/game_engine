#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H
#include <rendering/mesh.h>

#include <string>
#include <vector>

struct Coord
{
    float x;
    float y;
    float z;
};

struct PartialFace
{
    int v;
    int t;
    int n;
};

struct TextureCoord
{
    float x;
    float y;
};

class ModelLoader
{
public:
    void load(std::string const& file_name); 

    Mesh createMesh() const;

private:
    std::vector<Coord> vertices_;
    std::vector<Coord> normals_;
    std::vector<TextureCoord> texture_coords_;
    std::vector<PartialFace> faces_;
};



#endif //MODEL_LOADER_H