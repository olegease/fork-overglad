#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <cstdint>

struct Window
{
    using voidfuncptr = void(*)(GLFWwindow *window);
    template< typename... Args >
    using Callback = void(*)(Args...);
    GLFWwindow* window;
    Window(uint32_t openglver = 0x0406CE);
    ~Window();

    operator GLFWwindow*() const;
    template< typename... Args >
    void run(Callback< Args... > callback, Args&&... args)
    {
        while (!glfwWindowShouldClose(window))
        {
            callback(args...);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
};
