// ======================================================================
//
// Copyright (c) 1997-2001 The CGAL Consortium

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
// - A commercial license is available through Algorithmic Solutions, who also
//   markets LEDA (http://www.algorithmic-solutions.com). 
// - Commercial users may apply for an evaluation license by writing to
//   (Andreas.Fabri@geometryfactory.com). 
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-2.3
// release_date  : 2001, August 13
//
// file          : include/CGAL/Optimisation/Access_coordinates_begin_d.h
// package       : Optimisation_basic (3.8.10)
//
// revision      : $Revision: 1.2 $
// revision_date : $Date: 2001/03/21 18:29:00 $
//
// author(s)     : Sven Sch�nherr
// coordinator   : ETH Z�rich (Bernd G�rtner)
//
// implementation: dD data accessor `coordinates'
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================

#ifndef CGAL_OPTIMISATION_ACCESS_COORDINATES_BEGIN_D_H
#define CGAL_OPTIMISATION_ACCESS_COORDINATES_BEGIN_D_H

// includes
#ifndef CGAL_POINT_D_H
#  include <CGAL/Point_d.h>
#endif

CGAL_BEGIN_NAMESPACE

// Class declaration
// =================
template < class R_ >
class Access_coordinates_begin_d;

// Class interface
// ===============
template < class R_ >
class Access_coordinates_begin_d {
  public:
    // self
    typedef  R_                         R;
    typedef  Access_coordinates_begin_d<R>
                                        Self;

    // types
    typedef  typename R::Point_d        Point;
    typedef  const typename R::RT *     Coordinate_iterator;

    // unary function class types
    typedef  Coordinate_iterator        result_type;
    typedef  Point                      argument_type;

    // creation
    Access_coordinates_begin_d( ) { }

    // operations
    Coordinate_iterator
    operator() ( const Point& p) const { return p.begin(); }
};

CGAL_END_NAMESPACE

#endif // CGAL_OPTIMISATION_ACCESS_COORDINATES_BEGIN_D_H

// ===== EOF ==================================================================
