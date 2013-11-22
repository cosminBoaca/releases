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
// source        : Tuple.fw
// file          : include/CGAL/Twotuple.h
// package       : Kernel_basic (2.9)
// revision      : 2.9
// revision_date : 04 Dec 1999 
// author(s)     : Andreas Fabri
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra>)
// email         : cgal@cs.uu.nl
//
// ======================================================================
 

#ifndef CGAL__TWOTUPLE_H
#define CGAL__TWOTUPLE_H

CGAL_BEGIN_NAMESPACE

template < class T >
class _Twotuple : public Rep
{
public:
  T  e0;
  T  e1;

  _Twotuple()
  {}

  _Twotuple(const T & a0, const T &a1)
  : e0(a0), e1(a1)
  {}

  ~_Twotuple()
  {}
};
CGAL_END_NAMESPACE

#endif // CGAL__TWOTUPLE_H
