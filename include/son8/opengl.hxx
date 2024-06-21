#pragma once
// RULES:
// - only call c language gl functions inside inlined functions definitions
#include <glad/gl.h>
#include <cassert>
#include <array>

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
    using array2i = std::array< GLint, 2 >;
    using array2s = std::array< GLshort, 2 >;
    using array2f = std::array< GLfloat, 2 >;
    using array2d = std::array< GLdouble, 2 >;

    struct Rect {
        struct Point { GLint x; GLint y; };
        struct Size { GLsizei w; GLsizei h; };
        Point lXb;
        Size wXh;
        Rect() noexcept: lXb({0, 0}), wXh({640, 480}) { }
        Rect(Rect::Size widthXHeight) noexcept: lXb({0, 0}), wXh(widthXHeight) { }
        Rect(Rect::Point leftXbottom, Rect::Size widthXheight) noexcept: lXb(leftXbottom), wXh(widthXheight) { }
    };
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
    }; // enum class Clear

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
        Table = GL_TABLE_TOO_LARGE,
    #endif
#endif
#ifdef SON8_OPENGL_VERSION_3_3
        Framebuffer = GL_INVALID_FRAMEBUFFER_OPERATION,
#endif
#ifdef SON8_OPENGL_VERSION_4_6
        Context = GL_CONTEXT_LOST,
#endif
    }; // enum class Error

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
    }; // enum class Draw

    enum class Dir : GLenum {
        Counter = GL_CCW,
        Clockwise = GL_CW,
    }; // enum class Dir

    // enums used in glEnable/glDisable/IsEnabled functions
    enum class Capability : GLenum {
        Blend = GL_BLEND,
        DepthTest = GL_DEPTH_TEST,
    }; // enum class Capability
    // enums used in glGet* functions
    enum class GetBoolean : GLenum {
        Doublebuffer = GL_DOUBLEBUFFER,
    }; // enum class GetBoolean
    enum class GetInteger : GLenum {
        MaxDrawBuffers = GL_MAX_DRAW_BUFFERS,
    }; // enum class GetInteger
    enum class GetDouble : GLenum { // same as GetFloat
        PointSize = GL_POINT_SIZE,
    }; // enum class GetFloat

#ifndef  SON8_OPENGL_PROFILE_CORE
    enum class Array : GLenum {
        Vertex = GL_VERTEX_ARRAY,
        Normal = GL_NORMAL_ARRAY,
        Color = GL_COLOR_ARRAY,
        Index = GL_INDEX_ARRAY,
        Texture = GL_TEXTURE_COORD_ARRAY,
        Edge = GL_EDGE_FLAG_ARRAY,
    };
# endif//SON8_OPENGL_PROFILE_CORE
}// namespace son8::opengl::enums

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
