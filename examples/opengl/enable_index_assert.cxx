#include <son8/opengl/v3_3.hxx>
#include <examples.hxx>
namespace gl = son8::opengl;

int main()
{
    Window win(SON8_OPENGL_VERSION);
    win.run([](){
        auto max = gl::Get(gl::enums::GetInteger::MaxDrawBuffers);
        gl::Enable(gl::enums::Capability::Blend, max - 1);
    });
}
