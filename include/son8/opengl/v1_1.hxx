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
    // CORE CATEGORY 1: SPECIAL
    // CORE CATEGORY 2: DRAW
    // CORE CATEGORY 3: DATA
    // CORE CATEGORY 4: TEXTURE
    // CORE CATEGORY 5: SHADER
    // CORE CATEGORY 6: FRAME
    // CORE CATEGORY 7: FEEDBACK
    // CORE CATEGORY 8: STATE
    SON8_OPENGL_AUTO GetError() { auto e = glGetError(); assert(e == GL_NO_ERROR); return static_cast< enums::Error >(e); }
    // UNCATEGORIZED
    // Core essential functions
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
    // inline auto Get(enums::GetFloat name) { GLfloat v; glGetFloatv(static_cast< GLenum >(name), &v); return v; }
    inline auto Get(enums::GetDouble name) { GLdouble v; glGetDoublev(static_cast< GLenum >(name), &v); return v; }
    inline auto Get(enums::GetArray2d name) { types::array2d v; glGetDoublev(static_cast< GLenum >(name), v.data()); return v; }
    inline auto Get(enums::GetArray4d name) { types::array4d v; glGetDoublev(static_cast< GLenum >(name), v.data()); return v; }
    inline auto Get(enums::GetArray4bool name) { types::array4bool v; glGetBooleanv(static_cast< GLenum >(name), v.data()); return v; }
    // GetTexImage
    // IsTexture
    // GetPointerv
    // GetString
    // compatibility functions
#ifndef  SON8_OPENGL_PROFILE_CORE
    // COMPATIBILITY CATEGORY 1: SPECIAL
    // COMPATIBILITY CATEGORY 2: DRAW
    //     Begin/End paradigm
    SON8_OPENGL_VOID Begin() { glBegin(static_cast< GLenum >(enums::Draw::Default)); }
    SON8_OPENGL_VOID Begin(enums::Draw mode) { glBegin(static_cast< GLenum >(mode)); }
    SON8_OPENGL_VOID End() { glEnd(); }
    SON8_OPENGL_VOID EdgeFlag(GLboolean flag) { glEdgeFlag(flag); }
    SON8_OPENGL_VOID EdgeFlag(types::array1bool const &flag) { glEdgeFlagv(flag.data()); }
    SON8_OPENGL_VOID Vertex(GLint x, GLint y) { glVertex2i(x, y); }
    SON8_OPENGL_VOID Vertex(GLshort x, GLshort y) { glVertex2s(x, y); }
    SON8_OPENGL_VOID Vertex(GLfloat x, GLfloat y) { glVertex2f(x, y); }
    SON8_OPENGL_VOID Vertex(GLdouble x, GLdouble y) { glVertex2d(x, y); }
    SON8_OPENGL_VOID Vertex(GLint x, GLint y, GLint z) { glVertex3i(x, y, z); }
    SON8_OPENGL_VOID Vertex(GLshort x, GLshort y, GLshort z) { glVertex3s(x, y, z); }
    SON8_OPENGL_VOID Vertex(GLfloat x, GLfloat y, GLfloat z) { glVertex3f(x, y, z); }
    SON8_OPENGL_VOID Vertex(GLdouble x, GLdouble y, GLdouble z) { glVertex3d(x, y, z); }
    SON8_OPENGL_VOID Vertex(GLint x, GLint y, GLint z, GLint w) { glVertex4i(x, y, z, w); }
    SON8_OPENGL_VOID Vertex(GLshort x, GLshort y, GLshort z, GLshort w) { glVertex4s(x, y, z, w); }
    SON8_OPENGL_VOID Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat w) { glVertex4f(x, y, z, w); }
    SON8_OPENGL_VOID Vertex(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glVertex4d(x, y, z, w); }
    SON8_OPENGL_VOID Vertex(types::array2s const &coords) { glVertex2sv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array2i const &coords) { glVertex2iv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array2f const &coords) { glVertex2fv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array2d const &coords) { glVertex2dv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array3s const &coords) { glVertex3sv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array3i const &coords) { glVertex3iv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array3f const &coords) { glVertex3fv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array3d const &coords) { glVertex3dv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array4s const &coords) { glVertex4sv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array4i const &coords) { glVertex4iv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array4f const &coords) { glVertex4fv(coords.data()); }
    SON8_OPENGL_VOID Vertex(types::array4d const &coords) { glVertex4dv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(GLint s) { glTexCoord1i(s); }
    SON8_OPENGL_VOID TexCoord(GLshort s) { glTexCoord1s(s); }
    SON8_OPENGL_VOID TexCoord(GLfloat s) { glTexCoord1f(s); }
    SON8_OPENGL_VOID TexCoord(GLdouble s) { glTexCoord1d(s); }
    SON8_OPENGL_VOID TexCoord(GLint s, GLint t) { glTexCoord2i(s, t); }
    SON8_OPENGL_VOID TexCoord(GLshort s, GLshort t) { glTexCoord2s(s, t); }
    SON8_OPENGL_VOID TexCoord(GLfloat s, GLfloat t) { glTexCoord2f(s, t); }
    SON8_OPENGL_VOID TexCoord(GLdouble s, GLdouble t) { glTexCoord2d(s, t); }
    SON8_OPENGL_VOID TexCoord(GLint s, GLint t, GLint p) { glTexCoord3i(s, t, p); }
    SON8_OPENGL_VOID TexCoord(GLshort s, GLshort t, GLshort p) { glTexCoord3s(s, t, p); }
    SON8_OPENGL_VOID TexCoord(GLfloat s, GLfloat t, GLfloat p) { glTexCoord3f(s, t, p); }
    SON8_OPENGL_VOID TexCoord(GLdouble s, GLdouble t, GLdouble p) { glTexCoord3d(s, t, p); }
    SON8_OPENGL_VOID TexCoord(GLint s, GLint t, GLint p, GLint q) { glTexCoord4i(s, t, p, q); }
    SON8_OPENGL_VOID TexCoord(GLshort s, GLshort t, GLshort p, GLshort q) { glTexCoord4s(s, t, p, q); }
    SON8_OPENGL_VOID TexCoord(GLfloat s, GLfloat t, GLfloat p, GLfloat q) { glTexCoord4f(s, t, p, q); }
    SON8_OPENGL_VOID TexCoord(GLdouble s, GLdouble t, GLdouble p, GLdouble q) { glTexCoord4d(s, t, p, q); }
    SON8_OPENGL_VOID TexCoord(types::array1s const &coords) { glTexCoord1sv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array1i const &coords) { glTexCoord1iv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array1f const &coords) { glTexCoord1fv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array1d const &coords) { glTexCoord1dv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array2s const &coords) { glTexCoord2sv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array2i const &coords) { glTexCoord2iv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array2f const &coords) { glTexCoord2fv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array2d const &coords) { glTexCoord2dv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array3s const &coords) { glTexCoord3sv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array3i const &coords) { glTexCoord3iv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array3f const &coords) { glTexCoord3fv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array3d const &coords) { glTexCoord3dv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array4s const &coords) { glTexCoord4sv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array4i const &coords) { glTexCoord4iv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array4f const &coords) { glTexCoord4fv(coords.data()); }
    SON8_OPENGL_VOID TexCoord(types::array4d const &coords) { glTexCoord4dv(coords.data()); }

    // COMPATIBILITY CATEGORY 3: DATA
    // COMPATIBILITY CATEGORY 4: TEXTURE
    // COMPATIBILITY CATEGORY 5: SHADER
    // COMPATIBILITY CATEGORY 6: FRAME
    // COMPATIBILITY CATEGORY 7: FEEDBACK
    // COMPATIBILITY CATEGORY 8: STATE
    // UNCATEGORIZED
    // matrix functions
    // MatrixMode, LoadMatrix, MultMatrix, LoadIdentity, Rotate, Translate, Scale, Frustum, Ortho, PushMatrix, PopMatrix
    //   vertex functions
    //     Array Pointers paradigm
    inline void EnableClientState(enums::Array array) { glEnableClientState(static_cast< GLenum >(array)); }
    inline void DisableClientState(enums::Array array) { glDisableClientState(static_cast< GLenum >(array)); }

    // EdgeFlagPointer, TexCoordPointer, NormalPointer, ColorPointer, IndexPointer VertexPointer
    // ArrayElement
    // InterleavedArrays

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
    // PushAttrib...
    // material functions
    // LightModel, Light, Material, ColorMaterial, ShadeModel
# endif//SON8_OPENGL_PROFILE_CORE
}
