#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <cstdint>

struct Window
{
    using voidfuncptr = void(*)(GLFWwindow *window);
    GLFWwindow* window;
    Window(uint32_t openglver = 0x0406CE);
    ~Window();

    operator GLFWwindow*() const;

    void run(voidfuncptr callback);
};
