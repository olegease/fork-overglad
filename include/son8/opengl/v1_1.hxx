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
    SON8_OPENGL_VOID Viewport(types::Rect rect = types::Rect{}) { glViewport(rect.lXb.x, rect.lXb.y, rect.wXh.w, rect.wXh.h); }
    SON8_OPENGL_VOID DepthRange(GLclampd near, GLclampd far) { glDepthRange(near, far); }
    // CORE CATEGORY 2: DRAW
    SON8_OPENGL_VOID DrawArrays(GLsizei count) { glDrawArrays(static_cast< GLenum >(enums::Draw::Default), 0, count); }
    SON8_OPENGL_VOID DrawArrays(enums::Draw mode, GLsizei count) { glDrawArrays(static_cast< GLenum >(mode), 0, count); }
    SON8_OPENGL_DEPR DrawArrays(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    SON8_OPENGL_DEPR DrawElements(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    // CORE CATEGORY 3: DATA
    // CORE CATEGORY 4: TEXTURE
    // CORE CATEGORY 5: SHADER
    // CORE CATEGORY 6: FRAME
    // CORE CATEGORY 7: FEEDBACK
    // CORE CATEGORY 8: STATE
    SON8_OPENGL_AUTO GetError() { auto e = glGetError(); assert(e == GL_NO_ERROR); return static_cast< enums::Error >(e); }
    SON8_OPENGL_VOID Enable(enums::Capability cap) { glEnable(static_cast< GLenum >(cap)); }
    SON8_OPENGL_VOID Disable(enums::Capability cap) { glDisable(static_cast< GLenum >(cap)); }
    SON8_OPENGL_AUTO IsEnabled(enums::Is is) -> bool { return glIsEnabled(static_cast< GLenum >(is)); }
    // UNCATEGORIZED
    // Core essential functions
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
    // DrawElements
    // get functions
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
    SON8_OPENGL_VOID PushMatrix() { glPushMatrix(); }
    SON8_OPENGL_VOID PopMatrix() { glPopMatrix(); }
    SON8_OPENGL_VOID MatrixMode(enums::Matrix mode) { glMatrixMode(static_cast< GLenum >(mode)); }
    SON8_OPENGL_VOID LoadIdentity(types::array16f const &m) { glLoadIdentity(); }
    SON8_OPENGL_VOID LoadMatrix(types::array16f const &m) { glLoadMatrixf(m.data()); }
    SON8_OPENGL_VOID LoadMatrix(types::array16d const &m) { glLoadMatrixd(m.data()); }
    SON8_OPENGL_VOID MultMatrix(types::array16f const &m) { glMultMatrixf(m.data()); }
    SON8_OPENGL_VOID MultMatrix(types::array16d const &m) { glMultMatrixd(m.data()); }
    SON8_OPENGL_VOID Scale(GLfloat x, GLfloat y, GLfloat z) { glScalef(x, y, z); }
    SON8_OPENGL_VOID Scale(GLdouble x, GLdouble y, GLdouble z) { glScaled(x, y, z); }
    SON8_OPENGL_VOID Translate(GLfloat x, GLfloat y, GLfloat z) { glTranslatef(x, y, z); }
    SON8_OPENGL_VOID Translate(GLdouble x, GLdouble y, GLdouble z) { glTranslated(x, y, z); }
    SON8_OPENGL_VOID Rotate(GLfloat degrees, GLfloat x, GLfloat y, GLfloat z) { glRotatef(degrees, x, y, z); }
    SON8_OPENGL_VOID Rotate(GLdouble degrees, GLdouble x, GLdouble y, GLdouble z) { glRotated(degrees, x, y, z); }
    SON8_OPENGL_DEPR Ortho(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    SON8_OPENGL_DEPR Frustum(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    SON8_OPENGL_VOID ClipPlane(enums::Clip plane, types::array4d const &equation) { glClipPlane(static_cast< GLenum >(plane), equation.data()); }
    // COMPATIBILITY CATEGORY 2: DRAW
    //      list paradigm
    SON8_OPENGL_DEPR CallList(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    //      vertex pointer paragigm
    SON8_OPENGL_VOID ArrayElement(GLint i) { glArrayElement(i); }
    SON8_OPENGL_VOID EnableClientState(enums::Array array) { glEnableClientState(static_cast< GLenum >(array)); }
    SON8_OPENGL_VOID DisableClientState(enums::Array array) { glDisableClientState(static_cast< GLenum >(array)); }
    //      Begin/End paradigm
    SON8_OPENGL_VOID Begin() { glBegin(static_cast< GLenum >(enums::Draw::Default)); }
    SON8_OPENGL_VOID Begin(enums::Draw mode) { glBegin(static_cast< GLenum >(mode)); }
    SON8_OPENGL_VOID End() { glEnd(); }
    SON8_OPENGL_VOID Index(GLint index) { glIndexi(index); }
    SON8_OPENGL_VOID Index(GLshort index) { glIndexs(index); }
    SON8_OPENGL_VOID Index(GLfloat index) { glIndexf(index); }
    SON8_OPENGL_VOID Index(GLubyte index) { glIndexub(index); }
    SON8_OPENGL_VOID Index(GLdouble index) { glIndexd(index); }
    SON8_OPENGL_VOID Index(types::array1s const &index) { glIndexsv(index.data()); }
    SON8_OPENGL_VOID Index(types::array1i const &index) { glIndexiv(index.data()); }
    SON8_OPENGL_VOID Index(types::array1f const &index) { glIndexfv(index.data()); }
    SON8_OPENGL_VOID Index(types::array1d const &index) { glIndexdv(index.data()); }
    SON8_OPENGL_VOID Index(types::array1ub const &index) { glIndexubv(index.data()); }
    SON8_OPENGL_VOID Color(GLint r, GLint g, GLint b, GLint a) { glColor4i(r, g, b, a); }
    SON8_OPENGL_VOID Color(GLbyte r, GLbyte g, GLbyte b, GLbyte a) { glColor4b(r, g, b, a); }
    SON8_OPENGL_VOID Color(GLuint r, GLuint g, GLuint b, GLuint a) { glColor4ui(r, g, b, a); }
    SON8_OPENGL_VOID Color(GLshort r, GLshort g, GLshort b, GLshort a) { glColor4s(r, g, b, a); }
    SON8_OPENGL_VOID Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a) { glColor4f(r, g, b, a); }
    SON8_OPENGL_VOID Color(GLubyte r, GLubyte g, GLubyte b, GLubyte a) { glColor4ub(r, g, b, a); }
    SON8_OPENGL_VOID Color(GLdouble r, GLdouble g, GLdouble b, GLdouble a) { glColor4d(r, g, b, a); }
    SON8_OPENGL_VOID Color(GLushort r, GLushort g, GLushort b, GLushort a) { glColor4us(r, g, b, a); }
    SON8_OPENGL_VOID Color(types::array4b const &components) { glColor4bv(components.data()); }
    SON8_OPENGL_VOID Color(types::array4s const &components) { glColor4sv(components.data()); }
    SON8_OPENGL_VOID Color(types::array4i const &components) { glColor4iv(components.data()); }
    SON8_OPENGL_VOID Color(types::array4f const &components) { glColor4fv(components.data()); }
    SON8_OPENGL_VOID Color(types::array4d const &components) { glColor4dv(components.data()); }
    SON8_OPENGL_VOID Color(types::array4ub const &components) { glColor4ubv(components.data()); }
    SON8_OPENGL_VOID Color(types::array4us const &components) { glColor4usv(components.data()); }
    SON8_OPENGL_VOID Color(types::array4ui const &components) { glColor4uiv(components.data()); }
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
    SON8_OPENGL_VOID Normal(GLint x, GLint y, GLint z) {  glNormal3i(x, y, z); }
    SON8_OPENGL_VOID Normal(GLbyte x, GLbyte y, GLbyte z) {  glNormal3b(x, y, z); }
    SON8_OPENGL_VOID Normal(GLshort x, GLshort y, GLshort z) {  glNormal3s(x, y, z); }
    SON8_OPENGL_VOID Normal(GLfloat x, GLfloat y, GLfloat z) {  glNormal3f(x, y, z); }
    SON8_OPENGL_VOID Normal(GLdouble x, GLdouble y, GLdouble z) {  glNormal3d(x, y, z); }
    SON8_OPENGL_VOID Normal(types::array3b const &coords) { glNormal3bv(coords.data()); }
    SON8_OPENGL_VOID Normal(types::array3s const &coords) { glNormal3sv(coords.data()); }
    SON8_OPENGL_VOID Normal(types::array3i const &coords) { glNormal3iv(coords.data()); }
    SON8_OPENGL_VOID Normal(types::array3f const &coords) { glNormal3fv(coords.data()); }
    SON8_OPENGL_VOID Normal(types::array3d const &coords) { glNormal3dv(coords.data()); }
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
    SON8_OPENGL_VOID EdgeFlag(GLboolean flag) { glEdgeFlag(flag); }
    SON8_OPENGL_VOID EdgeFlag(types::array1bool const &flag) { glEdgeFlagv(flag.data()); }
    SON8_OPENGL_VOID Rect(GLint x1, GLint y1, GLint x2, GLint y2) { glRecti(x1, y1, x2, y2); }
    SON8_OPENGL_VOID Rect(GLshort x1, GLshort y1, GLshort x2, GLshort y2) { glRects(x1, y1, x2, y2); }
    SON8_OPENGL_VOID Rect(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) { glRectf(x1, y1, x2, y2); }
    SON8_OPENGL_VOID Rect(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) { glRectd(x1, y1, x2, y2); }
    SON8_OPENGL_VOID Rect(types::array2s const &v1, types::array2s const &v2) { glRectsv(v1.data(), v2.data()); }
    SON8_OPENGL_VOID Rect(types::array2i const &v1, types::array2i const &v2) { glRectiv(v1.data(), v2.data()); }
    SON8_OPENGL_VOID Rect(types::array2f const &v1, types::array2f const &v2) { glRectfv(v1.data(), v2.data()); }
    SON8_OPENGL_VOID Rect(types::array2d const &v1, types::array2d const &v2) { glRectdv(v1.data(), v2.data()); }
    // COMPATIBILITY CATEGORY 3: DATA
    SON8_OPENGL_DEPR IndexPointer(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    SON8_OPENGL_DEPR ColorPointer(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    SON8_OPENGL_DEPR VertexPointer(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    SON8_OPENGL_DEPR NormalPointer(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    SON8_OPENGL_DEPR TexCoordPointer(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    SON8_OPENGL_DEPR EdgeFlagPointer(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    SON8_OPENGL_DEPR InterleavedArrays(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    // COMPATIBILITY CATEGORY 4: TEXTURE
    // TexGen
    SON8_OPENGL_DEPR TexGen(...) { assert(SON8_OPENGL_NOT_IMPLEMENTED); }
    // COMPATIBILITY CATEGORY 5: SHADER
    // COMPATIBILITY CATEGORY 6: FRAME
    // COMPATIBILITY CATEGORY 7: FEEDBACK
    // COMPATIBILITY CATEGORY 8: STATE

    // UNCATEGORIZED
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
