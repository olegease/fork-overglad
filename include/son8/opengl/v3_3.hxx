#pragma once
// because of core profile
# ifndef          SON8_OPENGL_DEFINED
# define          SON8_OPENGL_DEFINED
# define      SON8_OPENGL_VERSION_1_1
# define      SON8_OPENGL_VERSION_1_5
# define      SON8_OPENGL_VERSION_2_1
# define      SON8_OPENGL_VERSION_3_3
# define     SON8_OPENGL_PROFILE_CORE
# define SON8_OPENGL_VERSION 0x0303CE
#include                   "v1_1.hxx"
#include                   "v1_5.hxx"
#include                   "v2_1.hxx"
#  endif        //SON8_OPENGL_DEFINED

#include "../opengl.hxx"

namespace son8::opengl
{
    // glEnablei/glDisablei no i as cxx can overload it unlike c
    inline void Enable(enums::Capability cap, GLuint index) { glEnablei(static_cast< GLenum >(cap), index); assert(glGetError() != GL_INVALID_VALUE); }
    inline void Disable(enums::Capability cap, GLuint index) { glDisablei(static_cast< GLenum >(cap), index); assert(glGetError() != GL_INVALID_VALUE); }
}
