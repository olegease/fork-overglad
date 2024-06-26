#pragma once
// RULES:
// - only call c language gl functions inside inlined functions definitions
#include <glad/gl.h>
#include <cassert>
#include <array>
#include <vector>

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
    template< unsigned id >
    class GenTid {
        std::vector< GLuint > ids;
    public:
        explicit GenTid(GLuint num = 1) { ids.reserve(num); }
    };

    using List = GenTid< 1 >;
    using Buffer = GenTid< 2 >;

    using array2i = std::array< GLint, 2 >;
    using array2s = std::array< GLshort, 2 >;
    using array2f = std::array< GLfloat, 2 >;
    using array2d = std::array< GLdouble, 2 >;

    using array4b = std::array< GLboolean, 4 >;
    using array4d = std::array< GLdouble, 4 >;

    using array16d = std::array< GLdouble, 16 >;

    struct Rect {
        struct Point { GLint x; GLint y; };
        struct Size { GLsizei w; GLsizei h; };
        Point lXb;
        Size wXh;
        Rect() noexcept: lXb({0, 0}), wXh({640, 480}) { }
        Rect(Rect::Size widthXHeight) noexcept: lXb({0, 0}), wXh(widthXHeight) { }
        Rect(Rect::Point leftXbottom, Rect::Size widthXheight) noexcept: lXb(leftXbottom), wXh(widthXheight) { }
    };

    class Program {
        GLuint index;
    public:
        explicit Program(GLuint id) noexcept: index(id) { }
        operator GLuint() { return index; }
    };

    class Shader {
        GLuint index;
    public:
        explicit Shader(GLuint id) noexcept: index(id) { }
        operator GLuint() { return index; }
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

    // enums used in glEnable/glDisable functions
    enum class Capability : GLenum {
        Blend = GL_BLEND,
        DepthTest = GL_DEPTH_TEST,
    }; // enum class Capability

    // STATE is/get related
    enum class Is : GLboolean {
#ifdef SON8TEMP

#endif
    };

    // enums used in glGet* functions
    enum class GetUnknown : GLenum {
#ifdef SON8_OPENGL_VERSION_1_5
        CompressedTextureFormats = GL_COMPRESSED_TEXTURE_FORMATS,
#endif
    };

    enum class GetBoolean : GLenum {
        ColorLogicOp = GL_COLOR_LOGIC_OP,
        Doublebuffer = GL_DOUBLEBUFFER,
#ifndef SON8_OPENGL_PROFILE_CORE
        AlphaTest = GL_ALPHA_TEST,
        AutoNormal = GL_AUTO_NORMAL,
        ClipPlane0 = GL_CLIP_PLANE0,
        ClipPlane1 = GL_CLIP_PLANE1,
        ClipPlane2 = GL_CLIP_PLANE2,
        ClipPlane3 = GL_CLIP_PLANE3,
        ClipPlane4 = GL_CLIP_PLANE4,
        ClipPlane5 = GL_CLIP_PLANE5,
        ColorArray = GL_COLOR_ARRAY,
        ColorMaterial = GL_COLOR_MATERIAL,
    #ifdef SON8_OPENGL_VERSION_1_5
    #endif
#endif
    }; // enum class GetBoolean

    enum class GetInteger : GLenum {
        MaxDrawBuffers = GL_MAX_DRAW_BUFFERS,
#ifdef SON8_OPENGL_VERSION_1_5
        ActiveTexture = GL_ACTIVE_TEXTURE,
        ArrayBufferBinding = GL_ARRAY_BUFFER_BINDING,
        BlendDstAlpha = GL_BLEND_DST_ALPHA,
        BlendDstRGB = GL_BLEND_DST_RGB,
        BlendSrcAlpha = GL_BLEND_SRC_ALPHA,
        BlendSrcRGB = GL_BLEND_SRC_RGB,
#endif
#ifdef SON8_OPENGL_VERSION_2_1
        BlendEquationAlpha = GL_BLEND_EQUATION_ALPHA,
        BlendEquationRGB = GL_BLEND_EQUATION_RGB,
#endif
#ifdef SON8_OPENGL_VERSION_3_3
        ContextFlags = GL_CONTEXT_FLAGS,
#endif
#ifdef SON8_OPENGL_VERSION_4_3
        DebugGroupStackDepth = GL_DEBUG_GROUP_STACK_DEPTH,
        DispatchIndirectBufferBinding = GL_DISPATCH_INDIRECT_BUFFER_BINDING,
        MaxCombinedComputeUniformComponents = GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS,
        MaxCombinedShaderStorageBlocks = GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS,
        MaxDebugGroupStackDepth = GL_MAX_DEBUG_GROUP_STACK_DEPTH,
        MaxComputeAtomicCounterBuffers = GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS,
        MaxComputeAtomicCounters = GL_MAX_COMPUTE_ATOMIC_COUNTERS,
        MaxComputeShaderStorageBlocks = GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS,
        MaxComputeTextureImageUnits = GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS,
        MaxComputeUniformBlocks = GL_MAX_COMPUTE_UNIFORM_BLOCKS,
        MaxComputeUniformComponents = GL_MAX_COMPUTE_UNIFORM_COMPONENTS,
        MaxComputeWorkGroupCount = GL_MAX_COMPUTE_WORK_GROUP_COUNT,
        MaxComputeWorkGroupInfocations = GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS,
#endif
#ifndef SON8_OPENGL_PROFILE_CORE
        AccumAlphaBits = GL_ACCUM_ALPHA_BITS,
        AccumBlueBits = GL_ACCUM_BLUE_BITS,
        AccumGreenBits = GL_ACCUM_GREEN_BITS,
        AccumRedBits = GL_ACCUM_RED_BITS,
        AlphaBits = GL_ALPHA_BITS,
        AlphaTestFunc = GL_ALPHA_TEST_FUNC,
        AlphaTestRef = GL_ALPHA_TEST_REF,
        AttribStackDepth = GL_ATTRIB_STACK_DEPTH,
        AuxBuffers = GL_AUX_BUFFERS,
        BlendDst = GL_BLEND_DST,
        BlendSrc = GL_BLEND_SRC,
        BlueBits = GL_BLUE_BITS,
        ClientAttribStackDepth = GL_CLIENT_ATTRIB_STACK_DEPTH,
        ColorArraySize = GL_COLOR_ARRAY_SIZE,
        ColorArrayStride = GL_COLOR_ARRAY_STRIDE,
        ColorArrayType = GL_COLOR_ARRAY_TYPE,
        ColorMaterialFace = GL_COLOR_MATERIAL_FACE,
        ColorMaterialParameter = GL_COLOR_MATERIAL_PARAMETER,
    #ifdef SON8_OPENGL_VERSION_1_5
        BlendEquation = GL_BLEND_EQUATION,
        ClientActiveTexture = GL_CLIENT_ACTIVE_TEXTURE,
        ColorArrayBufferBinding = GL_COLOR_ARRAY_BUFFER_BINDING,
        ColorSum = GL_COLOR_SUM,
    #endif
#endif
    }; // enum class GetInteger

    enum class GetDouble : GLenum { // same as GetFloat
        PointSize = GL_POINT_SIZE,
#ifndef SON8_OPENGL_PROFILE_CORE
        AlphaBias = GL_ALPHA_BIAS,
        AlphaScale = GL_ALPHA_SCALE,
        BlueBias = GL_BLUE_BIAS,
        BlueScale = GL_BLUE_SCALE,
#endif
    }; // enum class GetFloat/GetDouble

    enum class GetArray2d : GLenum {
#ifdef SON8_OPENGL_VERSION_1_5
        AliasedLineWidthRange = GL_ALIASED_LINE_WIDTH_RANGE,
#endif
#ifndef SON8_OPENGL_PROFILE_CORE
    #ifdef SON8_OPENGL_VERSION_1_5
        AliasedPointSizeRange = GL_ALIASED_POINT_SIZE_RANGE,
    #endif
#endif
    }; // enum class GetArray2d

    enum class GetArray4b : GLenum {
        ColorWritemask = GL_COLOR_WRITEMASK,
    };

    enum class GetArray4d : GLenum {
        BlendColor = GL_BLEND_COLOR,
        ColorClearValue = GL_COLOR_CLEAR_VALUE,
#ifndef SON8_OPENGL_PROFILE_CORE
        AccumClearValue = GL_ACCUM_CLEAR_VALUE,
#endif
    };

#ifdef  SON8_OPENGL_VERSION_1_5
    enum class Buffer : GLenum {
        Array = GL_ARRAY_BUFFER,
        Element = GL_ELEMENT_ARRAY_BUFFER,
    };
#endif//SON8_OPENGL_VERSION_1_5

#ifdef SON8_OPENGL_VERSION_2_1
    enum class Shader : GLenum {
        Vertex = GL_VERTEX_SHADER,
        Fragment = GL_FRAGMENT_SHADER,
    #ifdef SON8_OPENGL_VERSION_3_3
        Geometry = GL_GEOMETRY_SHADER,
    #endif
    };
#endif//SON8_OPENGL_VERSION_2_1

#ifdef SON8_OPENGL_VERSION_4_6
    enum class Reset : GLenum {
        None = GL_NO_ERROR,
        Guilty = GL_GUILTY_CONTEXT_RESET,
        Innocent = GL_INNOCENT_CONTEXT_RESET,
        Unknown = GL_UNKNOWN_CONTEXT_RESET,
    };
#endif

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
namespace son8::opengl {
    inline auto GetGraphicsResetStatus() { return static_cast< enums::Reset >(glGetGraphicsResetStatus()); }
    // CreateQueries
    // GetQueryBufferObjectiv*
    // BufferStorage NamedBufferStorage
    // ClearNamedBufferSubData ClearNamedBufferData
    // MapNamedBufferRange MapNamedBuffer FlushMappedNamedBufferRange UnmapNamedBuffer CopyNamedBufferSubData
    // shader functions
    // SpecializeShader
    // MemoryBarrierByRegion
    // CreateTextures
    // BindImageTexture
    // TextureSubImage3D/2D/1D
    // CopyTextureSubImage3D/2D/1D
    // CompressedTextureSubImage1D/2D/3D
    // TextureBufferRange TextureBuffer
    // TextureParameter/I
    // GenerateTextureMipmap
    // TextureStorage1D/2/3D
    // TextureStorage2D/3DMultisample
    // ClearTexSubImage ClearTexImage
    // BindImageTextures
    // CreateFramebuffers
    // NamedFramebufferParameteri
    // CreateRenderbuffers
    // NamedRenderbufferStorageMultisample NamedRanderbufferStorage
    // NamedFramebufferRenderbuffer
    // NamedFramebufferTexture NamedFramebufferTextureLayer
    // TextureBarrier
    // CheckNamedFramebufferStatus
}// namespace son8::opengl
#endif//SON8_OPENGL_VERSION_4_6
#  endif//SON8_OPENGL_INCLUDE
