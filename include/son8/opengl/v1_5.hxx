#pragma once

# ifndef          SON8_OPENGL_DEFINED
# define          SON8_OPENGL_DEFINED
# define      SON8_OPENGL_VERSION_1_1
# define      SON8_OPENGL_VERSION_1_5
# define     SON8_OPENGL_PROFILE_NONE
# define SON8_OPENGL_VERSION 0x010500
#include                   "v1_1.hxx"
#  endif        //SON8_OPENGL_DEFINED

#include "../opengl.hxx"

namespace son8::opengl
{
    // vertex functions
    // MultiDrawArrays
    // MultiDrawElements
    // DrawRangeElements
    // buffer functions
    // GenBuffers
    // DeleteBuffers
    inline void BindBuffer(GLuint buffer) { glBindBuffer(static_cast< GLenum >(enums::Buffer::Array), buffer); }
    inline void BindBuffer(enums::Buffer target, GLuint buffer) { glBindBuffer(static_cast< GLenum >(target), buffer); }
    // BufferData
    // BufferSubData
    // MapBuffer
    // UnmapBuffer
    // texture functions
    // ActiveTexture
    // PointParameter
    // PolygonMode
    // PolygonOffset
    // TexImage3D TexSubImage3D CopyTexSubImage3D
    // CompressedTexImage1D/2D/3D
    // CompressedTexSubImage1D/2D/3D
    // framebuffer functions
    // SampleCoverage
    // BeginQuery
    // EndQuery
    // GenQueries
    // DeleteQueries
    // BlendEquation
    // BlendFuncSeparate
    // BlendColor

// compatibility functions
#ifndef SON8_OPENGL_PROFILE_CORE
    // SecondaryColorPointer FogCoordPointer
    // MultiTexCoord, FogCoord, SecondaryColor
    // ClientActiveTexture
    // LoadTransposeMatrix MultTransposeMatrix
    // WindowPos
#endif//SON8_OPENGL_PROFILE_CORE
}
