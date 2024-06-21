#include <examples.hxx>
#include <son8/opengl/v4_3cb.hxx>

namespace gl = son8::opengl;

void myCallback(Window* window)
{
    son8::opengl::Clear();
    son8::opengl::ClearColor(0.3f);

    gl::Begin();
    gl::End();
}

int main()
{
    Window window(SON8_OPENGL_VERSION);
    //son8::opengl::Viewport({{1200, 600}});
    glViewport(0, 0, 1200, 600);
    window.run(myCallback, &window);
}
