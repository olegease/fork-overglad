#pragma once

# ifndef          SON8_OPENGL_DEFINED
# define          SON8_OPENGL_DEFINED
# define      SON8_OPENGL_VERSION_1_1
# define     SON8_OPENGL_PROFILE_NONE
# define SON8_OPENGL_VERSION 0x010100
#  endif        //SON8_OPENGL_DEFINED

#include "../opengl.hxx"

namespace son8::opengl
{
    // Essential specification functions
    inline auto GetError() { auto e = glGetError(); assert(e != GL_NO_ERROR); return e; }
    inline void Viewport() { glViewport(0, 0, 640, 480); }
    inline void Viewport(GLsizei width, GLsizei height) { glViewport(0, 0, width, height); }
    inline void Viewport(GLint x, GLint y, GLsizei width, GLsizei height) { glViewport(x, y, width, height); }
    inline void Flush() { glFlush(); }
    inline void Finish() { glFinish(); }

    inline void Clear() { glClear(static_cast< GLbitfield >(enums::Clear::Allbit)); }
    inline void ClearColor() { glClearColor(0.0f, 0.0f, 0.0f, 0.0f); }
    inline void ClearColor(GLclampf rgb) { glClearColor(rgb, rgb, rgb, 0.0f); }
}
