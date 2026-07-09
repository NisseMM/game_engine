#include <core/window.h>
#include <rendering/renderer.h>

#include <iostream>

int main()
{
    Window window{
        1280,
        720,
        "Engine",
        true};
    
    Renderer renderer{};

    while (not window.shouldClose())
    {
        renderer.render(window);
        window.update();
    }
}