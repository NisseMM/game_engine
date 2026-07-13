#ifndef RENDERER_H
#define RENDERER_H

#include <cstddef>


// Window forward declare
class Window;
class Transform;
class Camera;
class Mesh;
class ShaderProgram;

/**
 * @brief Struct representing a Viewport used for rendering.
 *
 * @param x X coord for Viewport as an int
 * @param y Y coord for Viewport as an int
 * @param width Width for Viewport as an int
 * @param height Height for Viewport as an int
 */
struct Viewport
{
    int x;
    int y;
    int width;
    int height;
};

/**
 * @brief Struct representing a Color used for clearing when rendering.
 *
 * @param r Red amount as a float. 0.0 is no color, 1.0 is full color
 * @param g Green amount as a float. 0.0 is no color, 1.0 is full color
 * @param b Blue amount as a float. 0.0 is no color, 1.0 is full color
 * @param a Opacity amount as a float. 0.0 is no opacity, 1.0 is full opacity
 */
struct Color
{
    float r;
    float g;
    float b;
    float a;
};

// Default values for Viewport and Color
inline constexpr Viewport DEFAULT_VIEWPORT{0, 0, 1280, 720};
inline constexpr Color DEFAULT_COLOR{0.f, 0.f, 0.f, 1.f};

class Renderer
{
public:
    /**
     * @brief Default constructor sets both Viewport and Color to DEFAULT defined constants.
     */
    Renderer();

    /**
     * @brief Sets Color to input and Viewport to DEFAULT defined constant.
     *
     * @param color A Color struct that represents the new color for clearing.
     */
    Renderer(Color const &color);

    /**
     * @brief Sets Color to DEFAULT defined constant and Viewport to input.
     *
     * @param viewport A Viewport struct that represents the new viewport.
     */
    Renderer(Viewport const &viewport);

    /**
     * @brief Sets Color and Viewport to input.
     *
     * @param color A Color struct that represents the new color for clearing.
     * @param viewport A Viewport struct that represents the new viewport.
     */
    Renderer(Color const &color, Viewport const &viewport);

    /**
     * @brief Updates the internal Viewport.
     *
     * @param viewport A Viewport struct.
     */
    Renderer &setViewport(Viewport const &viewport);

    /**
     * @brief Updates the internal color for clearing.
     *
     * @param color A Color struct.
     */
    Renderer &setClearColor(Color const &color);

    /**
     * @brief Begins a new frame render to the window context that is given.
     *
     * @param window A Window object containing a context that will be set to current for rendering.
     */
    void beginFrame(Window const &window) const;

    void draw(Mesh const& mesh, Transform const& transform, Camera const& camera, ShaderProgram const& shader) const;

private:
    /**
     * @brief A Color struct used as clear color.
     */
    Color clear_color_;

    /**
     * @brief A Viewport struct used as viewport for rendering.
     */
    Viewport viewport_;
};

#endif // RENDERER_H