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
    // CORE CATEGORY 1: SPECIAL
    // CORE CATEGORY 2: DRAW
    // CORE CATEGORY 3: DATA
    // CORE CATEGORY 4: TEXTURE
    // CORE CATEGORY 5: SHADER
    // CORE CATEGORY 6: FRAME
    // CORE CATEGORY 7: FEEDBACK
    // CORE CATEGORY 8: STATE
    // UNCATEGORIZED
    // VertexAttribDivisor
    // PrimitiveRestartIndex
    // DrawArraysOneInstance/d
    // DrawElementsOneInstance/d
    // DrawElementsBaseVertex,DrawRangeElementsBaseVertex,DrawElementsInstancedBaseVertex
    // MultiDrawElementsBaseVertex
    // buffer functions
    // BindBufferRange BindBufferBase
    // MapBufferRange
    // FlushMappedBufferRange
    // InvalidateBufferSubData InvalidateBufferData
    // CopyBufferSubData
    // GenVertexArrays DeleteVertexArrays BindVertexArray
    // shader functions
    // UniformBlockBinding
    // TransformFeedbackVaryings
    // ???
    // Begin/EndConditionalRender
    // Begin/EndTransformFeedback
    // ProvokingVertex
    // GenSamplers DeleteSamplers BindSampler
    // SamplerParameter/SamplerParameterI
    // TexImage2DMultisample TexImage3DMultisample
    // TexBuffer
    // TexParameterI
    // GenerateMipmap
    // BindFragDataLocationIndexed BindFragDataLocation
    // SampleMaski ColorMaski
    // ClearBuffer ClearBufferfi
    // ClampColor
    // BlitFramebuffer
    // GenFramebuffers DeleteFramebuffers BindFramebuffer
    // GenRenderbuffers DeleteRenderbuffers BindRenderbuffer
    // RenderbufferStorageMultisample RenderbufferStorage
    // FramebufferRenderbuffer FramebufferTexture
    // FramebufferTexture1D/2D/3D
    // FramebufferTextureLayer
    // CheckFramebufferStatus
    // QueryCounter
    // FenceSync DeleteSync
    // ClientWaitSync WaitSync
    // BeginQueryIndexed EndQueryIndexed
    // glEnablei/glDisablei no i as cxx can overload it unlike c
    inline void Enable(enums::Capability cap, GLuint index) { glEnablei(static_cast< GLenum >(cap), index); assert(glGetError() != GL_INVALID_VALUE); }
    inline void Disable(enums::Capability cap, GLuint index) { glDisablei(static_cast< GLenum >(cap), index); assert(glGetError() != GL_INVALID_VALUE); }
}
