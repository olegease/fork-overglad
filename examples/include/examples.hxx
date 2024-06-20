#include <glad/gl.h>
#include <GLFW/glfw3.h>

struct Window
{
    using voidfuncptr = void(*)(GLFWwindow *window);
    GLFWwindow* window;
    Window();
    ~Window();

    operator GLFWwindow*() const;

    void run(voidfuncptr callback);
};
