
// --------------------------------------------------------
// Generated by glux perl script (Tue May 20 01:36:38 2014)
// 
// Sylvain Lefebvre - 2002 - Sylvain.Lefebvre@imag.fr
// --------------------------------------------------------
#ifdef WIN32
#  include <windows.h>
#endif
#ifdef __APPLE__
#  define GL_GLEXT_LEGACY
#endif

#ifndef GL_ARB_multitexture // hack due to MESA headers including GL_ARB_multitexture
#define GL_ARB_multitexture
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#undef  GL_ARB_multitexture
#else
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#undef  GL_ARB_multitexture
#endif

#undef  GL_GLEXT_PROTOTYPES
#ifdef WIN32
#  include "glux_glext.h"
#  include "glux_wglext.h"
#else
#ifdef __APPLE__
#  include "glux_glext.h"
#else
#  include <GL/glx.h>
#  include "glux_glext.h"
#  include "glux_glxext.h"
#endif
#endif
#include "gluxLoader.h"
#include "gluxPlugin.h"
// --------------------------------------------------------
//         Plugin creation
// --------------------------------------------------------

#ifndef __GLUX_GL_VERSION_3_1__
#define __GLUX_GL_VERSION_3_1__

GLUX_NEW_PLUGIN(GL_VERSION_3_1);
// --------------------------------------------------------
//           Extension conditions
// --------------------------------------------------------
// --------------------------------------------------------
//           Extension defines
// --------------------------------------------------------
#ifndef GL_SAMPLER_2D_RECT
#  define GL_SAMPLER_2D_RECT 0x8B63
#endif
#ifndef GL_SAMPLER_2D_RECT_SHADOW
#  define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#endif
#ifndef GL_SAMPLER_BUFFER
#  define GL_SAMPLER_BUFFER 0x8DC2
#endif
#ifndef GL_INT_SAMPLER_2D_RECT
#  define GL_INT_SAMPLER_2D_RECT 0x8DCD
#endif
#ifndef GL_INT_SAMPLER_BUFFER
#  define GL_INT_SAMPLER_BUFFER 0x8DD0
#endif
#ifndef GL_UNSIGNED_INT_SAMPLER_2D_RECT
#  define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#endif
#ifndef GL_UNSIGNED_INT_SAMPLER_BUFFER
#  define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#endif
#ifndef GL_TEXTURE_BUFFER
#  define GL_TEXTURE_BUFFER 0x8C2A
#endif
#ifndef GL_MAX_TEXTURE_BUFFER_SIZE
#  define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#endif
#ifndef GL_TEXTURE_BINDING_BUFFER
#  define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#endif
#ifndef GL_TEXTURE_BUFFER_DATA_STORE_BINDING
#  define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#endif
#ifndef GL_TEXTURE_RECTANGLE
#  define GL_TEXTURE_RECTANGLE 0x84F5
#endif
#ifndef GL_TEXTURE_BINDING_RECTANGLE
#  define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#endif
#ifndef GL_PROXY_TEXTURE_RECTANGLE
#  define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#endif
#ifndef GL_MAX_RECTANGLE_TEXTURE_SIZE
#  define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#endif
#ifndef GL_RED_SNORM
#  define GL_RED_SNORM 0x8F90
#endif
#ifndef GL_RG_SNORM
#  define GL_RG_SNORM 0x8F91
#endif
#ifndef GL_RGB_SNORM
#  define GL_RGB_SNORM 0x8F92
#endif
#ifndef GL_RGBA_SNORM
#  define GL_RGBA_SNORM 0x8F93
#endif
#ifndef GL_R8_SNORM
#  define GL_R8_SNORM 0x8F94
#endif
#ifndef GL_RG8_SNORM
#  define GL_RG8_SNORM 0x8F95
#endif
#ifndef GL_RGB8_SNORM
#  define GL_RGB8_SNORM 0x8F96
#endif
#ifndef GL_RGBA8_SNORM
#  define GL_RGBA8_SNORM 0x8F97
#endif
#ifndef GL_R16_SNORM
#  define GL_R16_SNORM 0x8F98
#endif
#ifndef GL_RG16_SNORM
#  define GL_RG16_SNORM 0x8F99
#endif
#ifndef GL_RGB16_SNORM
#  define GL_RGB16_SNORM 0x8F9A
#endif
#ifndef GL_RGBA16_SNORM
#  define GL_RGBA16_SNORM 0x8F9B
#endif
#ifndef GL_SIGNED_NORMALIZED
#  define GL_SIGNED_NORMALIZED 0x8F9C
#endif
#ifndef GL_PRIMITIVE_RESTART
#  define GL_PRIMITIVE_RESTART 0x8F9D
#endif
#ifndef GL_PRIMITIVE_RESTART_INDEX
#  define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#endif
// --------------------------------------------------------
//           Extension gl function typedefs
// --------------------------------------------------------
#ifndef __GLUX__GLFCT_glDrawArraysInstanced
typedef void (APIENTRYP PFNGLUXDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
#endif
#ifndef __GLUX__GLFCT_glDrawElementsInstanced
typedef void (APIENTRYP PFNGLUXDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount);
#endif
#ifndef __GLUX__GLFCT_glTexBuffer
typedef void (APIENTRYP PFNGLUXTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
#endif
#ifndef __GLUX__GLFCT_glPrimitiveRestartIndex
typedef void (APIENTRYP PFNGLUXPRIMITIVERESTARTINDEXPROC) (GLuint index);
#endif
// --------------------------------------------------------
//           Extension gl functions
// --------------------------------------------------------
namespace glux {
#ifndef __GLUX__GLFCT_glDrawArraysInstanced
extern PFNGLUXDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
#endif
#ifndef __GLUX__GLFCT_glDrawElementsInstanced
extern PFNGLUXDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
#endif
#ifndef __GLUX__GLFCT_glTexBuffer
extern PFNGLUXTEXBUFFERPROC glTexBuffer;
#endif
#ifndef __GLUX__GLFCT_glPrimitiveRestartIndex
extern PFNGLUXPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
#endif
} // namespace glux
// --------------------------------------------------------
#endif
// --------------------------------------------------------

// --------------------------------------------------------
// Generated by glux perl script (Thu Jun 19 23:09:58 2014)
// 
// Sylvain Lefebvre - 2002 - Sylvain.Lefebvre@imag.fr
// --------------------------------------------------------
#ifdef WIN32
#  include <windows.h>
#endif
#ifdef __APPLE__
#  define GL_GLEXT_LEGACY
#endif

#ifndef GL_ARB_multitexture // hack due to MESA headers including GL_ARB_multitexture
#define GL_ARB_multitexture
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#undef  GL_ARB_multitexture
#else
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#undef  GL_ARB_multitexture
#endif

#undef  GL_GLEXT_PROTOTYPES
#ifdef WIN32
#  include "glux_glext.h"
#  include "glux_wglext.h"
#else
#ifdef __APPLE__
#  include "glux_glext.h"
#else
#  include <GL/glx.h>
#  include "glux_glext.h"
#  include "glux_glxext.h"
#endif
#endif
#include "gluxLoader.h"
#include "gluxPlugin.h"
// --------------------------------------------------------
//         Plugin creation
// --------------------------------------------------------

#ifndef __GLUX_GL_VERSION_3_1__
#define __GLUX_GL_VERSION_3_1__

GLUX_NEW_PLUGIN(GL_VERSION_3_1);
// --------------------------------------------------------
//           Extension conditions
// --------------------------------------------------------
// --------------------------------------------------------
//           Extension defines
// --------------------------------------------------------
#ifndef GL_SAMPLER_2D_RECT
#  define GL_SAMPLER_2D_RECT 0x8B63
#endif
#ifndef GL_SAMPLER_2D_RECT_SHADOW
#  define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#endif
#ifndef GL_SAMPLER_BUFFER
#  define GL_SAMPLER_BUFFER 0x8DC2
#endif
#ifndef GL_INT_SAMPLER_2D_RECT
#  define GL_INT_SAMPLER_2D_RECT 0x8DCD
#endif
#ifndef GL_INT_SAMPLER_BUFFER
#  define GL_INT_SAMPLER_BUFFER 0x8DD0
#endif
#ifndef GL_UNSIGNED_INT_SAMPLER_2D_RECT
#  define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#endif
#ifndef GL_UNSIGNED_INT_SAMPLER_BUFFER
#  define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#endif
#ifndef GL_TEXTURE_BUFFER
#  define GL_TEXTURE_BUFFER 0x8C2A
#endif
#ifndef GL_MAX_TEXTURE_BUFFER_SIZE
#  define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#endif
#ifndef GL_TEXTURE_BINDING_BUFFER
#  define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#endif
#ifndef GL_TEXTURE_BUFFER_DATA_STORE_BINDING
#  define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#endif
#ifndef GL_TEXTURE_RECTANGLE
#  define GL_TEXTURE_RECTANGLE 0x84F5
#endif
#ifndef GL_TEXTURE_BINDING_RECTANGLE
#  define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#endif
#ifndef GL_PROXY_TEXTURE_RECTANGLE
#  define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#endif
#ifndef GL_MAX_RECTANGLE_TEXTURE_SIZE
#  define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#endif
#ifndef GL_RED_SNORM
#  define GL_RED_SNORM 0x8F90
#endif
#ifndef GL_RG_SNORM
#  define GL_RG_SNORM 0x8F91
#endif
#ifndef GL_RGB_SNORM
#  define GL_RGB_SNORM 0x8F92
#endif
#ifndef GL_RGBA_SNORM
#  define GL_RGBA_SNORM 0x8F93
#endif
#ifndef GL_R8_SNORM
#  define GL_R8_SNORM 0x8F94
#endif
#ifndef GL_RG8_SNORM
#  define GL_RG8_SNORM 0x8F95
#endif
#ifndef GL_RGB8_SNORM
#  define GL_RGB8_SNORM 0x8F96
#endif
#ifndef GL_RGBA8_SNORM
#  define GL_RGBA8_SNORM 0x8F97
#endif
#ifndef GL_R16_SNORM
#  define GL_R16_SNORM 0x8F98
#endif
#ifndef GL_RG16_SNORM
#  define GL_RG16_SNORM 0x8F99
#endif
#ifndef GL_RGB16_SNORM
#  define GL_RGB16_SNORM 0x8F9A
#endif
#ifndef GL_RGBA16_SNORM
#  define GL_RGBA16_SNORM 0x8F9B
#endif
#ifndef GL_SIGNED_NORMALIZED
#  define GL_SIGNED_NORMALIZED 0x8F9C
#endif
#ifndef GL_PRIMITIVE_RESTART
#  define GL_PRIMITIVE_RESTART 0x8F9D
#endif
#ifndef GL_PRIMITIVE_RESTART_INDEX
#  define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#endif
// --------------------------------------------------------
//           Extension gl function typedefs
// --------------------------------------------------------
#ifndef __GLUX__GLFCT_glDrawArraysInstanced
typedef void (APIENTRYP PFNGLUXDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
#endif
#ifndef __GLUX__GLFCT_glDrawElementsInstanced
typedef void (APIENTRYP PFNGLUXDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount);
#endif
#ifndef __GLUX__GLFCT_glTexBuffer
typedef void (APIENTRYP PFNGLUXTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
#endif
#ifndef __GLUX__GLFCT_glPrimitiveRestartIndex
typedef void (APIENTRYP PFNGLUXPRIMITIVERESTARTINDEXPROC) (GLuint index);
#endif
// --------------------------------------------------------
//           Extension gl functions
// --------------------------------------------------------
namespace glux {
#ifndef __GLUX__GLFCT_glDrawArraysInstanced
extern PFNGLUXDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
#endif
#ifndef __GLUX__GLFCT_glDrawElementsInstanced
extern PFNGLUXDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
#endif
#ifndef __GLUX__GLFCT_glTexBuffer
extern PFNGLUXTEXBUFFERPROC glTexBuffer;
#endif
#ifndef __GLUX__GLFCT_glPrimitiveRestartIndex
extern PFNGLUXPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
#endif
} // namespace glux
// --------------------------------------------------------
#endif
// --------------------------------------------------------

// --------------------------------------------------------
// Generated by glux perl script (Wed Jul 30 07:19:58 2014)
// 
// Sylvain Lefebvre - 2002 - Sylvain.Lefebvre@imag.fr
// --------------------------------------------------------
#ifdef WIN32
#  include <windows.h>
#endif
#ifdef __APPLE__
#  define GL_GLEXT_LEGACY
#endif

#ifndef GL_ARB_multitexture // hack due to MESA headers including GL_ARB_multitexture
#define GL_ARB_multitexture
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#undef  GL_ARB_multitexture
#else
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#undef  GL_ARB_multitexture
#endif

#undef  GL_GLEXT_PROTOTYPES
#ifdef WIN32
#  include "glux_glext.h"
#  include "glux_wglext.h"
#else
#ifdef __APPLE__
#  include "glux_glext.h"
#else
#  include <GL/glx.h>
#  include "glux_glext.h"
#  include "glux_glxext.h"
#endif
#endif
#include "gluxLoader.h"
#include "gluxPlugin.h"
// --------------------------------------------------------
//         Plugin creation
// --------------------------------------------------------

#ifndef __GLUX_GL_VERSION_3_1__
#define __GLUX_GL_VERSION_3_1__

GLUX_NEW_PLUGIN(GL_VERSION_3_1);
// --------------------------------------------------------
//           Extension conditions
// --------------------------------------------------------
// --------------------------------------------------------
//           Extension defines
// --------------------------------------------------------
#ifndef GL_SAMPLER_2D_RECT
#  define GL_SAMPLER_2D_RECT 0x8B63
#endif
#ifndef GL_SAMPLER_2D_RECT_SHADOW
#  define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#endif
#ifndef GL_SAMPLER_BUFFER
#  define GL_SAMPLER_BUFFER 0x8DC2
#endif
#ifndef GL_INT_SAMPLER_2D_RECT
#  define GL_INT_SAMPLER_2D_RECT 0x8DCD
#endif
#ifndef GL_INT_SAMPLER_BUFFER
#  define GL_INT_SAMPLER_BUFFER 0x8DD0
#endif
#ifndef GL_UNSIGNED_INT_SAMPLER_2D_RECT
#  define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#endif
#ifndef GL_UNSIGNED_INT_SAMPLER_BUFFER
#  define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#endif
#ifndef GL_TEXTURE_BUFFER
#  define GL_TEXTURE_BUFFER 0x8C2A
#endif
#ifndef GL_MAX_TEXTURE_BUFFER_SIZE
#  define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#endif
#ifndef GL_TEXTURE_BINDING_BUFFER
#  define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#endif
#ifndef GL_TEXTURE_BUFFER_DATA_STORE_BINDING
#  define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#endif
#ifndef GL_TEXTURE_RECTANGLE
#  define GL_TEXTURE_RECTANGLE 0x84F5
#endif
#ifndef GL_TEXTURE_BINDING_RECTANGLE
#  define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#endif
#ifndef GL_PROXY_TEXTURE_RECTANGLE
#  define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#endif
#ifndef GL_MAX_RECTANGLE_TEXTURE_SIZE
#  define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#endif
#ifndef GL_RED_SNORM
#  define GL_RED_SNORM 0x8F90
#endif
#ifndef GL_RG_SNORM
#  define GL_RG_SNORM 0x8F91
#endif
#ifndef GL_RGB_SNORM
#  define GL_RGB_SNORM 0x8F92
#endif
#ifndef GL_RGBA_SNORM
#  define GL_RGBA_SNORM 0x8F93
#endif
#ifndef GL_R8_SNORM
#  define GL_R8_SNORM 0x8F94
#endif
#ifndef GL_RG8_SNORM
#  define GL_RG8_SNORM 0x8F95
#endif
#ifndef GL_RGB8_SNORM
#  define GL_RGB8_SNORM 0x8F96
#endif
#ifndef GL_RGBA8_SNORM
#  define GL_RGBA8_SNORM 0x8F97
#endif
#ifndef GL_R16_SNORM
#  define GL_R16_SNORM 0x8F98
#endif
#ifndef GL_RG16_SNORM
#  define GL_RG16_SNORM 0x8F99
#endif
#ifndef GL_RGB16_SNORM
#  define GL_RGB16_SNORM 0x8F9A
#endif
#ifndef GL_RGBA16_SNORM
#  define GL_RGBA16_SNORM 0x8F9B
#endif
#ifndef GL_SIGNED_NORMALIZED
#  define GL_SIGNED_NORMALIZED 0x8F9C
#endif
#ifndef GL_PRIMITIVE_RESTART
#  define GL_PRIMITIVE_RESTART 0x8F9D
#endif
#ifndef GL_PRIMITIVE_RESTART_INDEX
#  define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#endif
// --------------------------------------------------------
//           Extension gl function typedefs
// --------------------------------------------------------
#ifndef __GLUX__GLFCT_glDrawArraysInstanced
typedef void (APIENTRYP PFNGLUXDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
#endif
#ifndef __GLUX__GLFCT_glDrawElementsInstanced
typedef void (APIENTRYP PFNGLUXDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount);
#endif
#ifndef __GLUX__GLFCT_glTexBuffer
typedef void (APIENTRYP PFNGLUXTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
#endif
#ifndef __GLUX__GLFCT_glPrimitiveRestartIndex
typedef void (APIENTRYP PFNGLUXPRIMITIVERESTARTINDEXPROC) (GLuint index);
#endif
// --------------------------------------------------------
//           Extension gl functions
// --------------------------------------------------------
namespace glux {
#ifndef __GLUX__GLFCT_glDrawArraysInstanced
extern PFNGLUXDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
#endif
#ifndef __GLUX__GLFCT_glDrawElementsInstanced
extern PFNGLUXDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
#endif
#ifndef __GLUX__GLFCT_glTexBuffer
extern PFNGLUXTEXBUFFERPROC glTexBuffer;
#endif
#ifndef __GLUX__GLFCT_glPrimitiveRestartIndex
extern PFNGLUXPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
#endif
} // namespace glux
// --------------------------------------------------------
#endif
// --------------------------------------------------------

// --------------------------------------------------------
// Generated by glux perl script (Mon Feb 23 17:42:56 2015)
// 
// Sylvain Lefebvre - 2002-2014 - Sylvain.Lefebvre@inria.fr
// --------------------------------------------------------
#ifdef WIN32
#  include <windows.h>
#endif
#ifdef __APPLE__
#  define GL_GLEXT_LEGACY
#endif

#ifndef GL_ARB_multitexture // hack due to MESA headers including GL_ARB_multitexture
#define GL_ARB_multitexture
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#undef  GL_ARB_multitexture
#else
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#undef  GL_ARB_multitexture
#endif

#undef  GL_GLEXT_PROTOTYPES
#ifdef WIN32
#  include "glux_glext.h"
#  include "glux_wglext.h"
#else
#ifdef __APPLE__
#  include "glux_apple_glext.h"
#else
#  include <GL/glx.h>
#  include "glux_glext.h"
#  include "glux_glxext.h"
#endif
#endif
#include "gluxLoader.h"
#include "gluxPlugin.h"
// --------------------------------------------------------
//         Plugin creation
// --------------------------------------------------------

#ifndef __GLUX_GL_VERSION_3_1__
#define __GLUX_GL_VERSION_3_1__

GLUX_NEW_PLUGIN(GL_VERSION_3_1)
// --------------------------------------------------------
//           Extension conditions
// --------------------------------------------------------
// --------------------------------------------------------
//           Extension defines
// --------------------------------------------------------
#ifndef GL_SAMPLER_2D_RECT
#  define GL_SAMPLER_2D_RECT 0x8B63
#endif
#ifndef GL_SAMPLER_2D_RECT_SHADOW
#  define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#endif
#ifndef GL_SAMPLER_BUFFER
#  define GL_SAMPLER_BUFFER 0x8DC2
#endif
#ifndef GL_INT_SAMPLER_2D_RECT
#  define GL_INT_SAMPLER_2D_RECT 0x8DCD
#endif
#ifndef GL_INT_SAMPLER_BUFFER
#  define GL_INT_SAMPLER_BUFFER 0x8DD0
#endif
#ifndef GL_UNSIGNED_INT_SAMPLER_2D_RECT
#  define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#endif
#ifndef GL_UNSIGNED_INT_SAMPLER_BUFFER
#  define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#endif
#ifndef GL_TEXTURE_BUFFER
#  define GL_TEXTURE_BUFFER 0x8C2A
#endif
#ifndef GL_MAX_TEXTURE_BUFFER_SIZE
#  define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#endif
#ifndef GL_TEXTURE_BINDING_BUFFER
#  define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#endif
#ifndef GL_TEXTURE_BUFFER_DATA_STORE_BINDING
#  define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#endif
#ifndef GL_TEXTURE_RECTANGLE
#  define GL_TEXTURE_RECTANGLE 0x84F5
#endif
#ifndef GL_TEXTURE_BINDING_RECTANGLE
#  define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#endif
#ifndef GL_PROXY_TEXTURE_RECTANGLE
#  define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#endif
#ifndef GL_MAX_RECTANGLE_TEXTURE_SIZE
#  define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#endif
#ifndef GL_RED_SNORM
#  define GL_RED_SNORM 0x8F90
#endif
#ifndef GL_RG_SNORM
#  define GL_RG_SNORM 0x8F91
#endif
#ifndef GL_RGB_SNORM
#  define GL_RGB_SNORM 0x8F92
#endif
#ifndef GL_RGBA_SNORM
#  define GL_RGBA_SNORM 0x8F93
#endif
#ifndef GL_R8_SNORM
#  define GL_R8_SNORM 0x8F94
#endif
#ifndef GL_RG8_SNORM
#  define GL_RG8_SNORM 0x8F95
#endif
#ifndef GL_RGB8_SNORM
#  define GL_RGB8_SNORM 0x8F96
#endif
#ifndef GL_RGBA8_SNORM
#  define GL_RGBA8_SNORM 0x8F97
#endif
#ifndef GL_R16_SNORM
#  define GL_R16_SNORM 0x8F98
#endif
#ifndef GL_RG16_SNORM
#  define GL_RG16_SNORM 0x8F99
#endif
#ifndef GL_RGB16_SNORM
#  define GL_RGB16_SNORM 0x8F9A
#endif
#ifndef GL_RGBA16_SNORM
#  define GL_RGBA16_SNORM 0x8F9B
#endif
#ifndef GL_SIGNED_NORMALIZED
#  define GL_SIGNED_NORMALIZED 0x8F9C
#endif
#ifndef GL_PRIMITIVE_RESTART
#  define GL_PRIMITIVE_RESTART 0x8F9D
#endif
#ifndef GL_PRIMITIVE_RESTART_INDEX
#  define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#endif
// --------------------------------------------------------
//           Extension gl function typedefs
// --------------------------------------------------------
#ifndef __GLUX__GLFCT_glDrawArraysInstanced
typedef void (APIENTRYP PFNGLUXDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
#endif
#ifndef __GLUX__GLFCT_glDrawElementsInstanced
typedef void (APIENTRYP PFNGLUXDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount);
#endif
#ifndef __GLUX__GLFCT_glTexBuffer
typedef void (APIENTRYP PFNGLUXTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
#endif
#ifndef __GLUX__GLFCT_glPrimitiveRestartIndex
typedef void (APIENTRYP PFNGLUXPRIMITIVERESTARTINDEXPROC) (GLuint index);
#endif
// --------------------------------------------------------
//           Extension gl functions
// --------------------------------------------------------
namespace glux {
#ifndef __GLUX__GLFCT_glDrawArraysInstanced
extern PFNGLUXDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
#endif
#ifndef __GLUX__GLFCT_glDrawElementsInstanced
extern PFNGLUXDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
#endif
#ifndef __GLUX__GLFCT_glTexBuffer
extern PFNGLUXTEXBUFFERPROC glTexBuffer;
#endif
#ifndef __GLUX__GLFCT_glPrimitiveRestartIndex
extern PFNGLUXPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
#endif
} // namespace glux
// --------------------------------------------------------
#endif
// --------------------------------------------------------