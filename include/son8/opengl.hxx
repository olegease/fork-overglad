#pragma once

#include <glad/gl.h>
#include <cassert>

# ifndef          SON8_OPENGL_DEFINED
# define          SON8_OPENGL_DEFINED
# define          SON8_OPENGL_INCLUDE
# define      SON8_OPENGL_VERSION_1_1
# define      SON8_OPENGL_VERSION_1_5
# define      SON8_OPENGL_VERSION_2_1
# define      SON8_OPENGL_VERSION_3_3
# define      SON8_OPENGL_VERSION_4_3
# define      SON8_OPENGL_VERSION_4_6
# define     SON8_OPENGL_PROFILE_CORE
# define SON8_OPENGL_VERSION 0x0406CE
#  endif        //SON8_OPENGL_DEFINED

namespace son8::opengl::types
{

}

namespace son8::opengl::enums
{
    enum class Clear : GLbitfield {
        Colorbit = GL_COLOR_BUFFER_BIT,
        Depthbit = GL_DEPTH_BUFFER_BIT,
        Stencilbit = GL_STENCIL_BUFFER_BIT,
#ifdef SON8_OPENGL_PROFILE_CORE
        Allbit = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT,
# else
        Accumbit = GL_ACCUM_BUFFER_BIT,
        Allbit = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_ACCUM_BUFFER_BIT,
#endif
    };

    enum class Error : GLenum {
        None = GL_NO_ERROR,
        Enum = GL_INVALID_ENUM,
        Value = GL_INVALID_VALUE,
        Operation = GL_INVALID_OPERATION,
        Memory = GL_OUT_OF_MEMORY,
#if defined(SON8_OPENGL_PROFILE_NONE) || defined(SON8_OPENGL_VERSION_4_3)
        Overflow = GL_STACK_OVERFLOW,
        Underflow = GL_STACK_UNDERFLOW,
#endif
#ifndef SON8_OPENGL_PROFILE_CORE
    #ifdef SON8_OPENGL_VERSION_1_5
        Table = GL_TABLE_TOO_LARGE
    #endif
#endif
#ifdef SON8_OPENGL_VERSION_3_3
        Framebuffer = GL_INVALID_FRAMEBUFFER_OPERATION,
#endif
#ifdef SON8_OPENGL_VERSION_4_6
        Context = GL_CONTEXT_LOST,
#endif
    };

    enum class Draw : GLenum {
        Default = GL_TRIANGLES,
        Fan = GL_TRIANGLE_FAN,
        Strip = GL_TRIANGLE_STRIP,
        Line = GL_LINES,
        LineStrip = GL_LINE_STRIP,
        LineLoop = GL_LINE_LOOP,
        Point = GL_POINTS,
#ifndef SON8_OPENGL_PROFILE_CORE
        Polygon = GL_POLYGON,
        Quad = GL_QUADS,
        QuadStrip = GL_QUAD_STRIP,
#endif
#ifdef SON8_OPENGL_VERSION_3_3
        Adjacency = GL_TRIANGLES_ADJACENCY,
        AdjacencyStrip = GL_TRIANGLE_STRIP_ADJACENCY,
        AdjacencyLine = GL_LINES_ADJACENCY,
        AdjacencyLineStrip = GL_LINE_STRIP_ADJACENCY,
#endif
#ifdef SON8_OPENGL_VERSION_4_3
        Patches = GL_PATCHES,
#endif
    };
}

#  ifdef  SON8_OPENGL_INCLUDE
#include    "opengl/v1_1.hxx"
#include    "opengl/v1_5.hxx"
#include    "opengl/v2_1.hxx"
#include    "opengl/v3_3.hxx"
#include    "opengl/v4_3.hxx"

// opengl 4.4, 4.5 and 4.6 functionality
# ifdef SON8_OPENGL_VERSION_4_6 // !important: if client include v4_6cb.hxx

#endif//SON8_OPENGL_VERSION_4_6
#  endif//SON8_OPENGL_INCLUDE
