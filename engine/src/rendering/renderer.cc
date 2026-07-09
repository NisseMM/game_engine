#include <rendering/renderer.h>
#include <core/window.h>

#include <glad/gl.h>

Renderer::Renderer()
    : Renderer{DEFAULT_COLOR, DEFAULT_VIEWPORT}
{}

Renderer::Renderer(Color const& color)
    : Renderer{color, DEFAULT_VIEWPORT}
{}

Renderer::Renderer(Viewport const& viewport)
    : Renderer{DEFAULT_COLOR, viewport}
{}

Renderer::Renderer(Color const& color, Viewport const& viewport)
    : clear_color_{color}, viewport_{viewport}
{}

Renderer& Renderer::setViewport(Viewport const& viewport)
{
    viewport_ = viewport;
    return *this;
}

Renderer& Renderer::setClearColor(Color const& color)
{
    clear_color_ = color;
    return *this;
}

void Renderer::render(Window const& window) const
{
    window.makeContextCurrent();
    glViewport(viewport_.x, viewport_.y, viewport_.width, viewport_.height);
    glClearColor(clear_color_.r, clear_color_.g, clear_color_.b, clear_color_.a);
    glClear(GL_COLOR_BUFFER_BIT);
}