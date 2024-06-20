#include <examples.hxx>
#include <son8/opengl/v1_1.hxx>

void myCallback()
{
    son8::opengl::Clear();
    son8::opengl::ClearColor(0.3f);
}

int main()
{
    Window window(SON8_OPENGL_VERSION);
    son8::opengl::Viewport();
    window.run(myCallback);
}
