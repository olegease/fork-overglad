#include <examples.hxx>

int main()
{
    Window window;
    window.run([](auto self)
    {
        glfwSwapBuffers(self);
        //glfwSetWindowTitle(self, "Hello World2");
    });
}
