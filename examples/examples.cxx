#include <examples.hxx>

#include <stdexcept>

Window::Window()
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

Window::operator GLFWwindow *() const
{
    return window;
}

void Window::run(voidfuncptr callback)
{
    //glfwMakeContextCurrent(window);
    //gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    while (!glfwWindowShouldClose(window))
    {
        callback(window);
        //glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
