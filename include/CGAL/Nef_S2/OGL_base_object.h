// Copyright (c) 1997-2002  Max-Planck-Institute Saarbruecken (Germany).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.3-branch/Nef_S2/include/CGAL/Nef_S2/OGL_base_object.h $
// $Id: OGL_base_object.h 37332 2007-03-20 20:33:56Z reichel $
// 
//
// Author(s)     : Peter Hachenberger  <hachenberger@mpi-sb.mpg.de>

#ifndef CGAL_OGL_BASE_OBJECT_H
#define CGAL_OGL_BASE_OBJECT_H

#include <CGAL/Simple_cartesian.h>

CGAL_BEGIN_NAMESPACE

namespace OGL {

  class OGL_base_object {    
  public:

    typedef CGAL::Simple_cartesian<double>       Double_kernel;  
    typedef Double_kernel::Point_3               Double_point;
    typedef Double_kernel::Vector_3              Double_vector;
    typedef Double_kernel::Segment_3             Double_segment;
    typedef Double_kernel::Aff_transformation_3  Affine_3;

    virtual void draw() const  = 0;
    virtual void init() = 0;
    virtual void toggle(int) = 0;
    virtual void set_style(int) = 0;
    virtual ~OGL_base_object() {}
  };
}

CGAL_END_NAMESPACE
#endif // CGAL_OGL_BASE_OBJECT_H
