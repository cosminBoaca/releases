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
// source        : enum.fw
// file          : include/CGAL/enum.h
// package       : Kernel_basic (2.9)
// revision      : 2.9
// revision_date : 04 Dec 1999 
// author(s)     : Stefan Schirra
//
// coordinator   : MPI, Saarbruecken
// email         : cgal@cs.uu.nl
//
// ======================================================================


#ifndef CGAL_ENUM_H
#define CGAL_ENUM_H

CGAL_BEGIN_NAMESPACE


enum  Sign
      {
        NEGATIVE   = -1,
        ZERO,
        POSITIVE
      };

typedef Sign Orientation;

const Orientation  LEFTTURN   = POSITIVE;
const Orientation  RIGHTTURN  = NEGATIVE;

const Orientation  CLOCKWISE  = NEGATIVE;
const Orientation  COUNTERCLOCKWISE = POSITIVE;

const Orientation  COLLINEAR  = ZERO;
const Orientation  COPLANAR   = ZERO;
const Orientation  DEGENERATE = ZERO;



enum  Oriented_side
      {
        ON_NEGATIVE_SIDE = -1,
        ON_ORIENTED_BOUNDARY,
        ON_POSITIVE_SIDE
      };


enum  Bounded_side
      {
        ON_UNBOUNDED_SIDE = -1,
        ON_BOUNDARY,
        ON_BOUNDED_SIDE
      };


enum  Comparison_result
      {
        SMALLER   = -1,
        EQUAL,
        LARGER
      };

CGAL_END_NAMESPACE


#ifndef CGAL_FUNCTIONS_ON_ENUMS_H
#include <CGAL/functions_on_enums.h>
#endif // CGAL_FUNCTIONS_ON_ENUMS_H

#endif // CGAL_ENUM_H
