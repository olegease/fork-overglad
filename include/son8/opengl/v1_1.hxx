#pragma once
// because of draw arrays and elements
# ifndef          SON8_OPENGL_DEFINED
# define          SON8_OPENGL_DEFINED
# define      SON8_OPENGL_VERSION_1_1
# define     SON8_OPENGL_PROFILE_NONE
# define SON8_OPENGL_VERSION 0x010100
#  endif        //SON8_OPENGL_DEFINED

#include "../opengl.hxx"

namespace son8::opengl
{
    // Core essential functions
    inline auto GetError() { auto e = glGetError(); assert(e == GL_NO_ERROR); return static_cast< enums::Error >(e); }
    inline void Viewport(types::Rect rect = types::Rect{}) { glViewport(rect.lXb.x, rect.lXb.y, rect.wXh.w, rect.wXh.h); }
    //inline void Viewport(GLsizei width, GLsizei height) { glViewport(0, 0, width, height); }
    //inline void Viewport(GLint x, GLint y, GLsizei width, GLsizei height) { glViewport(x, y, width, height); }
    inline void Flush() { glFlush(); }
    inline void Finish() { glFinish(); }

    inline void Clear() { glClear(static_cast< GLbitfield >(enums::Clear::Allbit)); }
    inline void Clear(enums::Clear maskbit) { glClear(static_cast< GLbitfield >(maskbit)); }
    inline void ClearColor() { glClearColor(0.0f, 0.0f, 0.0f, 0.0f); }
    inline void ClearColor(GLclampf rgb) { glClearColor(rgb, rgb, rgb, 0.0f); }
    inline void ClearColor(GLclampf rgb, GLclampf alpha) { glClearColor(rgb, rgb, rgb, alpha); }
    inline void ClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) { glClearColor(red, green, blue, alpha); }
    inline void FrontFace(enums::Dir dir) { glFrontFace(static_cast< GLenum >(dir)); }
    inline void PointSize(GLfloat size) { glPointSize(size); }
    inline void LineWidth(GLfloat width) { glLineWidth(width); }
    // DepthRange
    // CullFace
    // PolygonMode
    // PolygonOffset
    // PixelStore
    // texture functions
    // TexImage2D,1D
    // CopyTexImage2D,1D
    // TexSubImage1D/2D,CopyTexSubImage1D/2D
    // TexParameter
    // GenTextures
    // DeleteTextures
    // BindTexture
    // framebuffer functions
    inline void Scissor(GLint left, GLint bottom, GLsizei width, GLsizei height) { glScissor(left, bottom, width, height); }
    // StencilFunc
    // StencilOp
    // DepthFunc
    // BlendFunc
    // LogicOp
    // DrawBuffer
    // ColorMask
    // DepthMask
    // StencilMask
    // ClearDepth
    // ClearStencil
    // ReadPixels
    // ReadBuffer
    // special functions
    // Hint
    // vertex functions
    inline void DrawArrays(GLsizei count) { glDrawArrays(static_cast< GLenum >(enums::Draw::Default), 0, count); }
    inline void DrawArrays(enums::Draw mode, GLsizei count) { glDrawArrays(static_cast< GLenum >(mode), 0, count); }
    // DrawElements
    // get functions
    inline auto IsEnabled(enums::Capability cap) -> bool { return glIsEnabled(static_cast< GLenum >(cap)); }
    inline auto Get(enums::GetBoolean name) { GLboolean v; glGetBooleanv(static_cast< GLenum >(name), &v); return v; }
    inline auto Get(enums::GetInteger name) { GLint v; glGetIntegerv(static_cast< GLenum >(name), &v); return v; }
    inline auto Get(enums::GetDouble name) { GLdouble v; glGetDoublev(static_cast< GLenum >(name), &v); return v; }
    // GetTexImage
    // IsTexture
    // GetPointerv
    // GetString
    // compatibility functions
#ifndef  SON8_OPENGL_PROFILE_CORE
    // matrix functions
    // MatrixMode, LoadMatrix, MultMatrix, LoadIdentity, Rotate, Translate, Scale, Frustum, Ortho, PushMatrix, PopMatrix
    //   vertex functions
    //     Array Pointers paradigm
    inline void EnableClientState(enums::Array array) { glEnableClientState(static_cast< GLenum >(array)); }
    inline void DisableClientState(enums::Array array) { glDisableClientState(static_cast< GLenum >(array)); }

    // EdgeFlagPointer, TexCoordPointer, NormalPointer, ColorPointer, IndexPointer VertexPointer
    // ArrayElement
    // InterleavedArrays

    //     Begin/End paradigm
    inline void Begin() { glBegin(static_cast< GLenum >(enums::Draw::Default)); }
    inline void Begin(enums::Draw mode) { glBegin(static_cast< GLenum >(mode)); }
    inline void End() { glEnd(); }
    inline void Vertex(types::array2s const &coords) { glVertex2sv(coords.data()); }
    inline void Vertex(types::array2i const &coords) { glVertex2iv(coords.data()); }
    inline void Vertex(types::array2f const &coords) { glVertex2fv(coords.data()); }
    inline void Vertex(types::array2d const &coords) { glVertex2dv(coords.data()); }

    // EdgeFlag TexCoord Normal Color Index
    // Rect
    // TexGen
    // ClipPlane
    // RasterPos
    // LineStipple
    // PolygonStipple
    // PixelTransfer
    // PixelMap
    // PixelZoom
    // DrawPixels
    // Bitmap
    // AreTexturesResident
    // PrioritizeTextures
    // TexEnv
    // Fog
    // AlphaFunc
    // IndexMask
    // ClearIndex
    // ClearAccum
    // Accum
    // CopyPixels
    // special functions
    // Map1,2, EvalCoord, MapGrid, EvalMesh, EvalPoint
    // InitNames, LoadName, PushName, PopName
    // RenderMode, SelectBuffer, FeedbackBuffer, PassThrough
    // NewList, EndList, CallList, CallLists, ListBase, GenLists, IsList, DeleteLists
    // GetClipPlane, GetLight and other deprecated Get functions
    // GetPolygonStipple
    // PushAttrib...
    // material functions
    // LightModel, Light, Material, ColorMaterial, ShadeModel
# endif//SON8_OPENGL_PROFILE_CORE
}
