// ======================================================================
//
// Copyright (c) 1997 The CGAL Consortium

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
// file          : include/CGAL/smallest_radiusC2.h
// package       : Alpha_shapes_2 (5.5)
// source        : $RCSfile: smallest_radiusC2.h,v $
// revision      : $Revision: 1.3 $
// revision_date : $Date: 1999/11/05 16:37:28 $
// author(s)     : Tran Kai Frank DA
//
// coordinator   : INRIA Sophia-Antipolis (<Mariette.Yvinec>)
//
//
// email         : cgal@cs.uu.nl
//
// ======================================================================

#ifndef CGAL_SMALLEST_RADIUSC2_H
#define CGAL_SMALLEST_RADIUSC2_H

#include <CGAL/cartesian_classes.h>
//#include <CGAL/Cartesian/Point_2.h>
//#include <CGAL/Cartesian/Vector_2.h>

//-------------------------------------------------------------------
CGAL_BEGIN_NAMESPACE
//-------------------------------------------------------------------

template < class R >
inline
typename R::FT
squared_radius_circumcircle(const PointC2<R> &p,
			    const PointC2<R> &q,
			    const PointC2<R> &r)
{
  
  // the computation of the squared radius takes 17 multiplications
  // and 12 additions
  
  typedef typename R::FT FTT;

  VectorC2<R> v(p-q);
  FTT numerator = v*v;
  v=q-r;
  numerator *= (v*v);
  v=r-p;
  numerator *= (v*v);
 
  FTT denominator = (p.x()-q.x())*(q.y()-r.y())
    - (p.y()-q.y())*(q.x()-r.x());
  
  // assert(demominator ==  (p.x()*q.y() + q.x()*r.y() + r.x()*p.y()
  //			  -r.x()*q.y() - q.x()*p.y() - p.x()*r.y()));

  return ((denominator > FTT(0) ? 
	   numerator /(FTT(4) * denominator * denominator) : FTT(0)));
}

//-------------------------------------------------------------------
CGAL_END_NAMESPACE
//-------------------------------------------------------------------

#endif //CGAL_SMALLEST_RADIUSC2_H
