#include <glad/gl.h>
#include <iostream>
#include <core/window.h>

int main()
{
    Window window{
        1280,
        720,
        "Engine",
        true};
        
    std::cout << "GPU: "
              << glGetString(GL_RENDERER)
              << "\n";

    std::cout << "OpenGL: "
              << glGetString(GL_VERSION)
              << "\n";
            
    while (not window.shouldClose())
    {
        window.makeContextCurrent();
        glClear(GL_COLOR_BUFFER_BIT);
        window.update();
    }
}