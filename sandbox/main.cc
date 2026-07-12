#include <core/window.h>
#include <rendering/renderer.h>
#include <rendering/shader.h>
#include <rendering/vertex_array.h>
#include <rendering/vertex_buffer.h>
#include <rendering/vertex_layout.h>
#include <rendering/index_buffer.h>
#include <rendering/mesh.h>

#include <iostream>

#include <math/math.h>

int main()
{
    Window window{
        1280,
        720,
        "Engine",
        true};
    
    Renderer renderer{Color{1.0, 0.0, 1.0, 1.0}};

    ShaderProgram shader{ShaderStage{"assets/shaders/basic.frag", ShaderType::FRAG}, ShaderStage{"assets/shaders/basic.vert", ShaderType::VERT}};

    VertexBuffer vbo{
        0, 1, 0,
        -1, 0, 0,
        1, 0, 0,
        0, -1, 0};
    
    VertexLayout layout{};
    layout.addAttrib<glm::vec3>();
    
    VertexArray vao{};
    vao.addBuffer(vbo, layout);

    IndexBuffer ebo{
        0, 1, 2,
        1, 3, 2};

    Mesh mesh{std::move(vbo), layout, std::move(ebo)};

    while (not window.shouldClose())
    {
        renderer.render(window);
        shader.bind();
        mesh.draw();

        window.update();
    }
}