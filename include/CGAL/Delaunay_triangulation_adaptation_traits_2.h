// Copyright (c) 2006 Foundation for Research and Technology-Hellas (Greece).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.4-branch/Voronoi_diagram_2/include/CGAL/Delaunay_triangulation_adaptation_traits_2.h $
// $Id: Delaunay_triangulation_adaptation_traits_2.h 29163 2006-03-07 23:41:02Z mkaravel $
// 
//
// Author(s)     : Menelaos Karavelas <mkaravel@iacm.forth.gr>

#ifndef CGAL_DELAUNAY_TRIANGULATION_ADAPTATION_TRAITS_2_H
#define CGAL_DELAUNAY_TRIANGULATION_ADAPTATION_TRAITS_2_H 1

#include <CGAL/Voronoi_diagram_2/basic.h>
#include <CGAL/Voronoi_diagram_2/Delaunay_triangulation_nearest_site_2.h>
#include <CGAL/Voronoi_diagram_2/Adaptation_traits_base_2.h>
#include <CGAL/Voronoi_diagram_2/Site_accessors.h>
#include <CGAL/Voronoi_diagram_2/Construct_dual_points.h>
#include <CGAL/Voronoi_diagram_2/Adaptation_traits_functors.h>


CGAL_BEGIN_NAMESPACE

template<class DT2>
struct Delaunay_triangulation_adaptation_traits_2
  : public CGAL_VORONOI_DIAGRAM_2_INS::Adaptation_traits_base_2
  <DT2,
   CGAL_VORONOI_DIAGRAM_2_INS::Point_accessor
   <typename DT2::Geom_traits::Point_2,DT2,Tag_true>,
   CGAL_VORONOI_DIAGRAM_2_INS::Delaunay_triangulation_Voronoi_point_2<DT2>,
   CGAL_VORONOI_DIAGRAM_2_INS::Delaunay_triangulation_nearest_site_2<DT2> >
{
  typedef typename DT2::Geom_traits::Point_2      Point_2;
  typedef Point_2                                 Site_2;
};


CGAL_END_NAMESPACE

#endif // CGAL_DELAUNAY_TRIANGULATION_ADAPTATION_TRAITS_2_H
