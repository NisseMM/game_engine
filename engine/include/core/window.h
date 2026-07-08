#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <cstddef>

// Forward declare for GLFWwindow pointer
struct GLFWwindow;

/**
 * @brief Wrapper around a native application window.
 *
 * The Window class manages creation, destruction,
 * and event polling for the application's window.
 *
 * It owns the GLFW window handle and is responsible
 * for initializing and shutting down GLFW.
 */
class Window
{
public:
  /**
   * @brief Creates a new window.
   *
   * @param width Window width in pixels.
   * @param height Window height in pixels.
   * @param title Window title.
   * @param debug Enable debug in GLFW.
   */
  Window(int width, int height, std::string const &title, bool debug = false);

  /**
   * @brief Handles destruction of window and releases allocated resources.
   */
  ~Window();

  /**
   * @brief Copy construction is disabled
   */
  Window(const Window &) = delete;

  /**
   * @brief Copy assignment is disabled
   */
  Window &operator=(const Window &) = delete;

  /**
   * @brief Move construction is disabled (currently)
   */
  Window(Window &&) = delete;

  /**
   * @brief Move assignment is disabled (currently)
   */
  Window &operator=(Window &&) = delete;

  /**
   * @brief Checks if the window should close due to user input.
   *
   * @return true if the window should close.
   */
  bool shouldClose() const;

  /**
   * @brief Updates the window state.
   */
  void update();

private:
  /**
   * @brief GLFWwindow handle.
   *
   * Owned by this class.
   */
  GLFWwindow *window_;

  /**
   * @brief Number of active windows
   *
   * Used to manage GLFW lifetime. 
   * GLFW is terminated when last window is destroyed.
   */
  static int window_count_;
};

#endif // WINDOW_H