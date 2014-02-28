// Copyright (c) 1997-2010  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 3 of the License,
// or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
//
// Author(s)     : Mariette Yvinec

#ifndef CGAL_PROJECTION_TRAITS_XZ_3_H
#define CGAL_PROJECTION_TRAITS_XZ_3_H

#include <CGAL/internal/Projection_traits_3.h>

namespace CGAL {

template < class R >
class Projection_traits_xz_3
  : public internal::Projection_traits_3<R,1>
{
  public:
    typedef typename internal::Cartesian_const_projection_iterator<R, 1> Cartesian_const_iterator_d;
    typedef typename R::Point_3 Point_d;
    typedef internal::Construct_cartesian_const_projection_iterator<R, 1> Construct_cartesian_const_iterator_d;
    typedef typename R::FT FT;
    typename R::FT x(const Point_d& p) { return internal::Projection_traits_3<R, 1>::x(p); }
    typename R::FT y(const Point_d& p) { return internal::Projection_traits_3<R, 1>::y(p); }  
  
    Construct_cartesian_const_iterator_d construct_cartesian_const_iterator_d_object() const {
       return Construct_cartesian_const_iterator_d();
    }  
};

} //namespace CGAL

#endif // CGAL_PROJECTION_TRAITS_XZ_3_H
