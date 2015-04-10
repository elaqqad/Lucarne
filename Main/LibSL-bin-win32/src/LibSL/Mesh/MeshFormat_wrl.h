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
// LibSL::Mesh::MeshFormat_wrl
// ------------------------------------------------------
//
// Saves as WRL for 3D printing
// 
// ------------------------------------------------------
// Sylvain Lefebvre - 2013-03-27
// ------------------------------------------------------

#pragma once

#include <LibSL/Math/Vertex.h>
#include <LibSL/Mesh/Mesh.h>

namespace LibSL {
  namespace Mesh {

    class MeshFormat_wrl : public TriangleMeshFormat_plugin
    {

    public:

      typedef struct
      {
        LibSL::Math::v3f pos;
        LibSL::Math::v3f nrm;
        LibSL::Math::v2f uv;
        LibSL::Math::v3f clr;
      } t_VertexData;

      typedef MVF4(mvf_position_3f,mvf_normal_3f,mvf_texcoord0_2f,mvf_color0_3f) t_VertexFormat;

    public:

      MeshFormat_wrl();
      void           save(const char *,const TriangleMesh *) const;
      TriangleMesh  *load(const char *)                      const;
      const char    *signature()                             const {return "wrl";}

    };

  } //namespace LibSL::Mesh
} //namespace LibSL

// ------------------------------------------------------
