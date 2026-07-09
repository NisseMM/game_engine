#include <core/window.h>
#include <context/openglcontext.h>

#include <stdexcept>

#include <GLFW/glfw3.h>

// Initialize window_count_ to 0 before any windows are initialized
int Window::window_count_ = 0;

Window::Window(int width, int height, std::string const &title, bool debug)
    : window_{nullptr}, context_{nullptr}
{
    // Initialization of GLFW with OpenGL 4.6 and Core profile as well as debug
    if (window_count_ == 0 and not glfwInit())
        throw std::runtime_error("GLFW could not be initialized through glfwInit");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, debug ? GLFW_TRUE : GLFW_FALSE);

    window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (not window_)
    {
        glfwTerminate();
        throw std::runtime_error("Window could not be created by glfwCreateWindow");
    }

    context_ = std::make_unique<OpenGLContext>(window_);

    ++window_count_;
}

Window::~Window()
{
    context_.reset();

    if (window_)
    {
        glfwDestroyWindow(window_);
        window_ = nullptr;

        --window_count_;

        if (window_count_ == 0)
            glfwTerminate();
    }
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(window_);
}

void Window::makeContextCurrent() const
{
    context_->makeContextCurrent();
}

void Window::update()
{
    glfwSwapBuffers(window_);
    glfwPollEvents();
}
