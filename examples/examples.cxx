#include <examples.hxx>

#include <stdexcept>

Window::Window(uint32_t openglver)
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    // major version on bits 16-23
    unsigned major = (openglver >> 16) & 0xFF;
    // minor version on bits 8-15
    unsigned minor = (openglver >> 8) & 0xFF;
    // profile on bits 0-7, core value is 0xCE, compatibility value is 0xCB, none vale is 0x00
    unsigned profile = openglver & 0xFF;
    unsigned hintProfile = GLFW_OPENGL_ANY_PROFILE;
    switch (profile) {
        case 0xCE: hintProfile = GLFW_OPENGL_CORE_PROFILE; break;
        case 0xCB: hintProfile = GLFW_OPENGL_COMPAT_PROFILE; break;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, hintProfile);

    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
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
    while (!glfwWindowShouldClose(window))
    {
        callback(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
