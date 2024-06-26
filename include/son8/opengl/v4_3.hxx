#pragma once
// because of debugging
# ifndef          SON8_OPENGL_DEFINED
# define          SON8_OPENGL_DEFINED
# define      SON8_OPENGL_VERSION_1_1
# define      SON8_OPENGL_VERSION_1_5
# define      SON8_OPENGL_VERSION_2_1
# define      SON8_OPENGL_VERSION_3_3
# define      SON8_OPENGL_VERSION_4_3
# define     SON8_OPENGL_PROFILE_CORE
# define SON8_OPENGL_VERSION 0x0403CE
#include                   "v1_1.hxx"
#include                   "v1_5.hxx"
#include                   "v2_1.hxx"
#include                   "v3_3.hxx"
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
    // buffer functions
    // ClearBufferSubData ClearBufferData
    // shader functions
    inline void ReleaseShaderCompiler() { glReleaseShaderCompiler(); }
    // ShaderBinary
    // ProgramParameteri
    // CreateShaderProgramv
    // GenProgramPipelines DeleteProgramPipelines BindProgramPipeline
    // UseProgramStages
    // ActiveShaderProgram
    // ProgramBinary
    // ProgramUniform ProgramUniformMatrix
    // ShaderStorageBlockBinding
    // UniformSubroutinesuiv
    // thread functions
    // MemoryBarrier
    // TexBufferRange
    // TextureView
    // TexStorage1D/2D/3D
    // TexStorage2DMultisample/TexStorage3DMultisample
    // InvalidateTexSubImage InvalidateTexImage
    // FramebufferParameteri
}
