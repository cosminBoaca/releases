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
// 
// release       : CGAL-2.1
// release_date  : 2000, January 11
// 
// source        : distance_predicates_2.fw
// file          : include/CGAL/distance_predicates_2.h
// package       : _2 (2.8.1)
// revision      : 2.8.1
// revision_date : 07 Nov 1999 
// author(s)     : Stefan Schirra
//
// coordinator   : MPI, Saarbruecken
// email         : cgal@cs.uu.nl
//
// ======================================================================


#ifndef CGAL_DISTANCE_PREDICATES_2_H
#define CGAL_DISTANCE_PREDICATES_2_H

#ifndef CGAL_REP_CLASS_DEFINED
#error  no representation class defined
#endif  // CGAL_REP_CLASS_DEFINED

#ifdef CGAL_HOMOGENEOUS_H
#ifndef CGAL_DISTANCE_PREDICATESH2_H
#include <CGAL/distance_predicatesH2.h>
#endif // CGAL_DISTANCE_PREDICATESH2_H
#endif // CGAL_HOMOGENEOUS_H

#ifdef CGAL_CARTESIAN_H
#ifndef CGAL_DISTANCE_PREDICATESC2_H
#include <CGAL/Cartesian/distance_predicates_2.h>
#endif // CGAL_DISTANCE_PREDICATESC2_H
#endif // CGAL_CARTESIAN_H

#ifndef CGAL_POINT_2_H
#include <CGAL/Point_2.h>
#endif // CGAL_POINT_2_H
#ifndef CGAL_LINE_2_H
#include <CGAL/Line_2.h>
#endif // CGAL_LINE_2_H

CGAL_BEGIN_NAMESPACE


template < class R >
inline
Comparison_result
cmp_dist_to_point(const Point_2<R>& p,
                  const Point_2<R>& q,
                  const Point_2<R>& r)
{
  typedef typename  R::Point_2_base  RPoint_2;
  return cmp_dist_to_point((const RPoint_2& )p,
                           (const RPoint_2& )q,
                           (const RPoint_2& )r );
}

template < class R >
inline
bool
has_larger_dist_to_point(const Point_2<R>& p,
                         const Point_2<R>& q,
                         const Point_2<R>& r)
{
  typedef typename  R::Point_2_base  RPoint_2;
  return has_larger_dist_to_point((const RPoint_2& )p,
                                  (const RPoint_2& )q,
                                  (const RPoint_2& )r );
}

template < class R >
inline
bool
has_smaller_dist_to_point(const Point_2<R>& p,
                               const Point_2<R>& q,
                               const Point_2<R>& r)
{
  typedef typename  R::Point_2_base  RPoint_2;
  return has_smaller_dist_to_point((const RPoint_2& )p,
                                        (const RPoint_2& )q,
                                        (const RPoint_2& )r );
}

template < class R >
inline
Comparison_result
cmp_signed_dist_to_line(const Line_2<R>&  l,
                        const Point_2<R>& p,
                        const Point_2<R>& q)
{
  typedef typename  R::Point_2_base  RPoint_2;
  typedef typename  R::Line_2_base  RLine_2 ;
  return cmp_signed_dist_to_line((const RLine_2& )l,
                                      (const RPoint_2& )p,
                                      (const RPoint_2& )q );
}

template < class R >
inline
bool
has_larger_signed_dist_to_line(const Line_2<R>&  l,
                                    const Point_2<R>& p,
                                    const Point_2<R>& q)
{
  typedef typename  R::Point_2_base  RPoint_2;
  typedef typename  R::Line_2_base  RLine_2 ;
  return has_larger_signed_dist_to_line((const RLine_2& )l,
                                             (const RPoint_2& )p,
                                             (const RPoint_2& )q );
}

template < class R >
inline
bool
has_smaller_signed_dist_to_line(const Line_2<R>&  l,
                                     const Point_2<R>& p,
                                     const Point_2<R>& q)
{
  typedef typename  R::Point_2_base  RPoint_2;
  typedef typename  R::Line_2_base  RLine_2 ;
  return has_smaller_signed_dist_to_line((const RLine_2& )l,
                                              (const RPoint_2& )p,
                                              (const RPoint_2& )q );
}

template < class R >
inline
Comparison_result
cmp_signed_dist_to_line(const Point_2<R>& p,
                             const Point_2<R>& q,
                             const Point_2<R>& r,
                             const Point_2<R>& s)
{
  typedef typename  R::Point_2_base  RPoint_2;
  return cmp_signed_dist_to_line((const RPoint_2& )p,
                                      (const RPoint_2& )q,
                                      (const RPoint_2& )r,
                                      (const RPoint_2& )s );
}

template < class R >
inline
bool
has_smaller_signed_dist_to_line(const Point_2<R>& p,
                                     const Point_2<R>& q,
                                     const Point_2<R>& r,
                                     const Point_2<R>& s)
{
  typedef typename  R::Point_2_base  RPoint_2;
  return has_smaller_signed_dist_to_line((const RPoint_2& )p,
                                              (const RPoint_2& )q,
                                              (const RPoint_2& )r,
                                              (const RPoint_2& )s );
}

template < class R >
inline
bool
has_larger_signed_dist_to_line(const Point_2<R>& p,
                                    const Point_2<R>& q,
                                    const Point_2<R>& r,
                                    const Point_2<R>& s)
{
  typedef typename  R::Point_2_base  RPoint_2;
  return has_larger_signed_dist_to_line((const RPoint_2& )p,
                                             (const RPoint_2& )q,
                                             (const RPoint_2& )r,
                                             (const RPoint_2& )s );
}

CGAL_END_NAMESPACE


#endif //CGAL_DISTANCE_PREDICATES_2_H
