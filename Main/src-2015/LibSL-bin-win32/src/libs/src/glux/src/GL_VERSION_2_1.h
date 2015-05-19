
// --------------------------------------------------------
// Generated by glux perl script (Tue May 20 01:36:44 2014)
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

#ifndef __GLUX_GL_VERSION_2_1__
#define __GLUX_GL_VERSION_2_1__

GLUX_NEW_PLUGIN(GL_VERSION_2_1);
// --------------------------------------------------------
//           Extension conditions
// --------------------------------------------------------
// --------------------------------------------------------
//           Extension defines
// --------------------------------------------------------
#ifndef GL_PIXEL_PACK_BUFFER
#  define GL_PIXEL_PACK_BUFFER 0x88EB
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER
#  define GL_PIXEL_UNPACK_BUFFER 0x88EC
#endif
#ifndef GL_PIXEL_PACK_BUFFER_BINDING
#  define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER_BINDING
#  define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#endif
#ifndef GL_FLOAT_MAT2x3
#  define GL_FLOAT_MAT2x3 0x8B65
#endif
#ifndef GL_FLOAT_MAT2x4
#  define GL_FLOAT_MAT2x4 0x8B66
#endif
#ifndef GL_FLOAT_MAT3x2
#  define GL_FLOAT_MAT3x2 0x8B67
#endif
#ifndef GL_FLOAT_MAT3x4
#  define GL_FLOAT_MAT3x4 0x8B68
#endif
#ifndef GL_FLOAT_MAT4x2
#  define GL_FLOAT_MAT4x2 0x8B69
#endif
#ifndef GL_FLOAT_MAT4x3
#  define GL_FLOAT_MAT4x3 0x8B6A
#endif
#ifndef GL_SRGB
#  define GL_SRGB 0x8C40
#endif
#ifndef GL_SRGB8
#  define GL_SRGB8 0x8C41
#endif
#ifndef GL_SRGB_ALPHA
#  define GL_SRGB_ALPHA 0x8C42
#endif
#ifndef GL_SRGB8_ALPHA8
#  define GL_SRGB8_ALPHA8 0x8C43
#endif
#ifndef GL_COMPRESSED_SRGB
#  define GL_COMPRESSED_SRGB 0x8C48
#endif
#ifndef GL_COMPRESSED_SRGB_ALPHA
#  define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#endif
#ifndef GL_CURRENT_RASTER_SECONDARY_COLOR
#  define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#endif
#ifndef GL_SLUMINANCE_ALPHA
#  define GL_SLUMINANCE_ALPHA 0x8C44
#endif
#ifndef GL_SLUMINANCE8_ALPHA8
#  define GL_SLUMINANCE8_ALPHA8 0x8C45
#endif
#ifndef GL_SLUMINANCE
#  define GL_SLUMINANCE 0x8C46
#endif
#ifndef GL_SLUMINANCE8
#  define GL_SLUMINANCE8 0x8C47
#endif
#ifndef GL_COMPRESSED_SLUMINANCE
#  define GL_COMPRESSED_SLUMINANCE 0x8C4A
#endif
#ifndef GL_COMPRESSED_SLUMINANCE_ALPHA
#  define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
#endif
// --------------------------------------------------------
//           Extension gl function typedefs
// --------------------------------------------------------
#ifndef __GLUX__GLFCT_glUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x3fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
// --------------------------------------------------------
//           Extension gl functions
// --------------------------------------------------------
namespace glux {
#ifndef __GLUX__GLFCT_glUniformMatrix2x3fv
extern PFNGLUXUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x2fv
extern PFNGLUXUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix2x4fv
extern PFNGLUXUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x2fv
extern PFNGLUXUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x4fv
extern PFNGLUXUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x3fv
extern PFNGLUXUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;
#endif
} // namespace glux
// --------------------------------------------------------
#endif
// --------------------------------------------------------

// --------------------------------------------------------
// Generated by glux perl script (Thu Jun 19 23:10:03 2014)
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

#ifndef __GLUX_GL_VERSION_2_1__
#define __GLUX_GL_VERSION_2_1__

GLUX_NEW_PLUGIN(GL_VERSION_2_1);
// --------------------------------------------------------
//           Extension conditions
// --------------------------------------------------------
// --------------------------------------------------------
//           Extension defines
// --------------------------------------------------------
#ifndef GL_PIXEL_PACK_BUFFER
#  define GL_PIXEL_PACK_BUFFER 0x88EB
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER
#  define GL_PIXEL_UNPACK_BUFFER 0x88EC
#endif
#ifndef GL_PIXEL_PACK_BUFFER_BINDING
#  define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER_BINDING
#  define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#endif
#ifndef GL_FLOAT_MAT2x3
#  define GL_FLOAT_MAT2x3 0x8B65
#endif
#ifndef GL_FLOAT_MAT2x4
#  define GL_FLOAT_MAT2x4 0x8B66
#endif
#ifndef GL_FLOAT_MAT3x2
#  define GL_FLOAT_MAT3x2 0x8B67
#endif
#ifndef GL_FLOAT_MAT3x4
#  define GL_FLOAT_MAT3x4 0x8B68
#endif
#ifndef GL_FLOAT_MAT4x2
#  define GL_FLOAT_MAT4x2 0x8B69
#endif
#ifndef GL_FLOAT_MAT4x3
#  define GL_FLOAT_MAT4x3 0x8B6A
#endif
#ifndef GL_SRGB
#  define GL_SRGB 0x8C40
#endif
#ifndef GL_SRGB8
#  define GL_SRGB8 0x8C41
#endif
#ifndef GL_SRGB_ALPHA
#  define GL_SRGB_ALPHA 0x8C42
#endif
#ifndef GL_SRGB8_ALPHA8
#  define GL_SRGB8_ALPHA8 0x8C43
#endif
#ifndef GL_COMPRESSED_SRGB
#  define GL_COMPRESSED_SRGB 0x8C48
#endif
#ifndef GL_COMPRESSED_SRGB_ALPHA
#  define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#endif
#ifndef GL_CURRENT_RASTER_SECONDARY_COLOR
#  define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#endif
#ifndef GL_SLUMINANCE_ALPHA
#  define GL_SLUMINANCE_ALPHA 0x8C44
#endif
#ifndef GL_SLUMINANCE8_ALPHA8
#  define GL_SLUMINANCE8_ALPHA8 0x8C45
#endif
#ifndef GL_SLUMINANCE
#  define GL_SLUMINANCE 0x8C46
#endif
#ifndef GL_SLUMINANCE8
#  define GL_SLUMINANCE8 0x8C47
#endif
#ifndef GL_COMPRESSED_SLUMINANCE
#  define GL_COMPRESSED_SLUMINANCE 0x8C4A
#endif
#ifndef GL_COMPRESSED_SLUMINANCE_ALPHA
#  define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
#endif
// --------------------------------------------------------
//           Extension gl function typedefs
// --------------------------------------------------------
#ifndef __GLUX__GLFCT_glUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x3fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
// --------------------------------------------------------
//           Extension gl functions
// --------------------------------------------------------
namespace glux {
#ifndef __GLUX__GLFCT_glUniformMatrix2x3fv
extern PFNGLUXUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x2fv
extern PFNGLUXUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix2x4fv
extern PFNGLUXUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x2fv
extern PFNGLUXUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x4fv
extern PFNGLUXUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x3fv
extern PFNGLUXUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;
#endif
} // namespace glux
// --------------------------------------------------------
#endif
// --------------------------------------------------------

// --------------------------------------------------------
// Generated by glux perl script (Wed Jul 30 07:20:04 2014)
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

#ifndef __GLUX_GL_VERSION_2_1__
#define __GLUX_GL_VERSION_2_1__

GLUX_NEW_PLUGIN(GL_VERSION_2_1);
// --------------------------------------------------------
//           Extension conditions
// --------------------------------------------------------
// --------------------------------------------------------
//           Extension defines
// --------------------------------------------------------
#ifndef GL_PIXEL_PACK_BUFFER
#  define GL_PIXEL_PACK_BUFFER 0x88EB
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER
#  define GL_PIXEL_UNPACK_BUFFER 0x88EC
#endif
#ifndef GL_PIXEL_PACK_BUFFER_BINDING
#  define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER_BINDING
#  define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#endif
#ifndef GL_FLOAT_MAT2x3
#  define GL_FLOAT_MAT2x3 0x8B65
#endif
#ifndef GL_FLOAT_MAT2x4
#  define GL_FLOAT_MAT2x4 0x8B66
#endif
#ifndef GL_FLOAT_MAT3x2
#  define GL_FLOAT_MAT3x2 0x8B67
#endif
#ifndef GL_FLOAT_MAT3x4
#  define GL_FLOAT_MAT3x4 0x8B68
#endif
#ifndef GL_FLOAT_MAT4x2
#  define GL_FLOAT_MAT4x2 0x8B69
#endif
#ifndef GL_FLOAT_MAT4x3
#  define GL_FLOAT_MAT4x3 0x8B6A
#endif
#ifndef GL_SRGB
#  define GL_SRGB 0x8C40
#endif
#ifndef GL_SRGB8
#  define GL_SRGB8 0x8C41
#endif
#ifndef GL_SRGB_ALPHA
#  define GL_SRGB_ALPHA 0x8C42
#endif
#ifndef GL_SRGB8_ALPHA8
#  define GL_SRGB8_ALPHA8 0x8C43
#endif
#ifndef GL_COMPRESSED_SRGB
#  define GL_COMPRESSED_SRGB 0x8C48
#endif
#ifndef GL_COMPRESSED_SRGB_ALPHA
#  define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#endif
#ifndef GL_CURRENT_RASTER_SECONDARY_COLOR
#  define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#endif
#ifndef GL_SLUMINANCE_ALPHA
#  define GL_SLUMINANCE_ALPHA 0x8C44
#endif
#ifndef GL_SLUMINANCE8_ALPHA8
#  define GL_SLUMINANCE8_ALPHA8 0x8C45
#endif
#ifndef GL_SLUMINANCE
#  define GL_SLUMINANCE 0x8C46
#endif
#ifndef GL_SLUMINANCE8
#  define GL_SLUMINANCE8 0x8C47
#endif
#ifndef GL_COMPRESSED_SLUMINANCE
#  define GL_COMPRESSED_SLUMINANCE 0x8C4A
#endif
#ifndef GL_COMPRESSED_SLUMINANCE_ALPHA
#  define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
#endif
// --------------------------------------------------------
//           Extension gl function typedefs
// --------------------------------------------------------
#ifndef __GLUX__GLFCT_glUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x3fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
// --------------------------------------------------------
//           Extension gl functions
// --------------------------------------------------------
namespace glux {
#ifndef __GLUX__GLFCT_glUniformMatrix2x3fv
extern PFNGLUXUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x2fv
extern PFNGLUXUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix2x4fv
extern PFNGLUXUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x2fv
extern PFNGLUXUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x4fv
extern PFNGLUXUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x3fv
extern PFNGLUXUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;
#endif
} // namespace glux
// --------------------------------------------------------
#endif
// --------------------------------------------------------

// --------------------------------------------------------
// Generated by glux perl script (Mon Feb 23 17:43:05 2015)
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

#ifndef __GLUX_GL_VERSION_2_1__
#define __GLUX_GL_VERSION_2_1__

GLUX_NEW_PLUGIN(GL_VERSION_2_1)
// --------------------------------------------------------
//           Extension conditions
// --------------------------------------------------------
// --------------------------------------------------------
//           Extension defines
// --------------------------------------------------------
#ifndef GL_PIXEL_PACK_BUFFER
#  define GL_PIXEL_PACK_BUFFER 0x88EB
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER
#  define GL_PIXEL_UNPACK_BUFFER 0x88EC
#endif
#ifndef GL_PIXEL_PACK_BUFFER_BINDING
#  define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#endif
#ifndef GL_PIXEL_UNPACK_BUFFER_BINDING
#  define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#endif
#ifndef GL_FLOAT_MAT2x3
#  define GL_FLOAT_MAT2x3 0x8B65
#endif
#ifndef GL_FLOAT_MAT2x4
#  define GL_FLOAT_MAT2x4 0x8B66
#endif
#ifndef GL_FLOAT_MAT3x2
#  define GL_FLOAT_MAT3x2 0x8B67
#endif
#ifndef GL_FLOAT_MAT3x4
#  define GL_FLOAT_MAT3x4 0x8B68
#endif
#ifndef GL_FLOAT_MAT4x2
#  define GL_FLOAT_MAT4x2 0x8B69
#endif
#ifndef GL_FLOAT_MAT4x3
#  define GL_FLOAT_MAT4x3 0x8B6A
#endif
#ifndef GL_SRGB
#  define GL_SRGB 0x8C40
#endif
#ifndef GL_SRGB8
#  define GL_SRGB8 0x8C41
#endif
#ifndef GL_SRGB_ALPHA
#  define GL_SRGB_ALPHA 0x8C42
#endif
#ifndef GL_SRGB8_ALPHA8
#  define GL_SRGB8_ALPHA8 0x8C43
#endif
#ifndef GL_COMPRESSED_SRGB
#  define GL_COMPRESSED_SRGB 0x8C48
#endif
#ifndef GL_COMPRESSED_SRGB_ALPHA
#  define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#endif
#ifndef GL_CURRENT_RASTER_SECONDARY_COLOR
#  define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#endif
#ifndef GL_SLUMINANCE_ALPHA
#  define GL_SLUMINANCE_ALPHA 0x8C44
#endif
#ifndef GL_SLUMINANCE8_ALPHA8
#  define GL_SLUMINANCE8_ALPHA8 0x8C45
#endif
#ifndef GL_SLUMINANCE
#  define GL_SLUMINANCE 0x8C46
#endif
#ifndef GL_SLUMINANCE8
#  define GL_SLUMINANCE8 0x8C47
#endif
#ifndef GL_COMPRESSED_SLUMINANCE
#  define GL_COMPRESSED_SLUMINANCE 0x8C4A
#endif
#ifndef GL_COMPRESSED_SLUMINANCE_ALPHA
#  define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
#endif
// --------------------------------------------------------
//           Extension gl function typedefs
// --------------------------------------------------------
#ifndef __GLUX__GLFCT_glUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x3fv
typedef void (APIENTRYP PFNGLUXUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
// --------------------------------------------------------
//           Extension gl functions
// --------------------------------------------------------
namespace glux {
#ifndef __GLUX__GLFCT_glUniformMatrix2x3fv
extern PFNGLUXUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x2fv
extern PFNGLUXUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix2x4fv
extern PFNGLUXUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x2fv
extern PFNGLUXUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix3x4fv
extern PFNGLUXUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
#endif
#ifndef __GLUX__GLFCT_glUniformMatrix4x3fv
extern PFNGLUXUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;
#endif
} // namespace glux
// --------------------------------------------------------
#endif
// --------------------------------------------------------