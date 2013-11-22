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
// file          : include/CGAL/constructions/squared_radius_smallest_orthogonalcircle_ftC2.h
// package       : Alpha_shapes_2 (11.19)
// source        : $RCSfile: squared_radius_smallest_orthogonalcircle_ftC2.h,v $
// revision      : $Revision: 1.6 $
// revision_date : $Date: 2000/07/11 16:16:11 $
// author(s)     : Tran Kai Frank DA
//
// coordinator   : INRIA Sophia-Antipolis (<Mariette.Yvinec>)
//
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================

#ifndef CGAL_SQUARED_RADIUS_SMALLEST_ORTHOGONALCIRCLE_FTC2_H 
#define CGAL_SQUARED_RADIUS_SMALLEST_ORTHOGONALCIRCLE_FTC2_H

#include <CGAL/determinant.h>
#include <CGAL/enum.h>

//-------------------------------------------------------------------
CGAL_BEGIN_NAMESPACE
//-------------------------------------------------------------------

template< class FT >
CGAL_MEDIUM_INLINE
FT
squared_radius_orthogonalcircleC2(
  const FT &px, const FT &py, const FT  &pw,
  const FT &qx, const FT &qy, const FT  &qw,  
  const FT &rx, const FT &ry, const FT  &rw)

{
  FT FT4(4);
  FT dpx = px-rx;
  FT dpy = py-ry;
  FT dqx = qx-rx;
  FT dqy = qy-ry;
  FT dpp = CGAL_NTS square(dpx)+CGAL_NTS square(dpy)-pw+rw;
  FT dqq = CGAL_NTS square(dqx)+CGAL_NTS square(dqy)-qw+rw;

  FT det0 = det2x2_by_formula(dpx, dpy, dqx, dqy);
  
  FT det1 = det2x2_by_formula(dpp, dpy, dqq, dqy);

  FT det2 = det2x2_by_formula(dpx, dpp, dqx, dqq);

  return 
    (CGAL_NTS square(det1)+CGAL_NTS square(det2))/
                                  (FT4*CGAL_NTS square(det0)) - rw;
}

template< class FT >
CGAL_MEDIUM_INLINE
FT
squared_radius_smallest_orthogonalcircleC2(
  const FT &px, const FT &py, const FT  &pw,
  const FT &qx, const FT &qy, const FT  &qw)

{
  FT FT4(4);
  FT dpz = CGAL_NTS square(px-qx)+CGAL_NTS square(py-qy);

  return (CGAL_NTS square(dpz-pw+qw)/(FT4*dpz)-qw);
}

//-------------------------------------------------------------------
CGAL_END_NAMESPACE
//-------------------------------------------------------------------

#endif //CGAL_SQUARED_RADIUS_SMALLEST_ORTHOGONALCIRCLE_ftC2_H