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

#ifndef CGAL_PROJECTION_TRAITS_YZ_3_H
#define CGAL_PROJECTION_TRAITS_YZ_3_H

#include <CGAL/internal/Projection_traits_3.h>

namespace CGAL {

template < class R >
class Projection_traits_yz_3
  : public internal::Projection_traits_3<R,0>
{
    typedef typename internal::Projection_traits_3<R, 0> base;
 public:
    typedef typename base::Cartesian_const_iterator_2 Cartesian_const_iterator_2;
    typedef typename base::Point_2 Point_2;
    typedef typename base::Construct_cartesian_const_iterator_2 Construct_cartesian_const_iterator_2;
    typedef typename base::FT FT;

    typedef typename R::Iso_rectangle_2 Iso_rectangle_2;
    typedef typename R::Circle_2 Circle_2;

    typedef typename R::Construct_min_vertex_2 Construct_min_vertex_2;
    typedef typename R::Construct_max_vertex_2 Construct_max_vertex_2;
    typedef typename R::Construct_center_2 Construct_center_2;
    typedef typename R::Compute_squared_radius_2 Compute_squared_radius_2;

    typedef typename R::Construct_iso_rectangle_2 Construct_iso_rectangle_2;
};

} //namespace CGAL

#endif // CGAL_PROJECTION_TRAITS_YZ_3_H
