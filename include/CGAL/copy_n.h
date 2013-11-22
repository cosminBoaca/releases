// ======================================================================
//
// Copyright (c) 1997, 1998, 1999, 2000 The CGAL Consortium

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
// file          : include/CGAL/copy_n.h
// package       : STL_Extension (2.34)
// chapter       : $CGAL_Chapter: STL Extensions for CGAL $
// source        : stl_extension.fw
// revision      : $Revision: 1.26 $
// revision_date : $Date: 2001/07/11 09:00:27 $
// author(s)     : Michael Hoffmann
//                 Lutz Kettner
//
// coordinator   : ETH
//
// STL like copy that copies n elements
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================


// This file is obsolete and exists only for backwards-compatibility.
// Include <CGAL/algorithm.h> instead.

#ifndef CGAL_COPY_N_H
#define CGAL_COPY_N_H 1
#include <cstddef>

// copy_n is usually in the STL as well, but not in the official
// standard. We provide out own copy_n. Only on Gnu g++ 2.8.1
// the hack to work with namespaces gives a name clash, which
// we avoid using the follwing workaround.
#ifndef CGAL_CFG_NO_NAMESPACE
CGAL_BEGIN_NAMESPACE
template <class InputIterator, class Size, class OutputIterator>
OutputIterator copy_n( InputIterator first,
                       Size n,
                       OutputIterator result) {
  // copies the first `n' items from `first' to `result'. Returns
  // the value of `result' after inserting the `n' items.
  while( n--) {
    *result = *first;
    first++;
    result++;
  }
  return result;
}
CGAL_END_NAMESPACE
#endif // CGAL_CFG_NO_NAMESPACE //
#endif // CGAL_COPY_N_H //
// EOF //
