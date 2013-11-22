// ======================================================================
//
// Copyright (c) 1997 The CGAL Consortium

// This software and related documentation are part of the Computational
// Geometry Algorithms Library (CGAL).
// This software and documentation are provided "as-is" and without warranty
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
// - Please check the CGAL web site http://www.cgal.org/index2.html for 
//   availability.
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-2.4
// release_date  : 2002, May 16
//
// file          : include/CGAL/Alpha_shape_euclidean_traits_2.h
// package       : Alpha_shapes_2 (11.19)
// source        : $RCSfile: Alpha_shape_euclidean_traits_2.h,v $
// revision      : $Revision: 1.7 $
// revision_date : $Date: 2001/12/01 12:42:25 $
// author(s)     : Tran Kai Frank DA
//
// coordinator   : INRIA Sophia-Antipolis (<Mariette.Yvinec>)
//
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================

#ifndef CGAL_ALPHA_SHAPE_EUCLIDEAN_TRAITS_H
#define CGAL_ALPHA_SHAPE_EUCLIDEAN_TRAITS_H

#include <CGAL/basic.h>

#include <CGAL/Triangulation_euclidean_traits_2.h>

#include <CGAL/smallest_radius_2.h>

//-------------------------------------------------------------------
CGAL_BEGIN_NAMESPACE
//-------------------------------------------------------------------

//------------------ Function Objects ---------------------------------

template < class return_type, class T >
class Compute_squared_radius_2
{
public:
  typedef return_type result_type;

  result_type operator()(const T& p, const T& q, const T& r) const
    {
      return CGAL::squared_radius(p, q, r);
    }

  result_type operator()(const T& p, const T& q) const
    {
      return CGAL::squared_radius_smallest_circumcircle(p, q);
    }
};

//------------------ Traits class -------------------------------------

template < class R >
class Alpha_shape_euclidean_traits_2 : public
Triangulation_euclidean_traits_2<R> 
{
public: 
  typedef typename R::FT Coord_type;
  typedef typename Triangulation_euclidean_traits_2<R>::Point Point;

  typedef CGAL::Compute_squared_radius_2<Coord_type, Point> 
  Compute_squared_radius_2;
  typedef typename R::Side_of_bounded_circle_2 Side_of_bounded_circle_2;
  
  //------------------------------------------------------------------

  Compute_squared_radius_2
  compute_squared_radius_2_object() const
    {
      return Compute_squared_radius_2();
    }

  //------------------------------------------------------------------

  Side_of_bounded_circle_2 side_of_bounded_circle_2_object() const
    {
      return Side_of_bounded_circle_2();
    }
};

//-------------------------------------------------------------------
CGAL_END_NAMESPACE
//-------------------------------------------------------------------

#endif