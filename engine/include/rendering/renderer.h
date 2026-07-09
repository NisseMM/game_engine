#ifndef RENDERER_H
#define RENDERER_H

#include <cstddef>

// Window forward declare
class Window;

struct Viewport
{
    int x;
    int y;
    int width;
    int height;
};

struct Color
{
    float r;
    float g;
    float b;
    float a;
};

// Default values for Viewport and Color
static constexpr Viewport DEFAULT_VIEWPORT{0, 0, 1280, 720};
static constexpr Color DEFAULT_COLOR{0.f, 0.f, 0.f, 1.f};

class Renderer
{
public:
    Renderer();
    Renderer(Color const& color);
    Renderer(Viewport const& viewport);
    Renderer(Color const& color, Viewport const& viewport);

    Renderer& setViewport(Viewport const& viewport);
    Renderer& setClearColor(Color const& color);

    void render(Window const &window) const;

private:
    Color clear_color_;
    Viewport viewport_;
};

#endif // RENDERER_H