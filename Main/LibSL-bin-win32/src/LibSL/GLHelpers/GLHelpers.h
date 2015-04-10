/* --------------------------------------------------------------------
Author: Sylvain Lefebvre    sylvain.lefebvre@sophia.inria.fr

Simple Library for Graphics (LibSL)

This software is a computer program whose purpose is to offer a set of
tools to simplify programming real-time computer graphics applications
under OpenGL and DirectX.

This software is governed by the CeCILL-C license under French law and
abiding by the rules of distribution of free software.  You can  use,
modify and/ or redistribute the software under the terms of the CeCILL-C
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info".

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability.

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or
data to be ensured and,  more generally, to use and operate it in the
same conditions as regards security.

The fact that you are presently reading this means that you have had
knowledge of the CeCILL-C license and that you accept its terms.
-------------------------------------------------------------------- */
// ------------------------------------------------------
// LibSL::GLHelpers
// ------------------------------------------------------
//
// OpenGL helpers
//
// ------------------------------------------------------
// Sylvain Lefebvre - 2006-04-04
// ------------------------------------------------------

#pragma once

// ------------------------------------------------------

#include <LibSL/Errors/Errors.h>
#include <LibSL/System/Types.h>
#include <LibSL/Memory/Array.h>
#include <LibSL/Math/Vertex.h>
#include <LibSL/Math/Matrix4x4.h>

using namespace LibSL::System::Types;

#ifdef WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#ifdef USE_GLUX
# include <glux.h>
#include "GL_ARB_shader_objects.h"
#include "GL_ARB_vertex_shader.h"
#include "GL_ARB_fragment_shader.h"
#include "GL_EXT_geometry_shader4.h"
#include "GL_EXT_gpu_shader4.h"
#include "GL_ARB_timer_query.h"
#include "GL_ARB_occlusion_query.h"
#include "GL_ARB_texture_buffer_object.h"
#ifdef OPENGL4
#include "GL_ARB_vertex_buffer_object.h"
#include "GL_ARB_shader_image_load_store.h"
#include "GL_ARB_map_buffer_range.h"
#include "GL_ARB_shader_atomic_counters.h"
#include "GL_NV_shader_buffer_load.h"
#include "GL_ARB_compute_shader.h"
#include "GL_ARB_copy_buffer.h"
#endif
#undef Success
#else
#ifdef __APPLE__
#include <OpenGL/glext.h>
#else
#include <GL/glext.h>
#endif
#endif

#include <iostream>
#include <string>
#include <list>

// ------------------------------------------------------

#define LIBSL_GL_CHECK_ERROR {GLenum err; err=glGetError(); if (err) throw LibSL::GLHelpers::GLException("LibSL::GLHelpers - OpenGL error (%d), line %d, file %s",err,__LINE__,__FILE__); }

// ------------------------------------------------------

namespace LibSL {
	namespace GLHelpers {

    using namespace LibSL::Math;

		LIBSL_NEW_EXCEPTION_TYPE(GLException)

		GLhandleARB loadGLSLProgram(const char *prg,GLuint type);

#ifdef OPENGL4
		class GLBuffer;
    class GLCompute;
#endif

		class GLParameter;

    class GLBaseShader
    {
    public:
      virtual bool        isReady()  const =0;
      virtual bool        isActive() const =0;
      virtual bool        isStrict() const =0;
      virtual const char *name()     const =0;
      virtual GLhandleARB handle()   const =0;
    };

		class GLShader : public GLBaseShader
		{
		public:

			typedef struct {
				std::string code;
				uint        maxVerticesOut;
				GLuint      typeIn;
				GLuint      typeOut;
			} t_GeometryShaderNfo;

		private:

			std::string            m_Name;
			GLhandleARB            m_Shader;

			// error or warnings ?
			bool                   m_Strict;
			bool                   m_Active;

			// geometry shader settings
			uint                   m_gsMaxVerticesOut;

			// check everything is properly loaded
			void authorize() const;

		public:

			GLShader() : m_Shader(0), m_Strict(true), m_Active(false), m_gsMaxVerticesOut(0) { m_Name="[null]"; }

			void init(const char *vp_code,const char *fp_code,const t_GeometryShaderNfo *gs_code = NULL,const char *name="[noname]");

			void init(GLhandleARB shader);

			void terminate();

			void begin();
			void end();

			GLhandleARB                        handle()     const {return (m_Shader);}
			const char *                  name()       const {return (m_Name.c_str());}

			bool  isReady()  const {return (m_Shader!=0);}
			bool  isActive() const {return (m_Active);}
			bool  isStrict() const {return (m_Strict);}

			void  setStrict(bool s) {m_Strict=s;}

		};


		class GLParameter
		{
		protected:

			// handle to shader to which the parameter is bound
			const GLBaseShader *m_Shader;

			// handle to parameter
			GLint            m_Handle;

			// parameter name
			std::string      m_Name;

			// check everything is properly loaded
			void authorize() const;

			// error or warnings ?
			bool                   m_Strict;

		public:

			GLParameter() : m_Shader(NULL), m_Handle(-1), m_Strict(true)  { m_Name = "[null]"; }

			// init
			void init(GLBaseShader& shader,const char *name);

			// is parameter initialized
			bool isInitialized() const {return (m_Handle != -1 && m_Shader != NULL); }

			GLint handle() { return m_Handle; }

			// set methods
			void set(float f);
			void set(float a,float b);
			void set(float a,float b,float c);
			void set(float a,float b,float c,float d);
			void set(const float *matrix);
			void set(const LibSL::Math::m4x4f& m);
			void set(const LibSL::Memory::Array::Array<LibSL::Math::m4x4f>& m);
			void set(uint v);
			void set(int  v);
			void set(const LibSL::Math::v2f&);
			void set(const LibSL::Math::v3f&);
			void set(const LibSL::Math::v4f&);
      void set(const LibSL::Math::v3i& v);
      void set(const LibSL::Math::v4i& v);
			void setArray(const float *pv,int size);
			void setArray(const int   *pv,int size);
			void setArray(const uint  *pv,int size);
			void setArray(const v2f   *pv,int size);
			void setArray(const v2i   *pv,int size);
			void setArray(const v2u   *pv,int size);
			void setArray(const v3f   *pv,int size);
			void setArray(const v3i   *pv,int size);
			void setArray(const v3u   *pv,int size);
			void setArray(const v4f   *pv,int size);
			void setArray(const v4i   *pv,int size);
			void setArray(const v4u   *pv,int size);

#ifdef OPENGL4
			void set(const GLBuffer& buf);
#endif

		};

		class GLProtectViewport
		{
		private:

			GLint m_Vp[4];

		public:

			GLProtectViewport()
			{
				glGetIntegerv(GL_VIEWPORT,m_Vp);
			}

			~GLProtectViewport()
			{
				glViewport(m_Vp[0],m_Vp[1],m_Vp[2],m_Vp[3]);
			}

		};

		class GLProtectMatrices
		{
		public:

			GLProtectMatrices()
			{
				glMatrixMode(GL_TEXTURE);
				glPushMatrix();
				glMatrixMode(GL_PROJECTION);
				glPushMatrix();
				glMatrixMode(GL_MODELVIEW);
				glPushMatrix();
			}

			~GLProtectMatrices()
			{
				glMatrixMode(GL_TEXTURE);
				glPopMatrix();
				glMatrixMode(GL_PROJECTION);
				glPopMatrix();
				glMatrixMode(GL_MODELVIEW);
				glPopMatrix();
			}

		};

#ifdef OPENGL4

		class GLTimer
		{
		public:

			typedef GLuint t_Handle;

		private:

			t_Handle m_Handle;

		public:

			GLTimer() : m_Handle(0) {}

			void init()
			{
				sl_assert(m_Handle == 0);
				// check to make sure functionality is supported
				GLint bitsSupported;
				glGetQueryivARB(GL_TIME_ELAPSED,GL_QUERY_COUNTER_BITS_ARB,&bitsSupported);
				if (bitsSupported == 0) {
					throw LibSL::Errors::Fatal("LibSL::GLHelpers::GLTimer - hardware does not support timers");
				}
				glGenQueriesARB(1,&m_Handle);
			}

			void terminate()
			{
				sl_assert(m_Handle != 0);
				glDeleteQueriesARB(1,&m_Handle);
			}

			void start()
			{
				sl_assert(m_Handle != 0);
				glBeginQueryARB(GL_TIME_ELAPSED,m_Handle);
			}

			void stop()
			{
				sl_assert(m_Handle != 0);
				glEndQueryARB(GL_TIME_ELAPSED);
			}

			GLint64 done()
			{
				sl_assert(m_Handle != 0);
				int available=0;
				glGetQueryObjectivARB(m_Handle,
					GL_QUERY_RESULT_AVAILABLE_ARB,
					&available);
				if (available) {
					GLuint64 tmElapsed=0;
					glGetQueryObjectui64v(m_Handle, GL_QUERY_RESULT_ARB,&tmElapsed);
					return GLint64(tmElapsed);
				} else {
					return (-1);
				}
			}

      double waitResult()
      {
        while (1) {
          GLint64 t = done();
          if (t >= 0) {
            return ((double)t) / (1e6);
            break;
          }
        }
      }

		};

		// Helper class for data buffers. Relies on GL_NV_shader_buffer_load.
		class GLBuffer
		{
		protected:

      GLuint   m_glId;
			GLuint64 m_gpuPtr;
			uint     m_Sz;

      static const GLuint c_buf_type = GL_TEXTURE_BUFFER;

		public:

			GLBuffer( );
			GLBuffer( uint sz );
			virtual ~GLBuffer();
			GLBuffer(GLBuffer const& buffer);

      void adopt(GLBuffer const& buffer);
      void forget();

			GLuint glId() const { return m_glId; }
			uint size() const { return m_Sz; }
			void copy(GLBuffer const& buffer);

			void init(uint sz);
			void resize(uint sz);
			virtual void terminate();

			template <typename T>
			void writeTo(const LibSL::Memory::Array::Array<T>& arr)
			{
				sl_assert( m_glId != 0 );
				sl_assert( arr.size()*sizeof(T) <= m_Sz );
//				LIBSL_GL_CHECK_ERROR;
				glBindBufferARB(c_buf_type, m_glId);
				glBufferSubDataARB(c_buf_type, 0, arr.size()*sizeof(T), arr.raw());
        glBindBufferARB(c_buf_type, 0);
//				LIBSL_GL_CHECK_ERROR;
			}
			void writeTo (const void *raw,uint nBytes)
			{
				sl_assert( m_glId != 0 );
				sl_assert( nBytes <= m_Sz );
				LIBSL_GL_CHECK_ERROR;
				glBindBufferARB(c_buf_type, m_glId);
				glBufferSubDataARB(c_buf_type, 0, nBytes, raw);
				LIBSL_GL_CHECK_ERROR;
        glBindBufferARB(c_buf_type, 0);
			}

			template <typename T>
			void readBack(LibSL::Memory::Array::Array<T>& arr)
			{
				sl_assert( m_glId != 0 );
				sl_assert( arr.size()*sizeof(T) <= m_Sz );
				LIBSL_GL_CHECK_ERROR;
				glBindBufferARB(c_buf_type, m_glId);
				glGetBufferSubDataARB(c_buf_type,0,arr.size()*sizeof(T),arr.raw());
				LIBSL_GL_CHECK_ERROR;
        glBindBufferARB(c_buf_type, 0);
			}

			void readBack(void *raw,uint nBytes)
			{
				sl_assert( m_glId != 0 );
				sl_assert( nBytes <= m_Sz );
//				LIBSL_GL_CHECK_ERROR;
				glBindBufferARB(c_buf_type, m_glId);
				glGetBufferSubDataARB(c_buf_type,0,nBytes,raw);
//				LIBSL_GL_CHECK_ERROR;
        glBindBufferARB(c_buf_type, 0);
			}

      template <typename T>
      void readBackSub(LibSL::Memory::Array::Array<T>& arr,uint offset)
			{
				sl_assert( m_glId != 0 );
				sl_assert( offset + arr.size()*sizeof(T) <= m_Sz );
				LIBSL_GL_CHECK_ERROR;
				glBindBufferARB(c_buf_type, m_glId);
				glGetBufferSubDataARB(c_buf_type,offset,arr.size()*sizeof(T),arr.raw());
				LIBSL_GL_CHECK_ERROR;
        glBindBufferARB(c_buf_type, 0);
			}

      void readBackSub(void *raw,uint nBytes,uint offset)
			{
				sl_assert( m_glId != 0 );
				sl_assert( offset + nBytes <= m_Sz );
				LIBSL_GL_CHECK_ERROR;
				glBindBufferARB(c_buf_type, m_glId);
				glGetBufferSubDataARB(c_buf_type,offset,nBytes,raw);
				LIBSL_GL_CHECK_ERROR;
        glBindBufferARB(c_buf_type, 0);
			}

      GLuint64 ptr() const { sl_assert( m_glId != 0 ); return m_gpuPtr; }
		};

		class GLTexBuffer : public GLBuffer
		{
    protected:
      GLuint m_glTexId;
      GLuint m_glFormat;

      void createTexture();
      void deleteTexture();
    public:
      GLTexBuffer( );
      GLTexBuffer( uint sz );
      GLTexBuffer( uint sz, uint format );
      GLTexBuffer(GLTexBuffer const& buffer);

      void adopt(GLTexBuffer const& buffer);
      void forget();

      virtual ~GLTexBuffer() { terminate(); }

      void init(uint sz);
      void init(uint sz, uint format);

			void resize(uint sz);
      /*override*/ void terminate();

      GLuint glTexId()  const { return m_glTexId; }
      GLuint glFormat() const { return m_glFormat; }
    };

		class GLCompute : public GLBaseShader
		{
		private:

			std::string            m_Name;
			GLuint                 m_Shader;

			// error or warnings ?
			bool                   m_Strict;
			bool                   m_Active;

			// check everything is properly loaded
			void authorize() const;

		public:

			GLCompute() : m_Shader(0), m_Strict(true), m_Active(false) { m_Name="[null]"; }

			void init(const char *cp_code,const char *name="[noname]");
			void init(GLuint shader);

			void run(const LibSL::Math::v3i& numGroups);

			void terminate();

			void begin();
			void end();

			GLuint                        handle()     const {return (m_Shader);}
			const char *                  name()       const {return (m_Name.c_str());}

			bool  isReady()  const {return (m_Shader!=0);}
			bool  isActive() const {return (m_Active);}
			bool  isStrict() const {return (m_Strict);}

			void  setStrict(bool s) {m_Strict=s;}

		};

#endif

		// -----------------------------------------------------

	} //namespace LibSL::GLHelpers
} //namespace LibSL

// ------------------------------------------------------
