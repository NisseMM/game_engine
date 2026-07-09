#include <context/openglcontext.h>

#include <stdexcept>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

// Set state to GLAD being uninitialized
std::once_flag OpenGLContext::glad_init_flag_;

OpenGLContext::OpenGLContext(GLFWwindow *window)
    : window_{window}
{
    if (not window_)
    {
        throw std::runtime_error("Cannot create OpenGLContext with null window");
    }

    OpenGLContext::init_glad(window);
}

void OpenGLContext::makeContextCurrent() const
{
    glfwMakeContextCurrent(window_);
}

void OpenGLContext::init_glad(GLFWwindow*const window)
{
    std::call_once(glad_init_flag_, [window]()
        {
            glfwMakeContextCurrent(window);
            if (not gladLoadGL((GLADloadfunc)glfwGetProcAddress))
            {
                throw std::runtime_error("Failed to initialize GLAD");
            } 
        });
}