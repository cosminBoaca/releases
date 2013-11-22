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
// file          : include/CGAL/ch_value_type.h
// package       : Convex_hull (3.3)
// source        : stl_extensions.lw
// revision      : 3.2.1
// revision_date : 19 Apr 2000
// author(s)     : Stefan Schirra
//
// coordinator   : MPI, Saarbruecken
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================

#ifndef CGAL_CH_VALUE_TYPE_H
#define CGAL_CH_VALUE_TYPE_H

CGAL_BEGIN_NAMESPACE

#ifndef CGAL_CFG_NO_ITERATOR_TRAITS
template <class Iterator>
inline 
typename std::iterator_traits<Iterator>::value_type*
ch_value_type(const Iterator&) 
{
  typedef typename std::iterator_traits<Iterator>::value_type  v_type;
  return static_cast<v_type*>(0);
}
#else
#ifdef _MSC_VER
template<class Iterator> 
inline
Iterator::value_type* 
ch_value_type(const Iterator& it)
{return static_cast<Iterator::value_type*>(0); }

template<class T> 
inline
T*
ch_value_type(const T*) 
{return static_cast<T*>(0); }
#else 
#error To be fixed
#endif // _MSC_VER_
#endif // CGAL_CFG_NO_ITERATOR_TRAITS
CGAL_END_NAMESPACE
#endif // CGAL_CH_VALUE_TYPE_H
