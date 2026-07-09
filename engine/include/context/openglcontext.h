#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H

#include <mutex>

class GLFWwindow;

class OpenGLContext
{
public:
    /**
     * @brief Creates a OpenGLContext and binds it to a GLFWwindow, also initializes GLAD if needed.
     */
    explicit OpenGLContext(GLFWwindow *window);

    /**
     * @brief Sets context to currently active.
     */
    void makeContextCurrent() const;

private:
    /**
     * @brief Handle to a GLFW window.
     *
     * Not owned by class.
     */
    GLFWwindow *const window_;

    /**
     * @brief Flag for initializing GLAD once.
     */
    static std::once_flag glad_init_flag_;

    /**
     * @brief Helper function to initialize GLAD if needed.
     */
    static void init_glad(GLFWwindow*const window);
};

#endif // OPENGLCONTEXT_H