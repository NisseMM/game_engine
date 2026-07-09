#include <rendering/renderer.h>
#include <core/window.h>

#include <glad/gl.h>

Renderer::Renderer()
{}

void Renderer::render(Window const& window) const
{
    window.makeContextCurrent();
    glClear(GL_COLOR_BUFFER_BIT);
}