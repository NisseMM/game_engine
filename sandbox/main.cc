#include <core/window.h>
#include <rendering/renderer.h>
#include <rendering/shader.h>

#include <iostream>

int main()
{
    Window window{
        1280,
        720,
        "Engine",
        true};
    
    Renderer renderer{Color{1.0, 0.0, 1.0, 1.0}};

    ShaderProgram shader{ShaderStage{"assets/shaders/basic.frag", ShaderType::FRAG}, ShaderStage{"assets/shaders/basic.vert", ShaderType::VERT}};

    while (not window.shouldClose())
    {
        renderer.render(window);
        shader.bind();
        
        window.update();
    }
}