#pragma once
// because of shaders
# ifndef          SON8_OPENGL_DEFINED
# define          SON8_OPENGL_DEFINED
# define      SON8_OPENGL_VERSION_1_1
# define      SON8_OPENGL_VERSION_1_5
# define      SON8_OPENGL_VERSION_2_1
# define     SON8_OPENGL_PROFILE_NONE
# define SON8_OPENGL_VERSION 0x020100
#include                   "v1_1.hxx"
#include                   "v1_5.hxx"
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
    // StencilFuncSeparate
    // StencilOpSeparate
    // DrawBuffers
    // shader functions
    // VertexAttrib...
    // VertexAttribPointer
    // Enable/DisableVertexAttribArray
    inline auto CreateShader(enums::Shader type) { return types::Shader{glCreateShader(static_cast< GLenum >(type))}; }
    inline void DeleteShader(types::Shader shader) { glDeleteShader(shader); }
    // ShaderSource, CompileShader, DeleteShader
    inline auto CreateProgram() { return types::Program{glCreateProgram()}; }
    inline void AttachShader(types::Program program, types::Shader shader) { glAttachShader(program, shader); }
    inline void DetachShader(types::Program program, types::Shader shader) { glDetachShader(program, shader); }
    inline void LinkProgram(types::Program program) { glLinkProgram(program); }
    inline void UseProgram(types::Program program) { glUseProgram(program); }
    inline void DeleteProgram(types::Program program) { glDeleteProgram(program); }
    inline void ValidateProgram(types::Program program) { glValidateProgram(program); }
    // BindAttribLocation
    // Uniform* UniformMatrix*
}
