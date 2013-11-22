// ======================================================================
//
// Copyright (c) 1999 The GALIA Consortium
//
// This software and related documentation is part of the
// Computational Geometry Algorithms Library (CGAL).
//
// Every use of CGAL requires a license. Licenses come in three kinds:
//
// - For academic research and teaching purposes, permission to use and
//   copy the software and its documentation is hereby granted free of  
//   charge, provided that
//   (1) it is not a component of a commercial product, and
//   (2) this notice appears in all copies of the software and
//       related documentation.
// - Development licenses grant access to the source code of the library 
//   to develop programs. These programs may be sold to other parties as 
//   executable code. To obtain a development license, please contact
//   the GALIA Consortium (at cgal@cs.uu.nl).
// - Commercialization licenses grant access to the source code and the
//   right to sell development licenses. To obtain a commercialization 
//   license, please contact the GALIA Consortium (at cgal@cs.uu.nl).
//
// This software and documentation is provided "as-is" and without
// warranty of any kind. In no event shall the CGAL Consortium be
// liable for any damage of any kind.
//
// The GALIA Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
// release       : CGAL-2.0
// release_date  : 1999, June 03
//
// file          : include/CGAL/convex_hull_3.h
// package       : Convex_hull_3 (2.0.4)
// source        : chull_traits.lw
// revision      : 2.0.3
// revision_date : 28 Apr 1999
// author(s)     : Stefan Schirra
//
// coordinator   : MPI, Saarbruecken
// email         : cgal@cs.uu.nl
//
// ======================================================================

#ifndef CGAL_CONVEX_HULL_3_H
#define CGAL_CONVEX_HULL_3_H

#include <CGAL/dd_geo/chull_traits_3.h>
#include <CGAL/dd_geo/chull_support_3.h>

CGAL_BEGIN_NAMESPACE
template <class InputIterator, class Polyhedron>
void
convex_hull_3( InputIterator first, InputIterator beyond, Polyhedron& P)
{
  typedef typename Polyhedron::Traits       PolyTraits;
  typedef typename Polyhedron::Halfedge_data_structure
                                            HDS;
  typedef typename PolyTraits::R            R;
  typedef typename PolyTraits::Point        Point;
  typedef chull_traits_3<R>                 ChullTraits;
#ifndef CGAL_CFG_NO_DEFAULT_TEMPLATE_ARGUMENTS
  typedef chull< ChullTraits >              ChullType;
#else
  typedef Plane_3<R>                        Plane;
  typedef chull< ChullTraits, Point, Plane> ChullType;
#endif // CGAL_CFG_NO_DEFAULT_TEMPLATE_ARGUMENTS

  ChullType CH(3);
  for ( ; first != beyond ; ++first)  CH.insert(*first);

#ifndef DDGEO_STL_ITERATORS
  GRAPH<Point,int> G; 
  d3_surface_map( CH, G);
  G.compute_faces();
  Build_polyhedron_from_GRAPH< HDS>  polyhedron_maker( G );
#else
  Build_polyhedron_from_chull< HDS, ChullType>  polyhedron_maker( CH);
#endif // DDGEO_STL_ITERATORS
  Polyhedron P_local;
  P_local.delegate( polyhedron_maker );
  P = P_local;
}
CGAL_END_NAMESPACE

#endif // CGAL_CONVEX_HULL_3_H