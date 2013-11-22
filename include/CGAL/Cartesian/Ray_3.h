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
// file          : include/CGAL/Cartesian/Ray_3.h
// package       : C3 (4.0.3)
// revision      : $Revision: 1.7 $
// revision_date : $Date: 1999/11/05 22:29:39 $
// author(s)     : Andreas Fabri
// coordinator   : INRIA Sophia-Antipolis
//
// email         : cgal@cs.uu.nl
//
// ======================================================================

#ifndef CGAL_CARTESIAN_RAY_3_H
#define CGAL_CARTESIAN_RAY_3_H

#include <CGAL/Cartesian/redefine_names_3.h>
#include <CGAL/Twotuple.h>

CGAL_BEGIN_NAMESPACE

template < class _R >
class RayC3
#ifndef CGAL_CFG_NO_ADVANCED_KERNEL
// This is a partial specialization
<_R,Cartesian_tag>
#endif
  : public Handle
{
public:
  typedef _R                               R;
  typedef typename R::FT                   FT;
  typedef typename R::RT                   RT;
#ifndef CGAL_CFG_NO_ADVANCED_KERNEL
  typedef RayC3<R CGAL_CTAG>               Self;
  typedef typename R::Point_3              Point_3;
  typedef typename R::Direction_3          Direction_3;
  typedef typename R::Line_3               Line_3;
  typedef typename R::Aff_transformation_3 Aff_transformation_3;
#else
  typedef RayC3<R>                              Self;
  typedef typename R::Point_3_base              Point_3;
  typedef typename R::Direction_3_base          Direction_3;
  typedef typename R::Line_3_base               Line_3;
  typedef typename R::Aff_transformation_3_base Aff_transformation_3;
#endif

  RayC3();
  RayC3(const Self &r);
  RayC3(const Point_3 &sp, const Point_3 &secondp);
  RayC3(const Point_3 &sp, const Direction_3 &d);
  ~RayC3();

  Self        &operator=(const Self &r);

  bool        operator==(const Self &r) const;
  bool        operator!=(const Self &r) const;
  long        id() const;

  Point_3     start() const;
  Point_3     source() const;
  Point_3     second_point() const;
  Point_3     point(int i) const;

  Direction_3 direction() const;
  Line_3      supporting_line() const;
  Self        opposite() const;

  Self        transform(const Aff_transformation_3 &t) const;

  bool        is_degenerate() const;
  bool        has_on(const Point_3 &p) const;
  bool        collinear_has_on(const Point_3 &p) const;

private:
  _Twotuple< Point_3 > *ptr() const;
};

CGAL_END_NAMESPACE

#ifndef CGAL_CARTESIAN_CLASS_DEFINED
#include <CGAL/Cartesian/Ray_3.C>
#endif 

#endif // CGAL_CARTESIAN_RAY_3_H
