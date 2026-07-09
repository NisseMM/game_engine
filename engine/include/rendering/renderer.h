#ifndef RENDERER_H
#define RENDERER_H

class Window;

class Renderer
{
public:
    Renderer();

    void render(Window const &window) const;

private:
};

#endif // RENDERER_H