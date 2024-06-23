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
    inline void BindBuffer(GLuint buffer) { glBindBuffer(static_cast< GLenum >(enums::Buffer::Array), buffer); }
    inline void BindBuffer(enums::Buffer target, GLuint buffer) { glBindBuffer(static_cast< GLenum >(target), buffer); }
    // DeleteBuffers
    // GenBuffers
    // BufferData
    // BufferSubData
    // MapBuffer
    // UnmapBuffer
    // texture functions
    // ActiveTexture
    // PointParameter
    // PolygonMode
    // PolygonOffset
    // TexImage3D and other sub
    // CompressedTexImage1D/2D/3D
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
    // RasterPos WindowPos
    // arb imaging
    // ColorTable ColorTableParamete CopyColorTable ColorSubTable CopyColorSubTable
    // ConvolutionFilter2D/1D ConvolutionParameter CopyConvolutionFilter2D/1D
    // SeparableFilter2D/1D
    // Histogram Minmax

#endif//SON8_OPENGL_PROFILE_CORE
}
