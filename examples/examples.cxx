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
    std::string titleProfile = "Unknown";
    switch (profile) {
        case 0xCE: hintProfile = GLFW_OPENGL_CORE_PROFILE; titleProfile = "Core"; break;
        case 0xCB: hintProfile = GLFW_OPENGL_COMPAT_PROFILE; titleProfile = "Compatibility"; break;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, hintProfile);

    std::string title = "OPENGL ";
    title += std::to_string(major);
    title += ".";
    title += std::to_string(minor);
    title += " ";
    title += titleProfile;
    title += " Profile";

    window = glfwCreateWindow(640, 480, title.c_str(), NULL, NULL);
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
