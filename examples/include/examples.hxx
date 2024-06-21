#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <cstdint>
#include <utility>

struct Window
{
    GLFWwindow* window;
    Window(uint32_t openglver = 0x0406CE);
    ~Window();

    operator GLFWwindow*() const;
    template< typename Callback, typename... Args >
    void run(Callback&& callback, Args&&... args)
    {
        while (!glfwWindowShouldClose(window))
        {
            callback(std::forward< Args >(args)...);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
};

struct OnetimeOnly {
    bool once = true;
    template< typename Callback, typename... Args >
    void operator()(Callback&& callback, Args&&... args)
    {
        if (once)
        {
            callback(std::forward< Args >(args)...);
            once = false;
        }
    }
};

