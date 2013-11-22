// ======================================================================
//
// Copyright (c) 1999 The CGAL Consortium

// This software and related documentation is part of the Computational
// Geometry Algorithms Library (CGAL).
// This software and documentation is provided "as-is" and without warranty
// of any kind. In no event shall the CGAL Consortium be liable for any
// damage of any kind. 
//
// Every use of CGAL requires a license. 
//
// Academic research and teaching license
// - For academic research and teaching purposes, permission to use and copy
//   the software and its documentation is hereby granted free of charge,
//   provided that it is not a component of a commercial product, and this
//   notice appears in all copies of the software and related documentation. 
//
// Commercial licenses
// - A commercial license is available through Algorithmic Solutions, who also
//   markets LEDA (http://www.algorithmic-solutions.de). 
// - Commercial users may apply for an evaluation license by writing to
//   Algorithmic Solutions (contact@algorithmic-solutions.com). 
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
// release       : CGAL-2.2
// release_date  : 2000, September 30
//
// file          : include/CGAL/convex_hull_traits_2.h
// package       : Convex_hull (3.3)
// source        : convex_hull_2.lw
// revision      : 3.3
// revision_date : 03 Aug 2000
// author(s)     : Stefan Schirra
//
// coordinator   : MPI, Saarbruecken
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================


#ifndef CGAL_CONVEX_HULL_TRAITS_2_H
#define CGAL_CONVEX_HULL_TRAITS_2_H

#include <CGAL/Point_2.h>
#include <CGAL/predicates_on_points_2.h>
#include <CGAL/distance_predicates_2.h>
#include <CGAL/predicate_objects_on_points_2.h>

CGAL_BEGIN_NAMESPACE
template <class R_>
class convex_hull_traits_2 : public R_
{
public:
  typedef   R_                                              R;
  typedef   CGAL::Point_2<R>                                Point_2;    
  typedef   CGAL::p_Less_xy<Point_2>                        Less_xy_2;
  typedef   CGAL::p_Less_yx<Point_2>                        Less_yx_2;
  typedef   CGAL::p_Left_of_line_2p<Point_2>                Left_of_line_2;
  typedef   CGAL::p_Less_dist_to_line_2p<Point_2>           Less_signed_distance_to_line_2;
  typedef   CGAL::p_Less_rotate_ccw<Point_2>                Less_rotate_ccw_2;
  typedef   CGAL::p_Leftturn<Point_2>                       Leftturn_2;
  typedef   CGAL::Segment_2<R>                              Segment_2;    
  
  Less_xy_2
  less_xy_2_object() const 
  { return Less_xy_2(); } 

  Less_yx_2
  less_yx_2_object() const 
  { return Less_yx_2(); } 

  Left_of_line_2
  left_of_line_2_object( const Point_2& p, const Point_2& q) const 
  { return Left_of_line_2( p, q); } 

  Less_signed_distance_to_line_2
  less_signed_distance_to_line_2_object( const Point_2& p, const Point_2& q) const
  { return Less_signed_distance_to_line_2( p, q); } 

  Less_rotate_ccw_2
  less_rotate_ccw_2_object( const Point_2& p ) const
  { return Less_rotate_ccw_2( p); }

  Leftturn_2
  leftturn_2_object() const
  { return Leftturn_2(); }

};

CGAL_END_NAMESPACE

#endif // CGAL_CONVEX_HULL_TRAITS_2_H

